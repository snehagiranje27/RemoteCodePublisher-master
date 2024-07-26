#pragma once
///////////////////////////////////////////////////////////////////////////
// Executive.h :  Integrates all the code publisher functionalities      //
// ver 1.0                                                               //
//                                                                       // 
// Author:      Sneha Giranje					                         //
///////////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
* =======================
*  This package defines Executive which uses different components of
*  CodeConverter, Display and DirectoryN to put together the entire
*  functionality of the CodePublisher. The mentioned packages are indep-
*  ndent of each other and their only interaction is through this facade
*
*  NOTE: there are TWO modes for compiling this file:
*   1) Preprocessor DEMO_EXEC : runs in full demo mode for Pr3.
*   2) Preprocessor USE_EXEC  : runs normal functionality.
*
*  Required Files:
* =======================
*  Executive.h Executive.cpp CodeUtilities.h
*  Converter.h Converter.cpp Loader.h loader.cpp
*  Display.h Display.cpp
*Public Interface:
---------------------
Executive();
	bool processCommandLineArgs(int argc, char ** argv);

	const std::string& workingDirectory() const;

	void outputDirectory(const std::string& dir);
	const std::string& outputDirectory() const;

	bool extractFiles();

	void publish();
	void publish(const std::string& file);
	void publish(const std::vector<std::string>& files);
	std::vector<std::string> getConvertedFiles();

	void req1();
	void req2();
	void req3();
	void req4();
	void req5();
	void req6();
	void req7();
	void deleteExistingFiles();

	Utilitiess::DisplayMode displayMode() const;

*  Maintainence History:
* =======================
  ver 1.2 - 15 April 2019
  --Added methods to demonstate the project3 requirements
* 
*  ver 1.0 - 14 Feb 2019
*  - first release
*/

#include <string>
#include <vector>
#include "IExecutive.h"
#include "../Converter/Converter.h"
#include "../Loader/Loader.h"
#include "../Utilities/CodeUtilities/CodeUtilities.h"
#include "../Display/Display.h"


class Executive : public IExecutive
{
public:
	Executive();
	bool processCommandLineArgs(int argc, char ** argv);

	const std::string& workingDirectory() const;

	void outputDirectory(const std::string& dir);
	const std::string& outputDirectory() const;

	bool extractFiles();

	void publish();
	void publish(const std::string& file);
	void publish(const std::vector<std::string>& files);
	std::vector<std::string> getConvertedFiles();

	void req1();
	void req2();
	void req3();
	void req4();
	void req5();
	void req6();
	void req7();
	void deleteExistingFiles();

	Utilitiess::DisplayMode displayMode() const;

private:
	Utilitiess::ProcessCmdLine *pcl_;
	CodeConverter cconv_;
	Display display_;

	std::string dirIn_;
	std::string dirOut_;

	std::vector<std::string> files_;
	std::vector<std::string> convertedFiles_;
};
inline IExecutive* IExecutive::createProject()
{
	return new Executive;
}

