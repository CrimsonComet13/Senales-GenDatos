Señal de Misil



const int periodo = 50;   // 6 unidades * 100 pasos

const float amplitud = 50;       // para escalar la señal
const float escalaTiempo = 0.02;  // controla resolución
float x = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  float valor = 0;

  if (x >= 0 && x < 1) {
    valor = x;
  }
  else if (x >= 1 && x < 2) {
    valor = 1;
  }
  else if (x >= 2 && x < 3) {
    valor = x - 1;
  }
  else if (x >= 3 && x < 4) {
    valor = 4 * pow(x - 3.5, 2) + 1;
  }
  else if (x >= 4 && x <= 6) {
    valor = -x + 6;
  }

  Serial.println(valor);

  x += escalaTiempo;

  if (x > 6) {
    x = 0;
  }

  delay(20);
}
