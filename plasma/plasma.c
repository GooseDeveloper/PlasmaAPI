#include <plasma/plasma.h>

#include <stdio.h>
#include <stdlib.h>

void plasmaInitialize(void)
{
	puts(PLASMA_INFO "Initializing plasma...");
}

void plasmaTerminate(void)
{
	puts(PLASMA_INFO "Plasma terminated.");
}

void plasmaErrornDie(const char * message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}