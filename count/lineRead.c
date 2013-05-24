#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEMAX 0xFFF
char* r = "\r\n";


int main(int argc, char** argv) {
	if (argc != 2) {
		printf("usage: %s file.txt\n", argv[0]);
		printf(" counts lines in file that match the message tag");
		return 0;
	}
	
	FILE* txt = fopen(argv[1], "r");

	int count = 0, n = 0;
	char* buffer = (char*)calloc(sizeof(char), LINEMAX);
	
	while(1) {
		char* result = fgets(buffer, LINEMAX, txt);

		//Hard coded requirement; we count any line that matches ^\[msg ?[n\]]
		//  that is, either "[msg]"
		//  or "[msg n"
		if (result != NULL) {
			if (strncmp(buffer, "[msg", 4) == 0) {
				if (buffer[4] == ']')
					count++;
				else if (buffer[5] == 'n')
					count++;
			}
		} else {
			break;
		}
	}

	fclose(txt);
	return count;
}


