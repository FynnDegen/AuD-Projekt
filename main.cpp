#include <algoviz/SVG.hpp>
#include <iostream>

AlgoViz::clear();

SVG canvas = SVG(1920, 1080);

class Arrow {
    private:
        int dmg;
        int spd;
        Image arrow = Image("arrow.png", -500, -500, 200, 200, &canvas);
    
    public:
        Arrow(int pDmg, int pSpd) {
            dmg = pDmg;
            spd = pSpd;
        }
    
        void shoot(int pX, int pY) {
            arrow.moveTo(pX, pY);
            arrow.show();
            while(arrow.getX() < 1920) {
                arrow.moveTo(arrow.getX() + 5, arrow.getY());
            }
            arrow.hide();
        }
};

class Sword {
    private:
        int dmg;
        int spd;
        Image sword;
    
    public:
        Sword(int pDmg, int pSpd, int pX, int pY) {
            sword = Image("woosh3.png", pX + 300, pY, 500, 500, &canvas);
            sword.hide();
            dmg = pDmg;
            spd = pSpd;
        }
    
        void melee() {
            sword.show();
            AlgoViz::sleep(300);
            sword.hide();
        }
    
        void moveTo(int pX, int pY) {
            sword.moveTo(pX, pY);
        }
};

class Animation {
    private:
        Image arr[4];
    
    public:
        Animation() {
            arr[0] = Image("bild.png",500,500,600,600, &canvas);
            arr[1] = Image("bild2.jpeg",500,500,600,600, &canvas);
            arr[2] = Image("bild3.jpeg",500,500,600,600, &canvas);
            arr[3] = Image("bild4.jpeg",500,500,600,600, &canvas);
        }
    
        void playAnimation() {
            for(int j = 0; j < 200; j++) {
                for(int i = 0; i < 4; i++) {
                    arr[i].hide();
                }
                arr[0].show(); 
                for(int i = 0; i < 3; i++) {
                    AlgoViz::sleep(500);
                    arr[i].hide();
                    arr[i+1].show();
                }
            }
        }
};

class Player {
    private:
        int hp;
        int attDmg;
        int attSpd;
    
        int x;
        int y;
        int direc;
        int mapPos;
    
        Image player = Image("bild.png", 500, 500, 600, 600, &canvas);
        Image player2 = Image("bild2.jpeg",500,500,600,600, &canvas);
        Sword sword = Sword(1, 10, getX(), getY());
        Arrow arrow = Arrow(1, 10);
    
    public:
        Player(int pX, int pY) {
            x = pX;
            y = pY;
        }

        void keyMovement(std::string pKey) {
            if(pKey == "w") {
                player2.toFront();
                setY(getY() - 100);
                player.moveTo(getX(), getY());
                player2.moveTo(getX(), getY());
                sword.moveTo(getX(), getY());
            } else if(pKey == "a") {
                player.toFront();
                setX(getX() - 100);
                player.moveTo(getX(), getY());
                player2.moveTo(getX(), getY());
                sword.moveTo(getX(), getY());
            } else if(pKey == "s") {
                player.toFront();
                setY(getY() + 100);
                player.moveTo(getX(), getY());
                player2.moveTo(getX(), getY());
                sword.moveTo(getX(), getY());
            } else if(pKey == "d") {
                player2.toFront();
                setX(getX() + 100);
                player.moveTo(getX(), getY());
                player2.moveTo(getX(), getY());
                sword.moveTo(getX(), getY());
            } else if(pKey == "e") {
                arrow.shoot(getX(), getY());
            } else if(pKey == "q") {
                sword.melee();
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
    
        int getX() {
            return x;
        }
    
        void setX(int pX) {
            x = pX;
        }
    
        int getY() {
            return y;
        }
    
        void setY(int pY) {
            y = pY;
        }
};

Player player = Player(500, 500);

std::string key = canvas.lastKey();

while(key != "p") {
    key = canvas.lastKey();
    player.keyMovement(key);
}

class Enemy {
    
};

class Item {
    private:
        int addHeal;
        int addAtt;
        int addAttSpd;
        int addDef;
    
        Image item;
    
    public:
        Item(int pAddHeal, int pAddAtt, int pAddAttSpd, int pAddDef) {
            addHeal = pAddHeal;
            addAtt = pAddAtt;
            addAttSpd = pAddAttSpd;
            addDef = pAddDef;
        }
};


