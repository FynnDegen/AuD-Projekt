#include "sprite.hpp"
#include <cstdlib>

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
    private:
        int hp = 25;
        int attDmg = 10;
        int type;
    
        int mapPosX; // Schachbrettkoordinate
        int mapPosY; // Schachbrettkoordinate
        int direc;
    
        SVG *canvas;
        TileMap *tileMap;
        
        Sprite sprite;
    
    public:
        Enemy() {
        
        }
    
        // abhaengig vom floor wird Leben und attDmg erhoeht
        // mit pType wird der staerkere Gegner erzeugt (0 = einfach, 1 = staerker)
        Enemy(int pMapPosX, int pMapPosY, TileMap *tileMap, SVG *canvas, int floor, int pType) {
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            type = pType;
            this -> canvas = canvas;
            this -> tileMap = tileMap;
            
            tileMap -> setState(mapPosX, mapPosY, 2);
            
            switch(type) {
                // leichter Gegner
                case 0:
                    hp = 20 + (5 * floor); // mit jedem weiteren Lvl erhoehen sich die hp um 5
                    attDmg = 9 + floor;    // mit jedem weiteren Lvl erhoeht sich der attDmg um 1
                    sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/enemies/crab/enemyup.png", "gfx/enemies/crab/enemyleft.png",  "gfx/enemies/crab/enemydown.png", "gfx/enemies/crab/enemyright.png");
                    break;
                // schwerer Gegner
                case 1:
                    hp = 40 + (10 * floor); // mit jedem weiteren Lvl erhoehen sich die hp um 10
                    attDmg = 20 + (2 * floor);    // mit jedem weiteren Lvl erhoeht sich der attDmg um 2
                    sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/enemies/pyramide/enemyup.png", "gfx/enemies/pyramide/enemyleft.png",  "gfx/enemies/pyramide/enemydown.png", "gfx/enemies/pyramide/enemyright.png");
                    break;
            }
        }
    
        // Gegnerbewegnung //
    
        // bewege Gegner nach oben
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
    
        // bewege Gegner nach links
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
    
        // bewege Gegner nach unten
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
    
        // bewege Gegner nach rechts
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
    
        // automatische Gegnerbewegung
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
    
        // wird beim Löschen aufgerufen, damit das Tile-Objekt auf dem der Gegner steht wieder den Zustand 0 bekommt
        void adios() {
           tileMap -> setState(mapPosX, mapPosY, 0);
        }
    
        // sondierende Methoden //
    
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
    
        int getType() {
            return type;
        }
};
#endif