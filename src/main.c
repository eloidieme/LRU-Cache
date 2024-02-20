#include <stdio.h>

#include "dll.h"
#include "hashtable.h"

int main(int argc, char** argv) {
  char* prep[] = {"Félicité", "Emmanuel"};
  char* app[] = {"Fidèle", "Marie Thérèse"};
  dll* family = dllCreate("Eloi", 2, 2, prep, app);
  dll* eloi = dllFind(family, "Eloi");
  dllInsertAfter(family, eloi, "Eloss");
  dllInsertBefore(family, eloi, "Wael");
  dllPrint(family);
  tableNode** hashT = hashTableInit(dllLength(family));
  hashTableFillFromDll(hashT, family);
  hashTablePrint(hashT, dllLength(family));
  hashTableDestroy(hashT);
  dllDestroy(family);
  return 0;
}