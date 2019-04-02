#include <stdio.h>
#include <string.h>
#define MAX 255

void printcsv(FILE *f);
int isincluded(char *tofind, int thismany, char **inthis);
void findneeded(FILE *f, char *whatsneeded, int argc, char **argv);

int main(int argc, char **argv)
{
    FILE *fp;
    char isneeded[MAX];
    int i=0;

	// zero the array
	for( ; i < MAX ; i++ )
    	isneeded[i]=0;

    // Open the file
    fp = fopen("./testing.csv", "r");
	//printcsv(fp);
	findneeded(fp, isneeded, argc, argv);
}

int isincluded(char *tofind, int thismany, char **inthis)
{
    int i;
    // isincluded returns 1 when tofind appears inthis
    for ( i=0; i<thismany; i++) {
        if (!strcmp(tofind, inthis[i])){
        	return 1; // match
        }
    }
    return 0; // no match
}

void findneeded(FILE *f, char *whatsneeded, int argc, char **argv)
{
	// findneeded sets locations in *whatsneeded to 1 for csv 
	// header locations in FILE that are specified by argv
	char buff[MAX];
	char *token;
	const char delim[2] = ",";
	int i;

    // Read each line in file
    fgets(buff, MAX, (FILE*)f);
    token = strtok(buff, delim); // gives us first token

	i=0;
	if (isincluded(token, argc, argv))
        whatsneeded[i]=1;

	i++;

    while ((token=strtok(NULL, delim)) != NULL){
    	if (isincluded(token, argc, argv))
            whatsneeded[i]=1;
    	i++;
    }
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
