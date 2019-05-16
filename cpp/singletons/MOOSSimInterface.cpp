#include<stdlib.h>      // exit
#include<iostream>
#include <typeinfo>
#include <sstream>
#include <unistd.h>	// sleep

#include "MOOSSimInterface.h"
#include <google/protobuf/text_format.h>


using namespace AVA::Hardware;
using namespace std;
using namespace AVA::HW_Interface;
using namespace google::protobuf;

MOOSSimInterface* MOOSSimInterface::myInstance = 0;

AVA::Hardware::CHWInterface *CreateHWInterface()
{
	MOOSSimInterface *hwInt = MOOSSimInterface::getInstance();
	return hwInt;
}

void DestroyHWInterface(AVA::Hardware::CHWInterface *hw)
{
	if(dynamic_cast<AVA::Hardware::MOOSSimInterface *>(hw) != NULL)
		delete hw;
}

MOOSSimInterface::MOOSSimInterface()
{
	m_configVars.params.resourceID = 799;
}

MOOSSimInterface::~MOOSSimInterface()
{
	// Stop the interface.
	Stop();
}

MOOSSimInterface *MOOSSimInterface::getInstance() {
  if(!myInstance) {
    myInstance = new MOOSSimInterface();
  }
  return myInstance;
}

bool MOOSSimInterface::Start(const AVA::HW_Interface::Configuration &config)
{
	//Foo test = &MOOSSimInterface::TestFunc;

  std::cout << "MSIM: MOOSSimInterface Hardware Interface started" << std::endl;

	/// Base class initialization.
	CHWInterface::Start(config);

	/// Load configuration.
	if(_config.has_type())
	{
		switch(_config.type())
		{
		case Configuration::FILE:
			// TODO: Handle file processing.
			break;
		case Configuration::TEXT:
			// TODO: Handle text-based config.
			break;
		default:
			break;
		}
	}

  // Provide a name of this process for configurations
	string name = _config.has_name() ? _config.name() : "HWInterface";
	vector<string> strArgs;
	strArgs.push_back(name);
	if(_config.options_size() > 0)
	{
		for(int i = 0; i < _config.options_size(); i++)
		{
			strArgs.push_back(_config.options(i));
		}
	}

	m_configVars.params.timeout = 10;
	m_configVars.params.simulate = true;
	m_configVars.params.batteryCharge = 2500;
	m_configVars.params.batteryRate = 0.1;

	m_receiveThread = new std::thread(&MOOSSimInterface::UDPReceiveThread, this);

	return true;
}

bool MOOSSimInterface::ProcessCommandRequest(std::string msg)
{
	AVA::HW_Interface::CommandRequest commandRequest;
	commandRequest.ParseFromString(msg);

	string value;
	google::protobuf::TextFormat::PrintToString(commandRequest, &value);
	std::cout << "Received Command Request:\n" << value << std::endl;

	string bufferString;
	commandRequest.SerializeToString(&bufferString);

	m_socketLock.Lock();
	/// Attempt to send serialized vehicle status message
	if (sendto(m_socket, (void *)bufferString.data(), bufferString.size(), 0,
		 (struct sockaddr *)&m_serverAddr, sizeof(m_serverAddr)) == -1)
	{
		perror("MSIM: Could not send command request");
	}
	else
	{
		std::cout << "Command Request Sent" << std::endl;
	}
	m_socketLock.Unlock();

}
/*
void MOOSSimInterface::ProcessCommandRequest(const AVA::HW_Interface::CommandRequest &commandRequest)
{
	string value;
	google::protobuf::TextFormat::PrintToString(commandRequest, &value);
	std::cout << "Received Command Request:\n" << value << std::endl;

	string bufferString;
	commandRequest.SerializeToString(&bufferString);

	m_socketLock.Lock();
	/// Attempt to send serialized vehicle status message
	if (sendto(m_socket, (void *)bufferString.data(), bufferString.size(), 0,
		 (struct sockaddr *)&m_serverAddr, sizeof(m_serverAddr)) == -1)
	{
		perror("MSIM: Could not send command request");
	}
	else
	{
		std::cout << "Command Request Sent" << std::endl;
	}
	m_socketLock.Unlock();
}

void MOOSSimInterface::ProcessCommandRequest(std::string msg)
{
	std::cout << "Josh Testing" << endl;
	AVA::HW_Interface::CommandRequest commandRequest;
	commandRequest.ParseFromString(msg);

	string value;
	google::protobuf::TextFormat::PrintToString(commandRequest, &value);
	std::cout << "Received Command Request:\n" << value << std::endl;

	string bufferString;
	commandRequest.SerializeToString(&bufferString);

	m_socketLock.Lock();
	/// Attempt to send serialized vehicle status message
	if (sendto(m_socket, (void *)bufferString.data(), bufferString.size(), 0,
		 (struct sockaddr *)&m_serverAddr, sizeof(m_serverAddr)) == -1)
	{
		perror("MSIM: Could not send command request");
	}
	else
	{
		std::cout << "Command Request Sent" << std::endl;
	}
	m_socketLock.Unlock();
}
*/

bool MOOSSimInterface::ProcessExecutionPlan(std::string msg)
{
	AVA::BE_LLP::SetTaskExecutionPlan executionPlan;
	if (executionPlan.ParseFromString(msg))
	{
		std::cout << "Valid execution plan received" << endl;
	}

}

bool MOOSSimInterface::Stop()
{
	// TODO: Stop threads and perform connection cleanup.

	return true;
}

std::vector<CTypeInfoWrapper> MOOSSimInterface::AnnounceSupportedMessages()
{
	vector<CTypeInfoWrapper> supportedTypes;
	supportedTypes.push_back(CTypeInfoWrapper(typeid(AVA::HLP_BE::Resource)));
	supportedTypes.push_back(CTypeInfoWrapper(typeid(AVA::HLP_BE::VehicleStatus)));
	return supportedTypes;
}

void MOOSSimInterface::AnnounceRegisteredMail()
{
	using namespace std::placeholders;

	AVA::Hardware::CTypeInfoWrapper epType(typeid(AVA::BE_LLP::SetTaskExecutionPlan));
	RegisterMailMessage(epType, "SetTaskExecutionPlan");
	AttachMessageProcessor(epType, this, std::bind(&MOOSSimInterface::ProcessExecutionPlan, this, _1));

	AVA::Hardware::CTypeInfoWrapper crType(typeid(AVA::HW_Interface::CommandRequest));
	RegisterMailMessage(crType, "CommandRequest");

	AttachMessageProcessor(crType, this, std::bind(&MOOSSimInterface::ProcessCommandRequest, this, _1));

	return _mailMap;
}

void MOOSSimInterface::UDPReceiveThread()
{
	createUDPClient();
	connectUDPServer();

	int slen=sizeof(m_serverAddr);

	// Initialize server with client port
	char buf[5000];
	std::stringstream ss;
	ss << "Heartbeat";
	std::string s = ss.str();
	strcpy(buf,s.c_str());

	/// Send heartbeat to udp server to initialize server and provide client address
	if (sendto(m_socket, buf, strlen(buf), 0, (struct sockaddr *)&m_serverAddr, slen)==-1)
		perror("MSIM: sendto");

	socklen_t addrlen = sizeof(m_serverAddr);
	int recvlen;

	// Set timeout on UDP receive call cfor server
	struct timeval tv;
	tv.tv_sec = m_configVars.params.timeout;
	tv.tv_usec = 0;
	if (setsockopt(m_socket, SOL_SOCKET, SO_RCVTIMEO,&tv,sizeof(tv)) < 0) {
	    perror("Error");
	}

	cout << "Server and client setup complete" << endl;

  while (true)
	{
		// *********************************************************************
		// Non-Blocking hold to receive vehicle status from UDP Server
		// *********************************************************************
		m_socketLock.Lock();
    recvlen = recvfrom(m_socket, buf, 5000, 0, (struct sockaddr *)&m_serverAddr, &addrlen);
		m_socketLock.Unlock();

    if (recvlen > 0)
    {
			/// Attempt to parse message into vehicle status and send to HardwareManager
			AVA::HLP_BE::VehicleStatus status;
			if( status.ParseFromArray( buf, recvlen ) )
			{
				string bufferString;
				status.SerializeToString(&bufferString);

				cout << "MSIM: Serialized string: " << bufferString << endl;

				string value;
				google::protobuf::TextFormat::PrintToString(status, &value);
				std::cout << "MSIM: Vehicle Status:\n" << value << std::endl;

				SendToMessageProcessor(typeid(AVA::HLP_BE::VehicleStatus), bufferString);
			}
			else
			{
				std::cout << "MSIM: Bad Vehicle Status received" << std::endl;
			}

			/// Assuming any data received means we are connected, report status of
			/// hardware
			AVA::HLP_BE::Resource resource;
			resource.set_resource_type(AVA::HLP_BE::Resource::INS);
			resource.set_identifier(m_configVars.params.resourceID);
			resource.set_health(AVA::HLP_BE::Operational);
			resource.set_sensor_mode(AVA::HLP_BE::Resource::Activated);

			string bufferString;
			resource.SerializeToString(&bufferString);

			SendToMessageProcessor(typeid(AVA::HLP_BE::Resource), bufferString);
    }
		else
		{
			std::cout << "MSIM: Vehicle status not received" << std::endl;

			AVA::HLP_BE::Resource resource;
			resource.set_resource_type(AVA::HLP_BE::Resource::INS);
			resource.set_identifier(m_configVars.params.resourceID);
			resource.set_health(AVA::HLP_BE::Failed);

			string bufferString;
			resource.SerializeToString(&bufferString);

			SendToMessageProcessor(typeid(AVA::HLP_BE::Resource), bufferString);
		}

		usleep(10000);	// 10ms
	}
}

void MOOSSimInterface::createUDPClient()
{
	/// Create UDP Connection to connect to Simulation of output
	if ((m_socket=socket(AF_INET, SOCK_DGRAM, 0))==-1)
		printf("MSIM: socket created\n");

	/// bind it to all local addresses and pick any port number
	memset((char *)&m_clientAddr, 0, sizeof(m_clientAddr));
	m_clientAddr.sin_family = AF_INET;
	m_clientAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	m_clientAddr.sin_port = htons(0);

	if (bind(m_socket, (struct sockaddr *)&m_clientAddr, sizeof(m_clientAddr)) < 0)
	{
		perror("MSIM: bind failed");
		return false;
	}
}

void MOOSSimInterface::connectUDPServer()
{
	char *server = "127.0.0.1";

	memset((char *) &m_serverAddr, 0, sizeof(m_serverAddr));
	m_serverAddr.sin_family = AF_INET;
	m_serverAddr.sin_port = htons(12345);
	if (inet_aton(server, &m_serverAddr.sin_addr)==0) {
		fprintf(stderr, "inet_aton() failed\n");
		exit(1);
	}
}
