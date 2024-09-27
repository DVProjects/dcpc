#include "dcpc.h"
#include <string.h>
#include <stddef.h>

size_t suffix(char *file_name){
  size_t res = strlen(file_name);
  while (file_name[res] != '.' && res >= 0) res--;
  return res +1;
}
