    /* Projeto Curto Circuito – HC05: Controle Mobile */

/* Biblioteca */
#include <SoftwareSerial.h> /* Comandos Seriais */
SoftwareSerial HC05(10, 11); /* TX-RX */


/* Variáveis Lógicas ON-OFF */
int state = 0;  /*Controla o status do LED Verde */
int state2 = 0; /*Controla o status do LED Vermelho */
int state3 = 0; /* Controla o status do LED Azul */

/* Define a pinagem do LED */
#define azul 4
#define verde 3
#define vermelho 2

void setup()
{
  Serial.begin(9600);        /* Taxa de transmissão na serial */
  HC05.begin(9600);        /* Taxa de transmissão do Módulo */

  pinMode(verde, OUTPUT);      /* Declara verde como OUTPUT */
  pinMode(azul, OUTPUT);         /* Declara azul como OUTPUT */
  pinMode(vermelho, OUTPUT); /* Declara vermelho como OUTPUT */

}
void loop()
{
  /* Armazena os valores de leitura de HC05 na variável readBluetooth */
  int readBluetooth = HC05.read();

  switch (readBluetooth)
  { /* De acordo com o valor armazenado em readBluetooth */
    case 'a': /* Caso receba o caractere 'a'*/
      state = !state; /* substitui o valor de state entre 0 e 1 */
      digitalWrite(verde, state); /* state aciona ou desliga o LED */
      break; /* Fim do caso 'a' */

    case 'b': /* Caso receba o caractere 'b' */
      state2 = !state2; /* substitui o valor de state entre 0 e 1 */
      digitalWrite(vermelho, state2);/* state aciona ou desliga o LED */
      break; /* Fim do caso 'b'*/

    case 'c': /* Caso receba o caractere 'c' */
      state3 = !state3;/* substitui o valor de state entre 0 e 1 */
      digitalWrite(azul, state3);/* state aciona ou desliga o LED */
      break; /* Fim do caso 'c' */
  }
}