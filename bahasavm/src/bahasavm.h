// bahasavm.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#ifdef _WIN32
#  ifdef BAHASAVM_EXPORTS
#    define BAHASAVM_API __declspec(dllexport)
#  else
#    define BAHASAVM_API __declspec(dllimport)
#  endif
#else
#  define BAHASAVM_API
#endif

class BAHASAVM_API VirtualMachine {
public:
    static void run();
};

extern "C" BAHASAVM_API void say_hello();
