// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Background.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 10:45:03 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 09:23:08 by ngoguey          ###   ########.fr       //

//                                                                            //
// ************************************************************************** //

#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP

// # include <string>
//# include <stdexcept>
# include <iostream>

# include <SFML/Graphics.hpp>

# include <ft_gkrellm.hpp>
# include <ft_sfml/RoundedBox.hpp>
# include <ft_sfml/DefaultTextBox.hpp>

namespace ftsf
{
class Background : public sf::Drawable
{
public:
	// * STATICS ******************** //
	static float const			posX;
	static float const			posY;
	static std::string const	header;
	static std::string const	footer;
	static sf::Color const		color;
	static float const			titlePad;
	static float const			footerPad;

	// * CTORS / DTORS ************** //
	Background(const sf::Vector2f &size);
	virtual ~Background();

	// * GETTERS / SETTERS ********** //
	// * MEMBER FUNCTIONS / METHODS * //
	void                        draw(sf::RenderTarget& target,
									 sf::RenderStates states) const;
	
protected:
private:
	// * ATTRIBUTES ***************** //	
	sf::Vector2f const			_size;
	DefaultTextBox				_titleBox;
	RoundedBox					_box;
	DefaultTextBox				_footerBox;
	
	
	Background();
	Background(Background const &src);
	Background					&operator=(Background const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, Background const &rhs);
}

#endif // **************************************************** BACKGROUND_HPP //
