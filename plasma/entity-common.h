#pragma once

#include <plasma/plasma.h>

#define PLASMA_ENTITY_UNDEFINED 0
#define PLASMA_ENTITY_BOX	    1

typedef struct PlasmaEntity PlasmaEntity;

typedef union PlasmaEntityConfig PlasmaEntityConfig;

typedef void PlasmaEntityInitializer(PlasmaEntity * entity, const PlasmaEntityConfig * config);
typedef void PlasmaEntityCallback(PlasmaEntity * entity);

typedef struct PlasmaEntityDriver {
	PlasmaEntityInitializer * initialize;
	PlasmaEntityCallback * update;
} PlasmaEntityDriver;

typedef struct PlasmaEntityCommon { 
	union {
	    const PlasmaEntityDriver * driver;
	    int type;
	};
} PlasmaEntityCommon;
