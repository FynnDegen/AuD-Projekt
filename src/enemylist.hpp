#include "enemy.hpp"
#include <algoviz/SVG.hpp>
#include <vector>

#ifndef ENEMYLIST_HPP
#define ENEMYLIST_HPP

class EnemyList {
    private:
        vector<Enemy> enemyList;
        vector<Enemy>::iterator it = enemyList.begin();
    
    public:
        EnemyList() {

        }

        EnemyList(TileMap *tileMap, SVG *canvas) {
            generateEnemyList(tileMap, canvas);
        }
    
        Enemy *enemyOnTile(int pMapPosX, int pMapPosY) {
            for(int i = 0; i < enemyList.size(); i++) {
                if(enemyList[i].getMapPosX() == pMapPosX && enemyList[i].getMapPosY() == pMapPosY) {
                    return &enemyList[i];
                }
            }
            return nullptr;        
        }
    
        // löscht den getoeteten Enemy aus dem Vector
        void deleteEnemy(int pPosX, int pPosY){
            for(int i = 0; i < enemyList.size(); i++) {
                if (enemyList[i].getMapPosX() == pPosX && enemyList[i].getMapPosY() == pPosY) {
                    enemyList[i].adios();
                    enemyList.erase(enemyList.begin() + i);
                }
            }
        }
    
        Enemy * getEnemy(int i) {
            return &enemyList[i];
        }
    
        int getSize(){
            return enemyList.size(); 
        }
    
        void generateEnemyList(TileMap *tileMap, SVG *canvas) {
            for(int i = 0; i < 4; i++) {
                Tile *tile = tileMap -> getRandomFreeTile();
                enemyList.push_back(Enemy(tile -> getMapX(), tile -> getMapY(), tileMap, canvas));
            }
        }
    
        void clearEnemyList() {
            enemyList.clear();
        }
};
#endif