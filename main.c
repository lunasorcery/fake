#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "misc.h"
#include "crc32.h"

int main(int argc, char** argv)
{
	// --version flag
	if (argc > 1 && ((strcmp(argv[1], "--version") == 0) || (strcmp(argv[1], "-v") == 0)))
	{
		printf("Fake 0.1a\n");
		printf("Copyright (C) 2019  Luna Sorcery\n");
		printf("This is free software; see the source for copying conditions.\n");
		printf("There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A\n");
		printf("PARTICULAR PURPOSE.\n");
		return 0;
	}

	// try to open the fakefile
	FILE* fh = fopen("Fakefile", "rb");

	// check if it actually exists
	if (!fh)
	{
		printf("fake: *** No targets specified and no fakefile found.  Stop.\n");
		return 1;
	}

	// load the fakefile
	char* fileContents = readFileToString(fh);

	// hash it
	uint32_t hash = crc32(fileContents, strlen(fileContents));
	srand(hash);

	// check for syntax errors
	if ((hash & 1) == 0)
	{
		// count the newlines
		int numLines = countLines(fileContents);
		
		// print where the syntax error was
		int errorLine = (rand() % numLines) + 1;
		printf("Fakefile:%d: *** syntax error.  Stop.\n", errorLine);
		return 1;
	}

	int numFiles = (rand() & 0x7ff) + 10;
	int speedScale = 1 + (25000 / numFiles);

	// prepare build targets
	printf("Checking files:\n");
	for (int i = 0; i <= numFiles; ++i) {
		progressBar(i, numFiles);
		usleep(speedScale * 10 * (rand() & 31));
	}
	printf("\n");

	// sanity checking
	printf("Extra sanity checks:\n");
	for (int i = 0; i <= numFiles; ++i) {
		progressBar(i, numFiles);
		usleep(speedScale * 10 * (rand() & 31));
		if ((rand() & 0xff) == 0)
		{
			printf("\nfake: *** Failed sanity check.  Stop.\n");
			return 1;
		}
	}
	printf("\n");

	// sentience
	printf("Achieving sentience:\n");
	for (int i = 0; i <= 100; ++i) {
		progressBar(i, 100);
		usleep(speedScale * 25 * (rand() & 31));
		if ((rand() & 0xff) == 0)
		{
			printf("\nfake: *** Failed to achieve sentience.  Stop.\n");
			return 1;
		}
	}
	printf("\n");

	// build!
	printf("Building:\n");
	for (int i = 0; i <= numFiles; ++i) {
		progressBar(i, numFiles);
		usleep(speedScale * 100 * (rand() & 31));
		if ((rand() & 0x3f) == 0 || i == (numFiles - 1))
		{
			printf("\nfake: *** Internal compiler error.  Stop.\n");
			return 1;
		}
	}
	printf("\n");

	printf("fake: Build succeeded!\n");
	return 0;
}