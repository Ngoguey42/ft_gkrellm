// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/03 10:02:40 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
# include <modules/IMonitorModule.hpp>

class TimeModule : public IMonitorModule
{
public:
	TimeModule();
	virtual ~TimeModule();
	void						refresh_datas(void);
	
protected:
private:
	TimeModule(TimeModule const &src);
	TimeModule					&operator=(TimeModule const &rhs);

};
//std::ostream					&operator<<(std::ostream &o, TimeModule const &rhs);

#endif // **************************************************** TIMEMODULE_HPP //
