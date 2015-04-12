// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NetworkModule.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/12 11:27:54 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NetworkModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

namespace ft
{
// * STATICS **************************************************************** //
std::string					NetworkModule::datas[2] = {"", ""};

// * CONSTRUCTORS *********************************************************** //
NetworkModule::NetworkModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[NetworkModule]() Ctor called" << std::endl;
	this->_strings.push_back("PACKETS");
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
NetworkModule::~NetworkModule()
{
	// std::cout << "[NetworkModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&NetworkModule::getStrings(void) const
{return (this->_strings);}

std::string const			&NetworkModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						NetworkModule::refresh_datas(void)
{
	this->_strings[1] = "in: " + NetworkModule::datas[0];
	this->_strings[2] = "out: " + NetworkModule::datas[1];
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
