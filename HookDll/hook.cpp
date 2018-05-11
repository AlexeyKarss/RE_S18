#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <string>
#include <fstream>
using std::string;
using namespace std;

extern __declspec(dllexport) HWND	g_hGCLWnd;
extern __declspec(dllexport) char	g_szCmdLine[4096];

#pragma data_seg (".shared")
HWND	g_hGCLWnd = 0;
char	g_szCmdLine[4096] ={'\0'};
#pragma data_seg ()

#pragma comment(linker,"/SECTION:.shared,RWS") 

void GetCmdLine()
{
    //LPSTR cmdLine = GetCommandLine();
    auto cmdLine = GetCommandLine();
    strcpy(g_szCmdLine, cmdLine);
}

BOOL APIENTRY DllMain(HANDLE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if((ul_reason_for_call == DLL_PROCESS_ATTACH)){
        GetCmdLine();
    }

    return TRUE;
}
