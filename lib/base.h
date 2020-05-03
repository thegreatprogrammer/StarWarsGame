

// La siguiente función define el color de las letras
void color(int col){

  HANDLE  hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
  SetConsoleTextAttribute(hConsole, col);
}

/* La siguiente función simula la función original gotoxy presente en 
lenguajes como Pascal; ubica el cursor o el objeto a través de las coordenadas
x e y de la consola*/
void gotoxy(int x, int y){

  HANDLE hCon;
  hCon = GetStdHandle(STD_OUTPUT_HANDLE);

  COORD dwPos;
  dwPos.X =  x;
  dwPos.Y = y;

  SetConsoleCursorPosition(hCon, dwPos);

}

// Ocultamos el cursor de la pantalla

void OcultarCursor(){
                    
  HANDLE hCon;
  hCon = GetStdHandle(STD_OUTPUT_HANDLE);
  
  // Creando un objeto de la estructura CONSOLE_CURSOR_INFO
  CONSOLE_CURSOR_INFO cci;
  // Tamaño del cursor (nulo)
  cci.dwSize = 2;
  //Visibilidad del cursor
  cci.bVisible = FALSE;
  
  SetConsoleCursorInfo(hCon, &cci);
  
}

void lim(){

    for(int i = 2; i<78; i++){
          gotoxy(i,1); printf("%c",205);
          gotoxy(i,33); printf("%c",205);  
    }  
    
    for(int i = 2; i<33; i++){
          gotoxy(2,i); printf("%c",186);
          gotoxy(77,i); printf("%c",186);  
    }   

    gotoxy(2,1);   printf("%c",201);
    gotoxy(2,33);  printf("%c",200);
    gotoxy(77,1);  printf("%c",187); 
    gotoxy(77,33); printf("%c",188);
}


void win(){
     system("cls");
     lim();
     gotoxy(25,15); cout<<"Has llegado al final del juego! Felicidades.";
     Sleep(1500);    
}

/*La siguiente función se vale de tres parámetros: firstP, que es la coordenada
que funciona como punto de partida; lastP, que es la coordenada que funciona como
punto de fin del borrado; y la variable y, que funciona para que el usuario indique
en qué línea desea borrar el contenido indicado.*/

//Con este for, recorremos desde la primera posición x dada hasta la última posición
//x dada; de esta manera, borramos en horizontal, en la línea indicada.

void borrar(int firstP, int lastP, int y){

  for(int i = firstP; i<=lastP;i++){
    gotoxy(i,y); cout<<" ";
  }
}

//Valida que la opción dada por el usuario no sea distinta de 1 ó 2
int validarOp(int op){
    
    while(op != 1 && op != 2){
        borrar(26, 50, 20);
        gotoxy(22,20);cout<<"Modo de juego invalido. Introduce de nuevo: ";
        cin>>op;        
        borrar(22, 68, 20);
    }
    
    return op;
}
