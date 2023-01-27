class Menu{
    private:
        Rect background;
        Rect buttonRim;
        Rect button1;
        Rect button2;
        Rect button3;
        Text titleText;
        Text button1Text;
        Text button2Text;
        Text button3Text;
        Text diffText;
        Text escText;
        int buttonCounter = 0;
        int menuCounter;
        int diffSetting = 0;
        string lastKey;
        bool gameStart = false;
        SVG *canvas;
        
    public:
    
        Menu(SVG *canvas){
            this -> canvas = canvas;
            mainMenu();
        }
        
        void mainMenu(){
            
            menuCounter = 0;
            buttonCounter = 0;
            background = Rect(0, 0, 5000, 5000, canvas);
            background.setFill("lightBlue");
            buttonRim = Rect(0, 0, 0, 0, canvas);
            titleText = Text("Cyber Crawler", 430, 300, canvas);
            titleText.setAttribute("font-size", 180);
            
            button1 = Rect(510, 460, 980, 180 , canvas);
            button2 = Rect(510, 710, 980, 180, canvas);
            button3 = Rect(510, 960, 980, 180, canvas);
            
            button1Text = Text("Spielen", 800, 580, canvas);
            button1Text.setAttribute("font-size", 100);
            button1Text.setAttribute("fill", "white");
            
            button2Text = Text("Schwierigkeit", 700, 830, canvas);
            button2Text.setAttribute("font-size", 100);
            button2Text.setAttribute("fill", "white");
            
            button3Text = Text("Mitwirkende", 725, 1080, canvas);
            button3Text.setAttribute("font-size", 100);
            button3Text.setAttribute("fill", "white");
        }
        
        void diffMenu(){
            
            menuCounter = 1;
            buttonCounter = 0;
            background = Rect(0, 0, 5000, 5000, canvas);
            background.setFill("red");
            buttonRim = Rect(0, 0, 0, 0, canvas);
            titleText = Text("Schwierigkeitsgrad", 250, 300, canvas);
            titleText.setAttribute("font-size", 180);
            
            button1 = Rect(510, 460, 980, 180 , canvas);
            button2 = Rect(510, 710, 980, 180, canvas);
            button3 = Rect(510, 960, 980, 180, canvas);
            
            button1Text = Text("Leicht", 850, 580, canvas);
            button1Text.setAttribute("font-size", 100);
            button1Text.setAttribute("fill", "white");
            
            button2Text = Text("Medium", 825, 830, canvas);
            button2Text.setAttribute("font-size", 100);
            button2Text.setAttribute("fill", "white");
            
            button3Text = Text("Schwer", 825, 1080, canvas);
            button3Text.setAttribute("font-size", 100);
            button3Text.setAttribute("fill", "white");
            
            switch(diffSetting){
                    
                case 0:
                    diffText = Text("Der Schwierigkeitsgrad ist auf LEICHT gesetzt.", 50, 1300, canvas);
                    diffText.setAttribute("font-size", 75);
                    break;
                    
                case 1:
                    diffText = Text("Der Schwierigkeitsgrad ist auf MEDIUM gesetzt.", 50, 1300, canvas);
                    diffText.setAttribute("font-size", 75);

                    break;
                    
                case 2:
                    diffText = Text("Der Schwierigkeitsgrad ist auf SCHWER gesetzt.", 50, 1300, canvas);
                    diffText.setAttribute("font-size", 75);
                    break;
                    
                default:
                    break;  
            }
            
            escText = Text("Esc, um zum Hauptmenü zurückzukehren.", 0, 1490, canvas);
            escText.setAttribute("font-size", 50);
        }
    
        void creatorsMenu(){
            menuCounter = 2;
            background = Rect(0, 0, 5000, 5000, canvas);
            background.setFill("green");
            
            titleText = Text("Mitwirkende", 475, 300, canvas);
            titleText.setAttribute("font-size", 180);

            button1Text = Text("Fynn Degen", 710, 580, canvas);
            button1Text.setAttribute("font-size", 100);
            
            button2Text = Text("Jan Miller", 750, 830, canvas);
            button2Text.setAttribute("font-size", 100);
            
            button3Text = Text("Jannis Neuhaus", 610, 1080, canvas);
            button3Text.setAttribute("font-size", 100);
            
            escText = Text("ESC, um zum Hauptmenü zurückzukehren.", 0, 1490, canvas);
            escText.setAttribute("font-size", 50);
            
        }
    
        void Update(string lastKey){
        
            if(lastKey == "ArrowDown"){
                if(buttonCounter < 2){
                    buttonCounter++;
                }
                else{
                    buttonCounter = 0;
                }
            } 
            else if(lastKey == "ArrowUp"){
                if(buttonCounter > 0){
                     buttonCounter--;
                }
                else{
                    buttonCounter = 2;
                }
            }   
            
            
            switch(buttonCounter){
                    
                case 0:
                    buttonRim.moveTo(500, 450);
                    buttonRim.setWidth(1000);
                    buttonRim.setHeight(200);
                    buttonRim.setFill("white");
                    break;
                    
                case 1:
                    buttonRim.moveTo(500, 700);
                    buttonRim.setWidth(1000);
                    buttonRim.setHeight(200);
                    buttonRim.setFill("white");
                    break;
                    
                case 2:
                    buttonRim.moveTo(500, 950);
                    buttonRim.setWidth(1000);
                    buttonRim.setHeight(200);
                    buttonRim.setFill("white");
                    break;
                    
                default:
                    break;  
            }
            
            if(lastKey == "Enter" && menuCounter == 0){
                switch(buttonCounter){
                    
                    case 0:
                        gameStart = true;
                        break;
                    
                    case 1:
                        diffMenu();
                        break;
                    
                    case 2:
                        creatorsMenu();
                        break;
                    
                    default:
                        break;  
                }
            }
            else if(lastKey == "Enter" && menuCounter == 1){
                
                switch(buttonCounter){
                    
                    case 0:
                        diffText = Text("Der Schwierigkeitsgrad ist auf LEICHT gesetzt.", 50, 1300, canvas);
                        diffText.setAttribute("font-size", 75);
                        diffSetting = 0;
                        break;
                    
                    case 1:
                        diffText = Text("Der Schwierigkeitsgrad ist auf MEDIUM gesetzt.", 50, 1300, canvas);
                        diffText.setAttribute("font-size", 75);
                        diffSetting = 1;
                        break;
                    
                    case 2:
                        diffText = Text("Der Schwierigkeitsgrad ist auf SCHWER gesetzt.", 50, 1300, canvas);
                        diffText.setAttribute("font-size", 75);
                        diffSetting = 2;
                        break;
                    
                    default:
                        break;  
                }
            }
            
            else if(lastKey == "Escape" && (menuCounter == 1 || menuCounter == 2)){ 
                mainMenu();
            }
        }
    
        
    
        bool getGameStart(){
           return gameStart; 
        }
};