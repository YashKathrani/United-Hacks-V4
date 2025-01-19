  #include <dht.h>

dht DHT; 
#define DHT11_PIN 2   // DHT11 sensor pin
#define GREEN_LED 3   // Green LED connected to pin 3
#define RED_LED 4     // Red LED connected to pin 4
#define BUZZER_PIN 5  // Buzzer connected to pin 5

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Set LED and Buzzer pins as outputs
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Turn off both LEDs and the buzzer at startup
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  // Read data from DHT11 sensor
  int chk = DHT.read11(DHT11_PIN);

  // Print temperature and humidity to Serial Monitor
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.println(" °F");
  
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");

  // Check conditions and control LEDs and buzzer
  if (DHT.temperature > 90 && DHT.humidity < 10) {
    // Turn on red LED and buzzer, turn off green LED
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER_PIN, HIGH); // Buzzer on
  } else {
    // Turn on green LED, turn off red LED and buzzer
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW); // Buzzer off
  }

  // Wait for 1 second before the next reading
  delay(1000);
}