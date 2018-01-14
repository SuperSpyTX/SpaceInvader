/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:21:50 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 13:32:41 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

class Entity {
	private:
		char	_projectile;
		int		_pX;
		int		_pY;
		void	setProjectile(char c);
	protected:
		Entity(char projectile, int x, int y);
	public:
		Entity();
		Entity(Entity const &src);
		Entity	&operator=(Entity const &rhs);
		~Entity();

		void		setpX(int i);
		void		setpY(int i);

		int			getpY(void);
		int			getpX(void);
		char		getProjectile(void);

		virtual void		doAction(void);
		void		moveProjectile(int i);
};

#endif
