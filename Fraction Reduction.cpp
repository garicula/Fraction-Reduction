// Garrick Morley
// CPSC 200 Project 3 A
// This program reduces fractions

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <cassert>
using namespace std;

//this function obtains the greatest common denominator
int gcd(int num, int dom)
{
	if (dom == 0)
    	return num;
    return gcd(dom, num % dom);
}

//this function reduces the numbers in a fraction
//this is a pass by reference function
double reduce(int &numer, int &denom) 
{
	int common = gcd(numer, denom);
	numer = numer / common;
	denom = denom / common;
}

//run everything in main
main()
{
	//declare all the variables
	int numerator = 0;
	int denominator = 0;
	int originalN = 0;
	int originalD = 0;
	
	//get the inputs for the numerator and denominator
	cout << "Enter the numerator: " << endl;
	cin >> numerator;
	
	cout << "Enter the denominator: " << endl;
	cin >> denominator;

	//print undefined if they try to reduce 0/0
	if (numerator == 0 && denominator == 0)
		{
			cout << "Undefined" << endl;
			exit(1);
		}
	
	//set variables for the original values
	originalN = numerator;
	originalD = denominator;
	
	//run the functions from above
	gcd(numerator, denominator);
	reduce(numerator, denominator);	

	//fix the negatives as instructed
	if (numerator > 0 && denominator > 0)
		int x = 1;
		//do nothing
	else if (denominator < 0 && numerator < 0)
	{
		//flip both signs
		numerator *= -1;
		denominator *= -1;
	}
	else if (denominator < 0 && numerator > 0)
	{
		//flip both signs
		numerator *= -1;
		denominator *= -1;	
	}
	else if (denominator > 0 && numerator < 0)
		//do nothing
		int y = 1;
	
	
	//check for special cases and print the results	
	if (denominator == 0)
		cout << "Undefined" << endl;
	else if (numerator == 0)
		cout << 0 << endl;
	else if (denominator == 1)	
		cout << originalN << "/" << originalD << " = " << numerator / denominator << endl;
	//if there's no special cases then print normally
	else
		cout << originalN << "/" << originalD << " = " << numerator << "/" << denominator << endl;
}
