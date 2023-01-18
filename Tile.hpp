class Tile {
    
    private:
        int posX;
        int posY;
        int state; // speichert den Tag den das Tile zugeteilt bekommt (1=Wand, 0=Frei, 2=Enemy, 3u4 item oder so) 
                   // NUR WERTE ZWISCHEN 0 und 4!
        int mapX;  // speichert die x-Pos vom Array Bauplan
        int mapY;  // speichert die y-Pos vom Array Bauplan
        SVG *field;
        Image tile;
    
    public:      
        Tile() {
            posX = 0;
            posY = 0;
            state = 1;
            field = nullptr;

        }

        Tile(int posX, int posY, int mapX, int mapY, int state, SVG *field) {
            this -> posX = posX;
            this -> posY = posY;
            this -> state = state;
            this -> field = field;
            this -> mapX = mapX;
            this -> mapY = mapY;

            if(state == 1) {
                tile = Image("gfx/wallFinal.png",posX + 50, posY + 50, 100, 100, field);
            } else {
                tile = Image("gfx/floor.png",posX + 50, posY + 50, 100, 100, field);
            }

        }

        int getX() {
            return posX + 50;
        }
        int getY() {
            return posY + 50;
        }
        int getMapX() {
            return mapX;
        }
        int getMapY() {
            return mapY;
        }
        int getState() {
            return state;
        }
    
        void setState(int state){
         
                this -> state = state;
            
        }
};