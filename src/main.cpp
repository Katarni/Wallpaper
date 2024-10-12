#include <string>
#include <iostream>
#include <windows.h>
#include <filesystem>

int main() {
    std::filesystem::path cwd = std::filesystem::current_path();
    std::wstring name = cwd.wstring() + L"\\..\\Winter\\Winter-1.jpg";

    SystemParametersInfoW(
            SPI_SETDESKWALLPAPER,
            0,
            (PVOID)name.c_str(),
            SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
    );
    return 0;
}
