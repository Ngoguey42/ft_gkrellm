// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:40:35 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/12 11:24:37 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RAMModule.hpp"
#include <sys/sysctl.h>
#include <sys/types.h>
#include <sstream>
#include <iomanip>

namespace ft
{
// * STATICS **************************************************************** //
std::string					RAMModule::datas[1] = {""};

// * CONSTRUCTORS *********************************************************** //
RAMModule::RAMModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	long long			ll;
	size_t				size = 100;
	std::stringstream	ram;
	// std::cout << "[RAMModule]() Ctor called" << std::endl;

	this->_strings.push_back("");
	this->_strings.push_back("");
	sysctlbyname("hw.memsize", static_cast<int64_t*>(&ll), &size, NULL, 0);
	ram << static_cast<float>(ll) / static_cast<float>(1024 * 1024 * 1024) * 1000 << "M";
	this->_strings[0] = "Capacity: " + ram.str();
	return ;
}

// * DESTRUCTORS ************************************************************ //
RAMModule::~RAMModule()
{
	// std::cout << "[RAMModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&RAMModule::getStrings(void) const
{return (this->_strings);}

std::string const			&RAMModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						RAMModule::refresh_datas(void)
{
	this->_strings[1] = "Usage: " + RAMModule::datas[0];
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
