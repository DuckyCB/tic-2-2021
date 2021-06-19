#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <error.h>

#define DEFAULT_LINE 10

int isnumber(char *str) {

	if (*str == '\0') {
		return 0;
	}

	for (; *str != '\0'; str++) {
		if (!isdigit(*str)) {
			return 0;
		}
	}

	return 1;
}

struct linkedlist *createlist() {


}

void filecopy(FILE *ifp, FILE *ofp, int last_lines) {

	struct linkedlist *ll = list_create();
	size_t len = 0;
	char *line = NULL;

	while (getline(&line, &len, ifp) != -1) {
		if (ll->size == last_lines) {
			delete_first(ll);
		}
		add_element(ll, line);
	}
	
	print_list(ll, ofp);
	delete_list(ll);
}

void validatefiles(char **files, int file_count) {

	FILE *fp;

	while (file_count-- > 0) {
		if ((fp = fopen(*files++, "r")) == NULL) {
			error(1, errno, "error in fopen '%s'", *files);
		}
		fclose(fp);
	}
}

int main(int argc, char *argv[]) {

	FILE *fp;
	int total_lines = DEFAULT_LINE;

	if (argc > 1 && **(argv + 1) == '-') {
		argc--;
		if (!isnumber(*(++argv) + 1)) {
			error(1, errno, "invalid parameter '%s'", *argv);
		}
		total_lines = atoi(*argv + 1);
	}

	if (argc == 1) {
		error(2, errno, "No inputs specified");
	}

	validatefiles(argv + 1, argc - 1);

	while (--argc > 0) {
		fp = fopen(*++argv, "r");
		printf("==> %s <==\n", *argv);
		filecopy(fp, stdout, total_lines);
		putc('\n', stdout);
		fclose(fp);
	}
}