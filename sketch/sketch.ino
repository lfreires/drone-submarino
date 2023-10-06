// =============================================================================================================================
// --- Definição de nomes para as portas do arduino

  #define GLCD_RST  9
  #define GLCD_CS   10
  #define GLCD_CLK  11
  #define GLCD_DATA 12

  #define botaoCimaPin 2
  #define botaoBaixoPin 3 
  #define botaoEnterPin 4 
  #define botaoDireitaPin 5
  #define botaoEsquerdaPin 6

// =============================================================================================================================

// =============================================================================================================================
// --- Importação de bibliotecas 

  #include <U8g2lib.h>
  U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, GLCD_CLK, GLCD_DATA, GLCD_CS, GLCD_RST); // Configuração para o display ST7920 128x64

// =============================================================================================================================

// =============================================================================================================================
// --- Função de setup do Arduino

  void setup() {

    pinMode(botaoCimaPin, INPUT_PULLUP);    // Configura o pino do botão de cima como entrada com pull-up
    pinMode(botaoBaixoPin, INPUT_PULLUP);   // Configura o pino do botão de baixo como entrada com pull-up
    pinMode(botaoEnterPin, INPUT_PULLUP);   // Configura o pino do botão Enter como entrada com pull-up
    pinMode(botaoDireitaPin, INPUT_PULLUP); // Configura o pino do botão direita como entrada com pull-up
    pinMode(botaoEsquerdaPin, INPUT_PULLUP);// Configura o pino do botão esquerda como entrada com pull-up

    u8g2.begin(); // Inicializa o display
    u8g2.setContrast(50); // Ajuste o contraste conforme necessário
  }

// =============================================================================================================================

// =============================================================================================================================
// --- Função de leitura dos botões

  bool botaoCimaPinFlag, botaoBaixoPinFlag, botaoEnterPinFlag, botaoDireitaPinFlag, botaoEsquerdaPinFlag = false; // Flag de estado para cada botão
  
  void readButtons(){

    bool botaoCimaPinState = digitalRead(botaoCimaPin), botaoBaixoPinState = digitalRead(botaoBaixoPin), botaoEnterPinState = digitalRead(botaoEnterPin); // Leitura do estado de cada botão
    bool botaoDireitaPinState = digitalRead(botaoDireitaPin), botaoEsquerdaPinState = digitalRead(botaoEsquerdaPin); 

  // =============================================================================================================================
  // --- Botão de cima

    if(botaoCimaPinState == 0 && botaoCimaPinFlag == false){ // Se o botão for apertado e a flag de estado estiver false
      botaoCimaPinFlag = true; // Seta a flag de estado como true
    }

    else if(botaoCimaPinState == 1 && botaoCimaPinFlag == true){ // Se o botão não estiver apertado mas a flag de estado estiver como true
      //
      botaoCimaPinFlag = false; // Reseto a flag para outra leitura do botao
    }

  // =============================================================================================================================

  // =============================================================================================================================
  // --- Botão de baixo 

    if(botaoBaixoPinState == 0 && botaoBaixoPinFlag == false){ // Se o botão for apertado e a flag de estado estiver false
      botaoBaixoPinFlag = true; // Seta a flag de estado como true
    }

    else if(botaoBaixoPinState == 1 && botaoBaixoPinFlag == true){ // Se o botão não estiver apertado mas a flag de estado estiver como true
      //
      botaoBaixoPinFlag = false; // Reseto a flag para outra leitura do botao
    }

  // =============================================================================================================================

  // =============================================================================================================================
  // --- Botão de enter

    if(botaoEnterPinState == 0 && botaoEnterPinFlag == false){ // Se o botão for apertado e a flag de estado estiver false
      botaoEnterPinFlag = true; // Seta a flag de estado como true
    }

    else if(botaoEnterPinState == 1 && botaoEnterPinFlag == true){ // Se o botão não estiver apertado mas a flag de estado estiver como true
      //
      botaoEnterPinFlag = false; // Reseto a flag para outra leitura do botao
    }

  // =============================================================================================================================

  // =============================================================================================================================
  // --- Botão de direita

    if(botaoDireitaPinState == 0 && botaoDireitaPinFlag == false){ // Se o botão for apertado e a flag de estado estiver false
      botaoDireitaPinFlag = true; // Seta a flag de estado como true
    }

    else if(botaoDireitaPinState == 1 && botaoDireitaPinFlag == true){ // Se o botão não estiver apertado mas a flag de estado estiver como true
      //
      botaoDireitaPinFlag = false; // Reseto a flag para outra leitura do botao
    }

  // =============================================================================================================================

  // =============================================================================================================================
  // --- Botão de esquerda

    if(botaoEsquerdaPinState == 0 && botaoEsquerdaPinFlag == false){ // Se o botão for apertado e a flag de estado estiver false
      botaoEsquerdaPinFlag = true; // Seta a flag de estado como true
    }

    else if(botaoEsquerdaPinState == 1 && botaoEsquerdaPinFlag == true){ // Se o botão não estiver apertado mas a flag de estado estiver como true
      //
      botaoEsquerdaPinFlag = false; // Reseto a flag para outra leitura do botao
    }

  // =============================================================================================================================

  }

// =============================================================================================================================

// =============================================================================================================================
// --- Funções de impressão dos menus (templates)
  
  // =============================================================================================================================
  // --- Primeiro menu (informações)

    void primeiroMenu(){

      // =============================================================================================================================
      // --- Impressão dos valores da bateria 

        u8g2.drawStr(30, 45, "Bateria:");

        u8g2.setCursor(90, 30);
        u8g2.print("100%");

      // =============================================================================================================================

      // =============================================================================================================================
      // --- Impressão de valores do motor

        u8g2.drawStr(30, 30, "Motor:");

        u8g2.setCursor(90, 30);
        u8g2.print("100%");

      // =============================================================================================================================

      // =============================================================================================================================
      // --- Impressão dos valores de profundidade 

        u8g2.drawStr(30, 45, "Profundidade:");

        u8g2.setCursor(90, 30);
        u8g2.print("30");

      // =============================================================================================================================

    }

  // =============================================================================================================================

  // =============================================================================================================================
  // --- Segundo menu (parâmetros)
    
    void segundoMenu(){

      // =============================================================================================================================
      // --- Impressão da seleção de profundidade

        u8g2.drawStr(30, 45, "Profundidade:");

        u8g2.setCursor(90, 30);
        u8g2.print("0000");

      // =============================================================================================================================

      // =============================================================================================================================
      // --- Impressão da seleção de controle de submerção

        u8g2.drawStr(30, 30, "Submergir");

        u8g2.setCursor(90, 30);
        u8g2.print("False");

      // =============================================================================================================================

      // =============================================================================================================================
      // --- Impressão dos valores de profundidade 

        u8g2.drawStr(30, 45, "Profundidade:");

        u8g2.setCursor(90, 30);
        u8g2.print("30");

      // =============================================================================================================================

    }
  
  // =============================================================================================================================

// =============================================================================================================================

// =============================================================================================================================
// --- Função de seleçao dos menus para impressão 
  
  char menuPrincipal, menuSelecao = 0; // Variaveis para impressão e logica dos menus determinados

  void imprimirMenu(){

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_profont10_tf);

    u8g2.drawRBox(10, 10, 108, 44, 8); // Desenho a margem do menu 

    switch(menuPrincipal){

      case 0:
        primeiroMenu();
      break;

      case 1:

        switch(menuSelecao){
          case 0:
            segundoMenu();
          break;

          case 1:
          break;
        }

      break;

    }

    u8g2.sendBuffer();
  }

// =============================================================================================================================

void loop() {

}
