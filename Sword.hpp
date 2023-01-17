class Sword {
    private:
        int dmg;
        int spd;

        int mapPosX;
        int mapPosY;
    
        Image sword;
        SVG *canvas;
     
    
    
    
    public:   
            Sword(int mapPosX, int mapPosY, Tile tileMap[15][15], SVG *canvas){
                sword = Image("PlayerDown.png", tileMap[mapPosY][mapPosX].getX(), tileMap[mapPosY][mapPosX].getY(), 100, 100, canvas);
                //sword.hide();
            
            }
    
        void melee() {
            sword.show();
            AlgoViz::sleep(300);
            sword.hide();
        }
    
        void moveSword(int pMapPosX, int pMapPosY, int pDirect, Tile tileMap[15][15]){
            switch(pDirect) {
                case 0:
                    sword.moveTo(tileMap[pMapPosY - 1][pMapPosX].getX() - 50, tileMap[pMapPosY - 1][pMapPosX].getY() - 50);
                    break;
                case 1:
                    sword.moveTo(tileMap[pMapPosY][pMapPosX - 1].getX() - 50, tileMap[pMapPosY][pMapPosX - 1].getY() - 50);
                    break;
                case 2:
                    sword.moveTo(tileMap[pMapPosY + 1][pMapPosX].getX() - 50, tileMap[pMapPosY + 1][pMapPosX].getY() - 50);
                    break;
                case 3:
                    sword.moveTo(tileMap[pMapPosY][pMapPosX + 1].getX() - 50, tileMap[pMapPosY][pMapPosX + 1].getY() - 50);
                    break;
                default:
                    break;
            }
        }
};