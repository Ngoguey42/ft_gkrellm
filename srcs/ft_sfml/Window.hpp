// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:13:06 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 09:47:20 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <iostream>
# include <stdexcept>
# include <vector>
# include <SFML/Graphics.hpp>

# include <ft_gkrellm.hpp>
# include <IMonitorDisplay.hpp>
# include <ft_sfml/Background.hpp>

namespace ftsf
{
class Window : public sf::RenderWindow, public ft::IMonitorDisplay
{
public:
	// * STATICS ******************** //
	static sf::Vector2f const	backgroundInsets;

	// * CTORS / DTORS ************** //
	Window(sf::Vector2f const &winSize);
	virtual ~Window();

protected:
private:
	Window();
	Window(Window const &src);
	Window						&operator=(Window const &rhs);

	// * ATTRIBUTES ***************** //
	ftsf::Background			_bg;
	std::vector<Module*>		_modules;
};
//std::ostream					&operator<<(std::ostream &o, Window const &rhs);
}

#endif // ******************************************************** WINDOW_HPP //
