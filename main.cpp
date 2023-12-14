#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "linkedlists.h"

int main() {

  std::ofstream ofs("output.txt");
  std::ifstream ifs("input.txt");

  head = NULL;

  std::string user_input;

  while (std::getline(ifs, user_input)) {

    std::string temp = CommandLines(user_input);
    
    if (temp.length() > 0) {

        ofs << temp << std::endl;

    }
    
  }

  return 0;
}
