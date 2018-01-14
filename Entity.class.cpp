/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:21:51 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 14:35:22 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity(): _projectile('|'){
	setProjectile('A');
}

Entity::Entity(int y, int x) : _maxX(x), _maxY(y), _projectile('|') {
	setProjectile('A');
}

Entity::Entity(Entity const &src) {
	*this = src;
}

Entity::~Entity() {
	
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

void		Entity::doAction() {
	
}

void		Entity::moveProjectile(int i) {
	(void)i;
	// either increment pY or pX
}

Entity		&Entity::operator=(Entity const &rhs) {
	if (this != &rhs) {
		this->_projectile = rhs._projectile;
		this->_pX = rhs._pX;
		this->_pY = rhs._pY;
	}
	return *this;
} 
