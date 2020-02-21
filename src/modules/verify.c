#include<stdio.h>
#include<stdlib.h>

int _dependecies(char[30] packet){
	printf("You can skip verification with --force or --no-verify")
}

int _exist(char[30] packet){
        if(system("which %s", packet) == 0){
		return 0;
	}else{
		printf("Packet does not exist");
		return 1;
	}
}
