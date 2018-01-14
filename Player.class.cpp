/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:08:44 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 15:48:18 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Entity.hpp"

Player::Player(int y, int x) : Entity(), _locX(x), _locY(y), _lives(3), _name("Spaceship_X") {
	(void)this->_lives;
}

Player::Player(Player const &src) {
	*this = src;
}

Player::~Player() {
	
}

void		Player::mvUp() {
	_locY--;
	if (_locY < 1) {
		_locY = 1;
	}
}

void		Player::mvDown() {
	_locY++;
	if (_locY > getmaxY() - 1) {
		_locY = getmaxY() - 1;
	}
}

void		Player::mvLeft() {
	_locX--;
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

std::string	Player::getName(void) {
	return _name;
}

Player	&Player::operator=(Player const &rhs) {
	if (this != &rhs) {
	}
	return *this;
}