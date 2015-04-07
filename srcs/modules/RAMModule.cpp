// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:40:35 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 17:31:13 by wide-aze         ###   ########.fr       //
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
// * CONSTRUCTORS *********************************************************** //
RAMModule::RAMModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[RAMModule]() Ctor called" << std::endl;
	this->_strings.push_back("");
	this->_strings.push_back("");
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
	// std::cout << "Updating ram datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	// std::cout << "[RAMModule]() Ctor called" << std::endl;
	std::stringstream	tmp;
	long long ll;
	size_t  size = 100;

// MAX RAM
	sysctlbyname("hw.memsize", static_cast<int64_t*>(&ll), &size, NULL, 0);
	tmp << std::fixed << std::setprecision( 2 ) <<
		static_cast<float>(ll) / static_cast<float>(1024 * 1024 * 1024) << "gB";
	this->_strings[0] = tmp.str();
	return ;
}



// * NESTED_CLASSES ********************************************************* //
}
