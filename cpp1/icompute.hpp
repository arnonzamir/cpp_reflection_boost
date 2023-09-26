#pragma once

#ifdef WIN32
    #define EXPORT_SYMBOL __declspec(dllexport)
#else
    #define EXPORT_SYMBOL
#endif

extern "C" {
    EXPORT_SYMBOL int compute(int a, int b);
}
