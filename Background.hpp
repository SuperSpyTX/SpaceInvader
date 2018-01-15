/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:10:33 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 20:18:08 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP

#include "Entity.hpp"
#include <iostream>
#include <ncurses.h>

class Background: public virtual Entity {
	private:
		char			_space;
		int				_locX;
		int				_locY;
		int				_ticks_;
	public:
		Background();
		Background(Background const &src);
		Background	&operator=(Background const &rhs);
		~Background();

		char			getSpace(void);


		void			moveSpace(WINDOW *win);
		void			setX(int i);
		void			setY(int i);

		int				getY(void);
		int				getX(void);

		void			setSpace(char c);
};

#endif