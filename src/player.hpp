//WICHTIG! Player einen Wert auf tileMap geben, wie der gegener auch, also mit setState. Gemacht

#include <algoviz/SVG.hpp>
#include "enemylist.hpp"
#include "sprite.hpp"
#include <string>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{
    private:
        int hp = 10;
        int attDmg = 10;
        int attSpd;
    
        int score = 0;
    
        int mapPosX;
        int mapPosY;
        int direc;
    
        SVG *canvas;
        TileMap *tileMap;
        EnemyList *enemyList;
        
        Sprite sprite;
        Image sword;
        Rect dead;
    
        // rudimentäres Textfeld fuers Leben
        Text health;
        Text dmg;
        Text points;
        Text deadText;
    
    public:
        Player(){
            
        }
    
        Player(int pMapPosX, int pMapPosY, TileMap *tileMap, EnemyList *pEnemyList, SVG *canvas) {
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            this -> canvas = canvas;
            this -> tileMap = tileMap;
            enemyList = pEnemyList;
            direc = 3;
            
            dead = Rect(0, 0, 1500, 1500, canvas);
            dead.hide();
            dead.setFill(176, 30, 30, 0.6);
            
            sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/PlayerUp.png", "gfx/PlayerLeft.png",  "gfx/PlayerDown.png", "gfx/PlayerRight.png");
            
            sword = Image("gfx/bild.png", tileMap -> getSwordPosX(mapPosX, mapPosY, direc), tileMap -> getSwordPosY(mapPosX, mapPosY, direc), 100, 100, canvas);
            sword.hide();
            
            health = Text("HP: " + to_string(hp), 100, 1570, canvas); 
            health.setAttribute("font-size", 50); 
            dmg = Text("DMG: " + to_string(attDmg), 600, 1570, canvas); 
            dmg.setAttribute("font-size", 50);
            points = Text("SCORE: " + to_string(score), 1100, 1570, canvas); 
            points.setAttribute("font-size", 50);
            deadText = Text("REBOOTING...", 500, 750, canvas); 
            deadText.setAttribute("font-size", 80);
            deadText.setAttribute("font-stroke", 7);
            deadText.setFill("white");
            deadText.setColor("white");
            deadText.hide();
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
                sword.moveTo(tileMap -> getSwordPosX(mapPosX, mapPosY, direc), tileMap -> getSwordPosY(mapPosX, mapPosY, direc));
                sword.show();
                Enemy *enemy = enemyList -> enemyOnTile(tileMap -> getSwordMapPosX(mapPosX, mapPosY, direc), tileMap -> getSwordMapPosY(mapPosX, mapPosY, direc));
                if(enemy != nullptr) {
                    enemy -> setHP(enemy -> getHP() - attDmg);
                    
                    if (enemy -> getHP() <= 0){
                        enemyList -> deleteEnemy(tileMap -> getSwordMapPosX(mapPosX, mapPosY, direc), tileMap -> getSwordMapPosY(mapPosX, mapPosY, direc));
                    }
                }
                AlgoViz::sleep(200);
                sword.hide();
            } else if(pKey == "ArrowUp") {
                sprite.toFront(0);
                direc = 0;
            } else if(pKey == "ArrowLeft") {
                sprite.toFront(1);
                direc = 1;
            } else if(pKey == "ArrowDown") {
                sprite.toFront(2);
                direc = 2;
            } else if(pKey == "ArrowRight") {
                sprite.toFront(3);
                direc = 3;
            }
        }
    
        int getHP() {
            return hp;
        }

        void setHP(int pHP) {
            hp = pHP;
            if (hp <= 0) {
                dead.show();
                dead.toFront();
                deadText.show();
                deadText.toFront();
                hp = 0;
            }
            health.setText("HP: " + to_string(hp));
        }

        int getAttDmg() {
            return attDmg;
        }

        void setAttDmg(int pAttDmg) {
            attDmg += pAttDmg;
            dmg.setText("DMG: " + to_string(attDmg));
        }
    
        int getMapPosX() {
            return mapPosX;
        }
    
        int getMapPosY() {
            return mapPosY;
        }
    
        void setScore(int pScore){
            score += pScore;
            points.setText("SCORE: " + to_string(score));
        }
};
#endif