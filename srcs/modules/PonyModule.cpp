// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PonyModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 12:43:01 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ctime>
#include "PonyModule.hpp"

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
PonyModule::PonyModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[PonyModule]() Ctor called" << std::endl;
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
PonyModule::~PonyModule()
{
	// std::cout << "[PonyModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&PonyModule::getStrings(void) const
{return (this->_strings);}

std::string const			&PonyModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						PonyModule::refresh_datas(void)
{
	// std::cout << "Updating pony datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	time_t		t;
	char		buffer[100];

	// std::cout << "[PonyModule]() Ctor called" << std::endl;
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
