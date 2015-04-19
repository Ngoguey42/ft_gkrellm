// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:35:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/19 11:09:23 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "CPUModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>
#include <cmath>

namespace ft
{
// * STATICS **************************************************************** //
std::string					CPUModule::datas[3] = {"", "", ""};

// * CONSTRUCTORS *********************************************************** //
CPUModule::CPUModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName),
	_numbers(0)
{
	char			buf[100];
	size_t			buflen = 100;
	size_t			pos;

	this->_strings.resize(2);
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
	pos = buflen;
	this->_strings[0].assign(buf, pos);
	pos = this->_strings[0].find(" ", this->_strings[0].find(" ") + 1);
	this->_strings[1].assign(this->_strings[0], pos + 1, buflen - pos - 2);
	this->_strings[0].resize(pos);
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_numbers.push_back(0.f);
	return ;
}

// * DESTRUCTORS ************************************************************ //
CPUModule::~CPUModule()
{
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&CPUModule::getStrings(void) const
{return (this->_strings);}

std::deque<float> const			&CPUModule::getNumbers(void) const
{return (this->_numbers);}

std::string const			&CPUModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						CPUModule::refresh_datas(void)
{
	size_t			pos = CPUModule::datas[1].find_first_of("0123456789.");
	float			nb = atof(
		CPUModule::datas[1].substr(
			pos, CPUModule::datas[1].find_last_of("0123456789.") - pos + 1
			).c_str());

	if (!isnan(nb) && nb > 0.f && nb < 100.f)
	{
		this->_numbers.push_back(nb / 100.f);
		if (this->_numbers.size() > 60)
			this->_numbers.pop_front();
	}
	this->_strings[2] = "user: " + CPUModule::datas[0];
	this->_strings[3] = "system: " + CPUModule::datas[1];
	this->_strings[4] = "idle: " + CPUModule::datas[2];
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
