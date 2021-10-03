#pragma once

#define PLASMA_WINDOW_VISIBLE (1 << 0)

typedef struct PlasmaWindow PlasmaWindow;

typedef void PlasmaCallback(void * arg);
typedef void PlasmaDriverInitializer(PlasmaWindow * window, void * arg);

typedef struct PlasmaWindowDriver {
	PlasmaDriverInitializer * initialize;
	PlasmaCallback * update;
} PlasmaWindowDriver;

typedef struct PlasmaWindowConfig {
	const char * title;
	int width, height;

	const PlasmaWindowDriver * driver;

	int flags;
} PlasmaWindowConfig;

extern const int plasmaWindow;

extern const PlasmaWindowConfig plasmaDefaultWindowConfig;

void plasmaCreateWindow(PlasmaWindow * target, PlasmaWindowConfig * config);
void plasmaExecuteWindow(PlasmaWindow * window, PlasmaCallback * update, void * arg);

void plasmaDeactivateWindow(PlasmaWindow * window);

const PlasmaWindowConfig * plasmaGetWindowConfig(PlasmaWindow * window);
