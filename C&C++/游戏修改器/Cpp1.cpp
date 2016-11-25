#include<windows.h>
#include<stdio.h>

BOOL WriteMemory(DWORD dwValue, DWORD dwAddr, HANDLE g_hProcess){
	return ::WriteProcessMemory(g_hProcess, (LPVOID)dwAddr, &dwValue, sizeof(DWORD), NULL);
}


int main(void){
	//init the message
	STARTUPINFO sinfo;	//������Ϣ
	PROCESS_INFORMATION pinfo;	//������Ϣ
	ZeroMemory(&sinfo, sizeof(sinfo));	//��ʼ��������Ϣ
	ZeroMemory(&pinfo, sizeof(pinfo));	//��ʼ��������Ϣ
	// cmd start the game 2048
	TCHAR name[MAX_PATH] = "java -jar 2048.jar";
	BOOL bRet = ::CreateProcess(NULL, name, NULL, NULL, FALSE, NULL, NULL, NULL, &sinfo, &pinfo);
	
	if(!bRet)
	{
		printf("Open the game fail!\n");
	}
	else
	{
		HANDLE g_hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pinfo.dwProcessId);
		if(g_hProcess == NULL)
		{
			printf("Connect with game fail!\n");
		}
		else
		{
			printf("success to game!\n");

			OSVERSIONINFO vi;
			ZeroMemory(&vi, sizeof(vi));
			::GetVersionEx(&vi);

			if(vi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
				printf("win32 version\n");
			else
				printf("other version\n");
			
			while(true){
				DWORD dValue;
				DWORD dAddr;
				scanf("%u %x", &dValue, &dAddr);
				WriteMemory(dValue, dAddr , g_hProcess);
			}
			
		
			
		}
		//�رվ��
		::CloseHandle(g_hProcess);
	}

	
	return 0;
}