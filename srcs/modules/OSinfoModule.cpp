// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSinfoModule.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 17:00:48 by wide-aze         ###   ########.fr       //
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

std::string const			&OSinfoModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						OSinfoModule::refresh_datas(void)
{
	// std::cout << "Updating os info datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	// std::cout << "[OSinfoModule]() Ctor called" << std::endl;
	char	hwmachine[100];
	size_t	size = 100;

//int sysctlbyname(char *name, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
	sysctlbyname("kern.uuid", &hwmachine, &size, NULL, 0);
	this->_strings[0] = hwmachine;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
