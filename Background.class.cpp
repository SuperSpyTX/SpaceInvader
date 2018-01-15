/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:10:34 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 20:48:02 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"
#include "Background.hpp"
#include "Tracker.hpp"
#include <ncurses.h>

Background::Background() : Entity(), _locY(0), _ticks_(0){
}

Background::Background(int maxY, int maxX, int y, int x) : Entity(maxX, maxY), _locX(x), _locY(y) {
	this->_projectile = '.';
	this->_checkCollision = false;
	this->_lives = 1;
	this->_type = 0;
	this->_pX = x;
	this->_pY = y;
	this->_locX = x;
	this->_locY = y;
}

Background::Background(Background const &src) {
	*this = src;
}

Background::~Background() {
	
}

void			Background::onCollision(Entity &entity) {
	// Do nothing!
	(void)entity;
}

void			Background::tick(Tracker &tracker, WINDOW *win) {
	this->_ticks_++;
	(void)tracker;
	if (this->_ticks_ == 5000) {
		mvwaddch(win, _pX, _pY, ' ');
		this->_pX += (rand() % 10);
		if (this->_pY >= (getmaxY() - 1))
			this->_pY -= 2;
		if (this->_pX >= (getmaxX() - 1)) {
			this->_pX = 2 + rand() % _locX;
			this->_pY = 2 + rand() % _locY;
		}
		mvwaddch(win, _pX, _pY, this->_projectile);
		this->_ticks_ = 0;
	}
}

Background	&Background::operator=(Background const &rhs) {
	if (this != &rhs) {
		this->_locX = rhs._locX;
		this->_locY = rhs._locY;
		this->_ticks_ = rhs._ticks_;
	}
	return (*this);
}
