// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 09:58:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/02 10:04:54 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <cmath>
#include <RoundedBox.hpp>
#include <SFML/Graphics.hpp>

int main(void)
{
    sf::RenderWindow    window(sf::VideoMode(400, 400), "SFML works!");
    RoundedBox          box(sf::Vector2f(200, 100), 30);

    box.setFillColor(sf::Color::Yellow);
    box.setPosition(50, 50);
    box.setBorderSize(10.);
    box.setBorderColor(sf::Color::Red);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        box.setBorderSize(-10. + static_cast<float>(std::time(NULL) % 10 * 3));
        window.clear();
        window.draw(box);
        window.display();
    }
    return (0);
}
