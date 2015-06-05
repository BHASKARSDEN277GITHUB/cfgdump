#ifndef search_header 
#define search_header

#include<dirent.h>

//method declarations
void searchExe(DIR * , char *,char *); //to search .exe installation directory
void searchFile(DIR * , char *,char *); //to search file installation directory

#endif
