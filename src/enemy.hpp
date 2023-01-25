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
        int x; // "normale" Koordinate
        int y; // "normale" Koordinate
        int direc;
    
        SVG *canvas;
        TileMap *tileMap;
        
        Sprite sprite;
    
    public:
        Enemy() {
        
        }
    
        Enemy(int pMapPosX, int pMapPosY, TileMap *tileMap, SVG *canvas) {
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            this -> canvas = canvas;
            this -> tileMap = tileMap;
            x = tileMap -> getTilePosX(mapPosX, mapPosY);
            y = tileMap -> getTilePosY(mapPosX, mapPosY);
            
            tileMap -> setState(mapPosX, mapPosY, 2);
            sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/EnemyUp.png", "gfx/EnemyLeft.png",  "gfx/EnemyDown.png", "gfx/EnemyRight.png");
            
            
        }
    
        int moveUp(){
            if(tileMap -> getTileStateUp(mapPosX, mapPosY) == 0){
                tileMap -> setState(mapPosX, mapPosY, 0);
                mapPosY--;
                sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                tileMap -> setState(mapPosX, mapPosY, 2);
                return 0;
            } else if(tileMap -> getTileStateUp(mapPosX, mapPosY) == 3){
                return attDmg;
            }
            return 0;
        }
    
        int moveLeft(){
            if(tileMap -> getTileStateLeft(mapPosX, mapPosY) == 0){
                tileMap -> setState(mapPosX, mapPosY, 0);
                mapPosX--;
                sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                tileMap -> setState(mapPosX, mapPosY, 2);
                return 0;
            } else if(tileMap -> getTileStateLeft(mapPosX, mapPosY) == 3){
                return attDmg;
            }
            return 0;
        }
    
        int moveDown(){
            if(tileMap -> getTileStateDown(mapPosX, mapPosY) == 0){
                tileMap -> setState(mapPosX, mapPosY, 0);
                mapPosY++;
                sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                tileMap -> setState(mapPosX, mapPosY, 2);
                return 0;
            } else if(tileMap -> getTileStateDown(mapPosX, mapPosY) == 3){
                return attDmg;
            }
            return 0;
        }
    
        int moveRight(){
            if(tileMap -> getTileStateRight(mapPosX, mapPosY) == 0){
                tileMap -> setState(mapPosX, mapPosY, 0);
                mapPosX++;
                sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                tileMap -> setState(mapPosX, mapPosY, 2);
                return 0;
            } else if(tileMap -> getTileStateRight(mapPosX, mapPosY) == 3){
                return attDmg;   
            }
            return 0;
        }
    
        int autoMove() {
                switch(rand() % 4) {
                    case 0:
                        return moveUp();
                    case 1:
                        return moveLeft();
                        break;
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
    
        int getX() {
            return x;
        }
    
        void setX(int pX) {
            x = pX;
        }
    
        int getY() {
            return y;
        }
    
        void setY(int pY) {
            y = pY;
        }

        int getMapPosX(){
           return mapPosX;
        }
    
        int getMapPosY(){
           return mapPosY; 
        }
        
        // wird beim Löschen aufgerufen, damit das Tile auf dem der steht wieder den Tag 0 bekommt
        void adios(){
           tileMap -> setState(mapPosX, mapPosY, 0);
        }
    
};
#endif