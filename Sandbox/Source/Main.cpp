#include <Egg.h>

int main()
{
	WindowSettings* winSettings = {};
	winSettings->caption = (char*) "Eggventure";
	winSettings->width = 800;
	winSettings->height = 600;
	winSettings->resizable = true;

	setWindowSettings(winSettings);
	StartEngine();
	
	return 0;
}