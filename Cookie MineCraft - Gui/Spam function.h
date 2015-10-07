#pragma once
#include "stdafx.h"


bool SpamText(int Which, string ToSpam) // Which is for the time - i.e. Which text so it knows which time.
{
	int SizeOfText = ToSpam.size(); 

	Which--; // Remove one so it will line up right with an array. (9 = 0-8)

	int Current = 0;
	while(SizeOfText > Current)
	{
		//Added 12/22/2012
		//Atempting to do beable to use {ENTER}, {WAIT:TIME}, {LEFTCLICK}, {RIGHTCLICK}, {MIDDLECLICK}
		if(ToSpam[Current] == '{'){

			int OtherBracket = Current;

			bool InvalidCommand = false;

			char TempHolder = 'h';
			while(TempHolder != '}'){
				if(OtherBracket < ToSpam.size()){
					OtherBracket++;
				}else{
					//Unable to find the other so we send key and keep going.
					InvalidCommand = true;
					break;
				}
				TempHolder = ToSpam[OtherBracket];
			}


			if(InvalidCommand){
				//We could not find the other } so it must mean they want to press {
				press_key('{', Which);
			}else{
				//We found the otherside so we will try to determine what it is.
				std::string WorkString;
				for(int i = Current + 1; i < OtherBracket;i++){
					WorkString += ToSpam[i];
				}
				//Atempting to do beable to use {ENTER}, {WAIT:TIME}, {LEFTCLICK}, {RIGHTCLICK}, {MIDDLECLICK}

				//{ENTER}
				if(WorkString == "ENTER"){
					keybd_event(VK_RETURN, NULL, NULL, NULL);  
					int speed = TextDelayValue[Which];
					Sleep(speed);
                    keybd_event(VK_RETURN, NULL, KEYEVENTF_KEYUP, NULL); 
				}
				//{LEFTCLICK}
				if(WorkString == "LEFTCLICK"){
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					Sleep(MouseClickDelayLEFT);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				}
				//{RIGHTCLICK}
				if(WorkString == "RIGHTCLICK"){
					mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
					Sleep(MouseClickDelayRIGHT);
					mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
				}
				//{MIDDLECLICK}
				if(WorkString == "MIDDLECLICK"){
					mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
					Sleep(MouseClickDelayMIDDLE);
					mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
				}
				//{WAIT:TIME}
				if(WorkString[0] == 'W' && WorkString[1] == 'A' && WorkString[2] == 'I' && WorkString[3] == 'T' && WorkString[4] == ':'){
					std::string myString;
					for(int i = Current + 5;i < OtherBracket - 1;i++){
						myString += WorkString[i];
					}


					int value = atoi(myString.c_str()); 
					if(value > 0){
						Sleep(value);
					}
				}
				


				Current = OtherBracket;
			}
						

		}else{
			press_key(ToSpam[Current], Which);
		}

		Current++;
	}

	return true;
}


// Last tested 10/1/2011 - Working.
// bool Unused = press_key('f');
bool press_key(char use, int delay)
{
	int speed = TextDelayValue[delay];
	int KeyPressDelay = TextDelayValueForKey[delay];

	switch(use)
	{
						case 'a': keybd_event('A', NULL, NULL, NULL);  
						keybd_event('A', NULL, KEYEVENTF_KEYUP, NULL); 
						Sleep(KeyPressDelay); 
						break;

						case 'b': keybd_event('B', NULL, NULL, NULL);  
                        keybd_event('B', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'c': keybd_event('C', NULL, NULL, NULL);  
                        keybd_event('C', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'd': keybd_event('D', NULL, NULL, NULL);  
                        keybd_event('D', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'e': keybd_event('E', NULL, NULL, NULL);  
                        keybd_event('E', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'f': keybd_event('F', NULL, NULL, NULL);  
                        keybd_event('F', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'g': keybd_event('G', NULL, NULL, NULL);  
                        keybd_event('G', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'h': keybd_event('H', NULL, NULL, NULL);  
                        keybd_event('H', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'i': keybd_event('I', NULL, NULL, NULL);  
                        keybd_event('I', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'j': keybd_event('J', NULL, NULL, NULL);  
                        keybd_event('J', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'k': keybd_event('K', NULL, NULL, NULL);  
                        keybd_event('K', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'l': keybd_event('L', NULL, NULL, NULL);  
                        keybd_event('L', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'm': keybd_event('M', NULL, NULL, NULL);  
                        keybd_event('M', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'n': keybd_event('N', NULL, NULL, NULL);  
                        keybd_event('N', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'o': keybd_event('O', NULL, NULL, NULL);  
                        keybd_event('O', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'p': keybd_event('P', NULL, NULL, NULL);  
                        keybd_event('P', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'q': keybd_event('Q', NULL, NULL, NULL);  
                        keybd_event('Q', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'r': keybd_event('R', NULL, NULL, NULL);  
                        keybd_event('R', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 's': keybd_event('S', NULL, NULL, NULL);  
                        keybd_event('S', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 't': keybd_event('T', NULL, NULL, NULL);  
                        keybd_event('T', NULL, KEYEVENTF_KEYUP, NULL);
						Sleep(KeyPressDelay); 	                    
						break;

						case 'u': keybd_event('U', NULL, NULL, NULL);  
                        keybd_event('U', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'v': keybd_event('V', NULL, NULL, NULL);  
                        keybd_event('V', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'w': keybd_event('W', NULL, NULL, NULL);  
                        keybd_event('W', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'x': keybd_event('X', NULL, NULL, NULL);  
                        keybd_event('X', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'y': keybd_event('Y', NULL, NULL, NULL); 
                        keybd_event('Y', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case 'z': keybd_event('Z', NULL, NULL, NULL);  
                        keybd_event('Z', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;


						//Caps added on 3/30/2011

						case 'A': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('A', NULL, NULL, NULL);  
						keybd_event('A', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'B': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('B', NULL, NULL, NULL);  
                        keybd_event('B', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'C': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('C', NULL, NULL, NULL);  
                        keybd_event('C', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'D': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('D', NULL, NULL, NULL);  
                        keybd_event('D', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'E': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('E', NULL, NULL, NULL);  
                        keybd_event('E', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'F': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('F', NULL, NULL, NULL);  
                        keybd_event('F', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'G': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('G', NULL, NULL, NULL);  
                        keybd_event('G', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'H': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('H', NULL, NULL, NULL);  
                        keybd_event('H', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'I': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('I', NULL, NULL, NULL);  
                        keybd_event('I', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'J':
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('J', NULL, NULL, NULL);  
                        keybd_event('J', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'K':
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('K', NULL, NULL, NULL);  
                        keybd_event('K', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'L': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('L', NULL, NULL, NULL);  
                        keybd_event('L', NULL, KEYEVENTF_KEYUP, NULL);
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);						
	                    Sleep(KeyPressDelay); 
						break;

						case 'M':
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('M', NULL, NULL, NULL);  
                        keybd_event('M', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'N': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('N', NULL, NULL, NULL);  
                        keybd_event('N', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'O': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('O', NULL, NULL, NULL);  
                        keybd_event('O', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'P': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('P', NULL, NULL, NULL);  
                        keybd_event('P', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'Q':
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('Q', NULL, NULL, NULL);  
                        keybd_event('Q', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'R': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('R', NULL, NULL, NULL);  
                        keybd_event('R', NULL, KEYEVENTF_KEYUP, NULL); 
	                    keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
					    Sleep(KeyPressDelay); 
						break;

						case 'S': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('S', NULL, NULL, NULL);  
                        keybd_event('S', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'T':
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('T', NULL, NULL, NULL);  
                        keybd_event('T', NULL, KEYEVENTF_KEYUP, NULL);
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
						Sleep(KeyPressDelay); 	                    
						break;

						case 'U': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('U', NULL, NULL, NULL);  
                        keybd_event('U', NULL, KEYEVENTF_KEYUP, NULL);
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);						
	                    Sleep(KeyPressDelay); 
						break;

						case 'V': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('V', NULL, NULL, NULL);  
                        keybd_event('V', NULL, KEYEVENTF_KEYUP, NULL);
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'W': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('W', NULL, NULL, NULL);  
                        keybd_event('W', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'X': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('X', NULL, NULL, NULL);  
                        keybd_event('X', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						case 'Y': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('Y', NULL, NULL, NULL); 
                        keybd_event('Y', NULL, KEYEVENTF_KEYUP, NULL);
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);						
	                    Sleep(KeyPressDelay); 
						break;

						case 'Z': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);
						keybd_event('Z', NULL, NULL, NULL);  
                        keybd_event('Z', NULL, KEYEVENTF_KEYUP, NULL); 
						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL);
	                    Sleep(KeyPressDelay); 
						break;

						// End of caps.



						case '1': keybd_event('1', NULL, NULL, NULL);  
                        keybd_event('1', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case '2': keybd_event('2', NULL, NULL, NULL);  
                        keybd_event('2', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case '3': keybd_event('3', NULL, NULL, NULL);  
                        keybd_event('3', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case '4': keybd_event('4', NULL, NULL, NULL);  
                        keybd_event('4', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case '5': keybd_event('5', NULL, NULL, NULL);  
                        keybd_event('5', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case '6': keybd_event('6', NULL, NULL, NULL);  
                        keybd_event('6', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case '7': keybd_event('7', NULL, NULL, NULL);  
                        keybd_event('7', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case '8': keybd_event('8', NULL, NULL, NULL);  
                        keybd_event('8', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case '9': keybd_event('9', NULL, NULL, NULL);  
                        keybd_event('9', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;
						 
						case '0': keybd_event('0', NULL, NULL, NULL);  
                        keybd_event('0', NULL, KEYEVENTF_KEYUP, NULL); 
	                    Sleep(KeyPressDelay); 
						break;

						case ' ': keybd_event(' ', NULL, NULL, NULL);  
                        keybd_event(' ', NULL, KEYEVENTF_KEYUP, NULL); 
						Sleep(KeyPressDelay); 	                    
						break;

						case '/': keybd_event(VK_DIVIDE, NULL, NULL, NULL);  
                        keybd_event(VK_DIVIDE, NULL, KEYEVENTF_KEYUP, NULL); 
						Sleep(KeyPressDelay);                     
						break;

						case '>': keybd_event('>', NULL, NULL, NULL);  
                        keybd_event('>', NULL, KEYEVENTF_KEYUP, NULL); 
						Sleep(KeyPressDelay); 
						break;

						case '<': keybd_event('<', NULL, NULL, NULL);  
                        keybd_event('<', NULL, KEYEVENTF_KEYUP, NULL); 
				        Sleep(KeyPressDelay); 
						break;

						case '_': 
						keybd_event(VK_RSHIFT, NULL, NULL, NULL);

						keybd_event(VK_OEM_MINUS, NULL, NULL, NULL);  
                        keybd_event(VK_OEM_MINUS, NULL, KEYEVENTF_KEYUP, NULL); 

						keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL); 

						Sleep(KeyPressDelay); 
	                    
						break;

						case '-': 

						keybd_event(VK_OEM_MINUS, NULL, NULL, NULL);  
                        keybd_event(VK_OEM_MINUS, NULL, KEYEVENTF_KEYUP, NULL); 

						Sleep(KeyPressDelay); 
	                    
						break;

						case '~':
							keybd_event(VK_RSHIFT, NULL, NULL, NULL);
							keybd_event(VK_OEM_3, NULL, NULL, NULL);  
							 keybd_event(VK_OEM_3, NULL, KEYEVENTF_KEYUP, NULL); 
							keybd_event(VK_RSHIFT, NULL, KEYEVENTF_KEYUP, NULL); 
						Sleep(speed);                   
						break;

						default:
						
							//I have no idea why this is here, sorry.

							INPUT ip;

		
							// Set up a generic keyboard event.
							ip.type = INPUT_KEYBOARD;
							ip.ki.wScan = use; // hardware scan code for key
							ip.ki.time = 0;
							ip.ki.dwExtraInfo = 0;

							// Press the "A" key
							ip.ki.wVk = 0;//MapVirtualKey(use, MAPVK_VSC_TO_VK);// 0x41; // virtual-key code for the "a" key
							ip.ki.dwFlags = KEYEVENTF_UNICODE; // 0 for key press
							SendInput(1, &ip, sizeof(INPUT));

							// Release the "A" key
							ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
							SendInput(1, &ip, sizeof(INPUT));

							Sleep(speed);   


						}






	

		return true;
}