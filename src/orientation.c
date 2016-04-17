/*
 * orientation.c
 *
 *  Created on: 17 апр. 2016 г.
 *      Author: Vladmir
 */

#include "orientation.h"
#include <stdio.h>


Orientation Orientation_RotateLeft(Orientation o) {
	switch(o) {
	case PO_N:
		return PO_W;
	case PO_W:
		return PO_S;
	case PO_S:
		return PO_E;
	case PO_E:
		return PO_N;
	default:
		return o;
	}
}

Orientation Orientation_RotateRight(Orientation o) {
	switch(o) {
	case PO_N:
		return PO_E;
	case PO_W:
		return PO_N;
	case PO_S:
		return PO_W;
	case PO_E:
		return PO_S;
	default:
		return o;
	}
}
