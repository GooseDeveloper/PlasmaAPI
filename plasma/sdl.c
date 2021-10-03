#include <plasma/graphics.h>
#include <plasma/plasma.h>
#include <plasma/sdl.h>
#include <plasma/macro.h>

#include <SDL.h>

#include <stdio.h>
#include <stdbool.h>

typedef struct PlasmaSDLWindow {
	PlasmaWindow * source;

	SDL_Window * window;
	SDL_Renderer * renderer;
} PlasmaSDLWindow;

const int plasmaSDLWindow = sizeof(PlasmaSDLWindow);

static void initializeSDLWindow(PlasmaWindow * window, PlasmaSDLWindow * state);
static void updateSDLWindow(PlasmaSDLWindow * window);

const PlasmaWindowDriver plasmaSDL = { (PlasmaDriverInitializer *) &initializeSDLWindow, (PlasmaCallback *) &updateSDLWindow };

static void initializeSDLWindow(PlasmaWindow * window, PlasmaSDLWindow * state)
{
	static bool initialized = false;

	puts(PLASMA_INFO "Window type: SDL");

	if(! initialized) {
	    int status = SDL_Init(SDL_INIT_EVERYTHING);
	    plasmaAssert(status >= 0, PLASMA_SDL "Failed to initialize SDL!");
	}

	state->source = window;

	const PlasmaWindowConfig * config = plasmaGetWindowConfig(window);

	int xpos = config->flags & PLASMA_SDL_CENTERED ? SDL_WINDOWPOS_CENTERED : SDL_WINDOWPOS_UNDEFINED;
	int ypos = config->flags & PLASMA_SDL_CENTERED ? SDL_WINDOWPOS_CENTERED : SDL_WINDOWPOS_UNDEFINED;

	int flags = (
	    (config->flags & PLASMA_WINDOW_VISIBLE ? SDL_WINDOW_SHOWN : 0)
	);

	state->window = SDL_CreateWindow(
	    config->title,
	    xpos, ypos,
	    config->width, config->height,
	    flags
	);

	state->renderer = SDL_CreateRenderer(state->window, -1, 0);

	if(! state->window) {
	    fprintf(stderr, PLASMA_ERROR PLASMA_SDL "%s\n", SDL_GetError());
	    plasmaErrornDie(PLASMA_FATAL PLASMA_SDL "Failed to create SDL window!");
	}
}

static void updateSDLWindow(PlasmaSDLWindow * window)
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
	    if(event.type == SDL_QUIT) {
	        puts(PLASMA_INFO PLASMA_SDL "Window closed by user.");
	        plasmaDeactivateWindow(window->source);
	    }
	}
}

