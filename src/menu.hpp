#include <string>

class Menu {
    private:
        Image background;
        Image buttonBorder;
        Image btn1, btn2, btn3, btn4;
        Image currentSet;
        Text scoreText, killsText, lvlText;

        int buttonCounter = 0;
        int menuCounter;
        int diffSetting = 0; // 0=einfach, 1=mittel, 2=schwer
        string lastKey;
        bool gameStart = false;
    
        int highScore = 0;
        int overallKills = 0;
        int highestLvl = 0;
    
        SVG *canvas;
        
    public:
    
        Menu(int pHighScore, int pOverallKills, int pHighestLvl, SVG *pCanvas) {
            highScore = pHighScore;
            overallKills = pOverallKills;
            highestLvl = pHighestLvl;
            canvas = pCanvas;
            mainMenu();
        }
        
        void mainMenu() {
            menuCounter = 0;
            buttonCounter = 0;
            
            background = Image("gfx/menu/backgrounds/mainmenu.png", 1000, 750, 2000, 1500, canvas);
            
            btn1 = Image("gfx/menu/buttons/mainmenu/play.png", 1000, 500, 980, 180, canvas);
            btn2 = Image("gfx/menu/buttons/mainmenu/settings.png", 1000, 750, 980, 180, canvas);
            btn3 = Image("gfx/menu/buttons/mainmenu/statistics.png", 1000, 1000, 980, 180, canvas);
            btn4 = Image("gfx/menu/buttons/mainmenu/credits.png", 1000, 1250, 980, 180, canvas);
            
            buttonBorder = Image("gfx/menu/buttons/buttonborder.png", 1000, 500, 980, 180, canvas);
        }
        
        void diffMenu() {
            menuCounter = 1;
            buttonCounter = 0;
            
            background = Image("gfx/menu/backgrounds/settings.png", 1000, 750, 2000, 1500, canvas);
            
            btn1 = Image("gfx/menu/buttons/settings/easy.png", 1000, 500, 980, 180, canvas);
            btn2 = Image("gfx/menu/buttons/settings/normal.png", 1000, 750, 980, 180, canvas);
            btn3 = Image("gfx/menu/buttons/settings/hard.png", 1000, 1000, 980, 180, canvas);
            btn4 = Image("", 1000, 1020, 980, 180, canvas);
            
            currentSet = Image("gfx/menu/buttons/settings/current.png", 380, 500, 200, 180 , canvas);
            
            buttonBorder = Image("gfx/menu/buttons/buttonborder.png", 1000, 520, 980, 180, canvas);
            
            switch(diffSetting) { 
                case 0:
                    currentSet.moveTo(380, 500);
                    break;
                case 1:
                    currentSet.moveTo(380, 750);
                    break;
                case 2:
                    currentSet.moveTo(380, 1000);
                    break;
                default:
                    break;  
            }
        }
    
        void statisticsMenu() {
            menuCounter = 2;
            background = Image("gfx/menu/backgrounds/statistics.png", 1000, 750, 2000, 1500, canvas);
            
            scoreText = Text(to_string(highScore), 1200, 660, canvas);
            scoreText.setAttribute("font-size", 200);
            scoreText.setFill("white");
            scoreText.setColor("white");
                
            killsText = Text(to_string(overallKills), 750, 920, canvas);
            killsText.setAttribute("font-size", 200);
            killsText.setFill("white");
            killsText.setColor("white");
                
            lvlText = Text(to_string(highestLvl), 1350, 1170, canvas);
            lvlText.setAttribute("font-size", 200);
            lvlText.setFill("white");
            lvlText.setColor("white");
        }
    
        void creatorsMenu() {
            menuCounter = 3;
            background = Image("gfx/menu/backgrounds/credits.png", 1000, 750, 2000, 1500, canvas); 
        }
    
        void update(string lastKey) {
            if(lastKey == "ArrowDown") {
                if(buttonCounter < 3) {
                    buttonCounter++;
                } else {
                    buttonCounter = 0;
                }
            } else if(lastKey == "ArrowUp") {
                if(buttonCounter > 0) {
                     buttonCounter--;
                } else {
                    buttonCounter = 3;
                }
            }   
            
            switch(buttonCounter) {
                case 0:
                    buttonBorder.moveTo(1000, 500);           
                    break;
                case 1:
                    buttonBorder.moveTo(1000, 750);
                    break;
                case 2:
                    buttonBorder.moveTo(1000, 1000);
                    break;
                case 3:
                    if(menuCounter == 0) {
                        buttonBorder.moveTo(1000, 1250);
                    } else if(lastKey == "ArrowDown") {
                        buttonCounter = 0;
                    } else if(lastKey == "ArrowUp") {
                        buttonCounter = 2;
                    }
                    break;
                default:
                    break;  
            }
            
            if(lastKey == "Enter" && menuCounter == 0) {
                switch(buttonCounter) {
                    case 0:
                        gameStart = true;
                        break;
                    case 1:
                        diffMenu();
                        break;
                    case 2:
                        statisticsMenu();
                        break;
                    case 3:
                        creatorsMenu();
                        break;
                    default:
                        break;  
                }
            } else if(lastKey == "Enter" && menuCounter == 1) {
                switch(buttonCounter) {
                    case 0:
                        diffSetting = 0;
                        currentSet.moveTo(380, 500);
                        break;
                    case 1:
                        diffSetting = 1;
                        currentSet.moveTo(380, 750);
                        break;
                    case 2:
                        diffSetting = 2;
                        currentSet.moveTo(380, 1000);
                        break;
                    default:
                        break;  
                }
            } else if(lastKey == "Enter" && menuCounter == 2) {
                statisticsMenu();
            } else if(lastKey == "Enter" && menuCounter == 3) {
                creatorsMenu();
            }else if(lastKey == "Escape" && menuCounter > 0) { 
                mainMenu();
            }
        }
    
        bool getGameStart(int &difficult) {
           difficult = diffSetting; // Referenz mit int diff gleichsetzten
           return gameStart; 
        }
};