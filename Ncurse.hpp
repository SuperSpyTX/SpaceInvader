/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:06:30 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 13:06:53 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_HPP
# define NCURSE_HPP

#include "Player.hpp"
#include <iostream>
#include <ncurses.h>
#include "time.h"
#define FPS 600
#define CLOCKS_PER_FRAME (CLOCKS_PER_SEC / FPS)

class	Ncurse {
	private:
		std::string _name;
		int _row;
		int _col;
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
	void	setcurseXY(void);

	void	clearWindow();
	// std::string getName(void); 
	
	int		getRow(void) const;
	int		getCol(void) const;
	WINDOW		*getWindow(void);

	Ncurse	&operator=(Ncurse const &rhs);
};

#endif
