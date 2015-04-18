// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DiskModule.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/12 11:14:46 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DISKMODULE_HPP
# define DISKMODULE_HPP

# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class DiskModule : public IMonitorModule
{
public:
	DiskModule(std::string const &moduleName);
	virtual ~DiskModule();

	static std::string          datas[2];
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<float> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	
protected:
private:
	DiskModule();
	DiskModule(DiskModule const &src);
	DiskModule					&operator=(DiskModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	std::deque<float>			_numbers;
	
};
}

#endif // ************************************************* DISKMODULE_HPP //
