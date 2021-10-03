#pragma once

#define PLASMA_INFO	"INFO: PLASMA: "
#define PLASMA_WARNING "WARNING: PLASMA: "
#define PLASMA_ERROR   "ERROR: PLASMA: "
#define PLASMA_FATAL   "FATAL: PLASMA: "

void plasmaInitialize(void);
void plasmaTerminate(void);

void plasmaErrornDie(const char * message);
