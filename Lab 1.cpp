// Lab 1.cpp
// Nico Shober
// September 17, 2018
// COSC II
//first actual lab
#include "stdafx.h"
#include<iostream>
#include<string>

#include <fstream>

using namespace std;

int main()
{
	int a, b, c, d, count = 0, input; //first,second, second to last, and last variables along with count  = 0 and input

	ifstream myFile;
	string filename;

	cout << "Enter a Filename: " << endl;
	cin >> filename;
	myFile.open(filename);

	if (!myFile) //testing to see if the file opens
	{
		cout << "The file could not be opened." << endl;
		exit(1);
	}

	while (!myFile.eof()) //reading until the end of the file
	{
		myFile >> input;
		if (!myFile.fail())
		{

			if (count == 0)
			{
				a = input; //a = first number
				d = input; //d = the last number read
			}
			if (count == 1)
			{
				b = input; //the second number
				c = d; //setting the second to last number as the previous last number
				d = input; //d = the last number read
			}
			if (count > 1)
			{
				c = d; //setting the second to last number as the previous last number
				d = input; //d = the last number read
			}
			count++;
		}
	}
	myFile.close(); //closing the file after completion
	cout << "first: " << a << " second: " << b << " second to last: " << c << " last number: " << d << " number of ints: " << count << endl;


	return 0;
}

