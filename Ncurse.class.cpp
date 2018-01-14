/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:06:31 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 03:22:57 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ncurse.hpp"
#include <iostream>
#include <ncurses.h>
#include <string>
#include "unistd.h"


Ncurse::Ncurse(){
	initscr();
	noecho();
	cbreak();
	timeout(0);
	getmaxyx(stdscr, _row, _col);
	WINDOW *gamewin = newwin(0, _col, _row, _col);
	mvwprintw(gamewin ,_row/2, (_col-std::strlen("SPACE INVADERS"))/2, "%s", "SPACEINVADERS");
	refresh();
	curs_set(0);
	getch();
	delwin(gamewin);
	if (setMenu()) {
		setGameEnv();
	}
}

Ncurse::Ncurse(Ncurse const &src) {
	*this = src;
	this->operator=(src);
}

Ncurse::~Ncurse() {
	WINDOW *gameover = newwin(0, 0, _row, _col);
	mvwprintw(gameover, _row/2, (_col-std::strlen("SPACE INVADERS"))/2, "%s", "SPACEINVADERS");
	delwin(gameover);
	endwin();
}

bool	Ncurse::setMenu() {
	std::string choices[2] = {"new game","quit game"};
	int choice;
	int highlight = 0;
	bool boom;
	WINDOW *menu = newwin(6, this->_col/4, this->_row/1.9, _col/2.7);
	wborder(menu, '-', '-', '-','-','-','-','-','-');
	keypad(menu, true);
	wrefresh(menu);

	while (1) {
		for (int i = 0; i < 2; i++) {
			if ( i == highlight)
				wattron(menu, A_STANDOUT);
			mvwprintw(menu, i+1, (this->_col/4)/2, choices[i].c_str());
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
			if(!c.compare("new game")) {
				boom = true;
				break;
			}
			else if (!c.compare("quit game")) {
				boom = false;
				break;
			}
		}	
	}
	clear();
	delwin(menu);
	return boom;
}

void	Ncurse::setGameEnv() {
	getmaxyx(stdscr, this->_row, this->_col);
	WINDOW 		*gamewin = newwin(this->_row - 8, this->_col - 3, 5, 1);
	WINDOW 		*score = newwin(5, this->_col - 3, 0, 1);
	WINDOW		*control = newwin(3, this->_col - 3, this->_row - 3, 1);
	refresh();
	box(gamewin, 0, 0);
	box(score, 0, 0);
	box(control, 0, 0);
	mvwprintw(control, 1, 20,
	"CONTROLS:      [SPACEBAR]: Shoot      |      [KEY_ARROWS]: Movement     |     [X]: Exit     |     [Lives]:");
	timeout(0);
	wrefresh(gamewin);
	wrefresh(score);
	wrefresh(control);
	int esc = 0;
	keypad(gamewin, true);
	nodelay(gamewin, true);
	wrefresh(gamewin);
	getch();
	while (1) {
		esc = wgetch(gamewin);
		if (esc == 'x') {
			break;
		}
		// getmaxyx(stdscr, _row, _col);
		wrefresh(gamewin);
		usleep(30000);
	}
}


void	Ncurse::setcurseXY() {
	getmaxyx(stdscr, this->_row, this->_col);

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
		this->_col = rhs._col;
		this->_row = rhs._row;
		*this = rhs;
	}
	return *this;
}