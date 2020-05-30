#include "MusicBeeper.hpp"

int main(void)
{
	PREVENT_BEEP_LOOP;

	// ...
	MusicBeeper::BeepGoT();
	MusicBeeper::BeepImperialMarch();
	MusicBeeper::BeepSovietAnthem();
	MusicBeeper::BeepOdeToJoy();

	return 0;
};