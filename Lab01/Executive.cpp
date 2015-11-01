/**
@File Executive.cpp
Reads in the files and calls the actions desired
@author Young Liu
@date Sept. 18 2013
*/



#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive() //constructor
{
}

int Executive::create(char* input)
{
	ifstream inp(input);//reads from first file
	double thing;

	int count=0; //initializes the count, so the program can count
	while (inp >> thing) //loop for constant reading
	{
		if (thing > 20)
		{
			//if there are more than 20 polynomials, it will display this message     
			cout << "You cannot have a degree that is over 20" << endl;
			return -1; //and then it will move on
		}

		//ensures there's not more than 10 polynomial
		if (count>MAX_NUM_POLYNOMIAL)
		{
			cout << "You cannot have over 10 polynomials"<< endl;
			break;
		}

	double tempc[MAX_DEGREE + 1];

		//this loop runs as many times as there are coeff
		for (int k=0; k<=thing; k++)
		{		
			//sets the different coeff in array
		inp >> tempc[k];
		}

	//gives the coeff to polynomial
	poly[count] = Polynomial((int)thing, tempc);

	//counts up everytime the loop runs
	count++;        
	}

	return 0;
}

void Executive::work(char* input)
{
	string thing;
	int num;
	ifstream inp(input);//reading from second file
	while (inp>> thing)
	{
		if (thing=="print")
		{
		inp>>num;
			if (num<0 || num>=10)
			{//makes sure you're not trying 
				//to call a polynomial that does not exist
				cout << "That polynomial does not exist" << endl;     
			}else       

		poly[num].print(cout);
		}
		else if (thing=="evaluate")
		{
			inp >> num;
			if (num<0 || num>=10)
			{//makes sure you're not trying 
				//to call a polynomial that does not exist
				cout << "That polynomial does not exist" << endl;     
			}
			else
			{
				double c; 
				inp >> c;
				double answer = poly[num].evaluate(c); //evaluates at function
				cout << answer << endl; 
			}
		}
		else if (thing=="add")
		{
			int r;
			inp>>num;
			inp>>r;

			if (num<0 || num>=10)//makes sure you're not trying
			{ 
				//to call a polynomial that does not exist
				cout << "That polynomial does not exist" << endl;     
			}

			Polynomial p3= poly[num].add(poly[r]);
			p3.print(cout);
		}
		else if (thing=="differentiate")
		{
			inp>>num;
			if (num<0 || num>=10)
			{
				//makes sure you're not trying 
				//to call a polynomial that does not exist
				cout << "That polynomial does not exist" << endl;     
			}
			else
			{
				poly[num].differentiate().print(cout);
			}
		}
	}
}
