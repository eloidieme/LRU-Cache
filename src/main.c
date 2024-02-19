#include <stdio.h>

#include "dll.h"

int main(int argc, char** argv) {
  char* prep[] = {"Félicité", "Emmanuel"};
  char* app[] = {"Fidèle", "Marie Thérèse"};
  dll* family = create("Eloi", 2, 2, prep, app);
  print_dll(family);
  destroy(family);
  return 0;
}