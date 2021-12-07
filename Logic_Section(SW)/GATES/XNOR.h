#ifndef XNOR_H
#define XNOR_H

#include "NOT.h"
#include "XOR.h"
#include "GATE.h"

class XNOR : virtual public NOT, virtual public XOR {
  public:
    void inputXNOR();
    void set_inputXNOR(bool input1, bool input2);
    bool operateXNOR();
    void outputXNOR();
    bool get_outputXNOR();

  private:
    bool _input1;
    bool _input2;
    bool _input;
    bool _output;
    int output;
};

#endif