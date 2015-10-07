/*
	KeyData.h - future self looking back on this I believe this tracks the trigger keys to see if they are pressed.		

*/
#pragma once
#include "stdafx.h" 
#include "Form1.h"

using namespace CookieMineCraftGui;


//Added 12/24/2012
int MouseClickDelayLEFT = 10;  
int MouseClickDelayMIDDLE = 10;
int MouseClickDelayRIGHT = 10;  
//TEXTBOX28 - LEFT  ||
//TEXTBOX29 - MIDDLE||
//TEXTBOX30 - RIGHT ||
void SetMouseDelay(std::string Which, char TextArg[256]){

	std::string myString = TextArg;
	int value = atoi(myString.c_str()); //value = 459
	if(value > 0){
		if(Which == "LEFT"){
			MouseClickDelayLEFT = value;
			return;
		}
		if(Which == "RIGHT"){
			MouseClickDelayRIGHT = value;
			return;
		}
		if(Which == "MIDDLE"){
			MouseClickDelayMIDDLE = value;
			return;
		}
	}
	
}

//The set keys for each spam: To change which key update these.
int KeyForText1 = 0x61;
int KeyForText2 = 0x62;
int KeyForText3 = 0x63;
int KeyForText4 = 0x64;
int KeyForText5 = 0x65;
int KeyForText6 = 0x66;
int KeyForText7 = 0x67;
int KeyForText8 = 0x68;
int KeyForText9 = 0x69;

int MouseKeyCodeLeft = 0x00;
int MouseKeyCodeMiddle = 0x00;
int MouseKeyCodeRight = 0x00;

//The key choose function data.

vector<string> KeyName;
vector<int> KeyHexValue;

DWORD WINAPI ThreadKeyData(LPVOID);
HANDLE ThreadKey;
DWORD ThreadIDKEY;

//ThreadKey = CreateThread(NULL, 0, ThreadKeyData, (LPVOID)1, 0, &ThreadIDKEY);

bool ThreadInUse = false;
string ThreadWhichToChange;

//This waits for the next key to be pressed - NOTE there is no time out.
DWORD WINAPI ThreadKeyData(LPVOID)
{
	for(;;)
	{
		SwitchSelectingNewKey(true);
		int NewKey = SetKey(); // NOTE SETKEY DOES NOT SUPPORT a-Z + 0-9. Please change. (Update i think i fixed that.)
		if(NewKey != 0x00){
					
			//Sadly i have to hard code each in.
			if(ThreadWhichToChange == "L1"){
				KeyForText1 = NewKey;

				LableText[0] = FindNameForKey(NewKey); // it's [0] because it's 0-8
			}

			if(ThreadWhichToChange == "L2"){
				KeyForText2 = NewKey;

				LableText[1] = FindNameForKey(NewKey); // it's [1] because it's 0-8
			}

			if(ThreadWhichToChange == "L3"){
				KeyForText3 = NewKey;

				LableText[2] = FindNameForKey(NewKey); // it's [2] because it's 0-8
			}

			if(ThreadWhichToChange == "L4"){
				KeyForText4 = NewKey;

				LableText[3] = FindNameForKey(NewKey); // it's [3] because it's 0-8
			}

			if(ThreadWhichToChange == "L5"){
				KeyForText5 = NewKey;

				LableText[4] = FindNameForKey(NewKey); // it's [4] because it's 0-8
			}

			if(ThreadWhichToChange == "L6"){
				KeyForText6 = NewKey;

				LableText[5] = FindNameForKey(NewKey); // it's [5] because it's 0-8
			}

			if(ThreadWhichToChange == "L7"){
				KeyForText7 = NewKey;

				LableText[6] = FindNameForKey(NewKey); // it's [6] because it's 0-8
			}

			if(ThreadWhichToChange == "L8"){
				KeyForText8 = NewKey;

				LableText[7] = FindNameForKey(NewKey); // it's [7] because it's 0-8
			}

			if(ThreadWhichToChange == "L9"){
				KeyForText9 = NewKey;

				LableText[8] = FindNameForKey(NewKey); // it's [8] because it's 0-8
			}

				SwitchSelectingNewKey(false);
				ThreadInUse = false;

				/*Added 1/1/2013 - HAPPY NEW YEAR :D
				** Ok so basicly the key was getting stuck down.. or? something so we make sure it unsticks by pressing up for the user.
				**
				**
				*/
				INPUT ip;

				ip.type = INPUT_KEYBOARD;
				ip.ki.wScan = NewKey; // hardware scan code for key
				ip.ki.time = 0;
				ip.ki.dwExtraInfo = 0;

				
				ip.ki.wVk = 0;
				//ip.ki.dwFlags = KEYEVENTF_UNICODE; 
				//SendInput(1, &ip, sizeof(INPUT));
								
				ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &ip, sizeof(INPUT));



				return 1;
			
		}

		Sleep(1);
	}

		return 0;
}

//just a loop to find the right one.
string FindNameForKey(int KeyCode)
{
	string Name = "null";

	int loop = 0;
	while(Name == "null")
	{
		if(KeyCode == KeyHexValue[loop])
		{
			Name = KeyName[loop];
		}else{
			loop++;
		}		
	}

	return Name;
}

//Note this just checks to see if it can start the thread so we don't have more then one up.
bool Start_SetKey(string WhichToChange, int SwitchLable)
{
	if(ThreadInUse)
	{return false;}else{
		LableText[SwitchLable] = "-";
		ThreadWhichToChange = WhichToChange;
		ThreadKey = CreateThread(NULL, 0, ThreadKeyData, (LPVOID)1, 0, &ThreadIDKEY);
		return true;
	}
	return false;
}

int SetKey()
{
	int loop = 1;
	int size = KeyHexValue.size();
	int KeyTemp = 0x00;
	while(loop < size)
	{
		int KeyTemp = KeyHexValue[loop];
		if(GetAsyncKeyState(KeyTemp)) 
		{
			return KeyHexValue[loop];
			break;
			
		}

		loop++;
	}

	return 0x0;
}

int LoadKeys()
{
	KeyName.push_back("Left Click");
	KeyHexValue.push_back(0x01);

	KeyName.push_back("Right Click");
	KeyHexValue.push_back(0x02);

	KeyName.push_back("Middle Click");
	KeyHexValue.push_back(0x04);

	KeyName.push_back("BackSpace");
	KeyHexValue.push_back(0x08);

	KeyName.push_back("Tab");
	KeyHexValue.push_back(0x09);

	KeyName.push_back("Clear Key");
	KeyHexValue.push_back(0x0C);

	KeyName.push_back("Enter Key");
	KeyHexValue.push_back(0x0D);

	KeyName.push_back("Shift Key");
	KeyHexValue.push_back(0x10);

	KeyName.push_back("CTRL Key");
	KeyHexValue.push_back(0x11);

	KeyName.push_back("ALT Key");
	KeyHexValue.push_back(0x12);

	KeyName.push_back("Pause Key");
	KeyHexValue.push_back(0x13);

	KeyName.push_back("Cap Lock");
	KeyHexValue.push_back(0x14);

	KeyName.push_back("ESC Key");
	KeyHexValue.push_back(0x1B);

	KeyName.push_back("Space key");
	KeyHexValue.push_back(0x20);

	KeyName.push_back("Page up");
	KeyHexValue.push_back(0x21);

	KeyName.push_back("Page down");
	KeyHexValue.push_back(0x22);

	KeyName.push_back("End Key");
	KeyHexValue.push_back(0x23);

	KeyName.push_back("Home Key");
	KeyHexValue.push_back(0x24);

	KeyName.push_back("Left Arrow");
	KeyHexValue.push_back(0x25);

	KeyName.push_back("Up Arrow");
	KeyHexValue.push_back(0x26);

	KeyName.push_back("Right Arrow");
	KeyHexValue.push_back(0x27);

	KeyName.push_back("Down Arrow");
	KeyHexValue.push_back(0x28);

	KeyName.push_back("Select Key");
	KeyHexValue.push_back(0x29);

	KeyName.push_back("Execute Key");
	KeyHexValue.push_back(0x2B);

	KeyName.push_back("Print Screen");
	KeyHexValue.push_back(0x2C);

	KeyName.push_back("Insert Key");
	KeyHexValue.push_back(0x2D);

	KeyName.push_back("Delete Key.");
	KeyHexValue.push_back(0x2E);

	KeyName.push_back("Help Key");
	KeyHexValue.push_back(0x2F);

	KeyName.push_back("Left Windows");
	KeyHexValue.push_back(0x5B);

	KeyName.push_back("Right Windows");
	KeyHexValue.push_back(0x5C);

	KeyName.push_back("App Key");
	KeyHexValue.push_back(0x5D);

	KeyName.push_back("Numpad 0");
	KeyHexValue.push_back(0x60);

	KeyName.push_back("Numpad 1");
	KeyHexValue.push_back(0x61);

	KeyName.push_back("Numpad 2");
	KeyHexValue.push_back(0x62);

	KeyName.push_back("Numpad 3");
	KeyHexValue.push_back(0x63);

	KeyName.push_back("Numpad 4");
	KeyHexValue.push_back(0x64);

	KeyName.push_back("Numpad 5");
	KeyHexValue.push_back(0x65);

	KeyName.push_back("Numpad 6");
	KeyHexValue.push_back(0x66);

	KeyName.push_back("Numpad 7");
	KeyHexValue.push_back(0x67);

	KeyName.push_back("Numpad 8");
	KeyHexValue.push_back(0x68);

	KeyName.push_back("Numpad 9");
	KeyHexValue.push_back(0x69);

	KeyName.push_back("Multiply Key");
	KeyHexValue.push_back(0x6A);

	KeyName.push_back("Add key");
	KeyHexValue.push_back(0x6B);

	KeyName.push_back("Separator Key");
	KeyHexValue.push_back(0x6C);

	KeyName.push_back("Subtract Key");
	KeyHexValue.push_back(0x6D);

	KeyName.push_back("Decimal key");
	KeyHexValue.push_back(0x6E);

	KeyName.push_back("Divide key");
	KeyHexValue.push_back(0x6F);

	KeyName.push_back("F1");
	KeyHexValue.push_back(0x70);

	KeyName.push_back("F2");
	KeyHexValue.push_back(0x71);

	KeyName.push_back("F3");
	KeyHexValue.push_back(0x72);

	KeyName.push_back("F4");
	KeyHexValue.push_back(0x73);

	KeyName.push_back("F5");
	KeyHexValue.push_back(0x74);
	
	KeyName.push_back("F6");
	KeyHexValue.push_back(0x75);

	KeyName.push_back("F7");
	KeyHexValue.push_back(0x76);

	KeyName.push_back("F8");
	KeyHexValue.push_back(0x77);

	KeyName.push_back("F9");
	KeyHexValue.push_back(0x78);
	
	KeyName.push_back("F10");
	KeyHexValue.push_back(0x79);

	KeyName.push_back("F11");
	KeyHexValue.push_back(0x7A);

	KeyName.push_back("F12");
	KeyHexValue.push_back(0x7B);

	KeyName.push_back("F13");
	KeyHexValue.push_back(0x7C);

	KeyName.push_back("F14");
	KeyHexValue.push_back(0x7D);

	KeyName.push_back("F15");
	KeyHexValue.push_back(0x7E);

	KeyName.push_back("F16");
	KeyHexValue.push_back(0x7F);

	KeyName.push_back("F17");
	KeyHexValue.push_back(0x80);

	KeyName.push_back("F18");
	KeyHexValue.push_back(0x81);

	KeyName.push_back("F19");
	KeyHexValue.push_back(0x82);

	KeyName.push_back("F20");
	KeyHexValue.push_back(0x83);

	KeyName.push_back("F21");
	KeyHexValue.push_back(0x84);

	KeyName.push_back("F22");
	KeyHexValue.push_back(0x85);

	KeyName.push_back("F23");
	KeyHexValue.push_back(0x86);

	KeyName.push_back("F24");
	KeyHexValue.push_back(0x87);

	KeyName.push_back("Num Lock");
	KeyHexValue.push_back(0x90);

	KeyName.push_back("Scroll lock");
	KeyHexValue.push_back(0x91);

	KeyName.push_back("Left Shift");
	KeyHexValue.push_back(0xA0);

	KeyName.push_back("Right Shift");
	KeyHexValue.push_back(0xA1);

	KeyName.push_back("Left CTRL");
	KeyHexValue.push_back(0xA2);

	KeyName.push_back("Right CTRL");
	KeyHexValue.push_back(0xA3);

	KeyName.push_back("Left ALT");
	KeyHexValue.push_back(0xA4);

	KeyName.push_back("Right ALT");
	KeyHexValue.push_back(0xA5);

	KeyName.push_back("ATTN Key");
	KeyHexValue.push_back(0xF6);

	KeyName.push_back("CRSEL Key");
	KeyHexValue.push_back(0xF7);

	KeyName.push_back("VK_EXSEL");
	KeyHexValue.push_back(0xF8);

	KeyName.push_back("VK_EREOF");
	KeyHexValue.push_back(0xF9);

	KeyName.push_back("Play key");
	KeyHexValue.push_back(0xFA);

	KeyName.push_back("Zoom key");
	KeyHexValue.push_back(0xFB);

	KeyName.push_back("Clear key");
	KeyHexValue.push_back(0xFE);

	KeyName.push_back("0");
	KeyHexValue.push_back(0x30);

	KeyName.push_back("1");
	KeyHexValue.push_back(0x31);

	KeyName.push_back("2");
	KeyHexValue.push_back(0x32);

	KeyName.push_back("3");
	KeyHexValue.push_back(0x33);

	KeyName.push_back("4");
	KeyHexValue.push_back(0x34);

	KeyName.push_back("5");
	KeyHexValue.push_back(0x35);

	KeyName.push_back("6");
	KeyHexValue.push_back(0x36);

	KeyName.push_back("7");
	KeyHexValue.push_back(0x37);

	KeyName.push_back("8");
	KeyHexValue.push_back(0x38);

	KeyName.push_back("9");
	KeyHexValue.push_back(0x39);

	KeyName.push_back("a");
	KeyHexValue.push_back(0x41);

	KeyName.push_back("b");
	KeyHexValue.push_back(0x42);

	KeyName.push_back("c");
	KeyHexValue.push_back(0x43);

	KeyName.push_back("d");
	KeyHexValue.push_back(0x44);

	KeyName.push_back("e");
	KeyHexValue.push_back(0x45);

	KeyName.push_back("f");
	KeyHexValue.push_back(0x46);

	KeyName.push_back("g");
	KeyHexValue.push_back(0x47);

	KeyName.push_back("h");
	KeyHexValue.push_back(0x48);

	KeyName.push_back("i");
	KeyHexValue.push_back(0x49);

	KeyName.push_back("j");
	KeyHexValue.push_back(0x4A);

	KeyName.push_back("k");
	KeyHexValue.push_back(0x4B);

	KeyName.push_back("l");
	KeyHexValue.push_back(0x4C);

	KeyName.push_back("m");
	KeyHexValue.push_back(0x4D);

	KeyName.push_back("n");
	KeyHexValue.push_back(0x4E);

	KeyName.push_back("o");
	KeyHexValue.push_back(0x4F);

	KeyName.push_back("p");
	KeyHexValue.push_back(0x50);

	KeyName.push_back("q");
	KeyHexValue.push_back(0x51);

	KeyName.push_back("r");
	KeyHexValue.push_back(0x52);

	KeyName.push_back("s");
	KeyHexValue.push_back(0x53);

	KeyName.push_back("t");
	KeyHexValue.push_back(0x54);

	KeyName.push_back("u");
	KeyHexValue.push_back(0x55);

	KeyName.push_back("v");
	KeyHexValue.push_back(0x56);

	KeyName.push_back("w");
	KeyHexValue.push_back(0x57);

	KeyName.push_back("x");
	KeyHexValue.push_back(0x58);

	KeyName.push_back("y");
	KeyHexValue.push_back(0x59);

	KeyName.push_back("z");
	KeyHexValue.push_back(0x5A);



	return 0;
}


