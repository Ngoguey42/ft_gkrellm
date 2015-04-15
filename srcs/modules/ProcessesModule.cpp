// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ProcessesModule.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 15:38:18 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ProcessesModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

namespace ft
{
// * STATICS **************************************************************** //
std::string					ProcessesModule::datas[3] = {"", "", ""};

// * CONSTRUCTORS *********************************************************** //
ProcessesModule::ProcessesModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
ProcessesModule::~ProcessesModule()
{
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&ProcessesModule::getStrings(void) const
{return (this->_strings);}

std::string const			&ProcessesModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						ProcessesModule::refresh_datas(void)
{
	this->_strings[0] = ProcessesModule::datas[0];
	this->_strings[1] = ProcessesModule::datas[1];
	this->_strings[2] = ProcessesModule::datas[2];
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
