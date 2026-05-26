int main() {
	HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);
    system("start \"\" \"giaodienphanmemquanli .html\"");
    return 0;
}
