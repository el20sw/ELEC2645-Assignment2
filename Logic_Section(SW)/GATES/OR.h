#ifndef OR_H
#define OR_H

#include "GATE.h"

class OR {
  public:
    void inputOR();
    void set_inputOR(bool input1, bool input2);
    bool operateOR();
    void outputOR();
    bool get_outputOR();

  private:
    bool _input1;
    bool _input2;
    bool _output;
    int output;
};

#endif