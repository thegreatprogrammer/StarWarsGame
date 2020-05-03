/*

	MAY THE FORCE BE WITH YOU

	.        .               .       .     .            .
   .           .        .                     .        .            .
             .               .    .          .              .   .         .
               _________________      ____         __________
 .       .    /                 |    /    \    .  |          \
     .       /    ______   _____| . /      \      |    ___    |     .     .
             \    \    |   |       /   /\   \     |   |___>   |
           .  \    \   |   |      /   /__\   \  . |         _/             .
 .     ________>    |  |   | .   /            \   |   |\    \_______    .
      |            /   |   |    /    ______    \  |   | \           |
      |___________/    |___|   /____/      \____\ |___|  \__________|    .
  .     ____    __  . _____   ____      .  __________   .  _________
       \    \  /  \  /    /  /    \       |          \    /         |      .
        \    \/    \/    /  /      \      |    ___    |  /    ______|  .
         \              /  /   /\   \ .   |   |___>   |  \    \
   .      \            /  /   /__\   \    |         _/.   \    \
           \    /\    /  /            \   |   |\    \______>    |   .
            \  /  \  /  /    ______    \  |   | \              /          .
 .       .   \/    \/  /____/      \____\ |___|  \____________/  MARY
                               .
                                           .               .

*/


# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <list>
# include <windows.h>
# include <string>

using namespace std;


// Librerías propias

# include "lib/base.h"
# include "lib/intro.h"
# include "lib/nave.h"
# include "lib/naveSith.h"
# include "lib/astbala.h"
# include "lib/level.h"
# include "lib/levelSith.h"


main(){
  
  //Ocultamos el cursor de la pantalla.
  OcultarCursor();
  //Pintamos los límites del juego (marco)
  lim();
  int modo;
  
  modo = intro(); //La respuesta que el usuario introduce en la función intro(),
  //es almacenada en la variable modo
  modo = validarOp(modo); //la variable modo es pasada a la función validarOp que
  // se asegura que su valor sea 1 o 2.
  
  if(validarOp(modo)==1){
  	for(int i = 0; i<6;i++){
        gotoxy(34,24);
  		if(i%2==0){
            color(15);
  			cout<<"1. JEDI";
  			Sleep(500);
		  }
		  
		else{
			color(11);cout<<"1. JEDI";
			Sleep(500);
		}
		gotoxy(34,24); borrar(34, 40, 24);
	  }
  
    system("cls");
    introGame("I", "AGAINST THE ASTEROIDS I", "Comienza tu camino hacia la lucha, joven Jedi.\n\t\tUnos pocos asteroides deberas pasar.", "Que la fuerza te acompane en tu mision, joven Padawan. ");
    //Ejecutamos el primer nivel Jedi
    Level(3, 1500);
    
    //Ejecutamos el segundo nivel Jedi
    introGame("II", "AGAINST THE ASTEROIDS II", "A traves de la galaxia volaras,\n\t\t y varios asteroides destruiras. Confio en ti, joven Jedi.", "Que la fuerza te acompane en tu mision, joven Padawan. ");
    Level(5, 3000);
    
    //Ejecutamos el tercer nivel Jedi
    introGame("III", "AGAINST THE ASTEROIDS III", "Finalizando tu camino,\n\t\t solo quedan otros asteroides que superar.", "Que la fuerza te acompane en tu mision, joven Padawan. ");
    Level(7, 6000);
  
    win();
	}

    if(validarOp(modo)==2){
  	for(int i = 0; i<=6;i++){
        gotoxy(34,26);
  		if(i%2==0){
            color(15);
  			cout<<"2. SITH";
  			Sleep(500);
		  }
		  
		else{
			color(4);cout<<"2. SITH";
			Sleep(500);
		}
		gotoxy(34,26); borrar(34, 40, 26);
	  }
  
    system("cls");
    introGame("I", "AGAINST THE ASTEROIDS I", "Comienza tu camino hacia la lucha, joven Sith.\n\t\tEl imperio te necesita.", "Solo a traves del lado oscuro conseguiras tus metas");
    //Ejecutamos el primer nivel Jedi
    levelSith(3, 1500);
    
    //Ejecutamos el segundo nivel Jedi
    introGame("II", "AGAINST THE ASTEROIDS II", "Para seguir con tu camino para destruir a los Jedi,\n\t\tpor este camino debes proseguir.", "Solo a traves del lado oscuro conseguiras tus metas");
    levelSith(5, 3000);
    
    //Ejecutamos el tercer nivel Jedi
    introGame("III", "AGAINST THE ASTEROIDS III", "Finalizando tu camino,\n\t\t solo quedan otros asteroides que superar, joven Sith.", "Solo a traves del lado oscuro conseguiras tus metas");
    levelSith(7, 6000);
  
    win();
    // gameover1();
	}
  
  system("PAUSE");
  return 0;
}
