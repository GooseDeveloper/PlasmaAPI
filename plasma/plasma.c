#include <plasma/plasma.h>

#include <stdio.h>

void plasmaInitialize(void)
{
    puts(PLASMA_INFO "Plasma initialized.");
}

void plasmaTerminate(void)
{
    puts(PLASMA_INFO "Plasma terminated.");
}