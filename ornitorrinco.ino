Señal Ornitorrinco 




// --- Configuración de la Señal ---
const float escalaTiempo = 0.05; // Velocidad del avance
const float amplitudGlobal = 50; // Para escalar la señal en el Serial Plotter
float x = -1;                    // Iniciamos en -1 según tu gráfica

void setup() {
  Serial.begin(9600);
}

void loop() {
  float valor = 0;

  // --- MODELADO SEGÚN TU ANÁLISIS ---

  // 1. Rango [-1, 0]: Línea en cero
  if (x >= -1 && x < 0) {
    valor = 0;
  }
  
  // 2. Rango [0, 1]: Caída constante a -1
  else if (x >= 0 && x < 1) {
    valor = -1;
  }
  
  // 3. Rango [1, 2]: Primer monte senoidal (positivo)
  // Usamos sin(pi * (x - 1)) para que empiece en cero en x=1
  else if (x >= 1 && x < 2) {
    valor = sin(PI * (x - 1));
  }
  
  // 4. Rango [2, 3]: Segundo monte senoidal (positivo)
  else if (x >= 2 && x < 3) {
    valor = sin(PI * (x - 2));
  }
  
  // 5. Rango [3, 4]: Valle senoidal (negativo)
  // Según tu dibujo, baja hasta -1 en este intervalo
  else if (x >= 3 && x < 4) {
    valor = -sin(PI * (x - 3));
  }
  
  // 6. Rango [4, 6]: Regreso a línea base (cero)
  else if (x >= 4 && x <= 6) {
    valor = 0;
  }

  // --- SALIDA ---
  // Enviamos al Serial Plotter
  Serial.println(valor * amplitudGlobal);

  // Incremento y reinicio de x de -1 a 6
  x += escalaTiempo;
  if (x > 6) {
    x = -1;
  }

  delay(20); 
}
