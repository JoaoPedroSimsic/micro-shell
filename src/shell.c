#include <stdio.h>
#include <string.h>
// #include "parser.h"
// #include "builtins.h"
// #include "exec.h"

#define INPUT_SIZE 1024

void shell_loop() {
	char input[INPUT_SIZE];
	char *argv[64];

	while (1) {
		printf("-> ");
		fflush(stdout);

		if (!fgets(input, INPUT_SIZE, stdin)) {
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = 0;

		int argc = parse_input(input, argv);
	}
}
