#include <plasma/plasma.h>
#include <plasma/sdl.h>

#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

int main(void)
{
	plasmaInitialize();

	PlasmaWindow * window = alloca(plasmaWindow + plasmaSDLWindow);

	PlasmaWindowConfig config = plasmaDefaultWindowConfig;
	config.title = "Plasma";
	config.width = config.height = 500;
	config.flags |= PLASMA_SDL_CENTERED;

	plasmaCreateWindow(window, &config);

	plasmaExecuteWindow(window, NULL, NULL);

	plasmaTerminate();
	return EXIT_SUCCESS;
}
