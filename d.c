/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:59:52 by viforget          #+#    #+#             */
/*   Updated: 2020/12/18 13:46:37 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

float RayIntersectsTriangle(t_obj *tr, float v[3], float p[3])
{
	float edge1[3];
	float edge2[3];
	float h[3];
	float q[3];
	float s[3];
	float a,f,u,w,t;
	//edge1 = vertex1 - vertex0;
	vector_sub(tr->c1, tr->c0, edge1);
	
	//edge2 = vertex2 - vertex0;
	vector_sub(tr->c2, tr->c0, edge2);
	
	//h = rayVector.crossProduct(edge2);
	ortho_vector(v, edge2, h);

	//a = edge1.dotProduct(h);
	a = scal_vector(edge1, h);

	if (a > -ZE && a < ZE)
		return (-1);    // Le rayon est parallèle au triangle.

	f = 1.0/a;
	//s = rayOrigin - vertex0;
	vector_sub(p, tr->c0, s);
	
	//u = f * (s.dotProduct(h));
	u = f * scal_vector(s, h);

	if (u < 0.0 || u > 1.0)
		return (-1);
	
	//q = s.crossProduct(edge1);
	ortho_vector(s, edge1, q);

	//v = f * rayVector.dotProduct(q);
	w = f * scal_vector(v, q);

	if (w < 0.0 || u + w > 1.0)
		return (-1);

	// On calcule t pour savoir ou le point d'intersection se situe sur la ligne.
	//float t = f * edge2.dotProduct(q);
	t = f * scal_vector(edge2, q);
	
	if (t > ZE) // Intersection avec le rayon
	{
		//outIntersectionPoint = rayOrigin + rayVector * t;
		return (t);
	}
	else // On a bien une intersection de droite, mais pas de rayon.
		return (-1);
}
