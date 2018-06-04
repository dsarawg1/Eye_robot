#ifndef encoder_h
#define encoder_h

#include "Arduino.h"

class encoder
{
  public:
  encoder(int input_pin[]);
  void read_encoder();
  void encoder_pin_count();

  private:
  int _input_pin[10];
  int pin_state[10];
  int prev_pin_state[10];
  int count[10];
  int init_1;
  int dec_position;
  
};

#endif

