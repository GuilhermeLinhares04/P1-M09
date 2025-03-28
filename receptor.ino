// Código do Receptor (RX)
#define RX_PIN 2
#define LED_VERMELHO 3
#define LED_VERDE 4
#define BIT_TIME 500

String decodeManchester() {
  String message = "";
  int samplesPerBit = 2; // 2 transições por bit
  for (int i = 0; i < 2; i++) { // Lê 2 bits (4 transições)
    int firstState = digitalRead(RX_PIN);
    delay(BIT_TIME/2);
    int secondState = digitalRead(RX_PIN);
    
    if (firstState == HIGH && secondState == LOW) message += "0";
    else if (firstState == LOW && secondState == HIGH) message += "1";
    delay(BIT_TIME/2);
  }
  return message;
}

void executeCommand(String cmd) {
  if (cmd == "00") digitalWrite(LED_VERMELHO, HIGH);
  else if (cmd == "01") digitalWrite(LED_VERDE, HIGH);
  else if (cmd == "10") { 
    digitalWrite(LED_VERMELHO, LOW); 
    digitalWrite(LED_VERDE, LOW);
  }
  else if (cmd == "11") { 
    // Exemplo: Alerta (piscar LEDs)
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED_VERMELHO, HIGH);
      digitalWrite(LED_VERDE, HIGH);
      delay(200);
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_VERDE, LOW);
      delay(200);
    }
  }
}

void setup() {
  pinMode(RX_PIN, INPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  String receivedMessage = decodeManchester();
  executeCommand(receivedMessage);
}