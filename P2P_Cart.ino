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
#include <Stepper.h>
#include <Servo.h>

//INSTANCIAS DE OBJETOS 
Stepper        motor         = Stepper(PASSOS_POR_PERIODO, MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_3, MOTOR_PIN_4); 
Servo          servo;
IRrecv         receptor(RECEPTOR_PIN);  
decode_results resultado;  

//VARIAVEIS
float resposta;

void setup() {
  //++++++++++++++Inicializa o módulo receptor+++++++++++++++++++
  Serial.begin(9600);  
  receptor.enableIRIn();
  //==============================================================

  motor.setSpeed(MOTOR_VELOCIDADE);
  servo.attach(SERVO_PIN);
}

void loop() {
  resposta = get_response();

  if (resposta > 0) {  

    if (is_forward(resposta)) {
      go_forward();
    } 
    else if (is_backward(resposta)) {  
      go_backward();
    }  

    if (is_right(resposta)) {  
      go_right();
    }  
    else if (is_left(resposta)) {  
      go_left();
    }  

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
    Serial.print("Valor lido : ");
    Serial.println(resultado.value, HEX); 

    valor = resultado.value;  
  }

  return valor;
}

/**
 * Verifica se o valor passado corresponde a constante de seguir em frente
 * @since 0.0.1
 * @return int Retorna true/false 
 */
boolean is_forward(float valor) {
  return (valor == FRONT);
}

/**
 * Verifica se o valor passado corresponde a constante de voltar
 * @since 0.0.1
 * @param float valor Campos preenchido com um valor Hexdecimanl
 * @return int Retorna true/false 
 */
boolean is_backward(float valor) {
  return (valor == BACK);
}

/**
 * Verifica se o valor passado corresponde a virar para a direita
 * @since 0.0.1
 * @param float valor Campos preenchido com um valor Hexdecimanl
 * @return int Retorna true/false 
 */
boolean is_right(float valor) {
  return (valor == RIGHT);
}

/**
 * Verifica se o valor passado corresponde a virar para a esquerda
 * @since 0.0.1
 * @param float valor Campos preenchido com um valor Hexdecimanl
 * @return int Retorna true/false 
 */
boolean is_left(float valor) {
  return (valor == LEFT);
}

/**
 * Move o carrinho para frente
 * @since 0.0.1
 * @return void
 */
void go_forward() {
  motor.step(MOTOR_STEP *(-1));
}

/**
 * Move o carrinho para tras
 * @since 0.0.1
 * @return void
 */
void go_backward() {
  motor.step(MOTOR_STEP);
}

/**
 * Move o carrinho para direita
 * @since 0.0.1
 * @return void
 */
void go_right() {
  servo.write(SERVO_MIN_TURN);
}

/**
 * Move o carrinho para esquerda
 * @since 0.0.1
 * @return void
 */
void go_left(){
  servo.write(SERVO_MAX_TURN);
}

