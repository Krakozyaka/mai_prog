#include <iostream>
#include <vector>
#include "List.h"


int main()
{
	List<string> krab;
	krab.InsertNode("Claw", 0);
	krab.InsertNode("Eyes", 0);
	krab.InsertNode("Mouth", 0);
	krab.RemoveNode(0);
	krab.InsertNode("Legs", 0);
	krab.PrintList();
}