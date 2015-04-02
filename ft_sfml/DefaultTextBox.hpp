// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DefaultTextBox.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 11:50:47 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/02 15:55:26 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DEFAULTTEXTBOX_HPP
# define DEFAULTTEXTBOX_HPP

//# include <string>
# include <iostream>
# include <ft_gkrellm.hpp>
# include <RoundedBox.hpp>
# include <SFML/Graphics.hpp>

namespace ftsf
{
class DefaultTextBox : public RoundedBox
{
public:	
	// * CTORS / DTORS ************** //
	virtual ~DefaultTextBox();
	DefaultTextBox(const sf::Vector2f &size, float radius);

	// * GETTERS / SETTERS ********** //
	//settext
	//override setposition
	void						setPosition(const float x, const float y);
	void						setText1(std::string const &txt);
	void						setCharacterSize(size_t s);
	void						setTextColor(sf::Color const &color);
	void						setStyle(sf::Uint32 style);
	
	// * MEMBER FUNCTIONS / METHODS * //
	void                        draw(sf::RenderTarget& target,
									 sf::RenderStates states) const;


protected:
private:
	// * ATTRIBUTES ***************** //
	sf::Text					_text1;
	DefaultTextBox();
	DefaultTextBox(DefaultTextBox const &src);
	DefaultTextBox				&operator=(DefaultTextBox const &rhs);
};
// std::ostream					&operator<<(std::ostream &o, DefaultTextBox const &rhs);
}
#endif // ************************************************ DEFAULTTEXTBOX_HPP //
