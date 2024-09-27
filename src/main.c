#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dcpc.h"

int cpreprocess(char *file_name, size_t file_ext_i){
  int res;
  char *command = malloc(strlen(file_name) * 2 +8);
  sprintf(command, "cpp -o %s %s", file_name, file_name);
  command[file_ext_i +7] = 'i';
  res = system(command);
  free(command);
  return res;
}

int main(int argc, char *argv[]){
  for (int i = 1; i < argc; i++) {
    size_t file_ext_i = suffix(argv[i]);
    if (file_ext_i){
      if (!strcmp("c+", argv[i] + file_ext_i)){
        cpreprocess(argv[i], file_ext_i);
        argv[i][file_ext_i] = 'i';
      }
      // Load buffer with file data
      // Arrange buffer content
      // Save to file / compile
    }
  }
  return 0;
}
