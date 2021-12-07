#ifndef NOR_H
#define NOR_H

#include "NOT.h"
#include "OR.h"
#include "GATE.h"

class NOR : virtual public NOT, virtual public OR {
  public:
    void inputNOR();
    void set_inputNOR(bool input1, bool input2);
    bool operateNOR();
    void outputNOR();
    bool get_outputNOR();
  
  private:
    bool _input1;
    bool _input2;
    bool _input;
    bool _output;
    int output;
};

#endif