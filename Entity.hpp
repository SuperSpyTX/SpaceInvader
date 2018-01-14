/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:21:50 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/13 23:50:53 by evanheum         ###   ########.fr       */
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
	public:
	Entity();
	Entity(Entity const &src);
	~Entity();

	void		setpX(int i);
	void		setpY(int i);

	int			getpY(void);
	int			getpX(void);
	char		getProjectile(void);

	void		doAction(void) virtual;

	void		moveProjectile(int i);
	
	
	Entity	&operator=(Entity const &rhs);
};

#endif
