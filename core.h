#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>

// Test --------------------------
int _teste(){
  printf("teste");
};


// Search packet --------------------------
void _search(char *search){
  // Search packet in packets.txt
  FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen("packets.txt", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, stream)) != -1) {
    if(strstr(line, search) != NULL){
      printf("%s", line);
    }
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);

};

// List dependencies ---------------
void _list(){

};


// Verify --------------------------
int _dependecies(char *packet){
	printf("You can skip verification with --force or --no-verify");
};

int _exist(char *packet){
  char *command = "which ";
  strcpy(command, packet);
  if(system(command) == 0){
		return 0;
	}else{
		printf("Packet does not exist");
		return 1;
	}
};

// Download --------------------------
int _download(int argc, char **argv){
	CURL *curl;
	FILE *fp;
	int result;

	fp = fopen(argv[2], "wb");

	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

	result = curl_easy_perform(curl);

	if(result == CURLE_OK)
		printf("Download successful!\n");
	else
		printf("Error: %s\n", curl_easy_strerror(result));

	fclose(fp);

	curl_easy_cleanup(curl);
};

// ######################################################################

// Install --------------------------
int _install(char *packet){
	if(system("which spm") == 0){

    // Read repo.conf
    char server[64];
    FILE *fptr;
    if ((fptr = fopen("repo.conf", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    fscanf(fptr, "%[^\n]", server);
    fclose(fptr);

    // Download packet
    char command[128] = "wget ";
    strcat(command, server);
    strcat(command, packet);
    strcat(command, ".slp");
    system(command);

    // Verifu packet
		//_verify("packet");

    // Actually install packet
		//system("spm -i /tmp/squirrel/packets/%s", packet);
	}else {
		printf("Please download and install spm before use squirrel");
	}
	return 0;
};


// Remove --------------------------
int _remove(char *packet){
  if(system("which spm") == 0){
    _exist(packet);
    _dependecies(packet);

    char *command = "spm -r ";
    strcpy(command, packet);

    system(command);
	}
};


// Update --------------------------
int _update(){
  // Download newsts packet list
  system("rm packets.txt");
  system("wget https://raw.githubusercontent.com/wxkz/Squirrel/master/packets.txt");
};
