// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 09:00:55 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "TimeModule.hpp"

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
TimeModule::TimeModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[TimeModule]() Ctor called" << std::endl;
	this->_strings.push_back("Mardi");
	this->_strings.push_back("18h42");
	return ;
}

// * DESTRUCTORS ************************************************************ //
TimeModule::~TimeModule()
{
	// std::cout << "[TimeModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&TimeModule::getStrings(void) const
{return (this->_strings);}

std::string const			&TimeModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						TimeModule::refresh_datas(void)
{
	std::cout << "Updating time datas:  this=" <<
		((unsigned long long int)this) % 0x1000
			  << std::endl;

	//updated notre vector de strings
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
