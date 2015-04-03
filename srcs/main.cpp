// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 09:55:25 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#include <ft_gkrellm.hpp>
#include <ft_sfml/Background.hpp>

namespace ftsf
{
sf::Font			Arial;
float                   getStrWidth(sf::Text const &ref)
{
	float		ret = static_cast<std::string const&>(ref.getString())
		.length();

	if (ref.getCharacterSize() <= 10)
		return ((ref.getCharacterSize() - 4)) * ret;
	if (ref.getCharacterSize() >= 20)
		return ((ref.getCharacterSize() - 8) * ret);
	return ((ref.getCharacterSize() - 5) * ret);
}
float                   getStrHeight(sf::Text const &ref)
{
	if (ref.getCharacterSize() <= 15)
		return (12.5);
	return (25);

}
}

int main(void)
{
    sf::RenderWindow    window(sf::VideoMode(220, 320),
							   "ft_gkrellm",
							   sf::Style::Default ^ sf::Style::Resize,
							   	sf::ContextSettings(0, 0, 8));
	ftsf::Background	bg(sf::Vector2f(200, 300));
	
	
	try
	{
		ftsf::Arial.loadFromFile("srcs/ft_sfml/Liberation.ttf");
	}
	catch (...)
	{ //todo
		return (1);
	}
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
		}
        window.clear();
        window.draw(bg);
        window.display();
    }
    return (0);
}
