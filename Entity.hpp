/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:21:50 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/14 21:16:49 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP
# include <ncurses.h>

// Forward declarations are in C++03, which isn't explicitly forbidden.
// This solves a circular dependency issue.
class Tracker;

# define MOVE_LEFT 1
# define MOVE_RIGHT 2
# define MOVE_UP 3
# define MOVE_DOWN 4

class Entity {
	private:
		int		_entityId;
		int		_maxX;
		int		_maxY;
	protected:
		char	_projectile;
		int		_lives;
		int		_pX;
		int		_pY;
		int		_type;
		bool	_checkCollision;
		void	setProjectile(char c);
		char	_ship;
		// Entity(char projectile, int x, int y);
	public:
		Entity();
		Entity(int y, int x);
		Entity(Entity const &src);
		Entity	&operator=(Entity const &rhs);
		virtual ~Entity();

		bool operator==(Entity const &rhs);

		void		setpX(int i);
		void		setpY(int i);

		int			getmaxY(void);
		int			getmaxX(void);
		int			getpY(void);
		int			getpX(void);
		char		getProjectile(void);
		char		getShip(void);
		int			getLives(void);
		bool		getCollisionCheck(void);
		int			getType(void);

		void		checkCollision(Tracker &tracker, WINDOW *win, int x, int y);

		virtual void		tick(Tracker &tracker, WINDOW *win);
		virtual void		onCollision(Entity &entity);
		void		moveProjectile(Tracker &tracker, WINDOW *win, int i);
};

#endif
