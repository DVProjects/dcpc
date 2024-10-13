#ifndef _DCPC_H
#define _DCPC_H 1

#include <stddef.h>

struct ClassS {
  char *name;
  char *body;
  size_t body_len;
};

size_t suffix(char *file_name);
char *findkey(char *text, char *str);
struct ClassS getclass(char **text_ptr);

#endif
