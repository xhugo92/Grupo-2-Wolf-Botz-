#define trigger 12 //da nome aos pinos que serão utilizados
#define echo 13 //define faclita mudar os pinos de cada componente
#define motor 7
#define IN1 2
#define IN2 3
#define IN3 4 //não usar os pinos 0 e 1 (TX/RX)
#define IN4 5

bool esq, dir,a;
void setup() 
{
  dir = true;
  esq = false;
  pinMode(trigger, OUTPUT); //
  pinMode(echo, INPUT); //
  pinMode(motor,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600); //começa o contador do circuito
  delay(5000);
  
}

void loop() 
{
  digitalWrite(motor,HIGH);
  while(distancia()<6)
  {andaFrente();}
  while(distancia()>6)
  {viraEsquerda();} 
}

int distancia()
{
  int dis; long tempo;
  digitalWrite(trigger, LOW);//garante que o pino esta no 0
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);//gera o pulso que vai medir a distancia
  delayMicroseconds(10);//tempo necessario dado no datasheet
  digitalWrite(trigger, LOW);//fim do pulso
  tempo = pulseIn(echo, HIGH);//contabiliza o tempo que demorou pro pulso voltar
  dis = tempo*0.034/2;// velocidade da onda sonora dividida por 2 (ida e volta)
  return dis;
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
