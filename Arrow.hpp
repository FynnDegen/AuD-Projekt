class Arrow {
    private:
        int dmg;
        int spd;
        
    
    public:
        Arrow(int pDmg, int pSpd, SVG *canvas) {
            dmg = pDmg;
            spd = pSpd;
            Image arrow = Image("arrow.png", -500, -500, 200, 200, canvas);
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