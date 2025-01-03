#include "inc/raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Window");

    // Game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("TEST", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    
    CloseWindow();
    return 0;
}