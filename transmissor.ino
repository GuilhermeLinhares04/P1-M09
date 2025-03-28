// Código do Transmissor (TX)
#define TX_PIN 2
#define BIT_TIME 500 // 500ms por bit

void sendManchesterBit(bool bit) {
  if (bit) {
    digitalWrite(TX_PIN, LOW);
    delay(BIT_TIME/2);
    digitalWrite(TX_PIN, HIGH);
    delay(BIT_TIME/2);
  } else {
    digitalWrite(TX_PIN, HIGH);
    delay(BIT_TIME/2);
    digitalWrite(TX_PIN, LOW);
    delay(BIT_TIME/2);
  }
}

void sendMessage(String message) {
  for (int i = 0; i < message.length(); i++) {
    bool bit = message[i] - '0'; // Converte char para bool (0 ou 1)
    sendManchesterBit(bit);
  }
}

void setup() {
  pinMode(TX_PIN, OUTPUT);
}

void loop() {
  sendMessage("01");
  delay(3000); // Aguarda 3 segundos entre envios
}