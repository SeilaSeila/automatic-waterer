#define pinSensorA A0
#define second 1000
#define hour 3600*second

const float sprinklingTime = 5000; //In milliseconds
const float CycleTime = 2; //In Hours

void setup() {
  Serial.begin(9600);
  
  //Solenoide
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  
}

int getdryPercent(int currentMoisture){
  if (currentMoisture == 0)
    return 0;

  return 100/(1024/currentMoisture); 
}

void sprinkle(){
  //Open Solenoide
  digitalWrite(7,LOW);
  Serial.println("SOLENOIDE WAS OPENED");

  delay(sprinklingTime);

  //Close Solenoide
  digitalWrite(7,HIGH);
  Serial.println("SOLENOIDE WAS CLOSED");
}

void loop() {
  
  delay(CycleTime * hour);

  int dryPercent = getdryPercent(analogRead(pinSensorA));

  //Soil drier than 70%
  if (dryPercent > 70)
     sprinkle();

  Serial.print(dryPercent + '\n');
  Serial.println("A cycle has passed");
}
