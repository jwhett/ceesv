#include <stdio.h>
#include <string.h>
#define MAX 255

void printcsv(FILE *f);

int main()
{
    FILE *fp;

    // Open the file
    fp = fopen("./testing.csv", "r");
	printcsv(fp);
}

void printcsv(FILE *f)
{
    char buff[MAX];
    char *token;
    const char delim[2] = ",";

    // Read each line in file
    while(fgets(buff, MAX, (FILE*)f))
    {
        // Print line
        printf("Line:\n\t%s", buff);
        token = strtok(buff, delim);

        printf("Tokens:\n\t");
        printf("%s ", token);
        while ((token=strtok(NULL, delim)) != NULL)
            printf("%s ", token);
        printf("\n");
    }
}
