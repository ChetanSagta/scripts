#include <array>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <stdlib.h>
#include <string>
#include <vector>

std::string execCommand(const std::string cmd, int &out_exitStatus) {
  out_exitStatus = 0;
  auto pPipe = ::popen(cmd.c_str(), "r");
  if (pPipe == nullptr) {
    throw std::runtime_error("Cannot open pipe");
  }
  std::array<char, 256> buffer;
  std::string result;
  while (not std::feof(pPipe)) {
    auto bytes = std::fread(buffer.data(), 1, buffer.size(), pPipe);
    result.append(buffer.data(), bytes);
  }
  auto rc = ::pclose(pPipe);
  if (WIFEXITED(rc)) {
    out_exitStatus = WEXITSTATUS(rc);
  }
  return result;
}

int main() {

  int p = 0;
  std::string output =
      execCommand("dpkg-query -Wf '${Installed-Size}\t${Package}\n'", p);

  std::map<int ,std::string> apps;
  int output_len = output.length();

  while (output.length() > 0) {
    int tab_pos = output.find('\t');
    int newline_pos = output.find('\n');
    std::string size_str = output.substr(0, tab_pos);
    std::string appName = output.substr(tab_pos + 1, newline_pos - tab_pos - 1);
    if (tab_pos != 0)
      apps.insert({std::stoi(size_str),appName});
    output = output.substr(newline_pos + 1, output_len);
  }

  int count = 0;
  for (const auto &app : apps) {
    std::cout << '[' << app.first << "] = " << app.second << ";\n";
    count += app.first;
  }

  std::cout<<"Total Size: "<<count<<std::endl;



  return 0;
}
