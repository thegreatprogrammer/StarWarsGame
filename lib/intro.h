int intro(){
  int opcion;
  color(14);
  gotoxy(13,17); cout<<"Hace mucho tiempo, en una galaxia muy, muy lejana";
   
  for(int j = 0; j<3; j++){
  gotoxy(63,17); 
    for(int i=0; i<3; i++){
      cout<<".";
      Sleep(500);
    }
    gotoxy(63,17);
    borrar(63, 66, 17);
    Sleep(500);
  } 

  system("cls");
  gotoxy(25,6);cout<<"     ________   ___   ____\n";
  gotoxy(25,7);cout<<"    / __   __| / _ \\ |  _ \\\n";
  gotoxy(25,8);cout<<" ___> \\ | |   |  _  ||    /__\n";
  gotoxy(25,9);cout<<"|_____/ |_|   |_| |_||_|\\____|\n";
  gotoxy(25,10);cout<<" _  _  _   ___   ____    ____\n";
  gotoxy(25,11);cout<<"| |/ \\| | / _ \\.|  _ \\  / ___|\n";
  gotoxy(25,12);cout<<"|   .   ||  _  ||    /__> \\\n";
  gotoxy(25,13);cout<<" \\_/ \\_/ |_| |_||_|\\______/\n";
  gotoxy(25,16);cout<<"           THE GAME\n\n";

  gotoxy(0,18);cout<<"_______________________________________________________________________________\n";
  gotoxy(26,20); cout<<"Ingresa tu modo de juego: "; 
  
  color(11);gotoxy(34,24); cout<<"1. JEDI";
  color(12);gotoxy(34,26); cout<<"2. SITH\n\n";
  
  color(15); gotoxy(52,20); cin>>opcion;

  return opcion;
}


//La función introJedi pide cuatro parámetros; todos de tipo cadena (string)
//El primero, el nivel cursado; el segundo, el nombre del nivel; el tercero,
//una breve descripción de lo que se hará en el nivel; el cuarto, la descripción
//dependiendo de si se es un Jedi o un Sith

void introGame(string nivel, string nivels, string description, string saludo){
    system("cls");
    color(14);
	gotoxy(25,6);cout<<"     ________   ___   ____\n";
    gotoxy(25,7);cout<<"    / __   __| / _ \\ |  _ \\\n";
    gotoxy(25,8);cout<<" ___> \\ | |   |  _  ||    /__\n";
    gotoxy(25,9);cout<<"|_____/ |_|   |_| |_||_|\\____|\n";
    gotoxy(25,10);cout<<" _  _  _   ___   ____    ____\n";
    gotoxy(25,11);cout<<"| |/ \\| | / _ \\.|  _ \\  / ___|\n";
    gotoxy(25,12);cout<<"|   .   ||  _  ||    /__> \\\n";
    gotoxy(25,13);cout<<" \\_/ \\_/ |_| |_||_|\\______/\n";
    gotoxy(25,16);cout<<"           THE GAME\n\n";

    gotoxy(0,18);cout<<"_______________________________________________________________________________\n";
    gotoxy(5,20); cout<<saludo; 
    Sleep(4000);
    gotoxy(15,23); cout<<"NIVEL "<<nivel<<" - "<<nivels; 
    gotoxy(5,20); borrar(5, 70, 20);
    gotoxy(15,26); cout<<description; 
    Sleep(4000);
    system("cls");
    
}
