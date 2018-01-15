/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tracker.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:37:45 by jkrause           #+#    #+#             */
/*   Updated: 2018/01/14 23:08:46 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tracker.hpp"
#include "Enemey.hpp"
#include "Background.hpp"
#include "Projectile.hpp"


Tracker::Tracker(void) {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		_entities[i] = 0;
	}
	this->_curCount = 0;
	this->_curEnemies = 0;
}

Tracker::Tracker (Tracker &src) {
	*this = src;
}

Tracker &Tracker::operator=(Tracker const &rhs) {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		this->_entities[i] = rhs._entities[i];
	}
	this->_curCount = rhs._curCount;
	return *this;
}

Tracker::~Tracker(void) {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (this->_entities[i] != 0)
			delete this->_entities[i];
	}
}

void Tracker::addEntity(Entity *entity) {
	for (int i = 0; i < this->_curCount + 1; i++) {
		if (this->_entities[i] == 0) {
			if (entity->getType() == 4)
				this->_curEnemies++;
			this->_entities[i] = entity;
			this->_curCount++;
			break;
		}
	}
}

void Tracker::removeEntity(Entity *entity) {
	for (int i = 0; i < this->_curCount; i++) {
		if (*(this->_entities[i]) == *entity) {
			this->_entities[i] = 0;
			break;
		}
	}
}

void Tracker::createProjectile(int maxY, int maxX, int y, int x, bool up) {
	Projectile *projectile = new Projectile(maxY, maxX, y, x, (up ? MOVE_UP : MOVE_DOWN));
	projectile->setExplosive();
	this->addEntity(projectile);
}

void Tracker::createEnemey(int maxY, int maxX, int y, int x) {
	Enemey *enemey = new Enemey(maxY, maxX, y, x);
	this->addEntity(enemey);
}

void Tracker::createBg(int maxY, int maxX, int y, int x) {
	Background *background = new Background(maxY, maxX, y, x);
	this->addEntity(background);
}

int Tracker::getNumOfEnemeies(void) {
	return this->_curEnemies;
}

Entity *Tracker::getEntity(int x, int y) {
	for (int i = 0; i < this->_curCount; i++) {
		if (this->_entities[i] != 0) {
			if (this->_entities[i]->getpX() == x && this->_entities[i]->getpY() == y
					&& this->_entities[i]->getLives() > 0 && this->_entities[i]->getCollisionCheck()) {
				return this->_entities[i];
			}
		}
	}

	return 0;
}

void Tracker::tickEntities(Tracker &tracker, WINDOW *win) {
	this->_curEnemies = 0;
	for (int i = 0; i < this->_curCount; i++) {
		if (this->_entities[i] != 0) {
			if (this->_entities[i]->getLives() == 0 && i > 0)
			{
				delete this->_entities[i];
				this->_entities[i] = 0;
				continue;
			}
			if (this->_entities[i]->getType() == 4) {
				this->_curEnemies++;
			}
			this->_entities[i]->tick(tracker, win);
		}
	}
}
