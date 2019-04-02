#include <stdio.h>
#include <string.h>
#define MAX 255

char * parsecsv(FILE *f, char **parsed);

int main()
{
    FILE *fp;
    char **tobeparsed;
    char *parsed;

    // Open the file
    fp = fopen("./testing.csv", "r");
	parsed = parsecsv(fp, tobeparsed);

}

char * parsecsv(FILE *f, char **parsed)
{
    int i=0;
    char buff[MAX];
    char *token;
    const char delim[2] = ",";

    // Read each line in file
    while(fgets(buff, MAX, (FILE*)f))
    {
        // Print line
        parsed[i] = strtok(buff, delim);

        while ((token=strtok(NULL, delim)) != NULL)
            parsed[++i]=token;
    }
    return *parsed;
}
