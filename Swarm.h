/*
 * Swarm.h
 *
 *  Created on: Oct 23, 2017
 *      Author: BC
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace asiamvl {

class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	Particle* m_pParticles;
public:
	Swarm();
	virtual ~Swarm();
	const Particle* const getParticles(){return m_pParticles;}
};

} /* namespace asiamvl */

#endif /* SWARM_H_ */
