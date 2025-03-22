#include <iostream>

static void usage(const std::string &name) {
  std::cerr << "Usage: " << name << "<path_to_display_library>" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage(argv[0]);
    return 84;
  }

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
