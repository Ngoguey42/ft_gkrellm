// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/17 09:01:13 by wide-aze         ###   ########.fr       //
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
#include <modules/CatModule.hpp>
#include <modules/DiskModule.hpp>
#include <modules/ProcessesModule.hpp>
#include <modules/VMModule.hpp>
#include <modules/MemRegionsModule.hpp>
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
		size_t				len;
		
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		// processes
		pos = std::strcspn(charbuf, " ") + 1;
		ft::ProcessesModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, ","));
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		len = std::strcspn(charbuf + pos, ",") + 1 ;
		len += std::strcspn(charbuf + pos + len, ",");
		ft::ProcessesModule::datas[1].assign(charbuf, pos, len);
		pos += len + 2;
		len  = std::strcspn(charbuf + pos, "\0") - 2;
		ft::ProcessesModule::datas[2].assign(charbuf, pos, len);
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
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::CPUModule::datas[1].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::CPUModule::datas[2].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		// MemRegions
		pos = std::strcspn(charbuf, " ") + 1;
		ft::MemRegionsModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, ","));
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		len = std::strcspn(charbuf + pos, ",");
		ft::MemRegionsModule::datas[1].assign(charbuf, pos, len);
		pos += len + 2;
		len  = std::strcspn(charbuf + pos, "\0") - 2;
		ft::MemRegionsModule::datas[2].assign(charbuf, pos, len);
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		//physmem
		pos = std::strcspn(charbuf, " ") + 1;
		ft::RAMModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		// VM
		pos = std::strcspn(charbuf, " ") + 1;
		ft::VMModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, ","));
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		len = std::strcspn(charbuf + pos, ",");
		ft::VMModule::datas[1].assign(charbuf, pos, len);
		pos += len + 2;
		len  = std::strcspn(charbuf + pos, "\0") - 2;
		ft::VMModule::datas[2].assign(charbuf, pos, len);
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		//network
		pos = std::strcspn(charbuf, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::NetworkModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::NetworkModule::datas[1].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
		if (fgets(charbuf, 256, stream) == NULL)
			return ;
		//disks
		pos = std::strcspn(charbuf, " ") + 1;
		ft::DiskModule::datas[0].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
		pos += std::strcspn(charbuf + pos, " ") + 1;
		pos += std::strcspn(charbuf + pos, " ") + 1;
		ft::DiskModule::datas[1].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
		pclose(stream);
	}
	return ;
}

int					main(int ac, char *av[])
{
	std::vector<ft::IMonitorModule*>	modules;
	std::list<ft::IMonitorDisplay*>		displays;

	if (!(ac <= 1 || av[1][0] != '-'))
		ft::parse_input(ac, av, modules, displays);	
	if (displays.size() < 1)
		std::cout << "./ft_gkrellm -[ns] " <<
			"hostname|osinfo|time|cpu|ram|network|disk|processes|memregions|vm|pony|cat" << std::endl;
	signal(SIGINT, &sig_handler);	
	while (displays.size() > 0)
	{
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
