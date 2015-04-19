// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/15 13:00:00 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/19 16:17:19 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ft_gkrellm.hpp>
#include <ft_sfml/Window.hpp>
#include <ft_nc/Window.hpp>

#include <modules/IMonitorModule.hpp>
#include <modules/TimeModule.hpp>
#include <modules/CPUModule.hpp>
#include <modules/HostnameModule.hpp>
#include <modules/NetworkModule.hpp>
#include <modules/OSinfoModule.hpp>
#include <modules/RAMModule.hpp>
#include <modules/DiskModule.hpp>
#include <modules/ProcessesModule.hpp>
#include <modules/VMModule.hpp>
#include <modules/MemRegionsModule.hpp>
#include <modules/PonyModule.hpp>
#include <modules/CatModule.hpp>

namespace ft
{
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
		else if (*it == "disk")
			modules.push_back(new ft::DiskModule("Disk"));
		else if (*it == "processes")
			modules.push_back(new ft::ProcessesModule("Processes"));
		else if (*it == "memregions")
			modules.push_back(new ft::MemRegionsModule("MemRegions"));
		else if (*it == "vm")
			modules.push_back(new ft::VMModule("VM"));
		else if (*it == "pony")
			modules.push_back(new ft::PonyModule("Pony"));
		else if (*it == "cat")
			modules.push_back(new ft::CatModule("Cat"));
	}
}

static void			put_sfml_displays(
	std::vector<ft::IMonitorModule*> &modules,
	std::list<ft::IMonitorDisplay*> &displays, int nb)
{
	if (nb < 1)
		nb = 1;
	std::cout << "SFML: Loading ..." << std::endl;
	if (!ftsf::Arial.loadFromFile("srcs/ft_sfml/Liberation.ttf"))
	{
		std::cout << "Could not load 'srcs/ft_sfml/Liberation.ttf'" << std::endl;
		exit(1);
	}
	const_cast<sf::Texture&>(ftsf::Arial.getTexture(11U)).setSmooth(false);

	if (!ftsf::Module::arrowTexture.loadFromFile("srcs/ft_sfml/arrow.png"))
	{
		std::cout << "Could not load 'srcs/ft_sfml/arrow.png'" << std::endl;
		exit(1);
	}
	while (--nb >= 0)
	{
		displays.push_back(new ftsf::Window(
							   modules,
							   ftsf::Window::calculateWindowSize(modules)));
	}
	std::cout << "SFML: Finished Loading ..." << std::endl;	
}

void				parse_input(int ac, char **av, 
								std::vector<ft::IMonitorModule*> &modules,
								std::list<ft::IMonitorDisplay*> &displays)
{
	std::string					opt = &av[1][1];
	std::vector<std::string> 	args(av + 2, av + ac);
	int							nb = atoi(&av[1][1]);
	size_t 						pos = opt.find_first_not_of("0123456789");
	bool						n = false, s = false;

	if (pos == std::string::npos)
		return ;
	opt.erase(0, pos);
	if (opt != "s" && opt != "n" && opt != "ns" && opt != "sn")
		return ;
	if (opt.find("n", 0) != std::string::npos)
		n = true;
	if (opt.find("s", 0) != std::string::npos)
		s = true;
	put_modules(args, modules);
	if (s)
		put_sfml_displays(modules, displays, nb);
	if (n)
 		displays.push_back(new ftnc::Window(modules));
}
}
