/*
 * Particle.h
 *
 *  Created on: Oct 23, 2017
 *      Author: BC
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace asiamvl {

struct Particle {
	double m_x;
	double m_y;
	double m_speed;
	double m_direction;

public:
	Particle();
	virtual ~Particle();
	void update();
};

} /* namespace asiamvl */

#endif /* PARTICLE_H_ */
