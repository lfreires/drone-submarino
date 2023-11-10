/*
Pressure Measurements with the
MPS20N0040D Breakout Board
with the HX710B/HX711 ADC
5V Supply Voltage
 */
#include <Q2HX711.h>
#include <math.h>

const byte MPS_OUT_pin = 2; // Pino de dados OUT
const byte MPS_SCK_pin = 3; // Pino de dados do relógio
int avg_size = 10; // #pontos para calcular a média

Q2HX711 MPS20N0040D(MPS_OUT_pin, MPS_SCK_pin); // começa a comunicação com o HX710B

void setup() {
  Serial.begin(9600); // inicia a porta serial
}

void loop() {
  float avg_val = 0.0; // variável para média
  for (int ii=0;ii<avg_size;ii++){
    avg_val += MPS20N0040D.read(); // adicionar várias leituras de ADC
    delay(50); // atraso entre as leituras
  }
  avg_val /= avg_size;
  Serial.println(avg_val,0); // imprime a média

}