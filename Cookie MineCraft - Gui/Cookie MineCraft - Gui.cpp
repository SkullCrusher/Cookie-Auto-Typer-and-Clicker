// Cookie MineCraft - Gui.cpp : main project file.
#pragma once
#include "stdafx.h"
#include "Form1.h"
#include "Gui.h"
#include "KeyData.h"
#include "Spam function.h"

using namespace CookieMineCraftGui;

//Convert data call.
std::wstring s2ws(const std::string& s)
{
 int len;
 int slength = (int)s.length() + 1;
 len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
 wchar_t* buf = new wchar_t[len];
 MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
 std::wstring r(buf);
 delete[] buf;
 return r;
}

DWORD WINAPI MainThread(LPVOID);
HANDLE ThreadHandle;
DWORD ThreadId;

bool KillThread = false;
bool ActiveWindow = false;

HWND MyProgramWindow;

//If we need to have a window on top to send input.
bool ForceWindow[9] = {false};
std::string ForceWindowName[9] = {"!"};

bool SelectingNewKey = false;
void SwitchSelectingNewKey(bool arg){
	SelectingNewKey = arg;
}



bool Load_ForceWindow(std::string WindowName, int Switch, bool Enabled){

	//Make sure we have a valid window name.
	if(WindowName.size() < 1){
		return false;
	}
	ForceWindowName[Switch] = WindowName;
	ForceWindow[Switch] = Enabled;

	return true;
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	// Check if program is already running.
	MyProgramWindow = FindWindow(NULL,TEXT("Cookie"));
	if(MyProgramWindow != NULL){
		MessageBox::Show("Program already running.");
		return 0;
	}
	
	//Application::
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	int value = LoadKeys();

	ThreadHandle = CreateThread(NULL, 0, MainThread, (LPVOID)1, 0, &ThreadId);

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}


DWORD WINAPI MainThread(LPVOID){
		
	while(KillThread == false){	
		/*
			The Getkey chunk.
		*/ 	

		//Make sure we skip spamming while selecting a new key.
		if(SelectingNewKey){
			//If we are reselecting key
			Sleep(600); // A good delay time.
			continue; //Skip current loop.
		}

		//Check if form is selected, if so do not allow spam.
		if(MyProgramWindow != NULL){

			HWND Temp =  GetForegroundWindow();
			if(MyProgramWindow == Temp){
				ActiveWindow = true;
			}else{
				ActiveWindow = false;
			}
		}else{
			MyProgramWindow = FindWindow(NULL,TEXT("Cookie"));
		}

		if(ActiveWindow == false){

			if(GetAsyncKeyState(KeyForText1)) // 1
			{
				if(ForceWindow[0] == false){
					bool Worked = SpamText(1, TextToSpam[0]);
				}else{

					//If we need to check the current window
					if(ForceWindowName[0] != "!"){
						HWND CurrentTopWindow =  GetForegroundWindow();

						std::wstring stemp = s2ws(ForceWindowName[0]); // Sadly we have to convert it.
						LPCWSTR result = stemp.c_str();
						HWND ForceWindow = FindWindow(NULL,result);

						//if we found the right window.
						if(CurrentTopWindow == ForceWindow){
							bool Worked = SpamText(1, TextToSpam[0]);
						}
					}
				}

			}

			if(GetAsyncKeyState(KeyForText2)) // 2
			{
				if(ForceWindow[1] == false){
						bool Worked = SpamText(2, TextToSpam[1]);
					}else{
						//If we need to check the current window
						if(ForceWindowName[1] != "!"){
							HWND CurrentTopWindow =  GetForegroundWindow();

							std::wstring stemp = s2ws(ForceWindowName[1]); // Sadly we have to convert it.
							LPCWSTR result = stemp.c_str();
							HWND ForceWindow = FindWindow(NULL,result);

							//if we found the right window.
							if(CurrentTopWindow == ForceWindow){
								bool Worked = SpamText(2, TextToSpam[1]);
							}
					}
				}
			}

			if(GetAsyncKeyState(KeyForText3)) // 3
			{
				if(ForceWindow[2] == false){
						bool Worked = SpamText(3, TextToSpam[2]);
					}else{
						//If we need to check the current window
						if(ForceWindowName[2] != "!"){
							HWND CurrentTopWindow =  GetForegroundWindow();

							std::wstring stemp = s2ws(ForceWindowName[2]); // Sadly we have to convert it.
							LPCWSTR result = stemp.c_str();
							HWND ForceWindow = FindWindow(NULL,result);

							//if we found the right window.
							if(CurrentTopWindow == ForceWindow){
								bool Worked = SpamText(3, TextToSpam[2]);
							}
					}
				}
			}

			if(GetAsyncKeyState(KeyForText4)) // 4
			{
					if(ForceWindow[3] == false){
						bool Worked = SpamText(4, TextToSpam[3]);
					}else{
						//If we need to check the current window
						if(ForceWindowName[3] != "!"){
							HWND CurrentTopWindow =  GetForegroundWindow();

							std::wstring stemp = s2ws(ForceWindowName[3]); // Sadly we have to convert it.
							LPCWSTR result = stemp.c_str();
							HWND ForceWindow = FindWindow(NULL,result);

							//if we found the right window.
							if(CurrentTopWindow == ForceWindow){
								bool Worked = SpamText(4, TextToSpam[3]);
							}
					}
				}
			}

			if(GetAsyncKeyState(KeyForText5)) // 5
			{
				if(ForceWindow[4] == false){
						bool Worked = SpamText(5, TextToSpam[4]);
					}else{
						//If we need to check the current window
						if(ForceWindowName[4] != "!"){
							HWND CurrentTopWindow =  GetForegroundWindow();

							std::wstring stemp = s2ws(ForceWindowName[4]); // Sadly we have to convert it.
							LPCWSTR result = stemp.c_str();
							HWND ForceWindow = FindWindow(NULL,result);

							//if we found the right window.
							if(CurrentTopWindow == ForceWindow){
								bool Worked = SpamText(5, TextToSpam[4]);
							}
					}
				}

			}

			if(GetAsyncKeyState(KeyForText6)) // 6
			{
				if(ForceWindow[5] == false){
						bool Worked = SpamText(6, TextToSpam[5]);
					}else{
						//If we need to check the current window
						if(ForceWindowName[5] != "!"){
							HWND CurrentTopWindow =  GetForegroundWindow();

							std::wstring stemp = s2ws(ForceWindowName[5]); // Sadly we have to convert it.
							LPCWSTR result = stemp.c_str();
							HWND ForceWindow = FindWindow(NULL,result);

							//if we found the right window.
							if(CurrentTopWindow == ForceWindow){
								bool Worked = SpamText(6, TextToSpam[5]);
							}
					}
				}
			
			}

			if(GetAsyncKeyState(KeyForText7)) // 7
			{
				if(ForceWindow[6] == false){
						bool Worked = SpamText(7, TextToSpam[6]);
					}else{
						//If we need to check the current window
						if(ForceWindowName[6] != "!"){
							HWND CurrentTopWindow =  GetForegroundWindow();

							std::wstring stemp = s2ws(ForceWindowName[6]); // Sadly we have to convert it.
							LPCWSTR result = stemp.c_str();
							HWND ForceWindow = FindWindow(NULL,result);

							//if we found the right window.
							if(CurrentTopWindow == ForceWindow){
								bool Worked = SpamText(7, TextToSpam[6]);
							}
					}
				}
			}

			if(GetAsyncKeyState(KeyForText8)) // 8
			{
				if(ForceWindow[7] == false){
						bool Worked = SpamText(8, TextToSpam[7]);
					}else{
						//If we need to check the current window
						if(ForceWindowName[7] != "!"){
							HWND CurrentTopWindow =  GetForegroundWindow();

							std::wstring stemp = s2ws(ForceWindowName[7]); // Sadly we have to convert it.
							LPCWSTR result = stemp.c_str();
							HWND ForceWindow = FindWindow(NULL,result);

							//if we found the right window.
							if(CurrentTopWindow == ForceWindow){
								bool Worked = SpamText(8, TextToSpam[7]);
							}
					}
				}
			
			}

			if(GetAsyncKeyState(KeyForText9)) // 9
			{
				if(ForceWindow[8] == false){
						bool Worked = SpamText(9, TextToSpam[8]);
					}else{
						//If we need to check the current window
						if(ForceWindowName[8] != "!"){
							HWND CurrentTopWindow =  GetForegroundWindow();

							std::wstring stemp = s2ws(ForceWindowName[8]); // Sadly we have to convert it.
							LPCWSTR result = stemp.c_str();
							HWND ForceWindow = FindWindow(NULL,result);

							//if we found the right window.
							if(CurrentTopWindow == ForceWindow){
								bool Worked = SpamText(9, TextToSpam[8]);
							}
					}
				}
			}
		}

		Sleep(10); //Force delay.
	}

	return 0;
}