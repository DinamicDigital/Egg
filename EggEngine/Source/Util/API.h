#pragma once

#ifdef EGG_EXPORT
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif
