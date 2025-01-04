#include "inc/raylib.h"
#include "inc/rcamera.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Window");

    // Camera settings
    Camera camera = {0};
    camera.position = (Vector3){0.0f, 2.0f, 4.0f};
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          
    camera.fovy = 60.0f;                             
    camera.projection = CAMERA_PERSPECTIVE;   
    int cameraMode = CAMERA_FIRST_PERSON;

    DisableCursor();

    // Game loop
    while (!WindowShouldClose()) {
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                DrawPlane((Vector3){0.0f, -0.0f, 0.0f}, (Vector2){40.0f, 40.0f}, WHITE);
                DrawGrid(40, 1);
            EndMode3D();
        EndDrawing();
    }

    
    CloseWindow();
    return 0;
}