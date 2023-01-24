#include <algoviz/SVG.hpp>

#ifndef SPRITE_HPP
#define SPRITE_HPP

class Sprite {
    private:
        Image pedUp, pedLeft, pedDown, pedRight;
    public:
        Sprite() {
            
        }
    
        // Nuetzlich fuer die Items
        Sprite(SVG *pSVG, int pX, int pY, std::string pPedUpPath) {
            pedUp = Image(pPedUpPath, pX, pY, 100, 100, pSVG);
        }

        // Fuer Spieler und Gegner
        Sprite(SVG *pSVG, int pX, int pY, std::string pPedUpPath, std::string pPedLeftPath, std::string pPedDownPath, std::string pPedRightPath) {
            pedUp = Image(pPedUpPath, pX, pY, 100, 100, pSVG);
            pedLeft = Image(pPedLeftPath, pX, pY, 100, 100, pSVG);
            pedDown = Image(pPedDownPath, pX, pY, 100, 100, pSVG);
            pedRight = Image(pPedRightPath, pX, pY, 100, 100, pSVG);
        }
    
        void moveSprite(int pX, int pY) {
            pedUp.moveTo(pX, pY);
            pedLeft.moveTo(pX, pY);
            pedDown.moveTo(pX, pY);
            pedRight.moveTo(pX, pY);
        }
    
        void toFront(int n) {
            switch(n) {
                case 0:
                    pedUp.toFront();
                    break;
                case 1:
                    pedLeft.toFront();
                    break;
                case 2:
                    pedDown.toFront();
                    break;
                case 3:
                    pedRight.toFront();
                    break;
                default:
                    break;
            }
        }
};
#endif