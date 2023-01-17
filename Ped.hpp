class Ped {
    private:
        int hp;
        int attDmg;
        int attSpd;
    
        int x;
        int y;
        int direc;
        int mapPosX;
        int mapPosY;
    
        Image* playerUp;
        Image* playerLeft;
        Image* playerDown;
        Image* playerRight;
        SVG *canvas;
        Image enemy1;
        
    
    
    public:
        Ped(){
            
        }
    
        Ped(int pDirec, int pMapPosX, int pMapPosY, Image* pPlayerUp, Image* pPlayerLeft, Image* pPlayerDown, Image* pPlayerRight, Tile tileMap[15][15], SVG *canvas) {
            direc = pDirec;
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;

            playerUp = pPlayerUp;
            playerLeft = pPlayerUp;
            playerDown = pPlayerUp;
            playerRight = pPlayerUp;
            this -> canvas = canvas;
            
            enemy1 = Image("bild.png", tileMap[pMapPosY][pMapPosX].getX(), tileMap[pMapPosY][pMapPosX].getY(), 100, 100, canvas);
        }
    
        void setAttributes(int pAttHp,int pAttDmg, int pAttSpd){
            pAttHp = hp;
            pAttDmg = attDmg;
            pAttSpd = attSpd;
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
    
        int getAttSpd() {
            return attSpd;
        }

        void setAttSpd(int pAttSpd) {
            attSpd = pAttSpd;
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
    
        int getDirec() {
            return direc;
        }
    
        void setDirec(int pDirec) {
            direc = pDirec;
        }
    
        int getMapPosX() {
            return mapPosX;
        }
    
        void setMapPosX(int pMapPosX) {
            mapPosX = pMapPosX;
        }
    
        int getMapPosY() {
            return mapPosY;
        }
    
        void setMapPosY(int pMapPosY) {
            mapPosY = pMapPosY;
        }
};