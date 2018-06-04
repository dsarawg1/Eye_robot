#include "Arduino.h"
#include "encoder.h"

encoder::encoder(int input_pin[10])
{
	for(int i=0; i<10; i++)
	   {
	    pinMode(input_pin[i], INPUT);
	    digitalWrite(input_pin[i],HIGH);
	   }

	   init_1=0;
	   
	for(int i=0; i<10; i++)
		{ 
		count[i]=0;
		}
	   
	for(int i=0; i<10; i++)
		{ 
		_input_pin[i]= input_pin[i];
		}


}

void encoder::read_encoder()
{
    dec_position=0;
    for(int i=0; i<10; i++)
    {
      pin_state[i]= !digitalRead(_input_pin[i]);
    }

    //Converting the digital read into decimal
    for(int i =0; i<10; i++)
    {
      dec_position+= pin_state[i]*pow(2,(9-i));
    }
  
    //Converting gray code to binary code output
    for(int i= dec_position>>1; i!=0; i=i>>1)
    {
     dec_position= dec_position^i;
    }

    //Display the output
    Serial.println(' ');
    for(int i=0; i<10;i++)
    {
      Serial.print(pin_state[i]);
      Serial.print(" ");
    }
    Serial.println(' ');
    Serial.println(dec_position);
}

void encoder::encoder_pin_count()
{

    for(int i=0; i<10; i++)
    {
      pin_state[i]= !digitalRead(_input_pin[i]);
    }
    
    if(init_1==0)
    {
        for( int i=0; i<10; i++)
        {
        prev_pin_state[i]= pin_state[i];
        }
    
        init_1=1;
    }
    
    //Checking for switches between signals
    for( int i=0; i<10; i++)
    {   
       if(pin_state[i]!=prev_pin_state[i])
        {
          count[i]++;
        }
    }
    
    for( int i=0; i<10; i++)
    {
    prev_pin_state[i]= pin_state[i];
    }

    //Display counts

    for(int i=0; i<10;i++)
    {
      Serial.print(count[i]);
      Serial.print(" ");
    }
    Serial.println(' ');
}



