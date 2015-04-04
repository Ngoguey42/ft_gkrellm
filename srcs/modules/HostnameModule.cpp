// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HostnameModule.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 15:35:34 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <unistd.h>
#include "HostnameModule.hpp"

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
HostnameModule::HostnameModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[HostnameModule]() Ctor called" << std::endl;
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
HostnameModule::~HostnameModule()
{
	// std::cout << "[HostnameModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&HostnameModule::getStrings(void) const
{return (this->_strings);}

std::string const			&HostnameModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						HostnameModule::refresh_datas(void)
{
	// std::cout << "Updating hostname datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	// std::cout << "[HostnameModule]() Ctor called" << std::endl;
	char		buffer[100];

	if (gethostname(buffer, 99))
		this->_strings[0] = "error...";
	else
		this->_strings[0] = buffer;
	// this->_strings[0] = "caca";
	//updated notre vector de strings
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
