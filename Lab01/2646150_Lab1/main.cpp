/**
@File main.cpp
calls the executive to read the files
@author Young Liu
@date Sept. 18 2013
*/
#include "Executive.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Executive e2;
	e2.create(argv[1]); //reads from file 1 and creates polynomials
	e2.work(argv[2]); //reads from file 2 to know what to do

return 0;
}


