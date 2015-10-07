// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once
#pragma comment(lib, "user32.lib")
// TODO: reference additional headers your program requires here
using namespace std;
 
#include <iostream>
#include <winsock2.h>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <psapi.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <Winuser.h>


#include <string>
#include <tchar.h> 

bool LoadLableText();

string ReqLableText(int Which);

bool LoadTimeString(string Load, int slot);
bool ChangeTextToSpam(string Load, int slot);
bool press_key(char use, int delay);
bool SpamText(int Which, string ToSpam);
bool LoadTimeStringForKey(string Load, int slot);
void SetMouseDelay(std::string Which, char TextArg[256]);
bool Load_ForceWindow(std::string WindowName, int Switch, bool Enabled);
int LoadKeys();
int SetKey(); // Loops getkeystatus.
string WaitForNewKeySelect();

bool Start_SetKey(string WhichToChange, int SwitchLable); // used by Lable(int)_click
string FindNameForKey(int KeyCode);
void SwitchSelectingNewKey(bool arg);
