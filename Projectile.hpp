/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:00:36 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 19:56:52 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "Entity.hpp"
#include <ncurses.h>
#include <string>

class Projectile: public virtual Entity {
	private:
		int			_locX;
		int			_locY;
		int			_ticks;
		int			_move;
		bool		_explosive;
		std::string	_name;
	public:
		Projectile();
		Projectile(int maxY, int maxX, int y, int x, int move);
		Projectile(Projectile const &src);
		Projectile	&operator=(Projectile const &rhs);
		~Projectile();

		void		setExplosive(void);

		void		onCollision(Entity &entity);
		void		tick(Tracker &tracker, WINDOW *win);
		int			getX(void);
		int			getY(void);
};

#endif
