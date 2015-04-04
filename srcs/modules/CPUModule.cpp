// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/04 15:35:12 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ctime>
#include "CPUModule.hpp"

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
	time_t		t;
	char		buffer[100];

	// std::cout << "[CPUModule]() Ctor called" << std::endl;
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
