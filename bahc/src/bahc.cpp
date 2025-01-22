#include "bahc.h"
#include "bahasavm.h"

using namespace std;

int main() {
	say_hello();
	VirtualMachine::run();
	return 0;
}
