#pragma once

#include <plasma/entity-common.h>

typedef struct PlasmaBox PlasmaBox;

typedef struct PlasmaBoxConfig {
    int width, height;
    int xpos, ypos;
} PlasmaBoxConfig;

extern const int plasmaBoxEntity;

extern const PlasmaEntityDriver plasmaBoxDriver;

void plasmaCreateBox(PlasmaEntity * target, const PlasmaEntityConfig * config);
