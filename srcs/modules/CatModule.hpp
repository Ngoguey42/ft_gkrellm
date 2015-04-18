// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CatModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/17 09:01:26 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CATMODULE_HPP
# define CATMODULE_HPP

# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class CatModule : public IMonitorModule
{
public:
	CatModule(std::string const &moduleName);
	virtual ~CatModule();
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<float> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	
protected:
private:
	CatModule();
	CatModule(CatModule const &src);
	CatModule					&operator=(CatModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	std::deque<float>			_numbers;
	
};
}

#endif // ***************************************************** CATMODULE_HPP //
