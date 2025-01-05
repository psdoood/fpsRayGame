@echo off
if exist my_program.exe (
    del my_program.exe
)
g++ src/main.cpp src/player.cpp src/map.cpp -o my_program.exe -I./inc -L./lib -lraylib -lopengl32 -lgdi32 -lwinmm -std=c++17

if exist my_program.exe (
    echo Running the game...
    my_program.exe
) else (
    echo Build failed!
)

pause