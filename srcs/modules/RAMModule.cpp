// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/04 15:40:35 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/19 11:14:01 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RAMModule.hpp"
#include <sys/sysctl.h>
#include <sys/types.h>
#include <sstream>
#include <iomanip>
#include <cmath>

namespace ft
{
// * STATICS **************************************************************** //
std::string					RAMModule::datas[1] = {""};

// * CONSTRUCTORS *********************************************************** //
RAMModule::RAMModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	long long			ll;
	size_t				size = 100;
	size_t				pos;
	std::stringstream	ram;
	
	// std::cout << "[RAMModule]() Ctor called" << std::endl;

	this->_strings.push_back("");
	this->_strings.push_back("");
	sysctlbyname("hw.memsize", static_cast<int64_t*>(&ll), &size, NULL, 0);
	ram << static_cast<float>(ll) / static_cast<float>(1024 * 1024 * 1024) * 1000 << "M";
	this->_strings[0] = "Capacity: " + ram.str();
	pos = ram.str().find_first_of("0123456789.");
	this->_maxRAM = atof(
		ram.str().substr(
			pos, ram.str().find_last_of("0123456789.") - pos + 1
			).c_str()) + 1000.;
	this->_numbers.push_back(0.f);
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

std::deque<float> const			&RAMModule::getNumbers(void) const
{return (this->_numbers);}

std::string const			&RAMModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						RAMModule::refresh_datas(void)
{
	size_t          pos = RAMModule::datas[0].find_first_of("0123456789.");
	float           nb = atof(
		RAMModule::datas[0].substr(
			pos, RAMModule::datas[0].find_last_of("0123456789.") - pos + 1
			).c_str());

	if (!isnan(nb) && nb > 0.f && nb < _maxRAM )
	{
		this->_numbers.push_back(nb / _maxRAM);
		if (this->_numbers.size() > 60)
			this->_numbers.pop_front();
	}
	this->_strings[1] = "Usage: " + RAMModule::datas[0];
	
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
