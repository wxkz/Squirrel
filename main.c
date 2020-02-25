#include<stdio.h>
#include<string.h>
#include "core.h"

int main(int argc, char **argv){
	if(argv[1] != NULL){
		// First parameter
		if(strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "search") == 0){
			_search(argv[2]);
		}
		if(strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "install") == 0){
			_install(argv[2]);
		}
		if(strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "remove") == 0){
			_remove(argv[2]);
		}
		if(strcmp(argv[1], "-u") == 0 || strcmp(argv[1], "update") == 0){
			_update();
		}
		if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "dependencies") == 0){
			//printf("dependencies");
		}


		// Second parameter
		// if(argv[2] != NULL){
		// 	if(strcmp(argv[2], "-f") == 0 || strcmp(argv[1], "-force") == 0){
		// 		printf("forced");
		// 	}
		// }
	}

}
