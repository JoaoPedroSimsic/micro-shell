#include "include/utils.h"
#include <stdlib.h>
#include <string.h>

void remove_new_line(char *str) {

  if (str == NULL) {
    return;
  }

  str[strcspn(str, "\n")] = 0;
}

void free_args_memory(char **args, int count) {

  if (args == NULL) {
    return;
  }

  for (int i = 0; i < count; i++) {

    if (args[i] != NULL) {
      free(args[i]);
      args[i] = NULL;
    }
  }

	free(args);
	args = NULL;
}
