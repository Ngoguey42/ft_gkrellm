// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/15 13:01:51 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

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
#include <ft_nc/Window.hpp>

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

static void			sig_handler(int sig)
{
	(void)sig;
	clear();
	refresh();
	endwin();
	exit(0);
}

static void					queryTop(void)
{
	FILE                *stream;

	if ((stream = popen("top -l 1 | head", "r")))
	{
		char                charbuf[256];
		size_t				pos;
		
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		//cpu
		pos = std::strcspn(charbuf, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::CPUModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
		// std::cerr << "{" << ft::CPUModule::datas[0] << "}" <<  std::endl;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::CPUModule::datas[1].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
		// std::cerr << "{" << ft::CPUModule::datas[1] << "}" <<  std::endl;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::CPUModule::datas[2].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
		// std::cerr << "{" << ft::CPUModule::datas[2] << "}" <<  std::endl;


		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		//physmem
		pos = std::strcspn(charbuf, " ") + 1;
		ft::RAMModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
		// std::cerr << "{" << ft::RAMModule::datas[0] << "}" <<  std::endl;


		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		//netwo
		pos = std::strcspn(charbuf, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::NetworkModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
		// std::cerr << "{" << ft::NetworkModule::datas[0] << "}" <<  std::endl;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::NetworkModule::datas[1].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
		// std::cerr << "{" << ft::NetworkModule::datas[1] << "}" <<  std::endl;


		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		//disks
		pos = std::strcspn(charbuf, " ") + 1;
		ft::DiskModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
		// std::cerr << "{" << ft::DiskModule::datas[0] << "}" <<  std::endl;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::DiskModule::datas[1].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
		// std::cerr << "{" << ft::DiskModule::datas[1] << "}" <<  std::endl;
		// std::cerr << charbuf << std::endl;
		pclose(stream);
		
	}
	return ;
}

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
		ft::parse_input(ac, av, modules, displays);
	}
	catch (...)
	{
		std::cout << "error" << std::endl;
		return (1);
	
	}
	signal(SIGINT, &sig_handler);
	while (displays.size() > 0)
	{
		//fuites memoires ?
		//fuites memoires ?
		//fuites memoires ?
		//fuites memoires ?
		::queryTop();
		std::for_each(modules.begin(), modules.end(),
					  std::mem_fun(&ft::IMonitorModule::refresh_datas)
			);
		for (std::list<ft::IMonitorDisplay*>::iterator it = displays.begin();
			 it != displays.end();)
		{			
			if ((*it)->updateDisplay() == 1)
			{
				delete *it;
				it = displays.erase(it);
				std::cerr << "deleting truc" << std::endl;
				
			}
			else
				it++;
			
		}
		usleep(1000000/3);
	}
    return (0);
}
