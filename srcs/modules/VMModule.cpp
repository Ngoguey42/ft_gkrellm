// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   VMModule.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 15:38:18 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "VMModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

namespace ft
{
// * STATICS **************************************************************** //
std::string					VMModule::datas[3] = {"", "", ""};

// * CONSTRUCTORS *********************************************************** //
VMModule::VMModule(std::string const &moduleName) :
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
VMModule::~VMModule()
{
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&VMModule::getStrings(void) const
{return (this->_strings);}

std::deque<float> const			&VMModule::getNumbers(void) const
{return (this->_numbers);}

std::string const			&VMModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						VMModule::refresh_datas(void)
{
	this->_strings[0] = VMModule::datas[0];
	this->_strings[1] = VMModule::datas[1];
	this->_strings[2] = VMModule::datas[2];
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
