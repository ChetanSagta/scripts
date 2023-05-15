#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

  if (argc == 1)
    return 0;
  std::string::size_type sz;
  int argument = std::stoi(argv[1], &sz);
  std::string filename = "/sys/class/leds/asus::kbd_backlight/brightness";
  int current_output;
  std::fstream file(filename, std::ios::in | std::ios::out);
  if (file.is_open()) {
    file >> current_output;
  }
  if((current_output == 0 && argument == -1) || (current_output == 3 && argument == 1)) return 0;
  else
    current_output += argument;
  file << current_output;
  file.close();
  return 0;
}
