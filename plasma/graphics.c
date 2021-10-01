#include <plasma/graphics.h>
#include <plasma/plasma.h>
#include <plasma/macro.h>
#include <plasma/sdl.h>

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

struct PlasmaWindow {
    PlasmaWindowConfig * source;

	bool active;

    char payload[];
};

const int plasmaWindow = sizeof(PlasmaWindow);

const PlasmaWindowConfig plasmaDefaultWindowConfig = { NULL, 0, 0, &plasmaSDL, PLASMA_WINDOW_VISIBLE};

void plasmaCreateWindow(PlasmaWindow * target, PlasmaWindowConfig * config)
{
	plasmaAssert(target, "Cannot create window targeting NULL!");
	plasmaAssert(config, "Cannot create window with NULL configuration!");
	plasmaAssert(config->driver, "Cannot create window with NULL driver!");

	target->source = config;
	target->active = true;

	config->driver->initialize(target, target->payload);

    puts(PLASMA_INFO "Created window.");
}

void plasmaExecuteWindow(PlasmaWindow * window, PlasmaCallback * update, void * arg)
{
	plasmaAssert(window, PLASMA_FATAL "Cannot execute NULL window!");

    puts(PLASMA_INFO "Executing window...");

	const PlasmaWindowDriver * driver = window->source->driver;

    do {
		driver->update(window->payload);

        if(update) update(arg);
    } while(window->active);
}

void plasmaDeactivateWindow(PlasmaWindow * window)
{
	window->active = false;
}