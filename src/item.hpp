//ABHÄNGIG VON DER PLAYERKLASSE
#include <iostream>
class Item{
    
       private:
            Image itemImage;
            int mapPosX;
            int mapPosY;
            int itemType;
            SVG *canvas;
            Player *player;
    
       public:
            Item(int itemType, int mapPosX, int mapPosY,SVG *canvas, Player *player){
                this -> mapPosX = mapPosX;
                this -> mapPosY = mapPosY;
                this -> canvas = canvas;
                this -> itemType = itemType;
                this -> player = player;
                
                switch(itemType){
                    case 1:
                        itemImage = Image("gfx/battery.png", mapPosX * 100 + 50, mapPosY * 100 + 50, 100, 100, canvas);
                        break;
                    case 2:
                        itemImage = Image("gfx/crystal.png", mapPosX * 100 + 50, mapPosY * 100 + 50, 100, 100, canvas);
                        break;
                    case 3:
                        itemImage = Image("gfx/bild.png", mapPosX * 100 + 50, mapPosY * 100 + 50, 100, 100, canvas);
                }
            }
    
            ~Item(){
                switch(itemType){
                    case 1:
                        player -> setHP(player -> getHP() + 25);
                        break;
                    case 2:
                        player -> setScore(42);
                        break;
                    case 3:
                        player -> setAttDmg(5);
                        break;
                }
            }
        
            int getMapPosX(){
                return mapPosX;
            }
            
            int getMapPosY(){
                return mapPosY;
            }
            
            int getItemType(){
                return itemType;
            }
            

};