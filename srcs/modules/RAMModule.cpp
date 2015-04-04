// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:40:35 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/04 15:40:36 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ctime>
#include "RAMModule.hpp"

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
	time_t		t;
	char		buffer[100];

	// std::cout << "[RAMModule]() Ctor called" << std::endl;
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
