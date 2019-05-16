#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char * argv[])
{
  std::ifstream infile;
  std::ofstream outfile;

  std::string infileName;
  std::string outfileName;

  // Get input file name and open file
  std::cout << "Enter an input file name: ";
  std::cin >> infileName;
  infile.open(infileName.c_str());

  while (!infile)
  {
    std::cout << "Enter an input file name: ";
    std::cin >> infileName;
    infile.open(infileName.c_str());
  }

  // Get output file name and open file
  std::cout << "Enter an output file name: ";
  std::cin >> outfileName;
  outfile.open(outfileName.c_str());

  while (!outfile)
  {
    std::cout << "Enter an output file name: ";
    std::cin >> outfileName;
    outfile.open(outfileName.c_str());
  }

  // Look over each character as the loop continues
  char c;
  char pc = '\0';

  bool inCommentSlash = false;
  bool inCommentAst = false;
  bool inString = false;

  int numberTabs = 0;

  while ( infile.get(c) )
  {
    if ( ((pc == '/') && (c == '/')) &&
         (!inCommentSlash || !inCommentAst) )
    {
      // Starting a standard comment
      inCommentSlash = true;
    }
    else if ( ((pc == '/') && (c == '*')) &&
              (!inCommentSlash || !inCommentAst) )
    {
      // Starting an extended comment
      inCommentAst = true;
    }
    else if ((inCommentSlash) && (c == '\n'))
    {
      // While in a standard comment, ending a comment has shown up
      inCommentSlash = false;
    }
    else if  ((inCommentAst) && (pc == '*') && (c == '/'))
    {
      // While in an extended comment, the end comment has shown up
      inCommentAst = false;
    }
    else if ( ((!inCommentSlash) && (!inCommentAst) && (!inString)) &&
              ((c == '\"') || (c == '\'')) )
    {
      // While not in a comment or a string, if a string or constant is
      // started, then in string
      inString = true;
    }
    else if ( ((!inCommentSlash) && (!inCommentAst) && (inString)) &&
              ((c == '\"') || (c == '\'')) )
    {
      inString = false;
    }

    if (c == '\t')
    {
      if (inCommentSlash || inCommentAst)
      {
//        outfile << c;
        outfile << "TAB";
      }
      else if (inString)
      {
        outfile << "\\t";
      }
      else
      {
        outfile << "   ";
      }

      numberTabs++;
    }
    else
    {
      outfile << c;
    }

    pc = c;
  }

  std::cout << "The input file " << infileName << " was copied to ";
  std::cout << outfileName << " with " << numberTabs << " tabs replaced." << std::endl;

  infile.close();
  outfile.close();
}
