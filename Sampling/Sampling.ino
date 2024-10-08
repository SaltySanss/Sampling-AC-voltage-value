int Voltage = A0; 
int Current = A1; 

float average = 0;
float squ = 0;
float ac = 0;

const int Sample = 137*3;
int Data[Sample];
void setup() {
  pinMode(Voltage,INPUT);
  pinMode(Current,INPUT);
  Serial.begin(115200);

  Sampling();
//-------------------------------------------------------------------- Graphing -------------------------------------------------------------------------------
  for(int i=0; i<= Sample;i++){
    Serial.print((Data[i]*5.0/1023));
    Serial.print("\t");
    Serial.println((Data[i]*5.0/1023)-average/Sample);
  }
//-------------------------------------------------------------------- Display -------------------------------------------------------------------------------
  Serial.print("Average Voltage(DC): ");
  Serial.println(average/Sample,3);
  Serial.print("AC rms Voltage: ");
  Serial.println(sqrt(ac/Sample),3);
  Serial.print("RMS AC+DC Voltage: ");
  Serial.println(sqrt(squ/Sample),3);
  Serial.print("Form Factor : ");
  Serial.println((sqrt(squ/Sample))/(average/Sample),3);
  
 // Serial.print("Voltage source (divider): ");
 // Serial.println((sqrt(squ/Sample))*(1/0.1304)); // reverse V divider VAC = 5.043  VDC = 10.55 
}

void loop() {
  /*double V = analogRead(Voltage);
  double I = analogRead(Current);

  Serial.print("Voltage : ");
  Serial.println(V*5.0/1023);
  Serial.print("Current : ");
  Serial.println(I,3);
  delay(200);*/

  
}

int Sampling(){
  for(int i=0; i<= Sample;i++){
    Data[i] = analogRead(Voltage);
    average = average + Data[i]*5.0/1023;
    squ = squ + (Data[i]*5.0/1023)*(Data[i]*5.0/1023);
    ac = ac + ((Data[i]*5.0/1023)-1.3)*((Data[i]*5.0/1023)-1.3);
  }
}
