// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HostnameModule.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 18:29:45 by ngoguey          ###   ########.fr       //
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
	char		buffer[100];

	this->_strings.resize(1);
	buffer[0] = '\0';
	if (gethostname(buffer, sizeof(buffer) - 1) != 0)
		this->_strings[0] = "error...";
	else
		this->_strings[0] = buffer;
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
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
