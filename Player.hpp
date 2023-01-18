class Player{
    private:
        int hp;
        int attDmg;
        int attSpd;
    
        int mapPosX;
        int mapPosY;
        int direc;
    
        SVG *canvas;
        TileMap *tileMap;
        
        Sprite sprite;
        Sword sword;
    
    public:
        Player(){
            
        }
    
        Player(int pMapPosX, int pMapPosY, TileMap *tileMap, SVG *canvas){
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            this -> canvas = canvas;
            this -> tileMap = tileMap;
            
            sprite = Sprite(canvas, tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), "gfx/PlayerUp.png", "gfx/PlayerLeft.png",  "gfx/PlayerDown.png", "gfx/PlayerRight.png");
            
            sword = Sword(tileMap -> getTilePosX(mapPosX + 1, mapPosY), tileMap -> getTilePosY(mapPosX + 1, mapPosY), canvas);
        }
    
        void keyMovement(string pKey){
            if(pKey == "w"){
                sprite.toFront(0);
                direc = 0;
                if(tileMap -> getTileStateUp(mapPosX, mapPosY) == 0){
                    mapPosY--;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                    sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 0), tileMap -> getSwordPosY(mapPosX, mapPosY, 0));
                }
            } else if(pKey == "a"){
                sprite.toFront(1);
                direc = 1;
                if(tileMap -> getTileStateLeft(mapPosX, mapPosY) == 0){
                    mapPosX--;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY)); 
                    sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 1), tileMap -> getSwordPosY(mapPosX, mapPosY, 1));
                }
            } else if(pKey == "s"){
                sprite.toFront(2);
                direc = 2;
                if(tileMap -> getTileStateDown(mapPosX, mapPosY) == 0){
                    mapPosY++;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                    sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 2), tileMap -> getSwordPosY(mapPosX, mapPosY, 2));
                }
            } else if(pKey == "d"){
                sprite.toFront(3);
                direc = 3;
                if(tileMap -> getTileStateRight(mapPosX, mapPosY) == 0){
                    mapPosX++;
                    sprite.moveSprite(tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY));
                    sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 3), tileMap -> getSwordPosY(mapPosX, mapPosY, 3));
                }
            }else if(pKey == "q") {
                sword.melee();
            }else if(pKey == "ArrowUp") {
                sprite.toFront(0);
                direc = 0;
                sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 0), tileMap -> getSwordPosY(mapPosX, mapPosY, 0));
            } else if(pKey == "ArrowLeft") {
                sprite.toFront(1);
                direc = 1;
                sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 1), tileMap -> getSwordPosY(mapPosX, mapPosY, 1));
            } else if(pKey == "ArrowDown") {
                sprite.toFront(2);
                direc = 2;
                sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 2), tileMap -> getSwordPosY(mapPosX, mapPosY, 2));
            } else if(pKey == "ArrowRight") {
                sprite.toFront(3);
                direc = 3;
                sword.moveSword(tileMap -> getSwordPosX(mapPosX, mapPosY, 3), tileMap -> getSwordPosY(mapPosX, mapPosY, 3));
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
    
};