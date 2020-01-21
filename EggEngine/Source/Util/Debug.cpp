#include "Debug.h"
#include <Windows.h>

void API debug_popup(const char* message)
{
	MessageBoxA(0, message, "Egg", MB_OK);
}
