#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
using namespace std;
int printProcessList(){
	PROCESSENTRY32 pe32;

	pe32.dwSize = sizeof(pe32);

	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if(hProcessSnap == INVALID_HANDLE_VALUE)
	{
		std::cout << "fail" << std::endl;
		return -1;
	}
	
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);

	while(bMore)
	{
		cout << "进程ID:" <<pe32.th32ProcessID << "     ";
		printf("进程名: %s\n", pe32.szExeFile);
		

		bMore = ::Process32Next(hProcessSnap, &pe32);
	}

	return 1;
}
int main(){

	
	
	while(true){
		system("cls");
		printProcessList();
		cout << "请输入你想终止的进程id" << endl;
		DWORD id;
		cin >> id;
		if(cin == 0)
			continue;
		else{
			HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS,FALSE, id);
			if(hProcess != NULL){
				::TerminateProcess(hProcess, 0);
				cout << "ok\n";
			}
			CloseHandle(hProcess);
		}
	}
	return 0;
}