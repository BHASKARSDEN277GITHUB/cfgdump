#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<malloc.h>

#include "search.h"

//method definitions

void searchExe(DIR * dir, char * nameExe, char * path) { //to search where exe is installed
	
	struct dirent *directoryInfo ; //creating pointer to dirent object to access the directory ..
	struct stat buf ; //creating stat object  ..
	char *currentPath ; //path of current directory being acessed ..
	char *newPath ; //path of directory going to be accessed now .. lol ..its funny ..

	DIR *newDirectory;
	char *name ;
	char *newinterPath;
	char * prefixWindows="\\";
	char * prefixUnix="/";
	
	//reading the directory now

	while((directoryInfo=readdir(dir))!=NULL) {

		name=directoryInfo->d_name;

		if(strcmp(name,".") && strcmp(name,"..")) {

			currentPath=(char *)malloc(strlen(name)+strlen(path)+10000); //created current path
			strcpy(currentPath,path);
			strcat(currentPath,name);
			newPath=(char *)malloc(strlen(currentPath)+100);
			strcpy(newPath,currentPath);
			strcat(newPath,prefixUnix); //created  newPath (added prefix to current path)
			
			
			//checking if a directory or not
			if(stat(currentPath,&buf)!=0) {
				continue;
			} else if(S_ISDIR(buf.st_mode)) {  // this is a directory
				//print dir name  if nameExe is same as directory's name
				if(!strcmp(nameExe,name)) {
					printf("%s	%s\n",name,currentPath);
					//recur as exe can be installed in some other place also
					newDirectory=opendir(newPath);
					searchExe(newDirectory,nameExe,newPath);
				} else {
					//go for next directory
					//printf("%s      %s\n",name,currentPath);
					newDirectory=opendir(newPath);
					searchExe(newDirectory,nameExe,newPath);
				}
				
			} else { //this is a file
				//none of use while searching for a directory
			}
			
		} 
	}
	

}

void searchFile(DIR * dir, char * nameFile, char  *path) { //to search a file
	
	struct dirent *directoryInfo ; //creating pointer to dirent object to access the directory ..
	struct stat buf ; //creating stat object  ..
	char *currentPath ; //path of current directory being acessed ..
	char *newPath ; //path of directory going to be accessed now .. lol ..its funny ..

	DIR *newDirectory;
	char *name ;
	char *newinterPath;
	char * prefixWindows="\\";
	char * prefixUnix="/";
	
	//reading the directory now
	while((directoryInfo=readdir(dir))!=NULL) {

		name=directoryInfo->d_name;

		if(strcmp(name,".") && strcmp(name,"..")) {

			currentPath=(char *)malloc(strlen(name)+strlen(path)+5); //created current path
			strcpy(currentPath,path);
			strcat(currentPath,name);
			newPath=(char *)malloc(strlen(currentPath)+5);
			strcpy(newPath,currentPath);
			strcat(newPath,prefixUnix); //created  newPath (added prefix to current path)
			
			//checking if a directory or not
			if(stat(currentPath,&buf)!=0) {
				continue;
			} else if(S_ISDIR(buf.st_mode)) {  // this is a directory
				//go for next directory
				newDirectory=opendir(newPath);
				searchFile(newDirectory,nameFile,newPath);
				
			} else { //this is a file
				//check if name of file is same as nameFile
				if(!strcmp(nameFile,name)) {
					//print name of file and location
					printf("%s	%s\n",name,currentPath);
					//stop here
					return;
				}
			}
		}
	}

}
