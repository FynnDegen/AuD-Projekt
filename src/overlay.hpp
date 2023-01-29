#ifndef OVERLAY_HPP
#define OVERLAY_HPP

class Overlay {
    private:
        Image overlay;
        Image cross, checkmark;
        Text health, dmg, points, lvlText;
    
        Rect dead;
        Text deadText;
        
    public:
    
        // Konstruktoren //
    
        Overlay() {
            
        }
    
        Overlay(SVG *canvas) {
            dead = Rect(0, 0, 1500, 1500, canvas);
            dead.hide();
            dead.setFill(176, 30, 30, 0.6);
            
            overlay = Image("gfx/overlay/overlay.png", 1750, 750, 500, 1500, canvas);

            health = Text("100", 1740, 290, canvas); 
            health.setAttribute("font-size", 100); 
            health.setFill("white");
            health.setColor("white");

            dmg = Text("10", 1740, 420, canvas); 
            dmg.setAttribute("font-size", 100);
            dmg.setFill("white");
            dmg.setColor("white");

            lvlText = Text("1", 1740, 530, canvas); 
            lvlText.setAttribute("font-size", 100);
            lvlText.setFill("white");
            lvlText.setColor("white");

            points = Text("0", 1740, 630, canvas); 
            points.setAttribute("font-size", 100);
            points.setFill("white");
            points.setColor("white");

            deadText = Text("REBOOTING...", 500, 750, canvas); 
            deadText.setAttribute("font-size", 80);
            deadText.setAttribute("font-stroke", 7);
            deadText.setFill("white");
            deadText.setColor("white");
            deadText.hide();

            checkmark = Image("gfx/overlay/checkmark.png", 1780, 685, 100, 100, canvas);
            checkmark.hide();
            cross = Image("gfx/overlay/cross.png", 1780, 685, 100, 100, canvas);
        }
    
        // Methoden //
    
        void updateHealth(int pHP) {
            health.setText(to_string(pHP));
        }
    
        void updateDmg(int pDmg) {
            dmg.setText(to_string(pDmg));
        }
    
        void updatePoints(int pPoints) {
            points.setText(to_string(pPoints));
        }
    
        void updateLvl(int pLvl) {
            lvlText.setText(to_string(pLvl));
        }
    
        void updateMapKey(bool pKey) {
            if(pKey) {
                cross.hide();
                checkmark.show();
            } else {
                checkmark.hide();
                cross.show();
            }
        }
    
        void showDeathScreen() {
            dead.show();
            dead.toFront();
            deadText.show();
            deadText.toFront();
        }
};
#endif