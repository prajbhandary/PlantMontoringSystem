
int photoresistor = A0; 
int temp=A2;
int psensorvalue,SoilSensor; // Here we are declaring the integer variable analogvalue, which we will use later to store the value of the moisture.
float voltage, degreesC, degreesF,tempC,tempvalue;

const int RED_PIN = D0;
const int GREEN_PIN = D2;


void setup() {

   
    pinMode(photoresistor,INPUT);      
    pinMode(temp,INPUT);      
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
  
  

}

void loop() {
    



   

  //Convert the reading into degree celcius
  tempvalue = analogRead(temp);
  degreesC = (((tempvalue * 3.3)/4095) - 0.5) * 100;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  //Reading and Maping the Moisture Sensor
  
  SoilSensor = map (psensorvalue, 0, 2200, 0,100);
  psensorvalue = analogRead(photoresistor);
    
    //Pubishing the values to Particle 
     Particle.publish( "Temperature",String(degreesF)); 
     Particle.publish( "Soil Moisture",String(SoilSensor)); 
    
    
    
        
        
    //If condition for the RBG light
    
    if ((SoilSensor > 80 || SoilSensor < 20) || (degreesF < 50 || degreesF > 85 ))
    {
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(RED_PIN, HIGH);
        
    }
    else{
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(RED_PIN, LOW);
    }
        
    delay(3000);
}

