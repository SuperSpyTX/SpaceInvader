/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:08:40 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/13 22:47:25 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <iostream>
#include <ncurses.h>

class	Player {
	private:
		WINDOW		*_curwin;
		int			_locX;
		int			_locY;
		int			_maxX;
		int			_maxY;
		char		_key;
		std::string _name;
	public:
		Player(WINDOW * win, int y, int x, char c);
		Player(Player const &src);
		~Player();

		void		mvUp();
		void		mvDown();
		void		mvLeft();
		void		mvRight();
		int			getmv();
		void		display();
		std::string	getName(void);


		Player	&operator=(Player const &rhs);	
};

#endif