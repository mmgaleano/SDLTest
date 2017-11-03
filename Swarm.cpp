/*
 * Swarm.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: BC
 */

#include "Swarm.h"
#include "Particle.h"

namespace asiamvl {

Swarm::Swarm():lastTime(0) {

	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {

	delete[] m_pParticles;
}

void Swarm::update(int elapsed){

	int interval = elapsed - lastTime;

	for(int i = 0; i < Swarm::NPARTICLES; i++){

		m_pParticles[i].update(interval);
	}

	lastTime = elapsed;
}

} /* namespace asiamvl */
