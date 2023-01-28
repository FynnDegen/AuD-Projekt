#ifndef ITEM_HPP
#define ITEM_HPP

class Item {
    private:
        int mapPosX;
        int mapPosY;
        int itemType;

        Image itemImage;

        TileMap *tileMap;
        SVG *canvas;
    
   public:
        Item(int pMapPosX, int pMapPosY, int pItemType,  TileMap *pTileMap, SVG *pCanvas) {
            mapPosX = pMapPosX;
            mapPosY = pMapPosY;
            itemType = pItemType;
            tileMap = pTileMap;
            canvas = pCanvas;

            switch(itemType){
                case 6:
                    itemImage = Image("gfx/items/batteryitem.png", tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), 100, 100, canvas);
                    break;
                case 7:
                    itemImage = Image("gfx/items/algoitem.png", tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), 100, 100, canvas);
                    break;
                case 8:
                    itemImage = Image("gfx/items/sworditem.png", tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), 100, 100, canvas);
                    break;
                case 9:
                    itemImage = Image("gfx/items/mapkeyitem.png", tileMap -> getTilePosX(mapPosX, mapPosY), tileMap -> getTilePosY(mapPosX, mapPosY), 100, 100, canvas);
                    break;
                default:
                    break;
            }
        }

        int getMapPosX() {
            return mapPosX;
        }

        int getMapPosY() {
            return mapPosY;
        }

        int getItemType() {
            return itemType;
        }
    
        SVG * getSVG() {
            return canvas;
        }
};
#endif