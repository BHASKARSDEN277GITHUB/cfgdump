//driver for testing search module
//check search.h for availaible method declarations


#include "search.h"
#include<stdio.h>

main() {
	//for windows use drive paths like char * initPath="E:\\";//
	char * initPath="/home/bhaskar/Documents/programming/summer_2015/"; //reference to start search
	DIR *currentDirectory; //creating refernce to directory 
	currentDirectory=opendir(initPath); 

	//directory search (in case of exe need to look up for directory)
//	printf("Searching directory\n");
//	searchExe(currentDirectory,"idm",initPath); //start the search now


	//file search 
	printf("Searching file\n");
	searchFile(currentDirectory,"testfile",initPath); //start the search now
}
