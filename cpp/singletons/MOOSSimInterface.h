#pragma once
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include "HWInterface.h"
#include <thread>
#include "BE_LLP.pb.h"

extern "C"
{
DllExport AVA::Hardware::CHWInterface *CreateHWInterface();
DllExport void DestroyHWInterface(AVA::Hardware::CHWInterface *hw);

namespace AVA { namespace Hardware
{
DllExport class MOOSSimInterface : public AVA::Hardware::CHWInterface
{
public:
	typedef void (MOOSSimInterface::*Foo)(std::string msg);

  MOOSSimInterface();
  ~MOOSSimInterface();

	static MOOSSimInterface *getInstance();

  /**
  * Starts the HW interface. User defined behavior.
  */
  virtual bool Start(const AVA::HW_Interface::Configuration &config);
  /**
  * Stops the HW interface. User defined behavior.
  */
  virtual bool Stop();
  bool ProcessExecutionPlan(std::string msg);
	bool ProcessCommandRequest(std::string msg);

protected:
  /**
  * Announce message types being supported by hardware interface to pass data to hardware manager
  *
  * @return Compiled vector of type_info hash codes for supported data types.
  */
  virtual std::vector<CTypeInfoWrapper> AnnounceSupportedMessages();
	/**
	 * [AnnounceRegisteredMail description]
	 * @method AnnounceRegisteredMail
	 */
  virtual void AnnounceRegisteredMail();

private:
  sockaddr_in m_clientAddr;
  sockaddr_in m_serverAddr;
  int m_socket;
  bool m_clientConnected;

  AVA::HLP_BE::VehicleStatus m_vehicleStatus;
  std::thread *m_receiveThread;

	Threading::Mutex m_socketLock;

	static MOOSSimInterface *myInstance;

  struct SConfigVars
  {
    struct SParams
    {
      uint32_t	resourceID;
      double		timeout;
			bool			simulate;
			double		batteryCharge;
			double		batteryRate;
    } params;
  } m_configVars;

  void UDPReceiveThread();
	void createUDPClient();
	void connectUDPServer();
};
}}
}
