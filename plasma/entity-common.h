#pragma once

#include <plasma/plasma.h>

#define PLASMA_ENTITY_UNDEFINED 0
<<<<<<< HEAD
#define PLASMA_ENTITY_BOX	    1
=======
#define PLASMA_ENTITY_BOX	   1
>>>>>>> 2cf6e3b6f2147218131ee073c156a81a693a2a7e

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
