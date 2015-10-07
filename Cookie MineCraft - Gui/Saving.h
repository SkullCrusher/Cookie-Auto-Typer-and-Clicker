#pragma once
#include "stdafx.h"

bool SaveAll()
{
	/*
		Saved file template.

   Which spam- Text to be spamed - Delay (K) - Delay (E)
		001:"SPAM TEXT GOES HERE":0001:0001:

	
	NOTE work on this when mouse is done.
	*/


	ofstream myfile;
	// Needs To take the file path from the textbox.
	myfile.open ("C:\\Ace of Spades\\example2.txt");
	
	myfile << Base;

	myfile.close();

}









/*
 ofstream myfile;
	 myfile.open ("C:\\Ace of Spades\\example2.txt");
	 myfile << Base;
	 myfile.close();
*/