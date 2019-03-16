#include <iostream>
#include "Stack.h"

using namespace std;

int main(void) {

	CStack stack;

	stack.push(5);
	stack.push(3);
	stack.push(7);
	stack.push(10);
	stack.push(2);

	std::cout << stack.pop() << std::endl;
	std::cout << stack.size() << std::endl;
	std::cout << stack.isEmptyStack() << std::endl;
	std::cout << stack.top() << std::endl;

	return 0;
}