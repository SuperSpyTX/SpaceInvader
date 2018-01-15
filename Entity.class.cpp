/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:21:51 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 21:19:15 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"
#include "Tracker.hpp"
#include <stdlib.h>
#include <ncurses.h>

Entity::Entity(): _projectile('|'){
	setProjectile('A');
	this->_entityId = rand();
	this->_checkCollision = true;
	this->_lives = 1;
}

Entity::Entity(int y, int x) : _maxX(x), _maxY(y), _projectile('|') {
	setProjectile('A');
	this->_checkCollision = true;
	this->_lives = 1;
}

Entity::Entity(Entity const &src) {
	*this = src;
}

Entity::~Entity() {
	
}

bool Entity::operator==(Entity const &rhs) {
	return this->_entityId == rhs._entityId;
}

void		Entity::setpX(int i) {
	this->_pX = i;
}

void		Entity::setpY(int i) {
	this->_pY = i;
}

void		Entity::setProjectile(char c) {
	this->_projectile = c;
}

char		Entity::getProjectile(void) {
	return this->_projectile;
}

int			Entity::getmaxX(void) {
	return this->_maxX;
}

int			Entity::getmaxY(void) {
	return this->_maxY;
}

int			Entity::getpX(void) {
	return this->_pX;
}

int			Entity::getpY(void) {
	return this->_pY;
}

char		Entity::getShip(void) {
	return this->_ship;
}

int			Entity::getLives(void) {
	return this->_lives;
}

bool		Entity::getCollisionCheck(void) {
	return this->_checkCollision;
}

int			Entity::getType(void) {
	return this->_type;
}

void		Entity::checkCollision(Tracker &tracker, WINDOW *win, int x, int y) {
	if (!this->_checkCollision)
		return;
	char g = mvwgetch(win, y, x);

	if (g != ' ') {
		// Locate entity in db.
		Entity *entity = tracker.getEntity(x, y);
		if (!entity)
			return;

		// Call respective functions.
		this->onCollision(*entity);
		entity->onCollision(*this);
	}
}

void		Entity::onCollision(Entity &entity) {
	(void)entity;
}

void		Entity::tick(Tracker &tracker, WINDOW *win) {
	(void)tracker;
	mvwaddch(win, _pX, _pY, _projectile);
}

void		Entity::moveProjectile(Tracker &tracker, WINDOW *win, int i) {
	// either increment pY or pX
	mvwaddch(win, _pX, _pY, ' ');
	switch (i) {
		case MOVE_LEFT:
			this->checkCollision(tracker, win, _pX, _pY - 1);
			_pY--;
			if (_pY < 1)
				_pY = 1;
			break;
		case MOVE_RIGHT:
			this->checkCollision(tracker, win, _pX, _pY + 1);
			_pY++;
			if (_pY > _maxY - 1)
				_pY = _maxY - 1;
			break;
		case MOVE_DOWN:
			this->checkCollision(tracker, win, _pX + 1, _pY);
			_pX++;
			if (_pX > _maxX - 1)
				_pX = _maxX - 1;
			break;
		case MOVE_UP:
			this->checkCollision(tracker, win, _pX - 1, _pY);
			_pX--;
			if (_pX < 1)
				_pX = 1;
			break;
	}
	// TODO: See if we need to redraw the entity after moving it.
	//mvwaddch(win, _pX, _pY,);
}

Entity		&Entity::operator=(Entity const &rhs) {
	if (this != &rhs) {
		this->_entityId = rhs._entityId;
		this->_maxX = rhs._maxX;
		this->_maxY = rhs._maxY;
		this->_projectile = rhs._projectile;
		this->_checkCollision = rhs._checkCollision;
		this->_lives = rhs._lives;
		this->_pX = rhs._pX;
		this->_pY = rhs._pY;
		this->_maxX = rhs._maxX;
		this->_maxY = rhs._maxY;
	}
	return *this;
}
