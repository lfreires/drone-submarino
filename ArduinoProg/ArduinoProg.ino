// ====================================================================================================================================================
// --- Definição de portas do arduino

  #define motorSeringa1P 22
  #define motorSeringa1N 23

  #define motorSeringa2P 24
  #define motorSeringa2N 25

  #define analogicoAceleracao A0
  #define analogicoPumps A1
  #define analogicoDepth A2

// ====================================================================================================================================================

// ====================================================================================================================================================
// --- Void de setup do arduino

  void setup() {

    pinMode(motorSeringa1P, OUTPUT);
    pinMode(motorSeringa1N, OUTPUT);

    pinMode(motorSeringa2P, OUTPUT);
    pinMode(motorSeringa2N, OUTPUT);

    pinMode(analogicoAceleracao, INPUT);
    pinMode(analogicoPumps, INPUT);
    pinMode(analogicoDepth, INPUT);

  }

// ====================================================================================================================================================

// ====================================================================================================================================================
// --- Voids de leituras dos analogicos

  void leituraAnalogicoAceleracao(int *aceleracao, int *stateMotorAceleracao, int *sentidoMotorAceleracao){

    int valorAnalogicoAceleracao = analogRead(analogicoAceleracao);
    int aceleracaoRead = map(valorAnalogicoAceleracao, 0, 1023, -255, 255);

    if(aceleracaoRead > 10){

      aceleracao = abs(aceleracaoRead);
      stateMotorAceleracao = 1;
      sentidoMotorAceleracao = 1;

    } else if(aceleracaoRead < -10){

      aceleracao = abs(aceleracaoRead);
      stateMotorAceleracao = 1;
      sentidoMotorAceleracao = 0;

    } else {

      stateMotorAceleracao = 0;

    }

  }

  void leituraAnalogicoDepth(int *stateMotorSeringa, int *sentidoMotorSeringa){

    int valorAnalogicoDepth = analogRead(analogicoDepth);
    int analogicRead = map(valorAnalogicoDepth, 0, 1023, -255, 255);

    if(analogicRead > 10){

      stateMotorSeringa = 1;
      sentidoMotorSeringa = 1;

    } else if(analogicRead < -10){

      stateMotorSeringa = 1;
      sentidoMotorSeringa = 0;

    } else {

      stateMotorSeringa = 0;

    }

  }
// ====================================================================================================================================================

// ====================================================================================================================================================
// --- Void para controle dos motores para movimentação das seringas

  void controleMotorSeringa(int *sentido, int *state){

    if(state == 1){

      if(sentido == 1){

        digitalWrite(motorSeringa1P, HIGH);
        digitalWrite(motorSeringa2P, HIGH);

        digitalWrite(motorSeringa1N, LOW);
        digitalWrite(motorSeringa2N, LOW);

      }

      else if(sentido == 0){

        digitalWrite(motorSeringa1P, LOW);
        digitalWrite(motorSeringa2P, LOW);

        digitalWrite(motorSeringa1N, HIGH);
        digitalWrite(motorSeringa2N, HIGH);

      }

    } else if(state == 0){

      digitalWrite(motorSeringa1P, LOW);
      digitalWrite(motorSeringa2P, LOW);

      digitalWrite(motorSeringa1N, LOW);
      digitalWrite(motorSeringa2N, LOW);

    }

  }

// ====================================================================================================================================================

// ====================================================================================================================================================
// --- Void loop arduino
  void loop() {

    int aceleracao = 0, stateMotorAceleracao = 0, sentidoMotorAceleracao = 1;
    int stateMotorSeringa = 1, sentidoMotorSeringa = 1;

    leituraAnalogicoAceleracao(&aceleracao, &stateMotorAceleracao, &sentidoMotorAceleracao);
    leituraAnalogicoDepth(&stateMotorSeringa, &sentidoMotorSeringa);
    
    
  }

// ====================================================================================================================================================
