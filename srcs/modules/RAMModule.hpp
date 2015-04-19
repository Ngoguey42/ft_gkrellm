// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/19 11:09:50 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class RAMModule : public IMonitorModule
{
public:
	RAMModule(std::string const &moduleName);
	virtual ~RAMModule();

	static std::string			datas[1];
	
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<float> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	
protected:
private:
	RAMModule();
	RAMModule(RAMModule const &src);
	RAMModule					&operator=(RAMModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	std::deque<float>			_numbers;

	float						_maxRAM;
	
};
}

#endif // ***************************************************** RAMMODULE_HPP //
