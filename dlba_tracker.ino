
int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup() {
    pinMode(inputPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    checkForMotion();
}

void checkForMotion(){
    val = digitalRead(inputPin);
    if (val == HIGH){
        if (pirState == LOW){
            Serial.println("Motion!");
            pirState = HIGH;
            sendToParticle();
        }
    } else {
        if (pirState == HIGH){
            Serial.println("Motion Ended");
            pirState = LOW;
        }
    }
}

void sendToParticle(){
    bool success;
    success = Particle.publish("motion-detected");
    if (!success) {
     // get here if event publish did not work
    }
}

void getStats(){
    
}
