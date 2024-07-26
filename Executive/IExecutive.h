#pragma once

///////////////////////////////////////////////////////////////////////////
// IExecutive.h : Interface of the Executive class                       //
// ver 1.0                                                               //
//                                                                       // 
// Author:      Sneha Giranje					                         //
///////////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
* =======================
*  This package defines IExecutive which is an Interface and is used
*  to declare the functions that will be used in WPF through the
*  ServerPrototype for C++/CLI translator.
*
*  Maintainence History:
* =======================
*  ver 1.0 - 5 Apr 2019
*  - first release
*/

#include <vector>
class IExecutive {
public:
	virtual bool processCommandLineArgs(int argc, char ** argv) = 0;
	virtual bool extractFiles() = 0;
	virtual void publish() = 0;
	virtual void deleteExistingFiles() = 0;
	virtual std::vector<std::string> getConvertedFiles() = 0;
	static IExecutive* createProject();
};

