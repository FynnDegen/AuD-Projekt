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

        // Konstruktoren //

        TileMap() {
            
        }

        TileMap(SVG *pCanvas) {
            canvas = pCanvas;
            generateTileMap();
        }
    
        // Methoden //

        // gebe ein freies Feld zurueck
        Tile * getRandomFreeTile() {
            int x, y;
            do {
                x = 1 + std::rand() % 14;
                y = 1 + std::rand() % 14;
            } while(tileMap[y][x].getState() != 0);
            return &tileMap[y][x];
        }
    
        // Position des Schwerts
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

        // Position des Schwerts
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

        // Kartenposition des Schwerts
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

        // Kartenposition des Schwerts
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

        // ist Gegner in Schwertrichtung
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

        // dynamische Kartengenerierung
        void generateTileMap() {
            // setzte alles auf Waende
            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 15; j++) {
                    walls[i][j] = 1;
                }
            }

            // generiere Weg an einem zufaelligen Startpunkt
            generateMaze(1 + std::rand() % 14, 1 + std::rand() % 14);

            // generiere Raueme
            for(int i = 0; i < 1 + std::rand() % 3; i++) {
                int x = 1 + std::rand() % 11;
                int y = 1 + std::rand() % 11;

                for(int j = 0; j < 3; j++) {
                    for(int k = 0; k < 3; k++) {
                        walls[y + k][x + j] = 0;
                    }
                }  
            }

            // generiere Aussenwand
            for(int i = 0; i < 14; i++) {
                walls[i][0] = 1;
                walls[0][i] = 1;
                walls[i][14] = 1;
                walls[14][i] = 1;
            }
            
            // uebersetze in Tiles
            for(int i = 0; i < 15; i++) {
                for(int k = 0; k < 15; k++) {
                    tileMap[i][k] = Tile(k*100, i*100, k, i, walls[i][k], canvas);
                }
            }
            
            setMapExit();
        }
    
        void generateMaze(int pX, int pY) {
            // Startpunkt
            walls[pX][pY] = 0;

            // zufaellige Richtungen
            int directions[4] = {0, 1, 2, 3};
            std::random_shuffle(directions, directions + 4);

            // Weggenerierung
            for (int i = 0; i < 4; i++) {
                // wenn die Richtung 0 ist und zwei Bloecke dahinter frei ist gehe ein vor
                if (directions[i] == 0 && pX > 2 && walls[pX-2][pY] != 0) {
                    walls[pX-1][pY] = 0;
                    generateMaze(pX-2, pY);
                }
                // wenn die Richtung 1 ist und zwei Bloecke dahinter frei ist gehe ein vor
                if (directions[i] == 1 && pX < 12 && walls[pX+2][pY] != 0) {
                    walls[pX+1][pY] = 0;
                    generateMaze(pX+2, pY);
                }
                // wenn die Richtung 2 ist und zwei Bloecke dahinter frei ist gehe ein vor
                if (directions[i] == 2 && pY > 2 && walls[pX][pY-2] != 0) {
                    walls[pX][pY-1] = 0;
                    generateMaze(pX, pY-2);
                }
                // wenn die Richtung 3 ist und zwei Bloecke dahinter frei ist gehe ein vor
                if (directions[i] == 3 && pY < 12 && walls[pX][pY+2] != 0) {
                    walls[pX][pY+1] = 0;
                    generateMaze(pX, pY+2);
                }
            }
        }
    
        // generiere zufaelligen Kartenausgang
        void setMapExit() {
            Tile *tile = getRandomFreeTile();
            *tile = Tile(tile -> getX() - 50, tile -> getY() - 50, tile -> getMapX(), tile -> getMapY(), 5, canvas);
        }

        // sondierende Methoden //

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
#endif