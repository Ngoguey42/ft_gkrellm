// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSinfoModule.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/19 16:29:01 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OSinfoModule.hpp"
#include <sys/sysctl.h>
#include <sys/types.h>

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
OSinfoModule::OSinfoModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[OSinfoModule]() Ctor called" << std::endl;
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
OSinfoModule::~OSinfoModule()
{
	// std::cout << "[OSinfoModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&OSinfoModule::getStrings(void) const
{return (this->_strings);}

std::deque<float> const			&OSinfoModule::getNumbers(void) const
{return (this->_numbers);}

std::string const			&OSinfoModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						OSinfoModule::refresh_datas(void)
{
	char	kernostype[100];
	char	kernosrelease[100];
	size_t	size = 100;

	sysctlbyname("kern.ostype", &kernostype, &size, NULL, 0);
	sysctlbyname("kern.osrelease", &kernosrelease, &size, NULL, 0);
	this->_strings[0] = "Type: ";
	this->_strings[0] += kernostype;
	this->_strings[1] = "Release: ";
	this->_strings[1] += kernosrelease;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
