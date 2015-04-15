// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Line.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 17:46:21 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 13:35:37 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LINE_HPP
# define LINE_HPP

# include <iostream>
# include <string>

namespace ftnc
{

class Line : public std::string
{

public:
	Line();
	Line(Line const &src);
	virtual ~Line();

	void				initialize(char bg, size_t width,
								   const std::string &refstr, bool isDynamic);
	void				update(void);

private:
	Line				&operator=(Line const &rhs);

	void				_update(void);

	char				_bg;
	size_t				_width;
	const std::string	*_refstr;
	bool				_isDynamic;
};

}

#endif
