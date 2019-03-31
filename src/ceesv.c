#include <stdio.h>
#include <string.h>
#define MAX 255


int csvparse(char buf[]);

int main()
{
    FILE *fp;
    char buff[MAX];
    char *token;
    const char delim[2] = ",";

	// Open the file
    fp = fopen("./testing.csv", "r");

	// Read each line in file
    while(fgets(buff, MAX, (FILE*)fp))
    {
        // Print line
        printf("Line:\n\t%s", buff);
        token = strtok(buff, delim);

		printf("Tokens:\n\t");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, delim);
        }
        printf("\n");
    }
}
