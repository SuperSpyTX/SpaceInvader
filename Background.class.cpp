/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:10:34 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 20:23:11 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"
#include "Background.hpp"
#include <ncurses.h>

Background::Background() : _space('.'), _locY(0), _ticks_(0){
}

Background::Background(Background const &src) {
	*this = src;
}

Background::~Background() {
	
}

void			Background::setX(int i) {
	this->_locX = i;
}

void			Background::setY(int i) {
	this->_locY = i;
}

char			Background::getSpace() {
	return this->_space;
}

void			Background::setSpace(char c) {
	this->_space = c;
}

int				Background::getY(void) {
	return this->_locY;
}

int 			Background::getX(void) {
	return this->_locX;
}

void			Background::moveSpace(WINDOW *win) {
	this->_ticks_++;
	if (this->_ticks_ == 20000) {
		mvwprintw(win, this->getY(), this->getX(), "%c", ' ');
		this->_locY++;
		mvwprintw(win, this->getY(), this->getX(), "%c", getSpace());
		if (this->_locY > (getmaxY() - 6))
			this->_locY = 2;
		this->_ticks_ = 0;
	}
}

Background	&Background::operator=(Background const &rhs) {
	if (this != &rhs) {
		this->_space = rhs._space;
	}
	return (*this);
}
