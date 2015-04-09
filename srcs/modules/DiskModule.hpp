// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DiskModule.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 10:00:53 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/04 15:37:40 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DISKMODULE_HPP
# define DISKMODULE_HPP

//# include <string>
//# include <iostream>
# include <Vector>
# include <modules/IMonitorModule.hpp>

namespace ft
{
class DiskModule : public IMonitorModule
{
public:
	DiskModule(std::string const &moduleName);
	virtual ~DiskModule();
	
	void						refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::string const			&getModuleName(void) const;
	
protected:
private:
	DiskModule();
	DiskModule(DiskModule const &src);
	DiskModule					&operator=(DiskModule const &rhs);

	std::vector<std::string>	_strings;
	std::string const			_moduleName;
	
};
//std::ostream					&operator<<(std::ostream &o, DiskModule const &rhs);
}

#endif // ************************************************* DISKMODULE_HPP //
