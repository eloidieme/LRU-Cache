#include <stdio.h>

#include "dll.h"

int main(int argc, char** argv) {
  char* prep[] = {"Félicité", "Emmanuel"};
  char* app[] = {"Fidèle", "Marie Thérèse"};
  dll* family = create("Eloi", 2, 2, prep, app);
  dll* eloi = find(family, "Eloi");
  insertAfter(family, eloi, "Eloi 2");
  insertBefore(family, eloi, "Eloi -1");
  printDll(family);
  destroy(family);
  return 0;
}