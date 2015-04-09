// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 08:47:32 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdexcept>
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <list>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include <ft_gkrellm.hpp>
#include <modules/IMonitorModule.hpp>
#include <modules/TimeModule.hpp>
#include <modules/CPUModule.hpp>
#include <modules/HostnameModule.hpp>
#include <modules/NetworkModule.hpp>
#include <modules/OSinfoModule.hpp>
#include <modules/RAMModule.hpp>
#include <modules/PonyModule.hpp>
#include <modules/DiskModule.hpp>
#include <ft_sfml/Window.hpp>
#include <ft_sfml/Module.hpp>

namespace ftsf
{
sf::Font			Arial;
float				getStrWidth(sf::Text const &ref)
{
	float			ret = static_cast<std::string const&>(ref.getString())
	.length();

	if (ref.getCharacterSize() <= 12)
		return ((ref.getCharacterSize() - 4)) * ret;
	if (ref.getCharacterSize() >= 20)
		return ((ref.getCharacterSize() - 8) * ret);
	return ((ref.getCharacterSize() - 5) * ret);
}
float				getStrHeight(std::string const &ref)
{
	(void)ref;
	return (12.5);
}
float				getStrHeight(sf::Text const &ref)
{
	if (ref.getCharacterSize() <= 15)
		return (12.5);
	return (25);

}
}

static void			put_modules(std::vector<std::string> &args,
std::vector<ft::IMonitorModule*> &modules)
{
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
	{
		std::transform(it->begin(), it->end(), it->begin(), ::tolower);
		if (*it == "hostname")
			modules.push_back(new ft::HostnameModule("Hostname"));
		else if (*it == "osinfo")
			modules.push_back(new ft::OSinfoModule("OSinfo"));
		else if (*it == "time" || *it == "date")
			modules.push_back(new ft::TimeModule("Time"));
		else if (*it == "cpu")
			modules.push_back(new ft::CPUModule("CPU"));
		else if (*it == "ram")
			modules.push_back(new ft::RAMModule("RAM"));
		else if (*it == "network")
			modules.push_back(new ft::NetworkModule("Network"));
		else if (*it == "pony")
			modules.push_back(new ft::PonyModule("Pony"));
		else if (*it == "disk")
			modules.push_back(new ft::DiskModule("Disk"));
	}
}

static void			put_sfml_displays(std::vector<ft::IMonitorModule*> &modules,
std::list<ft::IMonitorDisplay*> &displays, int nb)
{
	std::cout << "SFML: Loading ..." << std::endl;
	ftsf::Arial.loadFromFile("srcs/ft_sfml/Liberation.ttf"); //verif !!!!
	const_cast<sf::Texture&>(ftsf::Arial.getTexture(11U)).setSmooth(false);
	
	ftsf::Module::arrowTexture.loadFromFile("srcs/ft_sfml/arrow.png");//verif !!!!
	while (--nb >= 0)
	{
		displays.push_back(new ftsf::Window(modules,
				ftsf::Window::calculateWindowSize(modules)));
	}
	std::cout << "SFML: Finished Loading ..." << std::endl;	
}

static void			parse_input(int ac, char **av, 
std::vector<ft::IMonitorModule*> &modules,
std::list<ft::IMonitorDisplay*> &displays)
{
	if (ac <= 1 || av[1][0] != '-')
		throw std::exception();
	std::string					opt = &av[1][1];
	std::vector<std::string> 	args(av + 2, av + ac);
	int							nb = atoi(&av[1][1]);
	size_t 						pos = opt.find_first_not_of("0123456789");
	bool						n = false, s = false;

	if (pos == std::string::npos)
		throw std::exception();
	opt.erase(0, pos);
	if (opt != "s" && opt != "n" && opt != "ns" && opt != "sn")
		throw std::exception();
	if (opt.find("n", 0) != std::string::npos)
		n = true;
	if (opt.find("s", 0) != std::string::npos)
		s = true;
	put_modules(args, modules);
	if (s)
		put_sfml_displays(modules, displays, nb);
}

#include <unistd.h>

int					main(int ac, char *av[])
{
	std::vector<ft::IMonitorModule*>	modules;
	std::list<ft::IMonitorDisplay*>		displays;
	//on peut foutre autant de sfml qu'on veut dans le liste et ca fonctionne
	//penser bonus
	
	try
	{
		//fuites memoires ?
		//fuites memoires ?
		//fuites memoires ?
		//fuites memoires ?
		parse_input(ac, av, modules, displays);
	}
	catch (...)
	{
		std::cout << "error" << std::endl;
		return (1);
	
	}
	while (displays.size() > 0)
	{
		//fuites memoires ?
		//fuites memoires ?
		//fuites memoires ?
		//fuites memoires ?
		std::for_each(modules.begin(), modules.end(),
					  std::mem_fun(&ft::IMonitorModule::refresh_datas));
		displays.remove_if(std::mem_fun(&ft::IMonitorDisplay::updateDisplay));
		usleep(1000000/24);
	}
    return (0);
}
