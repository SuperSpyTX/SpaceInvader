/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemey.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:00:35 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 16:18:05 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemey(int y, int x) : Entity(), _locY(y), _loc(x), _lives(1), _name("Enemey") {
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

void		Player::mvDown() {
	_locY += 1;
	if (_locY > getmaxY() - 1) {
		_locY = getmaxY() - 1;
	}
}

Enemey &operator(Enemey const &rhs) {
	if (this != &rhs) {
		this->_locY = rhs._locY;
		this->_locX = rhs._locX;
		this->_lives = rhs._lives;
		this->_name = rhs._name;
	}
	return *this;
}