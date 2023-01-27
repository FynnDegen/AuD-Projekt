#include "tile.hpp"
#include <cstdlib>

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

class TileMap {
    private:
        SVG *canvas;
        Tile tileMap[15][15];
        int walls[15][15];
   
    public:
        TileMap() {
            
        }

        TileMap(SVG *pCanvas) {
            canvas = pCanvas;
            generateTileMap();
        }
    
        Tile * getRandomFreeTile() {
            int x, y;
            do {
                x = 1 + std::rand() % 14;
                y = 1 + std::rand() % 14;
            } while(tileMap[y][x].getState() != 0);
            return &tileMap[y][x];
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

        int getTileState(int pMapPosX, int pMapPosY) {
            return tileMap[pMapPosY][pMapPosX].getState();
        }

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
    
        void generateTileMap() {
            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 15; j++) {
                    walls[i][j] = 1;
                }
            }

            generateMaze(1 + std::rand() % 14, 1 + std::rand() % 14);

            for(int i = 0; i < 1 + std::rand() % 3; i++) {
                int x = 1 + std::rand() % 11;
                int y = 1 + std::rand() % 11;

                for(int j = 0; j < 3; j++) {
                    for(int k = 0; k < 3; k++) {
                        walls[y + k][x + j] = 0;
                    }
                }  
            }

            for(int i = 0; i < 14; i++) {
                walls[i][0] = 1;
                walls[0][i] = 1;
                walls[i][14] = 1;
                walls[14][i] = 1;
            }
            
            for(int i = 0; i < 15; i++) {
                for(int k = 0; k < 15; k++) {
                    tileMap[i][k] = Tile(k*100, i*100, k, i, walls[i][k], canvas);
                }
            }
            
            setMapExit();
        }
    
        void generateMaze(int x, int y) {
            walls[x][y] = 0;

            int directions[4] = {0, 1, 2, 3};
            std::random_shuffle(directions, directions + 4);

            for (int i = 0; i < 4; i++) {
                if (directions[i] == 0 && x > 2 && walls[x-2][y] == 1) {
                    walls[x-1][y] = 0;
                    generateMaze(x-2, y);
                }
                if (directions[i] == 1 && x < 12 && walls[x+2][y] == 1) {
                    walls[x+1][y] = 0;
                    generateMaze(x+2, y);
                }
                if (directions[i] == 2 && y > 2 && walls[x][y-2] == 1) {
                    walls[x][y-1] = 0;
                    generateMaze(x, y-2);
                }
                if (directions[i] == 3 && y < 12 && walls[x][y+2] == 1) {
                    walls[x][y+1] = 0;
                    generateMaze(x, y+2);
                }
            }
        }
    
        void setMapExit() {
            Tile *tile = getRandomFreeTile();
            *tile = Tile(tile -> getX() - 50, tile -> getY() - 50, tile -> getMapX(), tile -> getMapY(), 5, canvas);
        }
};
#endif