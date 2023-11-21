//
// Created by Will&Carm on 21/11/2023.
//

#define UNICODE

#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

switch (uMsg) {
case WM_CLOSE:
DestroyWindow(hWnd);
break;
case WM_DESTROY:
PostQuitMessage(0);
return 0;
}

return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

Window::Window() : m_hInstance(GetModuleHandle(nullptr)) {

    const wchar_t * CLASS_NAME = L"Wills first Window";

    WNDCLASS wndclass = {};
    wndclass.lpfnWndProc = WindowProc;
    wndclass.lpszClassName = CLASS_NAME;
    wndclass.hInstance = m_hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);


    RegisterClass(&wndclass);

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

    int width = 640;
    int height = 480;

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;

    AdjustWindowRect(&rect, style, false);

    m_hWnd = CreateWindowEx(
            0,
            CLASS_NAME,
            L"Title",
            style,
            rect.left,
            rect.top,
            rect.right - rect.left,
            rect.bottom - rect.top,
            NULL,
            NULL,
            m_hInstance,
            NULL
    );

    ShowWindow(m_hWnd, SW_SHOW);
}

Window::~Window() {

    const wchar_t* CLASS_NAME = L"Wills first Window";

    UnregisterClass(CLASS_NAME, m_hInstance);
}

bool Window::ProcessMessages() {
    MSG msg = {};

    while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {

        if (msg.message == WM_QUIT) {
            return false;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return true;
}