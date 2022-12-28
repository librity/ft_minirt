/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/28 17:39:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_projectile	tick(t_environment env, t_projectile projectile)
{
	projectile.position = add(projectile.position, projectile.velocity);
	projectile.velocity = add(projectile.velocity, env.gravity);
	projectile.velocity = add(projectile.velocity, env.wind);
	return (projectile);
}

/**
 * - [x] Declarar um projetil inicial e ambiente
 * - [x] Rodar a função tick enquanto o y do projetil > 0
 * - [x] Printar a posição do projetil na tela
 * - [x] Contar a quantidade de intervalos que demorou para o projetil cair
 */
void	projectile_demo(void)
{
	t_projectile	projectile;
	t_environment	env;
	int				ticks;

	ticks = 0;

	projectile.position = point(0, 1, 0);
	projectile.velocity = normalize(vector(1, 1, 0));

	env.gravity = vector(0, -0.1, 0);
	env.wind = vector(-0.01, 0, 0);

	while (projectile.position.y > 0)
	{
		inspect_p3d(projectile.position);
		inspect_v3d(projectile.velocity);
		printf("---\n");
		projectile = tick(env, projectile);
		ticks++;
	}
	printf("TOTAL TICKS: %d\n", ticks);
}
