#include <plasma/box.h>
#include <plasma/entity.h>

struct PlasmaBox {
	const PlasmaEntityConfig * source;
};

const int plasmaBoxEntity = sizeof(PlasmaBox);

static void initializeBox(PlasmaEntity * box, const PlasmaEntityConfig * config);
static void updateBox(PlasmaEntity * box);

const PlasmaEntityDriver plasmaBoxDriver = { &initializeBox, &updateBox };

static void initializeBox(PlasmaEntity * box, const PlasmaEntityConfig * config)
{
	puts(PLASMA_INFO "Entity type: box");
}

static void updateBox(PlasmaEntity * box)
{

}