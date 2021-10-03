#pragma once

#include <plasma/entity-common.h>
#include <plasma/graphics.h>
#include <plasma/box.h>

#define PLASMA_ENTITY_UNDEFINED 0
#define PLASMA_ENTITY_BOX	   1

union PlasmaEntityConfig {
	PlasmaEntityCommon common;

	PlasmaBoxConfig box;
};

extern const int plasmaEntity;

extern const PlasmaEntityConfig plasmaDefaultEntityConfig;

void plasmaCreateEntity(PlasmaWindow * window, PlasmaEntity * target, PlasmaEntityConfig * config);
