#include <stdio.h>
#define MAX 255


int main()
{
    FILE *fp;
    char buff[MAX];

    fp = fopen("./testing.csv", "r");
    while(fgets(buff, MAX, (FILE*)fp))
        printf("Line: %s", buff);

}
