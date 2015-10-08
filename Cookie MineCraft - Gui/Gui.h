#pragma once
#include "stdafx.h"

/*	Updates the Chat text and time.	*/ 

string Globle_text_Test; // Testing has no use.

string TextToSpam[9];   // Globle string. 

string TempTimeAsString[9];// Globle string.
int TextDelayValue[9];     // Globle value.

string TempTimeAsString2[9];  // Globle string.
int TextDelayValueForKey[9];  // Globle value.

vector<string> LableText;

bool LoadLableText()
{
	LableText.push_back("Numpad 1");
	LableText.push_back("Numpad 2");
	LableText.push_back("Numpad 3");
	LableText.push_back("Numpad 4");
	LableText.push_back("Numpad 5");
	LableText.push_back("Numpad 6");
	LableText.push_back("Numpad 7");
	LableText.push_back("Numpad 8");
	LableText.push_back("Numpad 9");

	return 0;
}


string ReqLableText(int Which)
{
	string Value = LableText[Which - 1];

	return Value;
}


bool LoadTimeStringForKey(string Load, int slot)
{

	slot--;
	TempTimeAsString2[slot] = Load;

	std::string myString = Load;
	TextDelayValueForKey[slot] = atoi(myString.c_str());

	return true;
}

bool LoadTimeString(string Load, int slot)
{

	slot--;
	TempTimeAsString[slot] = Load;

	std::string myString = Load;
	TextDelayValue[slot] = atoi(myString.c_str()); 

	return true;
}

bool ChangeTextToSpam(string Load, int slot)
{
	slot--;

	TextToSpam[slot] = Load; 

	return true;
}

