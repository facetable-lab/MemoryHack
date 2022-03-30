#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int valueToWrite = 0;
	cin >> valueToWrite;

	HWND window = FindWindowA(0, "AppForHack"); // Имя окна

	if (window == 0) {
		cout << "Окно не найдено" << endl;
		Sleep(500);
		return -1;
	}
	else {
		DWORD processID;

		GetWindowThreadProcessId(window, &processID);

		HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, false, processID);

		if (!process) {
			cout << "Не удалось открыть процесс" << endl;
			Sleep(500);
			return -2;
		}
		else {
			// Поиск адреса через Cheat Engine 
			int memoryWriteStatus = WriteProcessMemory(process, (LPVOID)0x20467C28278, &valueToWrite, (DWORD)sizeof(valueToWrite), NULL);
			
			if (memoryWriteStatus > 0) {
				cout << "Запись прошла успешно";
			}
			else {
				cout << "Ошибка" << endl;
				Sleep(500);
				return -3;
			}
		}
		CloseHandle(process);

		cin.get();
	}

	return 0;
}
