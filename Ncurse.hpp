/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:06:30 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/13 22:43:37 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_HPP
# define NCURSE_HPP

#include "Player.hpp"
#include <iostream>
#include <ncurses.h>

class	Ncurse {
	private:
		std::string _name;
		int _row;
		int _col;
		WINDOW *_curwin;
	protected:
	public:
	Ncurse();
	Ncurse(Ncurse const &src);
	~Ncurse();
	void	setRow(int i);
	void	setCol(int i);
	void	setWindow(WINDOW *name);
	bool	setMenu();
	void	setGameEnv();

	void	clearWindow();
	// std::string getName(void); 
	
	int		getRow(void) const;
	int		getCol(void) const;
	WINDOW		*getWindow(void);

	Ncurse	&operator=(Ncurse const &rhs);
};

#endif
