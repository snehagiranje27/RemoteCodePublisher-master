#pragma once
///////////////////////////////////////////////////////////////////////////
// DependencyTable.h : defines dependency table structure                //
// ver 1.1                                                               //
//                                                                       // 
// Author:      Sneha Giranje					                                   //
///////////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
* =======================
*  This package defines DependencyTable class which is used to hold files
*  relationships after dependency analysis is performed. It is simply a
*  wrapper around std::unordered_map which uses string key and vector
*  value. Therefore, every file in the analysis will point to a vector
*  of all the files it depends upon. 
*
*  Public Interface
* =======================
*  Dependency dt;
*  addDependency(filename,dependency);
*  removeDependenccy(filename,dependency);
*  remove entry(filename);
*  getDependencies(filename);
*  getFileDependencies(filename);
*  display();
*
*  Required Files:
* =======================
*  DependencyTable.h DependencyTable.cpp AbstrSynTree.h ConfigureParser.h
*  ActionsAndRules.h Utilities.h Parser.h
*
*  Maintainence History:
* =======================
*  ver 1.1 - 27 Feb 2019
*  - added functionality to fetch dependency from the headers of code and 
*    add it to the dependency table of the file.
*  ver 1.0 - 11 Feb 2019
*  - first release
*/

#include <unordered_map>
#include <string>
#include <vector>

class DependencyTable
{
public:
  using file = std::string;
  using files = std::vector<file>;
  using dependencies = std::vector<file>;
  using iterator = std::unordered_map<file, dependencies>::iterator;


  DependencyTable();
  DependencyTable(const files& list);
  ~DependencyTable();

  bool has(const std::string& file);

  void addDependency(file filename, file dependency);
  void removeDependency(file filename, file dependency);

  void removeEntry(file filename);

  const dependencies& getDependencies(file filename) const;
  const dependencies& operator[](const file& filename) const;

  void getFileDependencies(file filename);
 
  // these two functions allow 'for' loops in the form of
  // for(auto entry : dt) {...}
  iterator begin();
  iterator end();
  void clear() {
	  table_.clear(); 
  }

  files getFiles() const;

  void display();

private:
  std::unordered_map<file, dependencies> table_;
};

