// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PonyModule.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 09:00:52 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONYMODULE_HPP
# define PONYMODULE_HPP

# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class PonyModule : public IMonitorModule
{
public:
	PonyModule(std::string const &moduleName);
	virtual ~PonyModule();
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<float> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	
protected:
private:
	PonyModule();
	PonyModule(PonyModule const &src);
	PonyModule					&operator=(PonyModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	std::deque<float>			_numbers;
	
};
}

#endif // **************************************************** PONYMODULE_HPP //
