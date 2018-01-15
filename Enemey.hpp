/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemey.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:00:36 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 16:16:41 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMEY_HPP
# define ENEMEY_HPP

#include "Entity.hpp"
#include <string>

class Enemey: public virtual Entity{
	private:
		int			_locX;
		int			_locY;
		int			_lives;
		std::string	_name;
	public:
		Enemey();
		Enemey(int y, int x);
		Enemey(Enemey const &src);
		Enemey	&operator=(Enemey const &rhs);
		~Enemey();


		int			getX(void);
		int			getY(void);
		void		mvDown(void);
};

#endif