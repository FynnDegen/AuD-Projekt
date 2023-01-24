#include "enemy.hpp"
#include <algoviz/SVG.hpp>

#ifndef ENEMYLIST_HPP
#define ENEMYLIST_HPP

class EnemyList {
    private:
        vector<Enemy> enemyList;
    
    public:
        EnemyList() {

        }

        EnemyList(TileMap *tileMap, SVG *canvas) {
            enemyList.begin();
                enemyList.push_back(Enemy(12, 2, tileMap, canvas));
                enemyList.push_back(Enemy(5, 9, tileMap, canvas));
                enemyList.push_back(Enemy(2, 2, tileMap, canvas));
                enemyList.push_back(Enemy(5, 7, tileMap, canvas));
        }
    
        Enemy *enemyOnTile(int pMapPosX, int pMapPosY) {
            /*
            vector<Enemy>::iterator it;
            
            for(it = enemyList.begin(); it != enemyList.end(); it++) {
                if(it -> getMapPosX() == pMapPosX && it -> getMapPosY() == pMapPosY) {
                    return &it;
                }
            }
            return nullptr;
            */
            
            for(int i = 0; i < enemyList.size(); i++) {
                if(enemyList[i].getMapPosX() == pMapPosX && enemyList[i].getMapPosY() == pMapPosY) {
                    return &enemyList[i];
                }
            }
            return nullptr;
            
        }
    
        void damageEnemy() {
            
        }
};
#endif