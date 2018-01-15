/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:08:44 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 17:29:53 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Entity.hpp"

Player::Player(int maxY, int maxX, int y, int x) : Entity(maxX, maxY), _locX(x), _locY(y), _lives(3), _name("Spaceship_X") {
	(void)this->_lives;
	this->_projectile = 'g';
}

Player::Player(Player const &src) {
	*this = src;
}

Player::~Player() {
	
}

void		Player::mvUp() {
	_locY -= 1;
	if (_locY < 1) {
		_locY = 1;
	}
}

void		Player::mvDown() {
	_locY += 1;
	if (_locY > getmaxY() - 1) {
		_locY = getmaxY() - 1;
	}
}

void		Player::mvLeft() {
	_locX -= 1;
	if (_locX < 1) {
		_locX = 1;
	}
}

void		Player::mvRight() {
	_locX++;
	if (_locX > getmaxX() - 1) {
		_locX = getmaxX() - 1;
	}
}

int			Player::getX() {
	return _locX;
}

int			Player::getY() {
	return _locY;
}

int			Player::getLives() {
	return this->_lives;
}

// int			Player::getmv(int move) {
// 	int choice = wgetch(_curwin);
// 	switch (choice) {
// 		case KEY_UP:
// 			mvUp();
// 			break;
// 		case KEY_DOWN:
// 			mvDown();
// 			break;
// 		case KEY_LEFT:
// 			mvLeft();
// 			break;
// 		case KEY_RIGHT:
// 			mvRight();
// 			break;
// 		default:
// 			break;
// 	}
// 	return choice;
// }

// void		Player::tick(WINDOW *win) {
// }

std::string	Player::getName(void) {
	return _name;
}

Player	&Player::operator=(Player const &rhs) {
	if (this != &rhs) {
		this->_locX = rhs._locX;
		this->_locY = rhs._locY;
		this->_lives = rhs._lives;
		this->_name = rhs._name;
	}
	return *this;
}
