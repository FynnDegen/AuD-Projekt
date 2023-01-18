class TileMap {
    private:
        SVG *canvas;
        Tile tileMap[15][15];
   
    public:
        TileMap() {
            
        }

        TileMap(SVG *pCanvas) {
            canvas = pCanvas;
            int walls[15][15] = {
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                {1,1,0,0,0,0,0,1,1,1,1,0,0,0,1},
                {1,0,0,1,1,1,0,0,1,0,0,0,0,0,1},
                {1,1,0,0,0,0,0,1,1,0,1,0,0,0,1},
                {1,1,1,1,0,1,0,0,0,0,0,1,0,1,1},
                {1,1,1,0,0,1,1,1,0,1,0,1,0,1,1},
                {1,0,0,0,1,0,0,1,0,1,0,0,0,0,1},
                {1,0,1,0,0,0,1,1,0,1,0,1,1,0,1},
                {1,0,1,1,1,0,1,1,0,0,0,0,1,0,1},
                {1,0,0,1,1,0,0,0,0,1,1,0,0,0,1},
                {1,1,0,0,0,0,1,1,0,1,1,1,1,1,1},
                {1,1,0,1,1,1,1,1,0,0,0,0,0,1,1},
                {1,0,0,1,1,0,0,0,0,1,1,0,1,1,1},
                {1,1,0,0,0,0,1,1,0,1,0,0,0,0,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            };
            
            for(int i = 0; i < 15; i++) {
                for(int k = 0; k < 15; k++) {
                    tileMap[i][k] = Tile(k*100, i*100, k, i, walls[i][k], canvas);
                }
            }
        }
    
    int getTilePosX(int pMapPosX, int pMapPosY) {
        return tileMap[pMapPosY][pMapPosX].getX();
    }
    
    int getTilePosY(int pMapPosX, int pMapPosY) {
        return tileMap[pMapPosY][pMapPosX].getY();
    }
    
    // Funkt net so richtig
    int getTileState(int pMapPosX, int pMapPosY){
        int z = tileMap[pMapPosY][pMapPosX].getState();
        return z;
    }
    
    // Funktioniert
    void setState(int pMapPosX, int pMapPosY, int n){
        tileMap[pMapPosY][pMapPosX].setState(n);
    }
    
    int getSwordPosX(int pMapPosX, int pMapPosY, int pDirec) {
        switch(pDirec) {
            case 0:
                return tileMap[pMapPosY - 1][pMapPosX].getX() - 50;
            case 1:
                return tileMap[pMapPosY][pMapPosX - 1].getX() - 50;
            case 2:
                return tileMap[pMapPosY + 1][pMapPosX].getX() - 50;
            case 3:
                return tileMap[pMapPosY][pMapPosX + 1].getX() - 50;
            default:
                return 0;
        }
    }
    
    int getSwordPosY(int pMapPosX, int pMapPosY, int pDirec) {
        switch(pDirec) {
            case 0:
                return tileMap[pMapPosY - 1][pMapPosX].getY() - 50;
            case 1:
                return tileMap[pMapPosY][pMapPosX - 1].getY() - 50;
            case 2:
                return tileMap[pMapPosY + 1][pMapPosX].getY() - 50;
            case 3:
                return tileMap[pMapPosY][pMapPosX + 1].getY() - 50;
            default:
                return 0;
        }
    }
    
    int getTileStateUp(int pMapPosX, int pMapPosY) {
        return tileMap[pMapPosY - 1][pMapPosX].getState();
    }
    
    int getTileStateLeft(int pMapPosX, int pMapPosY) {
        return tileMap[pMapPosY][pMapPosX - 1].getState();
    }
    
    int getTileStateDown(int pMapPosX, int pMapPosY) {
        return tileMap[pMapPosY + 1][pMapPosX].getState();
    }
    
    int getTileStateRight(int pMapPosX, int pMapPosY) {
        return tileMap[pMapPosY][pMapPosX + 1].getState();
    }
};