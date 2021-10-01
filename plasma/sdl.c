#include <plasma/graphics.h>
#include <plasma/plasma.h>
#include <plasma/sdl.h>

#include <stdio.h>
#include <stdbool.h>

typedef struct PlasmaSDLWindow {
    PlasmaWindow * source;
} PlasmaSDLWindow;

const int plasmaSDLWindow = sizeof(PlasmaSDLWindow);

static void initializeSDLWindow(PlasmaWindow * window, PlasmaSDLWindow * state);
static void updateSDLWindow(PlasmaSDLWindow * window);

const PlasmaWindowDriver plasmaSDL = { (PlasmaDriverInitializer *) &initializeSDLWindow, (PlasmaCallback *) &updateSDLWindow };

static void initializeSDLWindow(PlasmaWindow * window, PlasmaSDLWindow * state)
{
    puts(PLASMA_INFO "Window type: SDL");

    state->source = window;
}

static void updateSDLWindow(PlasmaSDLWindow * window)
{
    plasmaDeactivateWindow(window->source);
}

