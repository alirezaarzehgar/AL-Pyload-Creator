#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#ifndef FUNC_H_
#define FUNC_H_

int port;
char Tip[10];
char Tname[30];
char OS[100];
char mode[1024];

int hacking;

void banner();
int TargetCreator(char* name, char* ip, int port);
void gettingAccess(int port);
int Wait(int number, int color_code);
int TargetCreator_server(char* name, int port);
int gettingAccess_server(int port, char* IP);

#endif /* func.h */
