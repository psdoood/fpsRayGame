#ifndef MAP_H
#define MAP_H
#include "raylib.h"
#include <vector>

const int CELL_SIZE = 4;
const int MAP_WIDTH = 16;
const int MAP_HEIGHT = 16;
const float WALL_HEIGHT = 10.0f;

class Map{
    public:
        Map();
        void DrawMap(const std::vector<std::vector<int>>& map);
        bool CheckCollision(Vector3 pos, float groundLvl);
        std::vector<std::vector<int>> initMap(int num);
    private:
};

#endif