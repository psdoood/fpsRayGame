#include "../inc/raylib.h"
#include "../inc/rcamera.h"
#include "../inc/raymath.h"
#include "../inc/rlgl.h"
#include "../inc/player.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Window");
    SetTargetFPS(120);

    // Camera settings
    Camera camera = {0};
    camera.position = (Vector3){0.0f, 2.0f, 4.0f};
    camera.target = (Vector3){ 0.0f, EYE_LVL, 0.0f };      
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          
    camera.fovy = 120.0f;                             
    camera.projection = CAMERA_PERSPECTIVE;   

    Player player;
    DisableCursor();

    // Game loop
    while (!WindowShouldClose()) {
        player.updatePlayer(camera);
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                DrawPlane((Vector3){0.0f, -0.0f, 0.0f}, (Vector2){40.0f, 40.0f}, WHITE);
                DrawGrid(40, 1);
                DrawCube((Vector3){-5.0f, EYE_LVL + 2.0f, -5.0f}, 2.0f, 4.0f, 2.0f, RED);
                DrawCube((Vector3){5.0f, EYE_LVL + 2.0f, 5.0f}, 2.0f, 4.0f, 2.0f, BLUE);
            EndMode3D();
            DrawFPS(10,10);
        EndDrawing();

    }
    
    CloseWindow();
    return 0;
}