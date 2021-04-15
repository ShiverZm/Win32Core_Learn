#include   <windows.h>   
#include <stdio.h>

long   __stdcall   callback(_EXCEPTION_POINTERS* excp)
{
    if (IsDebuggerPresent()) {//检测调试器
        return EXCEPTION_CONTINUE_SEARCH;
    }
        

    MessageBox(0, L"Error", L"error", MB_OK);
    printf("Error   address   0x%x/n", excp->ExceptionRecord->ExceptionAddress);
    printf("CPU   register:/n");
    printf("eax   %x   ebx   %x   ecx   %x   edx   %x/n", excp->ContextRecord->Eax,
        excp->ContextRecord->Ebx, excp->ContextRecord->Ecx,
        excp->ContextRecord->Edx);
    return   EXCEPTION_EXECUTE_HANDLER;
}

int main(int   argc, char* argv[])
{
    SetUnhandledExceptionFilter(callback);
    _asm   int   3   //只是为了让程序崩溃
    return   0;
}