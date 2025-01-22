// bahasavm.cpp : Defines the entry point for the application.
//

#include "bahasavm.h"
#include <iostream>

using namespace std;

void VirtualMachine::run() {
    // Implementation of the static method
    std::cout << "VirtualMachine is running!" << std::endl;
}

void say_hello() {
    std::cout << "Hello from bahasavm!" << std::endl;
}
