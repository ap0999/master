    #include <SoftwareSerial.h>
SoftwareSerial  BTSerial(2, 3); //RX TX
    #define trigPin 13
    #define echoPin 12
    #include <dht.h>
    dht DHT;
    #define DHT11_PIN 7
    
    void setup() {
        BTSerial.begin(9600); 
  Serial.begin(9600);
      Serial.begin (9600);
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
      pinMode(4, OUTPUT);
      pinMode(2, OUTPUT);
    
      
    }
    void loop() {
      long duration, distance;
      digitalWrite(trigPin, LOW);  // start trig at 0
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH); //The rising edge of trig pulse
      delayMicroseconds(10); // decides duration of trig pulse
      digitalWrite(trigPin, LOW); //falling edge of the trig pulse
      // NOTE: echo pin reads HIGH till it receives the reflected signal
      duration = pulseIn(echoPin, HIGH);  // Reading the duration for which echoPin was HIGH gives        //you the time the sensor receives a reflected signal at the echo pin
      distance = (duration / 2) / 29.1;   //Calculate the distance of the reflecting surface in cm
      
      bool distanceB = false;
      
      if (distance >= 0 && distance <70) {
        digitalWrite(4, HIGH);
        Serial.print("Distance = ");
        Serial.print(distance);
        distanceB = true;
      }
      else if (distance >= 70) {
          digitalWrite(4, LOW);
        Serial.print("Distance = ");
        Serial.print(distance);
      }
    
      int chk = DHT.read11(DHT11_PIN);
      Serial.print("   Temperature = ");
      Serial.print(DHT.temperature);
      Serial.print("   Humidity = ");
      Serial.println(DHT.humidity);
    bool humidityB = false;
    bool temperatureB = false;
    bool tempHum = false;
    
    if (DHT.humidity > 50) {
    humidityB = true;
    }
    if (DHT.temperature > 25) {
    temperatureB = true;
    }
    
    if (temperatureB || humidityB) {
      tempHum = true;
          
    }
    
    if (distanceB || tempHum) {
    Serial.println("Somebody is in the shower");
    BTSerial.println(String(1));
    } else {
    Serial.println("the shower is empty");
    BTSerial.println(String(0));
    }
      
      delay(1000);
    
      }
