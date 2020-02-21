#include<stdio.h>
#include<stdlib.h>

int main(char[30] packet){
        if(system("which spm") == 0){
		verify("packet");
                system("spm -r %s", packet);
	}
