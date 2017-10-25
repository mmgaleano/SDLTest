/*
 * Particle.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: BC
 */

#include <stdlib.h>
#include "Particle.h"

namespace asiamvl {

Particle::Particle() {

	m_x = ((2.0 * rand())/RAND_MAX) - 1;  //Range from -1 to 1
	m_y = ((2.0 * rand())/RAND_MAX) - 1;  //Range from -1 to 1
}

Particle::~Particle() {

}

} /* namespace asiamvl */
