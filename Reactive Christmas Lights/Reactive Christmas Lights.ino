#define DELAY 40
#define AVG_LENGTH 150

#define RELAY 13
#define MIC A0
#define POT A5

int volume;
int raw_input;

int volumes[AVG_LENGTH];
int num=0;
int total;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY,OUTPUT);
}

void loop() {
  num=(num+1)%AVG_LENGTH;
  volumes[num]= map(analogRead(MIC), 0, 447, 0, 681); //447 681

  total=0;
  for(int i=0; i<AVG_LENGTH; i++){
    total+=volumes[i];
  }
  volume = total/AVG_LENGTH;
  
  if(volume>analogRead(POT)){
    digitalWrite(RELAY,HIGH);
    //delay(DELAY);
  }
  else{
    digitalWrite(RELAY,LOW);
    //delay(DELAY);
  }
}
