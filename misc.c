#include <stdlib.h>
#include <string.h>
#include "misc.h"

char* readFileToString(FILE* fh)
{
	fseek(fh, 0, SEEK_END);
	size_t fileSize = ftell(fh);
	rewind(fh);
	char* fileContents = (char*)malloc(fileSize+1);
	fread(fileContents, 1, fileSize, fh);
	fileContents[fileSize] &=~ fileContents[fileSize];
	fclose(fh);
	return fileContents;
}

int countLines(char* str)
{
	int numLines = 1;
	for (int i = strlen(str); i --> 0; numLines += (str[i] == '\n') ? 1 : 0);
	return numLines;
}

void progressBar(int progress, int maximum)
{
	float percent = progress * 100.0f / maximum;
	printf("[");
	for(int i=0;i<25;++i)
		printf(i<progress*25/maximum?"#":"-");
	printf("] %d/%d (%0.1f%%)\n\033[1A", progress, maximum, percent);
}