// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NetworkModule.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 20:42:28 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NetworkModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

#define INCMD "top -l 1 | head -n 10 | grep Networks | cut -d' ' -f3"
#define OUTCMD "top -l 1 | head -n 10 | grep Networks | cut -d' ' -f5"

namespace ft
{
// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
NetworkModule::NetworkModule(std::string const &moduleName) :
	IMonitorModule(),
	_strings(),
	_moduleName(moduleName)
{
	// std::cout << "[NetworkModule]() Ctor called" << std::endl;
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	return ;
}

// * DESTRUCTORS ************************************************************ //
NetworkModule::~NetworkModule()
{
	// std::cout << "[NetworkModule]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::vector<std::string> const	&NetworkModule::getStrings(void) const
{return (this->_strings);}

std::string const			&NetworkModule::getModuleName(void) const
{return (this->_moduleName);}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						NetworkModule::refresh_datas(void)
{
	// std::cout << "Updating network datas:  this=" <<
	// 	((unsigned long long int)this) % 0x1000
	// 		  << std::endl;
	std::stringstream   inssbuf;
	char                incharbuf[100];
	FILE                *instream;
	std::stringstream   outssbuf;
	char                outcharbuf[100];
	FILE                *outstream;

	if ((instream = popen(INCMD, "r")))
	{
		if ((outstream = popen(OUTCMD, "r")))
		{
			while (fgets(incharbuf, 100, instream))
				inssbuf << incharbuf;
			while (fgets(outcharbuf, 100, outstream))
				outssbuf << outcharbuf;
			pclose(instream);
			pclose(outstream);
			this->_strings[0] = "PACKETS:";
			this->_strings[1] = "IN: " + inssbuf.str();
			this->_strings[2] = "OUT: " + outssbuf.str();
		}
		else
			pclose(instream);
	}
	return ;
}

// * NESTED_CLASSES ********************************************************* //
}
