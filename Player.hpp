/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:08:40 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 17:29:22 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <iostream>
#include <ncurses.h>
#include "Entity.hpp"

class	Player : public virtual Entity {
	private:
		int 		_ticks;
		std::string _name;
	public:
		Player(int maxY, int maxX, int y, int x);
		Player(Player const &src);
		~Player();

		std::string	getName(void);


		bool		readyToFire(void);
		void		fire(void);
		void		onCollision(Entity &entity);
		void		tick(Tracker &tracker, WINDOW *win);

		Player	&operator=(Player const &rhs);
};

#endif
