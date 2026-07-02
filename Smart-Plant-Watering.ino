#include <LiquidCrystal.h> //include lcd laibrary
const int S_M=A0;          //Definition of soil moisture sensor pin
const int W_L=A1;          //Definition of water klrvel sensor pin
const int led=13;          //Definition of led pin
LiquidCrystal lcd(12,11,5,4,3,2);  //Defineition of lcd pins


void setup() {
  pinMode(led, OUTPUT);  //definition of led like a OUTPUT and the sensors like a INPUT
  pinMode(S_M,INPUT);
  pinMode(W_L,INPUT);


  lcd.begin(16,2);      // Initialise the lcd
 
}

void loop() {
  int S_M_value=analogRead(S_M);    //Read analog sensors
  int W_L_value=analogRead(W_L);
  
  if(W_L_value>200){                 // Tank has water

    
    if(S_M_value<400){               //soil is Wet
      digitalWrite(led, LOW);
      lcd.setCursor(0, 0);
      lcd.print("Soil: WET       ");
      lcd.setCursor(0, 1);
      lcd.print("STOP WATERING...");
    }
      
      
    else if(S_M_value>=400 && S_M_value <=700){  // soil is normal
      digitalWrite(led, LOW);
      lcd.setCursor(0, 0);
      lcd.print("Soil: NORMAL    ");
      lcd.setCursor(0, 1);
      lcd.print("STOP WATERING...");
    }

      
    else{                                        //soil is Dry
      digitalWrite(led, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Soil: DRY  ");
      lcd.setCursor(0, 1);
      lcd.print("WATERING...");


    }
  }

    
  else{                                 //Tank is Empty
    digitalWrite(led, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Tank: Empty      ");
    lcd.setCursor(0, 1);
    lcd.print("Fill the Tank... ");
  }

delay(500);

}
