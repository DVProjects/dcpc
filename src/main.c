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

char *loadfile(FILE *file){   // Load buffer with file data
  char *buf;
  size_t file_size;
  fseek(file, 0, SEEK_END);
  file_size = ftell(file);
  rewind(file);
  buf = malloc(file_size + 1);
  fread(buf, file_size, 1, file);
  buf[file_size] = 0;
  return buf;
}

void arrange(char *text){   // Arrange buffer content
  struct ClassS *class = NULL, tmp;
  size_t class_n = 0;
  while (*text) {
    tmp = getclass(&text);
    if (!tmp.name || tmp.body_len < 2)
      break;
    class_n++;
    class = reallocarray(class, class_n, sizeof(struct ClassS));
    // Apply changes
  }
  if (class) free(class);
}

int main(int argc, char *argv[]){
  for (int i = 1; i < argc; i++){
    size_t file_ext_i = suffix(argv[i]);
    if (file_ext_i){
      if (!strcmp("c+", argv[i] + file_ext_i)){
        cpreprocess(argv[i], file_ext_i);
        argv[i][file_ext_i] = 'i';
      }
      if (!strcmp("i+", argv[i] + file_ext_i)){
        FILE *src = fopen(argv[i], "rb");
        char *file_buf = loadfile(src);
        arrange(file_buf);
        // Save to file / pass to gcc
        fclose(src);
        free(file_buf);
      }
    }
  }
  return 0;
}
