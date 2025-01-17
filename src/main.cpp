#include "../inc/raylib.h"
#include "../inc/rcamera.h"
#include "../inc/raymath.h"
#include "../inc/rlgl.h"
#include "../inc/player.h"
#include "../inc/Map.h"

int main() {
    // Window initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Window");
    SetTargetFPS(120);
    DisableCursor();
    rlEnableBackfaceCulling();
    rlEnableDepthTest();
    rlEnableDepthMask();

    // Camera settings
    Camera camera = {0};
    camera.position = (Vector3){CELL_SIZE * 1.5f, 2.0f, CELL_SIZE * 1.5f};
    camera.target = (Vector3){ 10.0f, EYE_LVL, 10.0f };      
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          
    camera.fovy = 120.0f;                             
    camera.projection = CAMERA_PERSPECTIVE;   

    // Game objects
    Player player;
    Map map;

    // Game loop
    while (!WindowShouldClose()) {
        player.updatePlayer(camera, map);
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                map.DrawMap(map.getCurrMap());
            EndMode3D();
            DrawFPS(10,10);
        EndDrawing();

    }
    
    CloseWindow();
    return 0;
}
