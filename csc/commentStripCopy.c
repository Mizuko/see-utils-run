
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEMAX 0xFFF
#define COMMENT ";"
#define COMMLEN 1


int main(int argc, char** argv) {
	if ((argc != 3) & (argc != 4)) {
		printf("usage: %s from.txt to.txt [comment]\n", argv[0]);
		printf(" copies from from to to, removing commented lines\n", argv[0]);
		printf(" [comment] - optional comment string; default \"%s\"\,", COMMENT);
		return 0;
	}
	
	FILE* src = fopen(argv[1], "r");
	FILE* txt = fopen(argv[2], "wb");

	char* comment = COMMENT;
	int commLen = COMMLEN;

	if (argc == 4) {
		comment = argv[3];
		commLen = strlen(comment);
	}
	

	char* buffer = (char*)calloc(sizeof(char), LINEMAX);	
	while(1) {
		char* result = fgets(buffer, LINEMAX, src);

		if (result != NULL) {
			if (strncmp(buffer, comment, commLen) != 0) {
				fwrite(buffer, sizeof(char), strlen(buffer), txt);
			}
		} else {
			break;
		}
	}

	fclose(txt);
	fclose(src);
	return 0;
}


