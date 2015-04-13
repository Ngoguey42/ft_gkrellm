// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Line.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 17:46:21 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 17:46:23 by wide-aze         ###   ########.fr       //
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
	virtual ~Line();

	void				initialize(char bg, int width, const std::string &refstr,
		bool isDynamic);
	void				update(void);

private:
	Line(Line const &src);
	Line				&operator=(Line const &rhs);

	void				_update(void);

	char				_bg;
	int					_width;
	const std::string	*_refstr;
	bool				_isDynamic;
};

}

#endif
