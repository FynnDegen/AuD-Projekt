#include <algoviz/SVG.hpp>
#include "enemylist.hpp"
#include "itemlist.hpp"
#include "overlay.hpp"
#include "sprite.hpp"
#include <string>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
    private:
        int hp = 100;
        int attDmg = 10;
    
        int score = 0;
        int kills = 0;
        int lvl = 1;
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
        Overlay overlay;
    
        bool startNewGame = false;
    
        // rudimentäres Textfeld fuers Leben

    
    public:

        // Konstruktoren //

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
            
            sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/player/playerup.png", "gfx/player/playerleft.png",  "gfx/player/playerdown.png", "gfx/player/playerright.png");
            
            sword = Image("gfx/player/sword.png", tileMap -> getSwordPosX(mapPosX, mapPosY, direc), tileMap -> getSwordPosY(mapPosX, mapPosY, direc), 100, 100, canvas);
            sword.hide();
            
            overlay = Overlay(canvas);
        }

        // Methoden //
    
        // koordiniert die Tasten
        void keyMovement(string pKey, EnemyList *pEnemyList) {
            if(hp > 0) {
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
                            if(enemy -> getType() == 0) {
                                setScore(score + 25);
                            } else if(enemy -> getType() == 1) {
                                setScore(score + 50);
                            }
                            kills++;
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
        }
        
        // setze Spieler auf die gegebene Position
        void setPlayerOnMapPos(int pMapPosX, int pMapPosY) {
            tileMap -> setState(mapPosX, mapPosY, 0);
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
            tileMap -> setState(mapPosX, mapPosY, 3);
        }
    
        // bewegt den Spieler
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
    
        // fragt ab, ob sich ein Item auf dem Feld an der gegebenen Position befindet
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
                    overlay.updateMapKey(mapKey);
                    break;
                default:
                    tileMap -> setState(mapPosX, mapPosY, 3);
                    break;
            }
            itemList -> deleteItem(itemList -> itemOnTile(mapPosX, mapPosY));
        }
    
        // erstellt eine neue TileMap für die naechste Ebene
        void resetTileMap() {
            mapKey = false;
            enemyList -> clearEnemyList();
            itemList -> deleteAllImages();
            itemList -> clearItemList();
            setLvl(lvl + 1);
            tileMap -> generateTileMap();
            Tile *tile = tileMap -> getRandomFreeTile();
            setPlayerOnMapPos(tile -> getMapX(), tile -> getMapY());
            enemyList -> generateEnemyList(tileMap, canvas, lvl);
            itemList -> generateItemList(tileMap, canvas);
            sprite.toFront(direc);
            overlay.updateMapKey(mapKey);
        }
    
        // sondierende Methoden //
    
        int getHP() {
            return hp;
        }

        // wenn die hp kleiner als 0 sind, kann man ein neues Spiel starten
        void setHP(int pHP) {
            hp = pHP;
            if (hp <= 0) {
                hp = 0;
                overlay.showDeathScreen();
                startNewGame = true;
            }
            overlay.updateHealth(hp);
        }
    
        int getAttDmg() {
            return attDmg;
        }

        void setAttDmg(int pAttDmg) {
            attDmg = pAttDmg;
            overlay.updateDmg(attDmg);
        }
    
        int getMapPosX() {
            return mapPosX;
        }
    
        int getMapPosY() {
            return mapPosY;
        }
    
        int getScore() {
            return score;
        }
    
        void setScore(int pScore) {
            score = pScore;
            overlay.updatePoints(score);
        }
    
        void setLvl(int pLvl) {
            lvl = pLvl;
            overlay.updateLvl(lvl);
        }
    
        int getKills() {
            return kills;
        }
    
        int getLvl() {
            return lvl;
        }
    
        bool getStartNewGame() {
            return startNewGame;
        }
};
#endif