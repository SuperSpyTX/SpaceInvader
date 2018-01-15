/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:08:44 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 20:59:58 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Entity.hpp"

Player::Player(int maxY, int maxX, int y, int x) : Entity(maxX, maxY), _name("Spaceship_X") {
	this->_pX = x;
	this->_pY = y;
	this->_type = 5;
	this->_projectile = 'A';
	this->_lives = 3;
}

Player::Player(Player const &src) {
	*this = src;
}

Player::~Player() {
	
}

bool		Player::readyToFire(void) {
	return this->_ticks == 20000;
}

void		Player::fire(void) {
	this->_ticks = 0;
}

void		Player::onCollision(Entity &entity) {
	// Bye felicia!
	(void)entity;
	this->_lives--;
}

void		Player::tick(Tracker &tracker, WINDOW *win) {
	if (this->_lives == 0)
		return;
	if (this->_ticks < 20000)
		this->_ticks++;
	(void)tracker;
	mvwaddch(win, _pX, _pY, _projectile);
}

std::string	Player::getName(void) {
	return _name;
}

Player	&Player::operator=(Player const &rhs) {
	if (this != &rhs) {
		this->_lives = rhs._lives;
		this->_name = rhs._name;
	}
	return *this;
}
