#include <algoviz/SVG.hpp>

#ifndef TILE_HPP
#define TILE_HPP

class Tile {
    
    private:
        int posX;
        int posY;
        int state;  // speichert den Zustand den das Tile zugeteilt bekommt (1=Wand, 0=Frei, 2=Enemy, 
                    // 3=Player, 4usw Items oder so) -> NUR WERTE Ab 0
        int mapX;   // speichert die x-Pos vom Array Bauplan
        int mapY;   // speichert die y-Pos vom Array Bauplan

        SVG *field;
        Image tile;
    
    public:

        // Konstruktoren //

        Tile() {
            posX = 0;
            posY = 0;
            state = 1;
            field = nullptr;
        }

        Tile(int posX, int posY, int mapX, int mapY, int state, SVG *field) {
            this -> posX = posX;
            this -> posY = posY;
            this -> state = state;
            this -> field = field;
            this -> mapX = mapX;
            this -> mapY = mapY;

            if(state == 1) {
                tile = Image("gfx/tiles/wall.png",posX + 50, posY + 50, 100, 100, field);
            } else if(state == 5) {
                tile = Image("gfx/tiles/teleportationpad.png", posX + 50, posY + 50, 100, 100, field);
            } else if(state == 0) {
                tile = Image("gfx/tiles/floor.png",posX + 50, posY + 50, 100, 100, field);
            }

        }

        // sondierende Methoden //

        int getX() {
            return posX + 50;
        }
        int getY() {
            return posY + 50;
        }
        int getMapX() {
            return mapX;
        }
        int getMapY() {
            return mapY;
        }
        int getState() {
            return state;
        }
        void setState(int state) {
            this -> state = state;
        }
};
#endif