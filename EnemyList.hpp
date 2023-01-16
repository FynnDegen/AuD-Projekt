#include "Enemy.hpp"

class EnemyList {
    Enemy enemy[4];
    
        public:
            EnemyList() {
                enemy[0] = Enemy(100, 5,1,4,3,1,nullptr,nullptr,nullptr,nullptr);
            }
};