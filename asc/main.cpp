#include "stdafx.h"

VOID Main(HINSTANCE hModule) {

    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    Globals::ModuleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");

    std::cout << Globals::ModuleBase << std::endl;

    std::thread EntityListThread(EntityList::Thread);

    EntityListThread.join();

    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, NULL);

}

BOOL WINAPI DllMain(_In_ HINSTANCE hModule, _In_ DWORD dwReason, _In_ LPVOID pReserved) {

    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Main, hModule, NULL, NULL); // Initialize Main Thread, break after

        break;

    default:

        break;
    }

    return TRUE; // Attached to process

}