// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSinfoModule.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 15:38:54 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ctime>
#include "OSinfoModule.hpp"

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
	time_t		t;
	char		buffer[100];

	// std::cout << "[OSinfoModule]() Ctor called" << std::endl;
	time (&t);
	std::strftime(buffer, 80, "%a %d %b %y", localtime(&t));
	this->_strings[0] = buffer;
	std::strftime(buffer, 80, "%r", localtime(&t));
	this->_strings[1] = buffer;
	// this->_strings[0] = "caca";
	//updated notre vector de strings
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
