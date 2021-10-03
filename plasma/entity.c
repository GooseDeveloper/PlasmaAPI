#include <plasma/entity.h>
#include <plasma/macro.h>

#include <stddef.h>

struct PlasmaEntity {
	const PlasmaEntityConfig * source;
	PlasmaWindow * parent;
};

const int plasmaEntity = sizeof(PlasmaEntity);

const PlasmaEntityConfig plasmaDefaultEntityConfig = { (PlasmaEntityCommon) { PLASMA_ENTITY_UNDEFINED } };

static const PlasmaEntityDriver * const drivers[] = {
	NULL, 

	&plasmaBoxDriver
};
static const int numDrivers = sizeof(drivers) / sizeof(PlasmaEntityDriver *); 

void plasmaCreateEntity(PlasmaWindow * window, PlasmaEntity * target, PlasmaEntityConfig * config)
{
	target->source = config;
	target->parent = window;

	int entityType = config->common.type;

	plasmaAssert(entityType <= numDrivers, PLASMA_FATAL "Invalid entity type!");

	config->common.driver = drivers[entityType];
}

