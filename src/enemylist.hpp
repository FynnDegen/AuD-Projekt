#include "enemy.hpp"
#include <algoviz/SVG.hpp>
#include <vector>
#include <cstdlib>

#ifndef ENEMYLIST_HPP
#define ENEMYLIST_HPP

class EnemyList {
    private:
        vector<Enemy> enemyList;
        vector<Enemy>::iterator it = enemyList.begin();
        int diff;
    
    public:

        // Konstruktoren //

        EnemyList() {

        }

        EnemyList(TileMap *tileMap, SVG *canvas, int difficult) {
            diff = difficult;
            generateEnemyList(tileMap, canvas, 1);
        }

        // Methoden //
    
        // fragt ab, ob ein Gegner auf dem Tile ist und gibt es ggf. zurueck
        Enemy *enemyOnTile(int pMapPosX, int pMapPosY) {
            for(int i = 0; i < enemyList.size(); i++) {
                if(enemyList[i].getMapPosX() == pMapPosX && enemyList[i].getMapPosY() == pMapPosY) {
                    return &enemyList[i];
                }
            }
            return nullptr;        
        }
    
        // loescht den getoeteten Gegner aus dem Vector
        void deleteEnemy(int pPosX, int pPosY){
            for(int i = 0; i < enemyList.size(); i++) {
                if (enemyList[i].getMapPosX() == pPosX && enemyList[i].getMapPosY() == pPosY) {
                    enemyList[i].adios();
                    enemyList.erase(enemyList.begin() + i);
                }
            }
        }

        // generiert eine Liste mit zuefaellig vielen Gegner in Abhaengigkeit vom Schwierigkeitsgrads
        void generateEnemyList(TileMap *tileMap, SVG *canvas, int lvl) {
            for(int i = 0; i < numberOfLightEnemies(); i++) {
                Tile *tile = tileMap -> getRandomFreeTile();
                enemyList.push_back(Enemy(tile -> getMapX(), tile -> getMapY(), tileMap, canvas, lvl, 0));
            }
            for(int i = 0; i < numberOfHeavyEnemies(); i++) {
                Tile *tile = tileMap -> getRandomFreeTile();
                enemyList.push_back(Enemy(tile -> getMapX(), tile -> getMapY(), tileMap, canvas, lvl, 1));
            }
        }
    
        // gibt die Zahl der leichten Gegner zurueck in Abhaengigkeit vom Schwierigkeitsgrad
        int numberOfLightEnemies() {
            switch(diff) {
                case 0:
                    return 3 + rand() % 4;
                case 1:
                    return 5 + rand() % 8;
                case 2:
                    return 8 + rand() % 12;
                default:
                    return 3 + rand() % 4;
            }
        }
    
        // gibt die Zahl der schweren Gegner zurueck in Abhaengigkeit vom Schwierigkeitsgrad
        int numberOfHeavyEnemies() {
            switch(diff) {
                case 0:
                    return rand() % 2;
                case 1:
                    return 1 + rand() % 3;
                case 2:
                    return 3 + rand() % 5;
                default:
                    return rand() % 2;
            }
        }
    
        // loescht alle Elemente aus dem Vector
        void clearEnemyList() {
            enemyList.clear();
        }

        // sondierende Methoden //

        Enemy * getEnemy(int i) {
            return &enemyList[i];
        }
    
        int getSize(){
            return enemyList.size(); 
        }
};
#endif