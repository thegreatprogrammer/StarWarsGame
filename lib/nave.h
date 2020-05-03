// Definiendo constantes
 
# define ARRIBA 72
# define IZQUIERDA 75
# define DERECHA 77
# define ABAJO 80

/*Mostramos los kilómetros recorridos por la nave
void pintar_cantidad(int asteroide){
     gotoxy(38,2); printf("KM: %d", asteroide);
}*/


class NAVE{
//Atributos privados
    int x,y;
    int corazon;
    int vidas;

//Métodos públicos    
public: 

    //Constructor
    NAVE(int _x, int _y, int _corazon, int _vidas);
    int X(){ return x; }
    int Y(){ return y; }
    int VID(){ return vidas; }
    void pintar();
    void borrar();
    void mover();
    void corazones(); 
    void COR() {corazon--;}
    void die();    

};

// Definir el constructor NAVE

NAVE::NAVE(int _x, int _y, int _corazon, int _vidas){
    x = _x;
    y = _y; 
    corazon = _corazon;  
    vidas = _vidas;            
}

/* Otra forma de definir el constructor:
        
NAVE::NAVE(int _x, int _y): x(_x), y(_y){}
   
        */

//Función para pintar la navecita
void NAVE::pintar(){
     color(11);
     gotoxy(x,y);   printf("   __");
     gotoxy(x,y+1); printf("  /||\\");
     gotoxy(x,y+2); printf(" / %c%c \\",192,217); 
     gotoxy(x,y+3); printf("|=====|//");  
     gotoxy(x,y+4); printf(" \\ /\\ /");  
     gotoxy(x,y+5); printf("  \\__/"); 
}

// Método borrar de la navecilla

void NAVE::borrar(){
     gotoxy(x,y);   printf("         ");
     gotoxy(x,y+1); printf("         ");    
     gotoxy(x,y+2); printf("         ");
     gotoxy(x,y+3); printf("         ");
     gotoxy(x,y+4); printf("         ");
     gotoxy(x,y+5); printf("         ");
}

// Método mover de la nave

void NAVE::mover(){
     if(kbhit()){
                 
         char tecla = getch();
         borrar();
         if(tecla == IZQUIERDA && x>3) x--;
         if(tecla == DERECHA && x+9<77) x++;
         if(tecla == ARRIBA && y>2) y--;
         if(tecla == ABAJO && y+6<33) y++;
         pintar();
         corazones();
     }
}

// Este método escribe la cantidad de salud y vidas de la nave. La salud en corazones,
//las vidas en números enteros.

void NAVE::corazones(){
     
     gotoxy(50,2); printf("Vidas %d", vidas);
     gotoxy(64,2); printf("Salud");
     gotoxy(70,2); printf("      "); 
     
     for(int i=0; i<corazon; i++){
         gotoxy(70+i,2); printf("%c",3);    
     }   
}

// Método que se ejecutará en dos ocasiones: cuando la nave queda con la salud
//en 0, o cuando las vidas llegan a 0.

void NAVE::die(){
     
     if(corazon == 0){
         borrar();
         gotoxy(x,y);   printf("   *   ");
         gotoxy(x,y+1); printf("  ****  "); 
         gotoxy(x,y+2); printf(" ******   ");
         gotoxy(x,y+3); printf("  *****  ");
         gotoxy(x,y+4); printf("   ***   ");
         gotoxy(x,y+5); printf("    *   ");
         Sleep(200);
         
         borrar();
         
         gotoxy(x,y);   printf(" ** ** **");
         gotoxy(x,y+1); printf(" * *** * "); 
         gotoxy(x,y+2); printf("   ****");
         gotoxy(x,y+3); printf("  * ** *");
         gotoxy(x,y+4); printf("  * ** * ");
         gotoxy(x,y+2); printf(" ** ** **");
         
         Sleep(200);
         
         borrar();
         
         vidas--;
         corazon = 3;
         corazones();
         pintar();         
     }     
}
