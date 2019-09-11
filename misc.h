#ifndef _MISC_H_
#define _MISC_H_

#include <stdio.h>

char* readFileToString(FILE* fh);
int countLines(char* str);
void progressBar(int progress, int maximum);

#endif