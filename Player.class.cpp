/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:08:44 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/13 14:55:10 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(WINDOW * win, int y, int x, char c) :
	_curwin(win), _locY(y), _locX(x), _key(c), _name("Spaceship_X") {
		keypad(_curwin, true);
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
	if (_locY > _maxY - 1) {
		_locY = _maxY - 1;
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
	if (_locX > _maxX - 1) {
		_locX = _maxX - 1;
	}
}

int			Player::getmv() {
	int choice = wgetch(_curwin);
	switch (choice) {
		case KEY_UP:
			mvUp();
			break;
		case KEY_DOWN:
			mvDown();
			break;
		case KEY_LEFT:
			mvLeft();
			break;
		case KEY_RIGHT:
			mvRight();
			break;
		default:
			break;
	}
	return choice;
}

void		Player::display() {
	mvwaddch(_curwin, _locY, _locX, _key);
}


std::string	Player::getName(void) {
	return _name;
}

Player	&Player::operator=(Player const &rhs) {
	if (this != &rhs) {
	}
	return *this;
}