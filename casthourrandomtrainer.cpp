// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <cstring>
#include <TlHelp32.h>
#include <stdlib.h>

using namespace std;

uintptr_t GetModuleBaseAddress(DWORD, const wchar_t*);
DWORD GetProcId(const wchar_t*);
void InsertRandom(char[8], uintptr_t, HANDLE);
void InsertRandomP2(char[8], uintptr_t, HANDLE);

int main()
{
	cout << "IIDX Random Trainer By VELIUS" << endl;
	//cout << "Go back to Resident now." << endl;
	//HWND hwnd = FindWindowA(NULL, "beatmania IIDX 30 RESIDENT main");

	cout << "Go back to CH now." << endl;
	HWND hwnd = FindWindowA(NULL, "beatmania IIDX 29 CastHour main");
	if (hwnd == NULL)
	{
		//cout << "Cannot find window. Make sure Resident has been started." << endl;
		cout << "Cannot find window. Make sure CH has been started." << endl;
		Sleep(3000);
		exit(-1);
	}
	else
	{
		DWORD64 procID = GetProcId(L"spice64.exe");
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);
		if (procID == NULL)
		{
			cout << "Cannot obtain process." << endl;
			Sleep(3000);
			exit(-1);
		}
		if (handle == NULL || handle == INVALID_HANDLE_VALUE)
		{
			cout << "Handle not found. Try running as Admin and try again." << endl;
			cout << "Error code: " << GetLastError();
		}
		else
		{


			uintptr_t Base = GetModuleBaseAddress(procID, L"bm2dx.dll");
			int key;
			DWORD64 address;
			cout << Base;
			BYTE nop[] = { 0x90, 0x90, 0x90, 0x90 };
			BYTE nop2[] = { 0x90, 0x90, 0x90 };
			BYTE nop3[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
			//BYTE orig1[] = { 0x44 ,0x8B, 0x04, 0x88 };
			BYTE orig1[] = { 0x41 ,0x89, 0x50, 0xFC };

			//BYTE orig2[] = { 0x89 ,0x14, 0x88 };
			BYTE orig2[] = { 0x89 ,0x04, 0x8F };



			//DWORD64 miscrec1 = Base + 0x622974;
			//DWORD64 miscrec2 = Base + 0x622956;
			//DWORD64 miscrec3 = Base + 0x6222E0;

			DWORD64 miscrec1 = Base + 0x355D08;
			DWORD64 miscrec2 = Base + 0x35621B;

			BYTE key1[] = { 0x41, 0xC7, 0x40, 0xE0, 0x01, 0x00, 0x00, 0x00 };
			BYTE key2[] = { 0x41, 0xC7, 0x40, 0xE4, 0x02, 0x00, 0x00, 0x00 };
			BYTE key3[] = { 0x41, 0xC7, 0x40, 0xE8, 0x03, 0x00, 0x00, 0x00 };
			BYTE key4[] = { 0x41, 0xC7, 0x40, 0xEC, 0x04, 0x00, 0x00, 0x00 };
			BYTE key5[] = { 0x41, 0xC7, 0x40, 0xF0, 0x05, 0x00, 0x00, 0x00 };
			BYTE key6[] = { 0x41, 0xC7, 0x40, 0xF4, 0x06, 0x00, 0x00, 0x00 };
			DWORD64 miscrec3 = Base + 0x355D14;
			DWORD64 miscrec4 = Base + 0x355D20;
			DWORD64 miscrec5 = Base + 0x355D2C;
			DWORD64 miscrec6 = Base + 0x355D38;
			DWORD64 miscrec7 = Base + 0x355D44;
			DWORD64 miscrec8 = Base + 0x355D50;

			char helloworld[] = "PRESS TAB TO ENTER RAN";
			char helloworld2[] = "PRESS BACKSLASH TO ENTER P2 RAN";
			char credit[] = "FREE PLAY";

			DWORD64 textaddress = Base + 0x758D68;
			DWORD old;
			VirtualProtectEx(handle, (LPVOID)textaddress, 32, PAGE_READWRITE, &old);
			if (VirtualProtectEx(handle, (LPVOID)textaddress, 32, PAGE_READWRITE, &old) == FALSE)
			{
				cout << GetLastError() << endl;
			}

			// 0x1003D487 0x89 0x90
			// 0x1003D488 0x06 0x90

			// 0x1003D4E2 0x44 0x03
			// 0x1003D4E3 0x96 0x90
			// 0x1003D4E4 0x68 0x90
			// 18008AEB4 41 C7 40 E0 01,18008AEC0 41 C7 40 E4 02, 18008AECC, 41 C7 40 E8 03, 18008AED8 41 C7 40 EC 04, 18008AEE8 41 C7 40 F0 05, 18008AEF4 41 C7 40 F4 06

			RegisterHotKey(NULL, 0, MOD_NOREPEAT, 0x09);
			//press Tab
			RegisterHotKey(NULL, 9, MOD_NOREPEAT, 0x51);
			// press Q
			RegisterHotKey(NULL, 10, MOD_NOREPEAT, 0xDC);
			//press backslash
			RegisterHotKey(NULL, 11, MOD_NOREPEAT, 0xDD);
			// press ]
			MSG msg = { 0 };
			while (GetMessage(&msg, NULL, 0, 0) != 0)
			{

				if (msg.wParam == 0) {
					for (int i = 0; i < strlen(helloworld); i++) {
						int y = 0;
						WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
						textaddress += 1;
					}
					textaddress = Base + 0x758D68;

					RegisterHotKey(NULL, 1, MOD_NOREPEAT, 0x31);
					RegisterHotKey(NULL, 2, MOD_NOREPEAT, 0x32);
					RegisterHotKey(NULL, 3, MOD_NOREPEAT, 0x33);
					RegisterHotKey(NULL, 4, MOD_NOREPEAT, 0x34);
					RegisterHotKey(NULL, 5, MOD_NOREPEAT, 0x35);
					RegisterHotKey(NULL, 6, MOD_NOREPEAT, 0x36);
					RegisterHotKey(NULL, 7, MOD_NOREPEAT, 0x37);
					RegisterHotKey(NULL, 8, MOD_NOREPEAT, 0x0D);
					MSG msg = { 0 };
					int b = 0;
					int ran[7];
					int key;

					while (GetMessage(&msg, NULL, 0, 0) != 0)
					{

						if (b == 7)
						{
							char placeholder[8] = "1234567";
							WriteProcessMemory(handle, (LPVOID)miscrec1, &nop, sizeof(nop), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec2, &nop2, sizeof(nop2), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec3, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec4, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec5, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec6, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec7, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec8, &nop3, sizeof(nop3), 0);
							Sleep(100);
							for (int i = 0; i < 7; i++) {
								int y = ran[i];
								placeholder[i] = y + '0';
							}
							InsertRandom(placeholder, Base, handle);
							textaddress = Base + 0x758D68;
							char success[] = "SUCCESS!! PRESS TAB TO CHANGE RAN";
							for (int i = 0; i < strlen(success); i++) {
								int y = success[i];
								WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
								textaddress += 1;
							}
							textaddress = Base + 0x758D68;
							Sleep(3000);
							for (int i = 0; i < strlen(credit); i++) {
								int y = credit[i];
								WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
								textaddress += 1;
							}
							textaddress = Base + 0x758D68;
							break;
						}
						if (msg.message == WM_HOTKEY) {
							switch (msg.wParam)
							{
							case 1:
								ran[b] = 1;
								key = 0x31;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								Sleep(300);
								break;
							case 2:
								ran[b] = 2;
								key = 0x32;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 3:
								ran[b] = 3;
								key = 0x33;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 4:
								ran[b] = 4;
								key = 0x34;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 5:
								ran[b] = 5;
								key = 0x35;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 6:
								ran[b] = 6;
								key = 0x36;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 7:
								ran[b] = 7;
								key = 0x37;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							default:
								break;
							}
						}
					}
				}

				if (msg.wParam == 9)
				{
					char randomRead[8] = "1234567"; //placeholder
					unsigned int read;
					WriteProcessMemory(handle, (LPVOID)miscrec1, &orig1, sizeof(orig1), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec2, &orig2, sizeof(orig2), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec3, &key1, sizeof(key1), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec4, &key2, sizeof(key2), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec5, &key3, sizeof(key3), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec6, &key4, sizeof(key4), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec7, &key5, sizeof(key5), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec8, &key6, sizeof(key6), 0);
					for (int i = 0; i < 7; i++) {
						switch (i)
						{
							// 4152637 = 2461357
						case 0:
							key = i + 1;
							address = Base + 0x5DA3690;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 1:
							key = i + 1;
							address = Base + 0x5DA3694;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 2:
							key = i + 1;
							address = Base + 0x5DA3698;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 3:
							key = i + 1;
							address = Base + 0x5DA369C;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 4:
							key = i + 1;
							address = Base + 0x5DA36A0;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 5:
							key = i + 1;
							address = Base + 0x5DA36A4;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 6:
							key = i + 1;
							address = Base + 0x5DA36A8;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						default:
							break;
						}
					} // end for loop
					for (int i = 0; i < strlen(randomRead); i++)
					{
						int y = randomRead[i];
						WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
						textaddress += 1;
					}
					textaddress = Base + 0x758D68;
					Sleep(10000);
					for (int i = 0; i < strlen(credit); i++)
					{
						int y = credit[i];
						WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
						textaddress += 1;
					}
					textaddress = Base + 0x758D68;
				}

				if (msg.wParam == 10) {
					for (int i = 0; i < strlen(helloworld); i++) {
						int y = 0;
						WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
						textaddress += 1;
					}
					textaddress = Base + 0x758D68;

					RegisterHotKey(NULL, 1, MOD_NOREPEAT, 0x31);
					RegisterHotKey(NULL, 2, MOD_NOREPEAT, 0x32);
					RegisterHotKey(NULL, 3, MOD_NOREPEAT, 0x33);
					RegisterHotKey(NULL, 4, MOD_NOREPEAT, 0x34);
					RegisterHotKey(NULL, 5, MOD_NOREPEAT, 0x35);
					RegisterHotKey(NULL, 6, MOD_NOREPEAT, 0x36);
					RegisterHotKey(NULL, 7, MOD_NOREPEAT, 0x37);
					RegisterHotKey(NULL, 8, MOD_NOREPEAT, 0x0D);
					MSG msg = { 0 };
					int b = 0;
					int ran[7];
					int key;
					while (GetMessage(&msg, NULL, 0, 0) != 0)
					{

						if (b == 7)
						{
							char placeholder[8] = "1234567";
							WriteProcessMemory(handle, (LPVOID)miscrec1, &nop, sizeof(nop), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec2, &nop2, sizeof(nop2), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec3, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec4, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec5, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec6, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec7, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)miscrec8, &nop3, sizeof(nop3), 0);
							Sleep(100);
							for (int i = 0; i < 7; i++) {
								int y = ran[i];
								placeholder[i] = y + '0';
							}
							InsertRandomP2(placeholder, Base, handle);
							textaddress = Base + 0x758D68;
							char success[] = "SUCCESS!! PRESS BACKSLASH TO CHANGE RAN";
							for (int i = 0; i < strlen(success); i++) {
								int y = success[i];
								WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
								textaddress += 1;
							}
							textaddress = Base + 0x758D68;
							Sleep(3000);
							for (int i = 0; i < strlen(credit); i++) {
								int y = credit[i];
								WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
								textaddress += 1;
							}
							textaddress = Base + 0x758D68;
							break;
						}
						if (msg.message == WM_HOTKEY) {
							switch (msg.wParam)
							{
							case 1:
								ran[b] = 1;
								key = 0x31;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								Sleep(300);
								break;
							case 2:
								ran[b] = 2;
								key = 0x32;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 3:
								ran[b] = 3;
								key = 0x33;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 4:
								ran[b] = 4;
								key = 0x34;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 5:
								ran[b] = 5;
								key = 0x35;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 6:
								ran[b] = 6;
								key = 0x36;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							case 7:
								ran[b] = 7;
								key = 0x37;
								WriteProcessMemory(handle, (LPVOID)textaddress, &key, sizeof(key), 0);
								textaddress += 1;
								b += 1;
								break;
							default:
								break;
							}
						}
					}
				}

				if (msg.wParam == 11)
				{
					char randomRead[8] = "1234567"; //placeholder
					unsigned int read;
					WriteProcessMemory(handle, (LPVOID)miscrec1, &orig1, sizeof(orig1), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec2, &orig2, sizeof(orig2), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec3, &key1, sizeof(key1), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec4, &key2, sizeof(key2), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec5, &key3, sizeof(key3), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec6, &key4, sizeof(key4), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec7, &key5, sizeof(key5), 0);
					WriteProcessMemory(handle, (LPVOID)miscrec8, &key6, sizeof(key6), 0);
					for (int i = 0; i < 7; i++) {
						switch (i)
						{
							// 4152637 = 2461357
						case 0:
							key = i + 1;
							address = Base + 0x5DA36B0;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 1:
							key = i + 1;
							address = Base + 0x5DA36B4;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 2:
							key = i + 1;
							address = Base + 0x5DA36B8;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 3:
							key = i + 1;
							address = Base + 0x5DA36BC;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 4:
							key = i + 1;
							address = Base + 0x5DA36C0;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 5:
							key = i + 1;
							address = Base + 0x5DA36C4;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						case 6:
							key = i + 1;
							address = Base + 0x5DA36C8;
							ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
							randomRead[read] = key + '0';
							break;
						default:
							break;
						}
					} // end for loop
					for (int i = 0; i < strlen(randomRead); i++)
					{
						int y = randomRead[i];
						WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
						textaddress += 1;
					}
					textaddress = Base + 0x758D68;
					Sleep(10000);
					for (int i = 0; i < strlen(credit); i++)
					{
						int y = credit[i];
						WriteProcessMemory(handle, (LPVOID)textaddress, &y, sizeof(y), 0);
						textaddress += 1;
					}
					textaddress = Base + 0x758D68;
				}


				/*
				Sleep(50);
				if (GetAsyncKeyState(VK_RSHIFT))
				{
					//prompt for random
					cout << "Enter your random" << endl;
					cin >> random;
					cin.ignore(8, '\n');
					if (strlen(random) == 7)
					{
						//input random into said addresses
						WriteProcessMemory(handle, (LPVOID)0x18008AEA8, &nop, sizeof(nop), 0);
						WriteProcessMemory(handle, (LPVOID)0x18008B3A2, &nop2, sizeof(nop2), 0);
						WriteProcessMemory(handle, (LPVOID)0x18008AEB4, &nop2, sizeof(nop2), 0);
						Sleep(100);
						InsertRandom(random, Base, handle);
						cout << "Success. Press Right Shift if you'd like to change your random, or press Left Shift if you want to enter Watch Mode." << endl;
					}

				}

				if (GetAsyncKeyState(VK_LSHIFT))
				{
					char randomRead[8] = "1234567"; //placeholder
					char compareRan[8];
					unsigned int read;
					cout << "Watch Mode enabled. Press Right Shift to replay the random or Left Shift to exit." << endl;

					//TODO: Put in second write for the other subroutine
					WriteProcessMemory(handle, (LPVOID)0x18008AEA8, &orig1, sizeof(orig1), 0);
					WriteProcessMemory(handle, (LPVOID)0x18008B3A2, &orig2, sizeof(orig2), 0);
					WriteProcessMemory(handle, (LPVOID)0x18008AEB4, &key1, sizeof(key1), 0);
					WriteProcessMemory(handle, (LPVOID)0x18008AEC0, &key2, sizeof(key2), 0);
					WriteProcessMemory(handle, (LPVOID)0x18008AECC, &key3, sizeof(key3), 0);
					WriteProcessMemory(handle, (LPVOID)0x18008AED8, &key4, sizeof(key4), 0);
					WriteProcessMemory(handle, (LPVOID)0x18008AEE4, &key5, sizeof(key5), 0);
					WriteProcessMemory(handle, (LPVOID)0x18008AEF0, &key6, sizeof(key6), 0);
					for (;;) {
						Sleep(100);
						for (int i = 0; i < 7; i++) {
							switch (i)
							{
								// 4152637 = 2461357
							case 0:
								key = i + 1;
								address = Base + 0x20BEBD0;
								ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
								randomRead[read] = key + '0';
								break;
							case 1:
								key = i + 1;
								address = Base + 0x20BEBD4;
								ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
								randomRead[read] = key + '0';
								break;
							case 2:
								key = i + 1;
								address = Base + 0x20BEBD8;
								ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
								randomRead[read] = key + '0';
								break;
							case 3:
								key = i + 1;
								address = Base + 0x20BEBDC;
								ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
								randomRead[read] = key + '0';
								break;
							case 4:
								key = i + 1;
								address = Base + 0x20BEBE0;
								ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
								randomRead[read] = key + '0';
								break;
							case 5:
								key = i + 1;
								address = Base + 0x20BEBE4;
								ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
								randomRead[read] = key + '0';
								break;
							case 6:
								key = i + 1;
								address = Base + 0x20BEBE8;
								ReadProcessMemory(handle, (BYTE*)address, &read, sizeof(read), 0);
								randomRead[read] = key + '0';
								break;
							default:
								break;
							}
						} // end for loop
						if (strcmp(compareRan, randomRead) != 0) {
							cout << "Your random was " << randomRead << endl;
							strcpy_s(compareRan, _countof(compareRan), randomRead);
						}
						if (GetAsyncKeyState(VK_RSHIFT) && strlen(randomRead) == 7) {
							WriteProcessMemory(handle, (LPVOID)0x18008AEA8, &nop, sizeof(nop), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008B3A2, &nop2, sizeof(nop2), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AEB4, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AEC0, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AECC, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AED8, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AEE4, &nop3, sizeof(nop3), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AEF0, &nop3, sizeof(nop3), 0);
							InsertRandom(randomRead, Base, handle);
							cout << "Random set as "<< randomRead << ". Press Right Shift to exit back to Watch Mode." << endl;
							for (;;) {
								Sleep(100);
								if (GetAsyncKeyState(VK_RSHIFT)) {
									break;
								}
							}
							cout << "Exiting back to Watch Mode." << endl;
							//TODO: Put in second write for the other subroutine
							WriteProcessMemory(handle, (LPVOID)0x18008AEA8, &orig1, sizeof(orig1), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008B3A2, &orig2, sizeof(orig2), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AEB4, &key1, sizeof(key1), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AEC0, &key2, sizeof(key2), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AECC, &key3, sizeof(key3), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AED8, &key4, sizeof(key4), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AEE4, &key5, sizeof(key5), 0);
							WriteProcessMemory(handle, (LPVOID)0x18008AEF0, &key6, sizeof(key6), 0);
						}
						if (GetAsyncKeyState(VK_LSHIFT)) {
							cout << "Exiting Watch Mode. Press Right Shift to enter a random or press Left Shift to enter back to Watch Mode." << endl;
							Sleep(50);
							break;
						}
					} // end infinite loop
				} // end if VK_LSHIFT
				*/
			}

		}
	}

}

void InsertRandom(char input[8], uintptr_t Base, HANDLE handle)
{
	int key;
	DWORD64 address;
	for (int i = 0; i < 7; i++)
	{
		switch (input[i])
		{
			// 4152637 = 2461357
		case '1':
			key = i;
			address = Base + 0x5DA3690;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '2':
			key = i;
			address = Base + 0x5DA3694;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '3':
			key = i;
			address = Base + 0x5DA3698;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '4':
			key = i;
			address = Base + 0x5DA369C;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '5':
			key = i;
			address = Base + 0x5DA36A0;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '6':
			key = i;
			address = Base + 0x5DA36A4;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '7':
			key = i;
			address = Base + 0x5DA36A8;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		default:
			break;
		}
	}
}

void InsertRandomP2(char input[8], uintptr_t Base, HANDLE handle)
{
	int key;
	DWORD64 address;
	for (int i = 0; i < 7; i++)
	{
		switch (input[i])
		{
			// 4152637 = 2461357
		case '1':
			key = i;
			address = Base + 0x5DA36B0;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '2':
			key = i;
			address = Base + 0x5DA36B4;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '3':
			key = i;
			address = Base + 0x5DA36B8;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '4':
			key = i;
			address = Base + 0x5DA36BC;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '5':
			key = i;
			address = Base + 0x5DA36C0;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '6':
			key = i;
			address = Base + 0x5DA36C4;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		case '7':
			key = i;
			address = Base + 0x5DA36C8;
			WriteProcessMemory(handle, (LPVOID)address, &key, sizeof(key), 0);
			break;
		default:
			break;
		}
	}
}
uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
{
	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry))
		{
			do
			{
				if (!_wcsicmp(modEntry.szModule, modName))
				{
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	CloseHandle(hSnap);
	return modBaseAddr;
}

DWORD GetProcId(const wchar_t* procName)
{
	DWORD procId;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!_wcsicmp(procEntry.szExeFile, procName))
				{
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));

		}
	}
	CloseHandle(hSnap);
	return procId;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file