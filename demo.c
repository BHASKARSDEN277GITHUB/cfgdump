#include<stdio.h>
#include<dirent.h>
#include<string.h>
int main()
{
char *path="/root/c/";
DIR *dp;
dp=opendir(path);
struct dirent *dptr=NULL;
while(NULL!=(dptr=readdir(dp)))
{
printf("%s",dptr->d_name);
printf("\n");
}
if(!strcmp("deepanshu","d"))
{
printf("they are not equal");
}
}
