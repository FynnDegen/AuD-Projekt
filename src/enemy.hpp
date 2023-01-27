#include "sprite.hpp"
#include <cstdlib>

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
    private:
        int hp = 25;
        int attDmg = 10;
        int attSpd;
    
        int mapPosX; // Schachbrettkoordinate
        int mapPosY; // Schachbrettkoordinate
        int direc;
    
        SVG *canvas;
        TileMap *tileMap;
        
        Sprite sprite;
    
    public:
        Enemy() {
        
        }
    
        Enemy(int pMapPosX, int pMapPosY, TileMap *tileMap, SVG *canvas, int level) {
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            hp = 20 + (5 * level); // mit jedem weiteren Lvl erhoeht sich das Leben um 5
            attDmg = 9 + level;    // mit jedem weiteren Lvl erhoeht sich der attDmg um 1
            this -> canvas = canvas;
            this -> tileMap = tileMap;
            
            tileMap -> setState(mapPosX, mapPosY, 2);
            sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/EnemyUp.png", "gfx/EnemyLeft.png",  "gfx/EnemyDown.png", "gfx/EnemyRight.png");
        }
    
        int moveUp() {
            sprite.toFront(0);
            switch(tileMap -> getTileStateUp(mapPosX, mapPosY)) {
                case 0:
                    tileMap -> setState(mapPosX, mapPosY, 0);
                    mapPosY--;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                    tileMap -> setState(mapPosX, mapPosY, 2);
                    return 0;
                case 3:
                    return attDmg;
                default:
                    return 0;
            }
        }
    
        int moveLeft() {
            sprite.toFront(1);
             switch(tileMap -> getTileStateLeft(mapPosX, mapPosY)) {
                case 0:
                    tileMap -> setState(mapPosX, mapPosY, 0);
                    mapPosX--;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                    tileMap -> setState(mapPosX, mapPosY, 2);
                    return 0;
                 case 3:
                     return attDmg;
                 default:
                     return 0;
            }
        }
    
        int moveDown() {
            sprite.toFront(2);
            switch(tileMap -> getTileStateDown(mapPosX, mapPosY)) {
                case 0:
                    tileMap -> setState(mapPosX, mapPosY, 0);
                    mapPosY++;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                    tileMap -> setState(mapPosX, mapPosY, 2);
                    return 0;
                case 3:
                    return attDmg;
                default:
                    return 0;
            }
        }
    
        int moveRight() {
            sprite.toFront(3);
            switch(tileMap -> getTileStateRight(mapPosX, mapPosY)) {
                case 0:
                    tileMap -> setState(mapPosX, mapPosY, 0);
                    mapPosX++;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                    tileMap -> setState(mapPosX, mapPosY, 2);
                    return 0;
                case 3:
                    return attDmg;
                default:
                    return 0;
            }
        }
    
        int autoMove() {
                switch(rand() % 4) {
                    case 0:
                        return moveUp();
                    case 1:
                        return moveLeft();
                    case 2:
                        return moveDown();
                    case 3:
                        return moveRight();
                    default:
                        return 0;
                }
        }    
    
        int getHP() {
            return hp;
        }

        void setHP(int pHP) {
            hp = pHP;
        }

        int getAttDmg() {
            return attDmg;
        }

        void setAttDmg(int pAttDmg) {
            attDmg = pAttDmg;
        }

        int getMapPosX() {
           return mapPosX;
        }
    
        int getMapPosY() {
           return mapPosY; 
        }
        
        // wird beim Löschen aufgerufen, damit das Tile auf dem der steht wieder den Tag 0 bekommt
        void adios() {
           tileMap -> setState(mapPosX, mapPosY, 0);
        }
    
};
#endif