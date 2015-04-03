// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 10:57:33 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

//# include <string>
//# include <iostream>
# include <Vector>
# include <modules/IMonitorModule.hpp>
# include <modules/Data.hpp>

namespace ft
{
class TimeModule : public IMonitorModule
{
public:
	TimeModule();
	virtual ~TimeModule();
	void						refresh_datas(void);
	std::vector<Data> const		&get_datas(void) const;

protected:
private:
	TimeModule(TimeModule const &src);
	TimeModule					&operator=(TimeModule const &rhs);

	std::vector<Data>			_datas;
};
//std::ostream					&operator<<(std::ostream &o, TimeModule const &rhs);
}

#endif // **************************************************** TIMEMODULE_HPP //
