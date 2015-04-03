// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Data.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:04:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 10:19:51 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DATA_HPP
# define DATA_HPP

//# include <string>
//# include <stdexcept>
# include <iostream>

namespace ft
{
class Data
{
public:
	
	enum						Type
	{
		String					= 0,
		Image					= 1
	};

	Data(Data::Type t);
	virtual ~Data();

	Data::Type const			&getType(void) const;
	std::string const			&getStr(void) const;

	void						setStr(std::string const &c);

	
protected:
private:
	Data();
	Data(Data const &src);
	Data						&operator=(Data const &rhs);

	Data::Type const					_type;
	std::string					_str;
};
//std::ostream					&operator<<(std::ostream &o, Data const &rhs);
}

#endif // ********************************************************** DATA_HPP //
