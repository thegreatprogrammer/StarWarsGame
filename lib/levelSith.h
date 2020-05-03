
int levelSith(int asteroid, int kilo){
    int gameover = 1;
    lim();
    
    // PRIMER NIVEL
    
    int km = 0;
    
    naveSith darth(40,27,3,3);
    color(4);
    darth.pintar();
    darth.corazones();  
    
    list<AST*> A;
    list<AST*>::iterator itA;
    for(int i = 0; i<asteroid; i++){ 
            A.push_back(new AST(rand()%75+3, rand()%5+4));      
    }
    
    //Memoria dinámica. Creando una lista de punteros
    list<BALA*> B;
    
    // Iterador dinámico
    list<BALA*>::iterator it;
    
    int puntos = 0;
       
    while(gameover!=0 && km < kilo){
         pintar_cantidad(km);
         gotoxy(4,2); printf("Puntaje: %d", puntos);
         if(kbhit()){
             char tecla = getch();
             
             //Creando nuevo objeto dinámicamente, al presionar 'a'
             if(tecla == 'a'){
                 B.push_back(new BALA(darth.X()+2, darth.Y()-1));
             }
         }
         
         for(it = B.begin(); it != B.end(); it++){
             (*it) -> mover();
             if((*it) -> fuera()){
                 gotoxy((*it)->X(), (*it)->Y());
                 printf(" ");
                 
                 //Quitamos elemento de la lista
                 delete(*it);
                 
                 //Retomamos iterador
                 it = B.erase(it);       
             }    
         }
         
         for(itA = A.begin(); itA != A.end(); itA++){
                 km++;
                 pintar_cantidad(km);
                 (*itA)->mover();
                 (*itA)->choque(darth);
                         
         }
         
         for(itA = A.begin(); itA != A.end(); itA++){
                 for(it = B.begin(); it != B.end(); it++){
                     if((*itA)->X() == (*it)->X() &&  ((*itA)->Y() || (*itA)-> Y() == (*it) -> Y())){
                          
                          gotoxy((*it)->X(), (*it)->Y()); printf(" ");
                          delete(*it);
                          it = B.erase(it);
                          
                          A.push_back(new AST(rand()%75 + 3, 2)); 
                          gotoxy((*itA)->X(), (*itA)->Y()); printf(" "); 
                          delete(*itA);   
                          itA = A.erase(itA);   
                          puntos+=5;       
                     }   
                 }
         }
         
         if(darth.VID() == 0) {
             gameover = 0;                         
         }
                                            
         darth.die();
         darth.mover();  
         Sleep(30); 
         
        }  
        
        if(gameover==0){
                        
            system("cls");
            lim();
            gotoxy(35,20); cout<<"GAME OVER!";
        }
        
        if(km == kilo){
              system("cls");
              lim();
              gotoxy(34,24); cout<<"NIVEL SUPERADO!!!";
              Sleep(2000);
              gotoxy(20,26); cout<<"Los asteroides has superado, joven Sith.";
              Sleep(3000);

        }        
}
