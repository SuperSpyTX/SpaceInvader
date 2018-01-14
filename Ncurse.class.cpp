/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:06:31 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/13 21:04:29 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ncurse.hpp"
#include <iostream>
#include <ncurses.h>
#include <string>


Ncurse::Ncurse(){
	initscr();
	noecho();
	raw();
	timeout(0);
	getmaxyx(stdscr, _row, _col);
	// WINDOW *gamewin = newwin(0, _col, _row, _col);
	mvprintw(_row/2, (_col-std::strlen("SPACE INVADERS"))/2, "%s", "SPACEINVADERS");
	refresh();
	curs_set(0);
	getch();
	if (setMenu()) {
		setGameEnv();
	}
}

Ncurse::Ncurse(Ncurse const &src) {
	*this = src;
	this->operator=(src);
}

Ncurse::~Ncurse() {
	endwin();
}

bool	Ncurse::setMenu() {
	WINDOW *menu = newwin(6, _col/4, _row/1.9, _col/2.7);
	wborder(menu, '-', '-', '-','-','-','-','-','-');
	keypad(menu, true);
	wrefresh(menu);
	std::string choices[2] = {"newgame","quitgame"};
	int choice;
	int highlight = 0;
	bool boom = true;

	while (1) {
		// getmaxyx(stdscr, _row, _col);
		for (int i = 0; i < 2; i++) {
			if ( i == highlight)
				wattron(menu, A_STANDOUT);
			mvwprintw(menu, i+1, (_col/4)/2, choices[i].c_str());
			 wattroff(menu, A_STANDOUT);
			wrefresh(menu);
		}
		choice = wgetch(menu);
		switch(choice) {
			case KEY_UP:
				highlight--;
				if (highlight == -1)
					highlight = 1;
				break;
			case KEY_DOWN:
				highlight++;
				if (highlight == 2)
					highlight = 0;
				break;
			default:
				break;
		}
		std::string c = choices[highlight].c_str();
		if (choice == 10) {
			if(!c.compare("newgame")) {
				boom = true;
				break;
			}
			else if (!c.compare("quitgame")) {
				boom = false;
				break;
			}
		}	
	}
	delwin(menu);
	return boom;
}

void	Ncurse::setGameEnv() {
	clearWindow();
	int esc = 0;
	while (esc != KEY_EIC) {
		getmaxyx(stdscr, _row, _col);
		WINDOW *gamewin = newwin(0, _col, _row, _col);
		esc = wgetch(gamewin);
		box(gamewin, 0, 0);
		keypad(gamewin, true);
		wrefresh(gamewin);
	}
}

void	Ncurse::setWindow(WINDOW *name) {
	this->_curwin = name;
}

void	Ncurse::setRow(int i) {
	this->_row = i;
}

void	Ncurse::setCol(int i) {
	this->_col = i; 
}

void	Ncurse::clearWindow() {
		clear();
		refresh();
		getch();
}

int		Ncurse::getRow(void) const {
	return this->_row;
}

int		Ncurse::getCol(void) const {
	return this->_col;
}

WINDOW		*Ncurse::getWindow() {
	return this->_curwin;
}


Ncurse	&Ncurse::operator=(Ncurse const &rhs) {
	if (this != &rhs){
		this->_col = rhs.getCol();
		this->_row = rhs.getRow();
		*this = rhs;
	}
	return *this;
}