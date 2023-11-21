//
// Created by Will&Carm on 21/11/2023.
//

#include <iostream>
#include "Window.h"

int main() {
    std::cout << "Creating Window" << std::endl;

    Window* pWindow = new Window();

    bool running = true;

    while (running) {

        if (!pWindow->ProcessMessages()) {
            std::cout << "Closing Window" << std::endl;
            running = false;
        }

        Sleep(10);
    }

    delete pWindow;

    return 0;
}