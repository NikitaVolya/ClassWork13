
#include <iostream>

#include "BinaryTree.h"

int main()
{

	BinaryTree<int> testTree { 15, 25, 11, 3, 8, 68, 45};

	std::cout << testTree.find(45) << std::endl;
	testTree.printINFIX(std::cout);

	return 0;
}