// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:13:06 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 16:51:49 by ngoguey          ###   ########.fr       //
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
# include <ft_sfml/Module.hpp>

namespace ftsf
{
class Window : public sf::RenderWindow, public ft::IMonitorDisplay
{
public:
	// * STATICS ******************** //
	static sf::Vector2f const	backgroundInsets;
	static float const			firstModulePadding;

	static sf::Vector2f			calculateWindowSize(
		std::vector<ft::IMonitorModule*> const &modules);
	
	// * CTORS / DTORS ************** //
	Window(std::vector<ft::IMonitorModule*> const &modules,
		   sf::Vector2f const &winSize);
	virtual ~Window();

	// * MEMBER FUNCTIONS / METHODS * //
	int							updateDisplay();
	
protected:
private:
	Window();
	Window(Window const &src);
	Window						&operator=(Window const &rhs);

	void						checkArrowClick(float x, float y);
	
	// * ATTRIBUTES ***************** //
	ftsf::Background			_bg;
	std::vector<ft::IMonitorModule*> const	&_modules;
	std::vector<Module*>		_modulesFrames;
};
//std::ostream					&operator<<(std::ostream &o, Window const &rhs);
}

#endif // ******************************************************** WINDOW_HPP //
