#ifndef AND_H
#define AND_H

#include "GATE.h" 

class AND {
  public:
    void inputAND();
    void set_inputAND(bool input1, bool input2);
    bool operateAND();
    void outputAND();
    bool get_outputAND();
    
  private:
    bool _input1;
    bool _input2;
    bool _output;
    int output; 
};

#endif


