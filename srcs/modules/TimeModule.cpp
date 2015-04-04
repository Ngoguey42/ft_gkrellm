// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 12:43:01 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ctime>
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
	time_t		t;
	char		buffer[100];

	// std::cout << "[TimeModule]() Ctor called" << std::endl;
	time (&t);
	std::strftime(buffer, 80, "%a %d %b %y", localtime(&t));
	this->_strings.push_back(buffer);
	std::strftime(buffer, 80, "%r", localtime(&t));
	this->_strings.push_back(buffer);
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

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						TimeModule::refresh_datas(void)
{
	// std::cout << "Updating time datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	time_t		t;
	char		buffer[100];

	// std::cout << "[TimeModule]() Ctor called" << std::endl;
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
