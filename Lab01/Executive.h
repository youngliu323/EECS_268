/**
@File Executive.cpp
method and constructor names
@author Young Liu
@date Sept. 18 2013
*/

#include "Polynomial.h"

class Executive
{
private:
    static const int MAX_NUM_POLYNOMIAL = 10; //sets limit to how many polys there can be
    Polynomial poly[MAX_NUM_POLYNOMIAL]; //the number of polynomials created

public: 
    Executive();
    int create(char* input);//creates the different polynomial classes
    void work(char* input); //does the functions of the file it reads next
};


