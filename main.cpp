
#include <iostream>

#include "BinaryTree.h"

int main()
{

	BinaryTree<int> testTree;
	testTree.add(8);
	testTree.add(12);
	testTree.add(45);
	testTree.add(1);

	std::cout << testTree.find(45) << std::endl;
	testTree.printINFIX(std::cout);

	return 0;
}