/*
 * orientation.h
 *
 *  Created on: 17 апр. 2016 г.
 *      Author: Vladmir
 */

#ifndef ORIENTATION_H_
#define ORIENTATION_H_

#include "map_typedefs.h"

enum Orientation {
	PO_N = 0, PO_E, PO_S, PO_W, PO_SIZE
};

Orientation Orientation_RotateLeft(Orientation o);
Orientation Orientation_RotateRight(Orientation o);

#endif /* ORIENTATION_H_ */
