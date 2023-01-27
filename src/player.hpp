//WICHTIG! Player einen Wert auf tileMap geben, wie der gegener auch, also mit setState. Gemacht

#include <algoviz/SVG.hpp>
#include "enemylist.hpp"
#include "itemlist.hpp"
#include "sprite.hpp"
#include <string>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
    private:
        int hp = 100;
        int attDmg = 10;
        int attSpd;
    
        int score = 0;
        int floor = 0;
        bool mapKey = false;
    
        int mapPosX;
        int mapPosY;
        int direc;
    
        SVG *canvas;
        TileMap *tileMap;
        EnemyList *enemyList;
        ItemList *itemList;
        
        Sprite sprite;
        Image sword;
        Rect dead;
    
        // rudimentäres Textfeld fuers Leben
        Text health;
        Text dmg;
        Text points;
        Text floorText;
        Text deadText;
    
    public:
        Player() {
            
        }
    
        Player(int pMapPosX, int pMapPosY, TileMap *pTileMap, EnemyList *pEnemyList, ItemList *pItemList, SVG *pCanvas) {
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            canvas = pCanvas;
            tileMap = pTileMap;
            enemyList = pEnemyList;
            itemList = pItemList;
            direc = 3;
            
            tileMap -> setState(mapPosX, mapPosY, 3);
            
            dead = Rect(0, 0, 1500, 1500, canvas);
            dead.hide();
            dead.setFill(176, 30, 30, 0.6);
            
            sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/player/playerup.png", "gfx/player/playerleft.png",  "gfx/player/playerdown.png", "gfx/player/playerright.png");
            
            sword = Image("gfx/bild.png", tileMap -> getSwordPosX(mapPosX, mapPosY, direc), tileMap -> getSwordPosY(mapPosX, mapPosY, direc), 100, 100, canvas);
            sword.hide();

            health = Text("HP: " + to_string(hp), 1600, 200, canvas); 
            health.setAttribute("font-size", 50); 
            dmg = Text("DMG: " + to_string(attDmg), 1600, 400, canvas); 
            dmg.setAttribute("font-size", 50);
            points = Text("SCORE: " + to_string(score), 1600, 600, canvas); 
            points.setAttribute("font-size", 50);
            floorText = Text("FLOOR: " + to_string(floor), 1600, 800, canvas); 
            floorText.setAttribute("font-size", 50);
            deadText = Text("REBOOTING...", 500, 750, canvas); 
            deadText.setAttribute("font-size", 80);
            deadText.setAttribute("font-stroke", 7);
            deadText.setFill("white");
            deadText.setColor("white");
            deadText.hide();
        }
    
        void keyMovement(string pKey, EnemyList *pEnemyList) {
            if(pKey == "w") {
                movePlayer(0);
            } else if(pKey == "a") {
                movePlayer(1);
            } else if(pKey == "s") {
                movePlayer(2);
            } else if(pKey == "d") {
                movePlayer(3);
            } else if(pKey == "q") {
                sword.moveTo(tileMap -> getSwordPosX(mapPosX, mapPosY, direc), tileMap -> getSwordPosY(mapPosX, mapPosY, direc));
                sword.toFront();
                sword.show();
                Enemy *enemy = enemyList -> enemyOnTile(tileMap -> getSwordMapPosX(mapPosX, mapPosY, direc), tileMap -> getSwordMapPosY(mapPosX, mapPosY, direc));
                if(enemy != nullptr) {
                    enemy -> setHP(enemy -> getHP() - attDmg);
                    
                    if (enemy -> getHP() <= 0){
                        enemyList -> deleteEnemy(tileMap -> getSwordMapPosX(mapPosX, mapPosY, direc), tileMap -> getSwordMapPosY(mapPosX, mapPosY, direc));
                        setScore(score + 25);
                    }
                }
                AlgoViz::sleep(200);
                sword.hide();
            } else if(pKey == "ArrowUp") {
                sprite.toFront(direc = 0);
            } else if(pKey == "ArrowLeft") {
                sprite.toFront(direc = 1);
            } else if(pKey == "ArrowDown") {
                sprite.toFront(direc = 2);
            } else if(pKey == "ArrowRight") {
                sprite.toFront(direc = 3);
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
            attDmg = pAttDmg;
            dmg.setText("DMG: " + to_string(attDmg));
        }
    
        int getMapPosX() {
            return mapPosX;
        }
    
        int getMapPosY() {
            return mapPosY;
        }
    
        void setScore(int pScore) {
            score = pScore;
            points.setText("SCORE: " + to_string(score));
        }
    
        void setFloor(int pFloor) {
            floor = pFloor;
            floorText.setText("FLOOR: " + to_string(floor));
        }
    
        int getScore() {
            return score;
        }
    
        void setPlayerOnMapPos(int pMapPosX, int pMapPosY) {
            tileMap -> setState(mapPosX, mapPosY, 0);
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
            tileMap -> setState(mapPosX, mapPosY, 3);
        }
    
        void movePlayer(int pDirec) {
            sprite.toFront(direc = pDirec);
            switch(pDirec) {
                case 0:
                    if(tileMap -> getTileStateUp(mapPosX, mapPosY) == 0 || tileMap -> getTileStateUp(mapPosX, mapPosY) > 4) {
                        mapPosY--;
                        sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                        itemOnTile();
                        if(tileMap -> getTileState(mapPosX, mapPosY + 1) != 5) {
                            tileMap -> setState(mapPosX, mapPosY + 1, 0);
                        }
                    }
                    break;
                case 1:
                    if(tileMap -> getTileStateLeft(mapPosX, mapPosY) == 0 || tileMap -> getTileStateLeft(mapPosX, mapPosY) > 4) {
                        mapPosX--;
                        sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                        itemOnTile();
                        if(tileMap -> getTileState(mapPosX + 1, mapPosY) != 5) {
                            tileMap -> setState(mapPosX + 1, mapPosY, 0);
                        }
                    }
                    break;
                case 2:
                    if(tileMap -> getTileStateDown(mapPosX, mapPosY) == 0 || tileMap -> getTileStateDown(mapPosX, mapPosY) > 4) {
                        mapPosY++;
                        sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                        itemOnTile();
                        if(tileMap -> getTileState(mapPosX, mapPosY - 1) != 5) {
                            tileMap -> setState(mapPosX, mapPosY - 1, 0);
                        }
                    }
                    break;
                case 3:
                    if(tileMap -> getTileStateRight(mapPosX, mapPosY) == 0 || tileMap -> getTileStateRight(mapPosX, mapPosY) > 4) {
                        mapPosX++;
                        sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                        itemOnTile();
                        if(tileMap -> getTileState(mapPosX - 1, mapPosY) != 5) {
                            tileMap -> setState(mapPosX - 1, mapPosY, 0);
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    
        void itemOnTile() {
            switch(tileMap -> getTileState(mapPosX, mapPosY)) {
                case 5:
                    if(mapKey) {
                        resetTileMap();
                    }
                    break;
                case 6:
                    setHP(hp + 25);
                    tileMap -> setState(mapPosX, mapPosY, 3);
                    break;
                case 7:
                    setScore(score + 42);
                    tileMap -> setState(mapPosX, mapPosY, 3);
                    break;
                case 8:
                    setAttDmg(attDmg + 5);
                    tileMap -> setState(mapPosX, mapPosY, 3);
                    break;
                case 9:
                    mapKey = true;
                    tileMap -> setState(mapPosX, mapPosY, 3);
                    break;
                default:
                    tileMap -> setState(mapPosX, mapPosY, 3);
                    break;
            }
            itemList -> deleteItem(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
        }
    
        void resetTileMap() {
            mapKey = false;
            enemyList -> clearEnemyList();
            itemList -> clearItemList();
            tileMap -> generateTileMap();
            Tile *tile = tileMap -> getRandomFreeTile();
            setPlayerOnMapPos(tile -> getMapX(), tile -> getMapY());
            enemyList -> generateEnemyList(tileMap, canvas);
            itemList -> generateItemList(tileMap, canvas);
            sprite.toFront(direc);
            setFloor(floor + 1);
        }
};
#endif