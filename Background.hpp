/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:10:33 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 20:38:19 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP

# include "Entity.hpp"
# include "Tracker.hpp"
# include <iostream>
# include <ncurses.h>

class Background: public virtual Entity {
	private:
		int				_locX;
		int				_locY;
		int				_ticks_;
	public:
		Background();
		Background(int maxY, int maxX, int y, int x);
		Background(Background const &src);
		Background	&operator=(Background const &rhs);
		~Background();


		void			onCollision(Entity &entity);
		void			tick(Tracker &tracker, WINDOW *win);
};

#endif
