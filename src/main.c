#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  char input [1024];

	while (1) {
		printf("mysh> ");
		if (!fgets(input, sizeof(input), stdin)) break;

		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit") == 0) break;

		char *args[100];
		int i = 0;
		args[i] = strtok(input, " ");
		while (args[1] && i < 99) {
			i++;
			args[i] = strtok(NULL, " ");
		}

		pid_t pid = fork();
		if (pid == 0) {
			if (execvp(args[0], args) == -1) {
				perror("mysh");
			}
			exit(1);
		} else if (pid > 0) {
			waitpid(pid, NULL, 0);
		} else {
			perror("fork failed");
		}
	}

	return 0;
}
