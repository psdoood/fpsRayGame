#include "../inc/Map.h"

Map::Map(){
    currMap = initMap(1);
}

void Map::DrawMap(const std::vector<std::vector<int>>& map){
    int MAP_HEIGHT = map.size();
    int MAP_WIDTH = map[0].size();
    // Floor 
    DrawPlane((Vector3){(MAP_WIDTH * CELL_SIZE) / 2.0f, 0, (MAP_HEIGHT * CELL_SIZE) / 2.0f},
              (Vector2){(float)MAP_WIDTH * CELL_SIZE, (float)MAP_HEIGHT * CELL_SIZE}, GRAY);
    // Ceiling (as a cube since I may want to climb on top at some point)
    DrawCube((Vector3){(MAP_WIDTH * CELL_SIZE) / 2.0f, WALL_HEIGHT, (MAP_HEIGHT * CELL_SIZE) / 2.0f},
              MAP_WIDTH * CELL_SIZE, 0.1f, MAP_HEIGHT * CELL_SIZE, GREEN);
    // Walls
    for(int x = 0; x < MAP_WIDTH; x++){
        for(int y = 0; y < MAP_HEIGHT; y++){
            if(map[y][x] == 1){
                float xpos = x * CELL_SIZE + CELL_SIZE / 2.0f;
                float zpos = y * CELL_SIZE + CELL_SIZE / 2.0f;
                DrawCube((Vector3){xpos, WALL_HEIGHT / 2.0f, zpos}, CELL_SIZE, WALL_HEIGHT, CELL_SIZE, DARKBLUE);
                DrawCubeWires((Vector3){xpos, WALL_HEIGHT / 2.0f, zpos}, CELL_SIZE, WALL_HEIGHT, CELL_SIZE, BLUE);
            }
        }
    }
}

bool Map::CheckCollision(Vector3 pos){

}

std::vector<std::vector<int>> Map::initMap(int num){
    std::vector<std::vector<int>> lvlMap;
    switch(num){
        case 1:
            lvlMap = {
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1},
                {1,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1},
                {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,1,0,0,0,0,1,1,1,0,1},
                {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
                {1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
            };
            break;
        default:
            return lvlMap;
    }
    return lvlMap;
}

std::vector<std::vector<int>> Map::getCurrMap(){
    return currMap;
}
