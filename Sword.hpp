#include "enemylist.hpp"

#ifndef SWORD_HPP
#define SWORD_HPP

class Sword {
    private:
        int mapPosX;
        int mapPosY;
    
        Image sword;
        SVG *canvas;

    public:
        Sword() {
            
        }
    
        Sword(int pX, int pY, SVG *canvas) {
            sword = Image("gfx/bild.png", pX, pY, 100, 100, canvas);
            sword.hide();
            mapPosX = pX;
            mapPosY = pY;
        }

        void melee(EnemyList &pEnemyList) {
            sword.show();
            Enemy *enemy = pEnemyList.enemyOnTile(mapPosX, mapPosY);
            if(enemy != nullptr) {
                enemy -> moveDown();
            }
            sword.hide();
        }
    
        void moveSword(int pX, int pY) {
            sword.moveTo(pX, pY);
            mapPosX = pX;
            mapPosY = pY;
        }
};
#endif