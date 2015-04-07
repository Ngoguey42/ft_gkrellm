// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 18:12:12 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "CPUModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
CPUModule::CPUModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[CPUModule]() Ctor called" << std::endl;
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
CPUModule::~CPUModule()
{
	// std::cout << "[CPUModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&CPUModule::getStrings(void) const
{return (this->_strings);}

std::string const			&CPUModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						CPUModule::refresh_datas(void)
{
	// std::cout << "Updating cpu datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	// std::cout << "[CPUModule]() Ctor called" << std::endl;
	char buf[100];
	size_t buflen = 100;

	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
	// transform here to 2 strings
	this->_strings[0] = buf;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
