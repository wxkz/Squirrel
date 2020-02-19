#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){
	if(strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "search") == 0){
		printf("search");
	}
	if(strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "install") == 0){
		printf("install");
	}
	if(strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "remove") == 0){
		printf("remove");
	}
	if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "dependencies") == 0){
		printf("dependencies");
	}
	

	//		
	if(strcmp(argv[2], "-f") == 0 || strcmp(argv[1], "-force") == 0){
		printf("forced");
	}
	else{}

}
