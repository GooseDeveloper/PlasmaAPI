#include <plasma/plasma.h>
#include <plasma/sdl.h>
#include <plasma/entity.h>

#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

int main(void)
{
	plasmaInitialize();

	PlasmaWindow * window = alloca(plasmaWindow + plasmaSDLWindow);
	PlasmaEntity * box = alloca(plasmaEntity + plasmaBoxEntity);

	PlasmaWindowConfig windowConfig = plasmaDefaultWindowConfig;
	windowConfig.title = "Plasma";
	windowConfig.width = windowConfig.height = 800;
	windowConfig.flags |= PLASMA_SDL_CENTERED;

	PlasmaEntityConfig entityConfig = plasmaDefaultEntityConfig;
	entityConfig.common.type = PLASMA_ENTITY_BOX;
	entityConfig.box.width = entityConfig.box.height = 100;
	entityConfig.box.xpos = entityConfig.box.ypos = 100;

	plasmaCreateWindow(window, &windowConfig);
	plasmaCreateEntity(window, box, &entityConfig);

	plasmaExecuteWindow(window, NULL, NULL);

	plasmaTerminate();
	return EXIT_SUCCESS;
}
