class Sword {
    private:
        int dmg;
        int spd;

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
            dmg = 10;
        }
    
        void melee() {
            sword.show();
            AlgoViz::sleep(300);
            sword.hide();
        }
    
        void moveSword(int pX, int pY) {
            sword.moveTo(pX, pY);
            mapPosX = pX;
            mapPosY = pY;
        }
    
        int getDmg(){
            return dmg;   
        }
};