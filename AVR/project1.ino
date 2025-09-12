const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
const int buzzerPin = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 
  noInterrupts();
  long duration = pulseIn(echoPin, HIGH, 30000);  
  interrupts();

  float distance = (duration > 0 ? duration * 0.034 / 2 : 1000.0);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 50) {
    
    float distanceMeters = distance / 100.0;
    float lightTime = (distanceMeters * 2) / 299792458.0;
    long lightTimeMicro = lightTime * 1e6;

    
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(lightTimeMicro);
    digitalWrite(buzzerPin, LOW);

    
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);

  } else {
    
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100);  
  }
}


