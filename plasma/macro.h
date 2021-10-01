#pragma once

#include <plasma/plasma.h>

#define plasmaAssert(condition, msg) if(! condition) plasmaErrornDie(PLASMA_FATAL msg)