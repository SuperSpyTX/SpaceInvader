/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemey.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:00:35 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 22:51:28 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemey.hpp"
#include <ncurses.h>

Enemey::Enemey(int maxY, int maxX, int y, int x) : Entity(maxX, maxY), _name("Enemey") {
	this->_pX = x;
	this->_pY = y;
	this->_type = 4;
	this->_locX = x;
	this->_locY = y;
	this->_projectile = 'X';
	this->_ticks = 0;
	this->_fireCurTick = 0;
	this->_fireTick = 25000 + (rand() % 500000);
}

Enemey::Enemey(Enemey const &src) {
	*this = src;
}

Enemey::~Enemey() {

}

int		Enemey::getX(void) {
	return this->_locX;
}

int		Enemey::getY(void) {
	return this->_locY;
}

void		Enemey::onCollision(Entity &entity) {
	// Eat my dust.
	(void)entity;
	this->_lives = -1;
}

void		Enemey::tick(Tracker &tracker, WINDOW *win) {
	if (this->_lives == 0)
		return;
	if (this->_lives == -2)
		this->_ticks++;
	if (this->_ticks == 20000 && this->_lives == -2) {
		this->_lives = 0;
		this->_ticks = 0;
		mvwaddch(win, _pX - 1, _pY - 1, ' ');
		mvwaddch(win, _pX + 1, _pY - 1, ' ');
		mvwaddch(win, _pX - 1, _pY + 1, ' ');
		mvwaddch(win, _pX + 1, _pY + 1, ' ');
		mvwaddch(win, _pX + 1, _pY + 1, ' ');
		mvwaddch(win, _pX, _pY + 1, ' ');
		mvwaddch(win, _pX + 1, _pY, ' ');
		mvwaddch(win, _pX - 1, _pY, ' ');
		mvwaddch(win, _pX, _pY - 1, ' ');
		mvwaddch(win, _pX, _pY, ' ');
		return;
	}
	if (this->_lives == -2)
		return;
	if (this->_lives == -1) {
		this->_ticks = 0;
		mvwaddch(win, _pX, _pY, ' ');
		if (_pX < 2)
			_pX++;
			this->checkCollision(tracker, win, _pX - 1, _pY - 1);
			this->checkCollision(tracker, win, _pX + 1, _pY - 1);
			this->checkCollision(tracker, win, _pX - 1, _pY + 1);
			this->checkCollision(tracker, win, _pX + 1, _pY + 1);
			this->checkCollision(tracker, win, _pX, _pY + 1);
			this->checkCollision(tracker, win, _pX + 1, _pY);
			this->checkCollision(tracker, win, _pX - 1, _pY);
			this->checkCollision(tracker, win, _pX, _pY - 1);
		mvwaddch(win, _pX - 1, _pY - 1, '*');
		mvwaddch(win, _pX + 1, _pY - 1, '*');
		mvwaddch(win, _pX - 1, _pY + 1, '*');
		mvwaddch(win, _pX + 1, _pY + 1, '*');
		mvwaddch(win, _pX, _pY + 1, '*');
		mvwaddch(win, _pX + 1, _pY, '*');
		mvwaddch(win, _pX - 1, _pY, '*');
		mvwaddch(win, _pX, _pY - 1, '*');
		this->_lives--;
		return;
	}

	/*if (this->_lives == -1) {
		mvwaddch(win, _pX, _pY, ' ');
		this->_lives = 0;
		return;
	}*/
	if (++this->_fireCurTick == this->_fireTick) {
		tracker.createProjectile(this->getmaxY(), this->getmaxX(), _pY, _pX + 2, false);
		this->_fireCurTick = 0;
	}
	this->_ticks++;
	if (this->_ticks == 7000) {
		this->_ticks = 0;
		this->moveProjectile(tracker, win, MOVE_DOWN);
		if (_pY >= this->getmaxY() - 1)
			_pY--;
		if (_pX >= this->getmaxX() - 1) {
			this->_pX = 2 + rand() % _locX;
			this->_pY = 2 + rand() % _locY;
			return;
		}
	}
	mvwaddch(win, _pX, _pY, _projectile);
}

Enemey &Enemey::operator=(Enemey const &rhs) {
	if (this != &rhs) {
		this->_locY = rhs._locY;
		this->_locX = rhs._locX;
		this->_lives = rhs._lives;
		this->_name = rhs._name;
	}
	return *this;
}
