#include<stdio.h>
#include<stdlib.h>

int main(){
	char[30] packet = "php-7";
	if(system("which spm") == 0){
		//download("packet-repo-v", "where"); 		
		//verify("packet-repo-v", "where");	
		system("spm -i /tmp/squirrel/packets/%s", packet);


	}else {
		printf("Please download and install spm before use squirrel");
	}
	return 0;
}
