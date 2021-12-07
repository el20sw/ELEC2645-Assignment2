#ifndef XOR_H
#define XOR_H

#include "GATE.h"

class XOR {
  public:
    void inputXOR();
    void set_inputXOR(bool input1, bool input2);
    bool operateXOR();
    void outputXOR();
    bool get_outputXOR();

  private:
    bool _input1;
    bool _input2;
    bool _output;
    int output;
};

#endif