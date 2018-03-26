

void setup() {


  //esta configuración hace que se ejecute una interrupción por cada cambio 
  //que halla en los pines A= o A1, ya sea un cambio positivo o negativo
  PCICR |=1<<PCIE1;
  PCMSK1 |=(1<<PCINT9)|(1<<PCINT8);

  //Acá se ponen los pines como entrada
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

  

}

void loop() {

}


//esta es la interrupción que generan estos pines.
ISR(PCINT1_vect){
    cont++;
}

