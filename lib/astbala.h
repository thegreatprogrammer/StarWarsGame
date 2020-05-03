// ASTEROIDES

class AST{
      // Atributos iniciales (privados)
    int x, y;

public:

    // Constructor del asteroide
    AST(int _x, int _y):x(_x), y(_y){}
    
    // Métodos que permiten a otras clases conocer el valor de los atributos
    // anteriormente privados.
    int X(){ return x; }
    int Y(){ return y; }
    
    void pintar();
    void mover();
    void choque(class NAVE &N); //Se pasa el objeto por referencia para poder hacer cambios
    // a la nave durante una colisión.
    void choque(class naveSith &N);
          
};

void AST::pintar(){

     gotoxy(x,y); printf("%c", 184); //Nuestro asteroide es un carácter ASCII de bolita
}

void AST::mover(){
     
     gotoxy(x,y); printf(" ");
     y++;
     
     if(y > 32){
         x = rand()%71 + 4;
         y = 4;     
     }    
     pintar(); 
}

void AST::choque(class NAVE &N){
     
     if( x >= N.X() && x < N.X()+6 && y >= N.Y() && y <= N.Y()+2){
          
          N.COR();
          N.borrar();
          N.pintar();
          N.corazones(); 
          
          x = rand()%71 + 4;
          y = 4; 
     }
     
}

void AST::choque(class naveSith &N){
     
     if( x >= N.X() && x < N.X()+6 && y >= N.Y() && y <= N.Y()+2){
          
          N.COR();
          N.borrar();
          N.pintar();
          N.corazones(); 
          
          x = rand()%71 + 4;
          y = 4; 
     }
     
}

//BALAS

class BALA {

      int x, y;
public:
       BALA(int _x, int _y): x(_x), y(_y){}
       int X(){return x;}
       int Y(){return y;}
       void mover();
       bool fuera();      
};

void BALA::mover(){
     
     gotoxy(x,y); printf(" ");
     y--;
     gotoxy(x,y); printf("*");     
}

bool BALA::fuera(){
     if(y == 2) return true;
     return false;      
}
