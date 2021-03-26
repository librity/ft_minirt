/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cardrt.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:53:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 03:14:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SOURCE:
// https://fabiensanglard.net/rayTracing_back_of_business_card/
// https://gist.github.com/sungiant/9524044

// gcc clean_cardrt.cpp -lm && ./a.out > aek.ppm

#include <stdlib.h> // card > aek.ppm
#include <stdio.h>
#include <math.h>

typedef int i;
typedef float f;

struct vector_3d
{
	f x, y, z;

	vector_3d operator+(vector_3d r)
	{
		return vector_3d(x + r.x, y + r.y, z + r.z);
	}

	vector_3d operator*(f r)
	{
		return vector_3d(x * r, y * r, z * r);
	}

	f operator%(vector_3d r)
	{
		return x * r.x + y * r.y + z * r.z;
	}

	vector_3d()
	{
	}

	vector_3d operator^(vector_3d r)
	{
		return vector_3d(y * r.z - z * r.y, z * r.x - x * r.z, x * r.y - y * r.x);
	}

	vector_3d(f a, f b, f c)
	{
		x = a;
		y = b;
		z = c;
	}

	vector_3d operator!()
	{
		return *this * (1 / sqrt(*this % *this));
	}
};

i G[] = {247570, 280596, 280600, 249748, 18578, 18577, 231184, 16, 16};

f R()
{
	return (f)rand() / RAND_MAX;
}

i T(vector_3d o, vector_3d d, f &t, vector_3d &n)
{
	t = 1e9;
	i m = 0;
	f p = -o.z / d.z;

	if (.01 < p)
	{
		t = p, n = vector_3d(0, 0, 1), m = 1;
	}

	for (i k = 19; k--;)
	{
		for (i j = 9; j--;)
		{
			if (G[j] & 1 << k)
			{
				vector_3d p = o + vector_3d(-k, 0, -j - 4);
				f b = p % d, c = p % p - 1, q = b * b - c;

				if (q > 0)
				{
					f s = -b - sqrt(q);

					if (s < t && s > .01)
					{
						t = s, n = !(p + d * t), m = 2;
					}
				}
			}
		}
	}

	return m;
}

vector_3d S(vector_3d o, vector_3d d)
{
	f t;
	vector_3d n;
	i m = T(o, d, t, n);

	if (!m)
	{
		return vector_3d(.7, .6, 1) * pow(1 - d.z, 4);
	}

	vector_3d h = o + d * t, l = !(vector_3d(9 + R(), 9 + R(), 16) + h * -1), r = d + n * (n % d * -2);
	f b = l % n;

	if (b < 0 || T(h, l, t, n))
	{
		b = 0;
	}

	f p = pow(l % r * (b > 0), 99);

	if (m & 1)
	{
		h = h * .2;
		return ((i)(ceil(h.x) + ceil(h.y)) & 1 ? vector_3d(3, 1, 1) : vector_3d(3, 3, 3)) * (b * .2 + .1);
	}

	return vector_3d(p, p, p) + S(h, r) * .5;
}

i main()
{
	printf("P6 512 512 255 ");
	vector_3d g = !vector_3d(-6, -16, 0), a = !(vector_3d(0, 0, 1) ^ g) * .002, b = !(g ^ a) * .002, c = (a + b) * -256 + g;

	for (i y = 512; y--;)
	{
		for (i x = 512; x--;)
		{
			vector_3d p(13, 13, 13);

			for (i r = 64; r--;)
			{
				vector_3d t = a * (R() - .5) * 99 + b * (R() - .5) * 99;
				p = S(vector_3d(17, 16, 8) + t, !(t * -1 + (a * (R() + x) + b * (y + R()) + c) * 16)) * 3.5 + p;
			}

			printf("%c%c%c", (i)p.x, (i)p.y, (i)p.z);
		}
	}
}