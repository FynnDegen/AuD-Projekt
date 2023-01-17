#include "Ped.hpp"

class Enemy : Ped {
    private:
        int test;
        Sword sword = Sword(12, 2);
    
    public:
        Enemy(){
            
        }
    
        Enemy(int pHp, int pAttDmg, int pAttSpd, int pDirec, int pMapPosX, int pMapPosY, Image* pPlayerUp, Image* pPlayerLeft, Image* pPlayerDown, Image* pPlayerRight) : Ped(pHp, pAttDmg, pAttSpd, pDirec, pMapPosX, pMapPosY, pPlayerUp, pPlayerLeft, pPlayerDown, pPlayerRight) {
            
        }
};