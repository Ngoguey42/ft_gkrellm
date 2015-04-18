// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MemRegionsModule.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 15:38:18 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MemRegionsModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

namespace ft
{
// * STATICS **************************************************************** //
std::string					MemRegionsModule::datas[3] = {"", "", ""};

// * CONSTRUCTORS *********************************************************** //
MemRegionsModule::MemRegionsModule(std::string const &moduleName) :
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
MemRegionsModule::~MemRegionsModule()
{
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&MemRegionsModule::getStrings(void) const
{return (this->_strings);}

std::deque<float> const			&MemRegionsModule::getNumbers(void) const
{return (this->_numbers);}

std::string const			&MemRegionsModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						MemRegionsModule::refresh_datas(void)
{
	this->_strings[0] = MemRegionsModule::datas[0];
	this->_strings[1] = MemRegionsModule::datas[1];
	this->_strings[2] = MemRegionsModule::datas[2];
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
