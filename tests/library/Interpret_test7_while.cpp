#include <iostream>
#include <sstream>
#include <string>

#include "syntax/Syntax.hpp"

using namespace RICC;

int main() {
  long result = 0;

  {
    std::string program =
        "while(false) {printSTRING(\"in WHILE\");} printSTRING(\"out WHILE\");";
    std::cout << program << std::endl;
    std::istringstream ss(program);
    Syntax s(ss);

    result += s.Parse();
    s.getIntepreter().printCode();
    result += s.getIntepreter().run();
  }

  {
    std::string program =
        "int x = 0; while(x < 5) {printINT(x); x = x + 1;} printSTRING(\"out "
        "WHILE\");";
    std::cout << program << std::endl;
    std::istringstream ss(program);
    Syntax s(ss);

    result += s.Parse();
    s.getIntepreter().printCode();
    result += s.getIntepreter().run();
  }

  {
    std::string program =
        "while(true) {printSTRING(\"in WHILE\"); break; break; break;} "
        "printSTRING(\"out WHILE\");";
    std::cout << program << std::endl;
    std::istringstream ss(program);
    Syntax s(ss);

    result += s.Parse();
    s.getIntepreter().printCode();
    result += s.getIntepreter().run();
  }

  {
    std::string program =
        "int x = 0; while(true) {if(x < 5) {x = x+1; continue; "
        "printSTRING(\"in WHILE\");} else { break;}} printSTRING(\"out "
        "WHILE\");";
    std::cout << program << std::endl;
    std::istringstream ss(program);
    Syntax s(ss);

    result += s.Parse();
    s.getIntepreter().printCode();
    result += s.getIntepreter().run();
  }

  return result;
}
