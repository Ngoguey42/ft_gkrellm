// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DiskModule.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/12 11:22:20 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DiskModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

namespace ft
{
// * STATICS **************************************************************** //
std::string					DiskModule::datas[2] = {"", ""};

// * CONSTRUCTORS *********************************************************** //
DiskModule::DiskModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[DiskModule]() Ctor called" << std::endl;
	this->_strings.push_back("DATA");
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
DiskModule::~DiskModule()
{
	// std::cout << "[DiskModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&DiskModule::getStrings(void) const
{return (this->_strings);}

std::string const			&DiskModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						DiskModule::refresh_datas(void)
{
	this->_strings[1] = "read: " + DiskModule::datas[0];
	this->_strings[2] = "write: " + DiskModule::datas[1];
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
