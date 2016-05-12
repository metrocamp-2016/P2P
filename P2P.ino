/*
 * POINT TO POINT
 * Automaçao de entrega de objeto, de um ponto a outro. 
 * De forma programvel, o carrinho ir receber informaçoes enviadas via controle remoto (infra vermelho)
 * para fazer com que o carrinho realize açoes especificas.
 *  
 * Configure as variveis do sistema para que eles possom ser visualizas dentro do fluxo de trabalho do carrinho
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

//CONSTANTES
const int PASSOS_POR_PERIODO = 500; 
const int MOTOR_VELOCIDADE   = 60; //rpms: Velocidade que motor deve realizar uma rotaço por minuto 

/** PORTAS **/
const int RECEPTOR_PIN       = 11;
const int SERVO_PIN          = 5;

const int MOTOR_PIN_1        = 8;
const int MOTOR_PIN_2        = 10;
const int MOTOR_PIN_3        = 9;
const int MOTOR_PIN_4        = 11;

//BOTOES DO CONTROLE REMOTO
const float TECLA_CH_MINUS   = 0xFFA25D;
const float TECLA_CH         = 0xFF629D;
const float TECLA_CH_PLUS    = 0xFFE21D;
const float TECLA_PREV       = 0xFF22DD;
const float TECLA_NEXT       = 0xFF02FD;
const float TECLA_PLAY_PAUSE = 0xFFC23D;
const float TECLA_VOL_MINUS  = 0xFFE01F;
const float TECLA_VOL_PLUS   = 0xFFA857;
const float TECLA_EQ         = 0xFF906F;
const float TECLA_100_PLUS   = 0xFF9867;
const float TECLA_200_PLUS   = 0xFFB04F;
const float TECLA_0          = 0xFF6897;
const float TECLA_1          = 0xFF30CF;
const float TECLA_2          = 0xFF18E7;
const float TECLA_3          = 0xFF7A85;
const float TECLA_4          = 0xFF10EF;
const float TECLA_5          = 0xFF38C7;
const float TECLA_6          = 0xFF5AA5;
const float TECLA_7          = 0xFF42BD;
const float TECLA_8          = 0xFF4AB5;
const float TECLA_9          = 0xFF52AD;


//SERVO
const int SERVO_MAX_TURN     = 180;
const int SERVO_MIN_TURN     = 0;

//MOTOR
const int MOTOR_STEP         = 500;


//CONTROLES
const float FRONT            = TECLA_1;
const float BACK             = TECLA_2;
const float RIGHT            = TECLA_5;
const float LEFT             = TECLA_4;
const float GRAVA            = TECLA_CH;
const float APAGA            = TECLA_CH_MINUS;
