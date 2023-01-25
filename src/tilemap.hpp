#include "tile.hpp"

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

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
    
        Tile getTile(int pMapPosX, int pMapPosY) {
            return tileMap[pMapPosY][pMapPosX];
        }
    
        int getTilePosX(int pMapPosX, int pMapPosY) {
            return tileMap[pMapPosY][pMapPosX].getX();
        }

        int getTilePosY(int pMapPosX, int pMapPosY) {
            return tileMap[pMapPosY][pMapPosX].getY();
        }

        // Funkt
        int getTileState(int pMapPosX, int pMapPosY) {
            int z = tileMap[pMapPosY][pMapPosX].getState();
            return z;
        }

        // Funktioniert
        void setState(int pMapPosX, int pMapPosY, int n) {
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

        int getSwordMapPosX(int pMapPosX, int pMapPosY, int pDirec) {
            switch(pDirec) {
                case 0:
                    return pMapPosX;
                case 1:
                    return pMapPosX - 1;
                case 2:
                    return pMapPosX;
                case 3:
                    return pMapPosX + 1;
                default:
                    return 0;
            }
        }

        int getSwordMapPosY(int pMapPosX, int pMapPosY, int pDirec) {
            switch(pDirec) {
                case 0:
                    return pMapPosY - 1;
                case 1:
                    return pMapPosY;
                case 2:
                    return pMapPosY + 1;
                case 3:
                    return pMapPosY;
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

        int swordHit(int pMapPosX, int pMapPosY, int pDirec) {
            switch(pDirec) {
                case 0:
                    if(getTileStateUp(pMapPosX, pMapPosY) == 2) {
                        return 1;
                    } else {
                        return 0; 
                    }
                case 1:
                    if(getTileStateLeft(pMapPosX, pMapPosY) == 2) {
                        return 1;
                    } else {
                        return 0;
                    }
                case 2:
                    if(getTileStateDown(pMapPosX, pMapPosY) == 2) {
                       return 1; 
                    } else {
                       return 0; 
                    }
                case 3:
                    if(getTileStateRight(pMapPosX, pMapPosY) == 2) {
                       return 1;
                    } else {
                       return 0;
                    }
                default:
                    return 0;
            }
        }
};
#endif