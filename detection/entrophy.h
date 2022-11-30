#ifndef ENTROPHY
#define ENTROPHY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int makehist(FILE *fh, int *hist, int len);

double entropy(int *hist, int histlen, int len);

double calc_file(char * filename);

#endif