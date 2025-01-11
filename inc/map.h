#ifndef MAP_H
#define MAP_H
#include "raylib.h"
#include <vector>

const int CELL_SIZE = 4;
const float WALL_HEIGHT = 15.0f;

// This class is for handling the drawing and collisions of map objects
class Map{
    public:
        Map();
        // Draws all the objects that are in the map
        void DrawMap(const std::vector<std::vector<int>>& map);
        // Checks if the player BoundingBox collides with any wallBox
        bool CheckCollision(BoundingBox& playerBox);
        // Loads a map defined by num
        std::vector<std::vector<int>> initMap(int num);
        // Creates a BoundingBox for all walls (only called with constructor)
        void initWallBoxes();
        std::vector<std::vector<int>> getCurrMap();
    private:
        std::vector<std::vector<int>> currMap;
        std::vector<BoundingBox> wallBoxes;
};

#endif
