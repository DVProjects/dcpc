#include "dcpc.h"
#include <string.h>
#include <ctype.h>
#include <stddef.h>

size_t suffix(char *file_name){
  size_t res = strlen(file_name);
  while (file_name[res] != '.' && res >= 0) res--;
  return res +1;
}

char *findkey(char *text, char *str){
  while (*text){
    if (*text == '"')
      text = strchr(text +1, '"');
    if (str && !memcmp(text, str, strlen(str))){ 
      return text;}
    text++;
  }
  return NULL;
}

char *skipblank(char *text){
  while (text && isblank(*text)) text++;
  return text;
}

char *skiptext(char *text){
  while (text && !isblank(*text)) text++;
  return text;
}

size_t endofblocki(char *text){
  size_t res;
  long depth = 1;
  for (res = 0; text[res] && depth; res++){
    if (text[res] == '{') depth++;
    if (text[res] == '}') depth--;
    //putchar(text[res]);
  }
  return res;
}

struct ClassS getclass(char **text_ptr){
  struct ClassS res;  
  *text_ptr = findkey(*text_ptr, "class");
  res.name = *text_ptr;
  if (!res.name)
    return (struct ClassS){0};
  *text_ptr += 5;
  res.name = skipblank(*text_ptr);
  res.body = skiptext(res.name);
  res.body = skipblank(res.body);
  if (*(res.body) != '{' && *(res.body) != ';')
    return (struct ClassS){.name = 0};
  if (*(res.body) == ';'){
    res.body_len = 1;
    return res;
  }
  *text_ptr = res.body +1;
  res.body_len = endofblocki(*text_ptr) +1;
  return res;
}
