// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 18:33:06 by ngoguey          ###   ########.fr       //
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
	// std::cout << "[TimeModule]() Ctor called" << std::endl;
	this->_strings.resize(2);
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
	time_t		t;
	char		buffer[100];
	size_t		ret;

	time(&t);
	ret = std::strftime(buffer, sizeof(buffer) - 1, "%a %d %b %y",
						localtime(&t));
	this->_strings[0].assign(buffer, ret);
	std::strftime(buffer, sizeof(buffer) - 1, "%r", localtime(&t));
	this->_strings[1].assign(buffer, ret - 2);
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
