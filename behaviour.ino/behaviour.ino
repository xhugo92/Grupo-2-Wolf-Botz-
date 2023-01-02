#include <Servo.h>
#define trigger 13 //da nome aos pinos que serão utilizados
#define echo 12 //define faclita mudar os pinos de cada componente
#define motor 3
#define IN1 4
#define IN2 5
#define IN3 6 //não usar os pinos 0 e 1 (TX/RX)
#define IN4 7

bool esq, dir;
Servo servo;//cria a variavel servo

void setup() 
{
  dir = true;
  esq = false;
  pinMode(trigger, OUTPUT); //
  pinMode(echo, INPUT); //
  servo.attach(2); //liga o servo ao pino 2
  pinMode(motor,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600); //começa o contador do circuito
}

void loop() 
{
  if(distancia()>5)
  {
    andaFrente();
  }
  else if (esq)
  {
    viraEsquerda();
    delay(150);
    if(distancia<5)
    {
      viraEsquerda();
      delay(150);
      viraEsquerda();
      delay(150);
    }
    else
    {
      andaFrente();
      delay(150);
      viraEsquerda();
      delay(150);
    }
    esq=false;
    dir=true;
  }
  else if(dir)
  {
    viraDireita();
    delay(150);
    if(distancia<5)
    {
      viraDireita();
      delay(150);
      viraDireita();
      delay(150);      
    }
    else
    {
      andaFrente();
      delay(150);
      viraDireita();
      delay(150);
    }
    dir=false;
    esq=true;
  }

}

int distancia()
{
  int long tempo;
  digitalWrite(trigger, LOW);//garante que o pino esta no 0
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);//gera o pulso que vai medir a distancia
  delayMicroseconds(10);//tempo necessario dado no datasheet
  digitalWrite(trigger, LOW);//fim do pulso
  tempo = pulseIn(echo, HIGH);//contabiliza o tempo que demorou pro pulso voltar
  distancia = tempo*0.034/2;// velocidade da onda sonora dividida por 2 (ida e volta)
  return distancia;
}

void posServo(int graus)
{
  servo.write(graus);//comanda o servo a ir para a posição da variavel pos
}

void aspirador(bool switch)
{
  if(switch == true )
  {
    digitalWrite(motor, HIGH);// Liga o motor
  }
  else if(switch == false)
  {
    digitalWrite(motor, LOW); //desliga o motor
  }
}

void viraEsquerda()//precisa ver se o robô virará pra esquerda
{
  digitalWrite(IN1, HIGH); // liga a roda esquerda sentido horario 
  digitalWrite(IN2, LOW); // liga a roda esquerda sentido horario
  digitalWrite(IN3, LOW); // liga a roda direita sentido anti-horario
  digitalWrite(IN4, HIGH);  // liga a roda direita sentido anti- horario
}

void viraDireita()//precisa ver se o robô virará pra direita
{
  digitalWrite(IN1, LOW); // liga a roda esquerda sentido anti-horario 
  digitalWrite(IN2, HIGH); // liga a roda esquerda sentido anti-horario
  digitalWrite(IN3, HIGH); // liga a roda direita sentido horario
  digitalWrite(IN4, LOW);  // liga a roda direita sentido horario
}

void andaFrente()//precisa ver se o robô andará pra frente
{
  digitalWrite(IN1, HIGH); // liga a roda esquerda sentido horario 
  digitalWrite(IN2, LOW); // liga a roda esquerda sentido horario
  digitalWrite(IN3, HIGH); // liga a roda direita sentido horario
  digitalWrite(IN4, LOW);  // liga a roda direita sentido horario
}

void andaAtras()//precisa ver se o robô andará pra trás
{
  digitalWrite(IN1, LOW); // liga a roda esquerda sentido anti-horario 
  digitalWrite(IN2, HIGH); // liga a roda esquerda sentido anti-horario
  digitalWrite(IN3, LOW); // liga a roda direita sentido anti-horario
  digitalWrite(IN4, HIGH);  // liga a roda direita sentido anti- horario
}

void paraRodas()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);  
}

