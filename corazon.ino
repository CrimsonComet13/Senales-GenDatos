Señal del corazon 


// --- Configuración de la Señal ---
const float escalaTiempo = 0.05; // Velocidad del avance
const float amplitudGlobal = 50; // Para escalar la señal en el Serial Plotter
float x = 0;                     // Variable de tiempo/fase (0 a 6)

void setup() {
  Serial.begin(9600);
}

void loop() {
  float valor = 0;

  // --- MODELADO DEL COMPLEJO PQRST ---
  
  // 1. Onda P (Contracción auricular)
  if (x >= 0.5 && x < 1.2) {
    valor = 0.15 * exp(-pow(x - 0.85, 2) / 0.02);
  }
  
  // 2. Onda Q (Inicio despolarización ventricular)
  else if (x >= 1.2 && x < 1.5) {
    valor = -0.15 * exp(-pow(x - 1.4, 2) / 0.005);
  }
  
  // 3. Complejo R (Pico principal - Contracción ventricular)
  else if (x >= 1.5 && x < 1.8) {
    valor = 1.0 * exp(-pow(x - 1.65, 2) / 0.003);
  }
  
  // 4. Onda S (Final de contracción ventricular)
  else if (x >= 1.8 && x < 2.2) {
    valor = -0.25 * exp(-pow(x - 1.9, 2) / 0.005);
  }
  
  // 5. Onda T (Repolarización / Relajación)
  else if (x >= 3.0 && x < 4.5) {
    valor = 0.35 * exp(-pow(x - 3.7, 2) / 0.15);
  }
  
  // Línea base (Silencio eléctrico)
  else {
    valor = 0;
  }

  // --- SALIDA ---
  // Multiplicamos por la amplitud para que sea visible en el Plotter
  Serial.println(valor * amplitudGlobal);

  // Incremento y reinicio de fase
  x += escalaTiempo;
  if (x > 6) {
    x = 0;
  }

  delay(20); // Control de frecuencia de muestreo
}
