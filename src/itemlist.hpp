#include <algoviz/SVG.hpp>
#include <cstdlib>
#include <vector>
#include "item.hpp"

#ifndef ITEMLIST_HPP
#define ITEMLIST_HPP

class ItemList {
    private:
        vector<Item> itemList;
        vector<Item>::iterator it;
    
    public:

        // Konstruktoren //

        ItemList() {

        }

        ItemList(TileMap *tileMap, SVG *canvas) {
            generateItemList(tileMap, canvas);
        }
    
        // Methoden //

        // fragt ab, ob ein Item auf dem Tile ist und gibt es ggf. zurueck
        Item *itemOnTile(int pMapPosX, int pMapPosY) {
            for(int i = 0; i < itemList.size(); i++) {
                if(itemList[i].getMapPosX() == pMapPosX && itemList[i].getMapPosY() == pMapPosY) {
                    return &itemList[i];
                }
            }
            return nullptr;        
        }

        // loescht ein Item
        void deleteItem(Item *pItem) {
            if(pItem != nullptr) {
                for(int i = 0; i < itemList.size(); i++) {
                    if(&itemList[i] == pItem) {
                        itemList[i].destroyImage();
                        itemList.erase(itemList.begin() + i);
                    }
                }
            }
        }

        // generiert eine Itemliste mit zufaellig vielen Items
        void generateItemList(TileMap *tileMap, SVG *canvas) {
            for(int i = 0; i < rand() % 2; i++) {
                Tile *tile = tileMap -> getRandomFreeTile();
                itemList.push_back(Item(tile -> getMapX(), tile -> getMapY(), 6, tileMap, canvas));
                tile -> setState(6);
            }
            for(int i = 0; i < 1 + rand() % 3; i++) {
                Tile *tile = tileMap -> getRandomFreeTile();
                itemList.push_back(Item(tile -> getMapX(), tile -> getMapY(), 7, tileMap, canvas));
                tile -> setState(7);
            }
            for(int i = 0; i < 1 + rand() % 2; i++) {
                Tile *tile = tileMap -> getRandomFreeTile();
                itemList.push_back(Item(tile -> getMapX(), tile -> getMapY(), 8, tileMap, canvas));
                tile -> setState(8);
            }
            Tile *tile = tileMap -> getRandomFreeTile();
            itemList.push_back(Item(tile -> getMapX(), tile -> getMapY(), 9, tileMap, canvas));
            tile -> setState(9);
            
        }
    
        // loescht alle Eintraege aus dem Vector
        void clearItemList() {
            itemList.clear();
        }
    
        // loescht alle Itembilder
        void deleteAllImages() {
            for(int i = 0; i < itemList.size(); i++) {
                itemList[i].destroyImage();
            }
        }

        // sondierende Methoden //

        Item *getItem(int i) {
            return &itemList[i];
        }
    
        int getSize() {
            return itemList.size(); 
        }
};
#endif