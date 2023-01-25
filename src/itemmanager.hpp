//ABHÄNGIG VON ITEM- UND PLAYERKLASSE 
#include <vector>
#include <iostream>
class ItemManager{
    
    private:
        std::vector<Item*> items;
        int save[15][15];
        Player *player;
    public:
        ItemManager(Player *player){   
            this -> player = player;
                //befüllt ein Array mit -1en
                for(int i = 0; i < 15; i++){
                    for(int e = 0; e < 15; e++){
                        save[i][e] = -1;
                    }
                }
        }
        //erstellt ein dyamisches Item und spreichert die Adresse in einer Liste, der Index wird mit der Position in einem Array gespeichert
        void spawnItem(int itemType, int mapPosX, int mapPosY, SVG *canvas){
            Item *item = new Item(itemType, mapPosX, mapPosY, canvas, player);
            items.push_back(item);    
            save[mapPosY][mapPosX] = items.size() - 1;
        }
        //gibt den Index des Itemvektors wieder
        int getItemIndex(int mapPosX, int mapPosY){
            return save[mapPosY][mapPosX];
        }
        //löscht das Item, wenn man die Position von diesem kennt
        void deleteItem(int mapPosX, int mapPosY){
            if(getItemIndex(mapPosX, mapPosY) == -1){
                std::cout << "Error";
            }else{
                delete(items[getItemIndex(mapPosX, mapPosY)]);
                save[mapPosY][mapPosX] = -1;
            }
        }
        //Guckt nach, ob die Position des Item mit dem des Spielers übereinstimmt und übergibt Informationen IN die Mainklasse
        void itemUpdate(bool *isOnItem, int *itemMapPosX, int *itemMapPosY, int counter){
            if((player -> getMapPosX() == items[counter] -> getMapPosX() && player -> getMapPosY() == items[counter] -> getMapPosY())){
                *itemMapPosX = items[counter] -> getMapPosX();
                *itemMapPosY = items[counter] -> getMapPosY();
                *isOnItem = true;
            }
        }
        
    
    
};