/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:06:30 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 22:20:49 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_HPP
# define NCURSE_HPP

# include "Player.hpp"
# include <iostream>
# include <ncurses.h>
# include "time.h"
# define FPS 60
# define CLOCKS_PER_FRAME (1000)

class	Ncurse {
	private:
		std::string _name;
		int _row;
		int _col;
		int _enemies;
		clock_t _time;
		WINDOW *_curwin;
	protected:
	public:
		Ncurse();
		Ncurse(Ncurse const &src);
		~Ncurse();
		void	setRow(int i);
		void	setCol(int i);
		void	setWindow(WINDOW *name);
		bool	setMenu(void);
		void	setGameEnv(void);
		void	setGameOver(bool won);
		void	setcurseXY(void);

		void	clearWindow();
		// std::string getName(void);

		int		getRow(void) const;
		int		getCol(void) const;
		WINDOW		*getWindow(void);

		Ncurse	&operator=(Ncurse const &rhs);
};

#endif
