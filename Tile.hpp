class Tile{
    
    public:
            int posX;
            int posY;
            int state; // speichert den Tag den das Tile zugeteilt bekommt (1=Wand, 0=Frei, 2 3 4=Item oder so)
            int mapX;  // speichert die x-Pos vom Array Bauplan
            int mapY;  // speichert die y-Pos vom Array Bauplan
            SVG *field;
            Image tile;
            
    Tile(){
        posX = 0;
        posY = 0;
        state = 1;
        field = nullptr;
       
    }
    
    Tile(int posX, int posY, int mapX, int mapY, int state, SVG *field){
        this -> posX = posX;
        this -> posY = posY;
        this -> state = state;
        this -> field = field;
        this -> mapX = mapX;
        this -> mapY = mapY;
        if(state == 1){
            tile = Image("dot.png",posX + 50, posY + 50, 100, 100, field);
            //tile.setColor("red");
        }else{
           tile = Image("dot.png",posX, posY, 0, 0, field);
        }
        
    }
    
    int getX(){
        return posX + 50;
    }
    int getY(){
        return posY + 50;
    }
    int getMapX(){
        return mapX;
    }
    int getMapY(){
        return mapY;
    }
    int getTag(){
        return state;   
    }
};