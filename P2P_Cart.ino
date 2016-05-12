/*
 * POINT TO POINT
 * Automaçao de entrega de objeto, de um ponto a outro. 
 * De forma programvel, o carrinho ir receber informaçoes enviadas via controle remoto (infra vermelho)
 * para fazer com que o carrinho realize açoes especificas.
 *  
 * @version 0.0.1 
 * @package P2P
 *
 * @see http://metrocamp-2016.github.io/arduino-car/
 *
 * @author Shankar Nakai Gonçalves dos Santos
 * @author Tiago Hass
 * @author Vinicius Souza Gomes
 */

#include <IRremote.h>
#include <IRremoteInt.h>

//INSTANCIAS DE OBJETOS 
IRrecv         receptor(RECEPTOR_PIN);  
decode_results resultado;  

//VARIAVEIS
float resposta;

void setup() {
  //++++++++++++++Inicializa o módulo receptor+++++++++++++++++++
  Serial.begin(9600);  
  receptor.enableIRIn();
  //==============================================================
}

void loop() {
  resposta = get_response();

  if (resposta > 0) {  
    receptor.resume(); //Le o próximo valor  
  }

  delay(15);  
}

/**
 * Pega a resposta do controle remoto do KIT arduino.
 * @since 0.0.1
 * @return float Retorna a resposta em valor HexDecimal do valor do controle remoto, caso seja 0 no foi recebido nenhuma informaçao
 */
float get_response() {
  float valor = 0;

  if (receptor.decode(&resultado)) {
    //Create log do valor ligo pelo controle remoto
    Serial.print("Valor lido : ");
    Serial.println(resultado.value, HEX); 

    //Guarda valor ligo na variável valor
    valor = resultado.value;  
  }

  return valor;
}
