/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tracker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:37:49 by jkrause           #+#    #+#             */
/*   Updated: 2018/01/14 21:34:50 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACKER_HPP
# define TRACKER_HPP
# include "Entity.hpp"
# include "Enemey.hpp"
# include "Projectile.hpp"
# include "Background.hpp"
# include <ncurses.h>

# define MAX_ENTITIES 512

class Tracker {
	private:
		Entity *_entities[MAX_ENTITIES];
		int _curCount;
		int _curEnemies;
	public:
		Tracker(void);
		Tracker(Tracker &src);
		Tracker &operator=(Tracker const &rhs);
		~Tracker(void);

		int	getNumOfEnemeies(void);

		void addEntity(Entity *entity);
		void removeEntity(Entity *entity);
		void createProjectile(int maxY, int maxX, int y, int x, bool up);
		void createEnemey(int maxY, int maxX, int y, int x);
		void createBg(int maxY, int maxX, int y, int x);
		Entity *getEntity(int x, int y);
		void tickEntities(Tracker &tracker, WINDOW *win);
};

#endif
