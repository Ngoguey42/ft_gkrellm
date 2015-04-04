// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 12:26:34 by ngoguey          ###   ########.fr       //
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
#include <ft_sfml/Window.hpp>

namespace ftsf
{
sf::Font			Arial;
float				getStrWidth(sf::Text const &ref)
{
	float			ret = static_cast<std::string const&>(ref.getString())
	.length();

	if (ref.getCharacterSize() <= 10)
		return ((ref.getCharacterSize() - 4)) * ret;
	if (ref.getCharacterSize() >= 20)
		return ((ref.getCharacterSize() - 8) * ret);
	return ((ref.getCharacterSize() - 5) * ret);
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
			modules.push_back(new ft::TimeModule("Time"));
		else if (*it == "osinfo")
			modules.push_back(new ft::TimeModule("Time"));
		else if (*it == "date")
			modules.push_back(new ft::TimeModule("Time"));
		else if (*it == "cpu")
			modules.push_back(new ft::TimeModule("Time"));
		else if (*it == "ram")
			modules.push_back(new ft::TimeModule("Time"));
		else if (*it == "network")
			modules.push_back(new ft::TimeModule("Time"));
	}
}

static void			put_sfml_displays(std::vector<ft::IMonitorModule*> &modules,
std::list<ft::IMonitorDisplay*> &displays, int nb)
{
	while (--nb >= 0)
	{
		std::cout << "SFML: Loading ..." << std::endl;
		ftsf::Arial.loadFromFile("srcs/ft_sfml/Liberation.ttf"); //verif
		displays.push_back(new ftsf::Window(modules,
				ftsf::Window::calculateWindowSize(modules)));
		std::cout << "SFML: Finished Loading ..." << std::endl;	
	}
}

void				parse_input(int ac, char **av, 
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

/* DEBUG */
	if (s)
		std::cout << "s" << std::endl;
	if (n)
		std::cout << "n" << std::endl;
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
		parse_input(ac, av, modules, displays);
	}
	catch (...)
	{
		std::cout << "error" << std::endl;
		return (1);
	
	}
	while (displays.size() > 0)
	{
		std::for_each(modules.begin(), modules.end(),
					  std::mem_fun(&ft::IMonitorModule::refresh_datas));
		displays.remove_if(std::mem_fun(&ft::IMonitorDisplay::updateDisplay));
		//fuites memoires ?
		usleep(1000000);
	}
    return (0);
}
