#ifndef MAP_H
#define MAP_H
#include "raylib.h"
#include <vector>

const int CELL_SIZE = 4;
const float WALL_HEIGHT = 15.0f;

class Map{
    public:
        Map();
        void DrawMap(const std::vector<std::vector<int>>& map);
        bool CheckCollision(BoundingBox& playerBox);
        std::vector<std::vector<int>> initMap(int num);
        void initWallBoxes();
        std::vector<std::vector<int>> getCurrMap();
    private:
        std::vector<std::vector<int>> currMap;
        std::vector<BoundingBox> wallBoxes;
};

#endif
