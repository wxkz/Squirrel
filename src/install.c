#include<stdio.h>
#include<stdlib.h>

int main(char[30] packet){
	if(system("which spm") == 0){
		//download("packet");
		//verify("packet");
		//system("spm -i /tmp/squirrel/packets/%s", packet);
	}else {
		printf("Please download and install spm before use squirrel");
	}
	return 0;
}
