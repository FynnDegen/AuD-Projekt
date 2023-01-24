//WICHTIG! Player einen Wert auf tileMap geben, wie der gegener auch, also mit setState. Gemacht

#include <algoviz/SVG.hpp>
#include "enemylist.hpp"
#include "sprite.hpp"
#include "sword.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{
    private:
        int hp;
        int attDmg = 10;
        int attSpd;
    
        int mapPosX;
        int mapPosY;
        int direc;
    
        SVG *canvas;
        TileMap *tileMap;
        EnemyList *enemyList;
        
        Sprite sprite;
        //Sword sword;
        Image testSword;
    
    public:
        Player(){
            
        }
    
        Player(int pMapPosX, int pMapPosY, TileMap *tileMap, EnemyList *pEnemyList, SVG *canvas) {
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            this -> canvas = canvas;
            this -> tileMap = tileMap;
            enemyList = pEnemyList;
            
            sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/PlayerUp.png", "gfx/PlayerLeft.png",  "gfx/PlayerDown.png", "gfx/PlayerRight.png");
            
            //sword = Sword(tileMap -> getTilePosX(mapPosX + 1, mapPosY), tileMap -> getTilePosY(mapPosX + 1, mapPosY), canvas);
            testSword = Image("gfx/bild.png", tileMap -> getTilePosX(mapPosX + 1, mapPosY), tileMap -> getTilePosY(mapPosX + 1, mapPosY), 100, 100, canvas);
        }
    
        void keyMovement(string pKey, EnemyList *pEnemyList){
            if(pKey == "w"){
                sprite.toFront(0);
                direc = 0;
                tileMap -> setState(mapPosX, mapPosY, 0);
                if(tileMap -> getTileStateUp(mapPosX, mapPosY) == 0){
                    mapPosY--;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                }
                tileMap -> setState(mapPosX, mapPosY, 3);
            } else if(pKey == "a"){
                sprite.toFront(1);
                direc = 1;
                tileMap -> setState(mapPosX, mapPosY, 0);
                if(tileMap -> getTileStateLeft(mapPosX, mapPosY) == 0){
                    mapPosX--;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));         
                }
                tileMap -> setState(mapPosX, mapPosY, 3);
            } else if(pKey == "s"){
                sprite.toFront(2);
                direc = 2;
                tileMap -> setState(mapPosX, mapPosY, 0);
                if(tileMap -> getTileStateDown(mapPosX, mapPosY) == 0){
                    mapPosY++;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                }
                tileMap -> setState(mapPosX, mapPosY, 3);
            } else if(pKey == "d"){
                sprite.toFront(3);
                direc = 3;
                tileMap -> setState(mapPosX, mapPosY, 0);
                if(tileMap -> getTileStateRight(mapPosX, mapPosY) == 0){
                    mapPosX++;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                }
                tileMap -> setState(mapPosX, mapPosY, 3);
            } else if(pKey == "q") {
                testSword.moveTo(tileMap -> getSwordPosX(mapPosX, mapPosY, direc), tileMap -> getSwordPosY(mapPosX, mapPosY, direc));
                Enemy *enemy = enemyList -> enemyOnTile(tileMap -> getSwordMapPosX(mapPosX, mapPosY, direc), tileMap -> getSwordMapPosY(mapPosX, mapPosY, direc));
                if(enemy != nullptr) {
                    testSword.moveTo(1000, 1000);
                    enemy -> setHP(enemy -> getHP() - attDmg);
                    
                    //std::cout << enemy << std::endl;
                    
                    if (enemy -> getHP() <= 0){
                        enemyList -> deleteEnemy(tileMap -> getSwordMapPosX(mapPosX, mapPosY, direc), tileMap -> getSwordMapPosY(mapPosX, mapPosY, direc));
                    }
                } 
            } else if(pKey == "ArrowUp") {
                sprite.toFront(0);
                direc = 0;
                //sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 0), tileMap -> getSwordPosY(mapPosX, mapPosY, 0));
            } else if(pKey == "ArrowLeft") {
                sprite.toFront(1);
                direc = 1;
                //sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 1), tileMap -> getSwordPosY(mapPosX, mapPosY, 1));
            } else if(pKey == "ArrowDown") {
                sprite.toFront(2);
                direc = 2;
                //sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 2), tileMap -> getSwordPosY(mapPosX, mapPosY, 2));
            } else if(pKey == "ArrowRight") {
                sprite.toFront(3);
                direc = 3;
                //sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 3), tileMap -> getSwordPosY(mapPosX, mapPosY, 3));
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
    
        // Brauchen wir, weil nur Player das Schwert kennt
        int getSwordX(){
            return 0;
        }
    
        int getSwordY(){
            return 0;
        }
    
};
#endif