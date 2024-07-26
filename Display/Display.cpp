///////////////////////////////////////////////////////////////////////////
// Display.cpp   : defines webpage display using browser functions       //
// ver 1.1                                                               //
//                                                                       // 
// Author:      Sneha Giranje					                         //
///////////////////////////////////////////////////////////////////////////

#include "Display.h"
#include "../Process/Process.h"
#include "../CppParser/FileSystem/FileSystem.h"

#include <iostream>

// -----< default ctor >--------------------------------------------------
Display::Display() { }

// -----< display single file >-------------------------------------------
void Display::display(const std::string & file)
{
	std::cout << "\n  Displaying file: " + FileSystem::Path::getName(file) + " in browser";

	CBP callback = []() {
		std::cout << "\n  --- child browser exited with this message ---";
	};
	Process p;
	std::ifstream outputFile;
	std::string fileInfo;
	outputFile.open("../browser.textbox");
	if (outputFile.fail()) {
		std::cout << "browserPath.textbox does not exist" << std::endl << "create ../browserPath.textbox" << std::endl;
	}
	std::cout << std::endl << "\t\tIf display not working" << std::endl << "\t\tEnter valid firefox.exe path in browserPath.textbox" << std::endl;
	std::getline(outputFile, fileInfo);
	std::string appPath = fileInfo;  // path to application to start
	p.application(appPath);
	std::cout << "\n  Will start Firefox and each time wait for termination.";
	std::cout << "\n  You need to kill each window (upper right button) to continue.";
	std::cout << "\n  Press key to start";

	std::string dirPath = "../ConvertedWebpages";
	std::string cmd = "--new-instance " + dirPath + "/" + file;

	p.commandLine(cmd);
	p.create();
	p.setCallBackProcessing(callback);
	p.registerCallback();
	WaitForSingleObject(p.getProcessHandle(), INFINITE);
}

// -----< display multiple files  >---------------------------------------
void Display::display(const std::vector<std::string>& files)
{
  for (auto file : files) 
    display(file);
}

#ifdef TEST_DISPLAY

#include <iostream>

int main() {

  std::vector<std::string> files;
  files.push_back("..\\ConvertedWebpages\\Converter.h.html");
  files.push_back("..\\ConvertedWebpages\\Converter.cpp.html");

  Display d;
  d.display(files);

}

#endif