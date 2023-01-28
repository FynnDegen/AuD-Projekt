#include "item.hpp"
#include <algoviz/SVG.hpp>
#include <vector>

#ifndef ITEMLIST_HPP
#define ITEMLIST_HPP

class ItemList {
    private:
        vector<Item> itemList;
        vector<Item>::iterator it;
    
    public:
        ItemList() {

        }

        ItemList(TileMap *tileMap, SVG *canvas) {
            generateItemList(tileMap, canvas);
        }
    
        Item *itemOnTile(int pMapPosX, int pMapPosY) {
            for(int i = 0; i < itemList.size(); i++) {
                if(itemList[i].getMapPosX() == pMapPosX && itemList[i].getMapPosY() == pMapPosY) {
                    return &itemList[i];
                }
            }
            return nullptr;        
        }

        void deleteItem(int pPosX, int pPosY) {
            for(it = itemList.begin(); it != itemList.end(); it++) {
                if(it -> getMapPosX() == pPosX && it -> getMapPosY() == pPosY) {
                    //itemList[it].destroyImage();
                    itemList.erase(it);
                }
            }
        }
    
        Item *getItem(int i) {
            return &itemList[i];
        }
    
        int getSize() {
            return itemList.size(); 
        }
    
        void generateItemList(TileMap *tileMap, SVG *canvas) {
            for(int i = 6; i <= 9; i++) {
                Tile *tile = tileMap -> getRandomFreeTile();
                itemList.push_back(Item(tile -> getMapX(), tile -> getMapY(), i, tileMap, canvas));
                tile -> setState(i);
            }
        }
    
        void clearItemList() {
            itemList.clear();
        }
};
#endif