/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:00:35 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 21:19:31 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tracker.hpp"
#include "Projectile.hpp"
#include <ncurses.h>

Projectile::Projectile(int maxY, int maxX, int y, int x, int move) : Entity(maxX, maxY), _name("Projectile") {
	this->_pX = x;
	this->_pY = y;
	this->_projectile = '|';
	this->_ticks = 0;
	this->_type = 3;
	this->_explosive = false;
	this->_move = move;
}

Projectile::Projectile(Projectile const &src) {
	*this = src;
}

Projectile::~Projectile() {

}

int		Projectile::getX(void) {
	return this->_locX;
}

int		Projectile::getY(void) {
	return this->_locY;
}

void		Projectile::setExplosive(void) {
	this->_explosive = true;
}

void		Projectile::onCollision(Entity &entity) {
	(void)entity;
	if (entity.getType() == this->_type)
		return;
	this->_lives = -1;
}

void		Projectile::tick(Tracker &tracker, WINDOW *win) {
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
		if (this->_explosive) {
			this->checkCollision(tracker, win, _pX - 1, _pY - 1);
			this->checkCollision(tracker, win, _pX + 1, _pY - 1);
			this->checkCollision(tracker, win, _pX - 1, _pY + 1);
			this->checkCollision(tracker, win, _pX + 1, _pY + 1);
			this->checkCollision(tracker, win, _pX, _pY + 1);
			this->checkCollision(tracker, win, _pX + 1, _pY);
			this->checkCollision(tracker, win, _pX - 1, _pY);
			this->checkCollision(tracker, win, _pX, _pY - 1);
		}
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
	this->_ticks++;
	if (this->_ticks == 5000) {
		this->_ticks = 0;
		this->moveProjectile(tracker, win, this->_move);
		if (_pX < 2 || _pX >= (this->getmaxY() - 1)) {
			this->_lives = 0;
			mvwaddch(win, _pX, _pY, ' ');
			return;
		}
	}
	mvwaddch(win, _pX, _pY, _projectile);
}

Projectile &Projectile::operator=(Projectile const &rhs) {
	if (this != &rhs) {
		this->_locY = rhs._locY;
		this->_locX = rhs._locX;
		this->_lives = rhs._lives;
		this->_name = rhs._name;
	}
	return *this;
}
