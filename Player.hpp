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
		int			_locX;
		int			_locY;
		int			_lives;
		std::string _name;
	public:
		Player(int maxY, int maxX, int y, int x);
		Player(Player const &src);
		~Player();

		void		mvUp();
		void		mvDown();
		void		mvLeft();
		void		mvRight();
		int			getX();
		int			getY();
		int			getmv();
		int			getLives();
		std::string	getName(void);

		void		tick(WINDOW *win);


		Player	&operator=(Player const &rhs);
};

#endif
