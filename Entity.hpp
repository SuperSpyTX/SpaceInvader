/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:21:50 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 14:34:57 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

class Entity {
	private:
		int		_maxX;
		int		_maxY;
	protected:
		char	_projectile;
		int		_pX;
		int		_pY;
		void	setProjectile(char c);
		char	_ship;
		// Entity(char projectile, int x, int y);
	public:
		Entity();
		Entity(int y, int x);
		Entity(Entity const &src);
		Entity	&operator=(Entity const &rhs);
		~Entity();

		void		setpX(int i);
		void		setpY(int i);


		int			getmaxY(void);
		int			getmaxX(void);
		int			getpY(void);
		int			getpX(void);
		char		getProjectile(void);
		char		getShip(void);

		virtual void		doAction(void);
		void		moveProjectile(int i);
};

#endif
