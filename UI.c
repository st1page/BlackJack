#include <stdio.h>

#include "UI.h"
int yORn(){
	char ch=getchar();
	while(ch!='y'&&ch!='Y'&&ch!='N'&&ch!='n') ch=getchar();
	if(ch=='y'||ch=='Y') return 1;
	else return 0;
}
void header(){
	printf("\n\n\n");
	printf(" ____  _            _       _            _    	\n");
	printf("| __ )| | __ _  ___| | __  | | __ _  ___| | __ 	\n");
	printf("|  _ \\| |/ _` |/ __| |/ /  | |/ _` |/ __| |/ /	\n");
	printf("| |_) | | (_| | (__|   < |_| | (_| | (__|   < 	\n");
	printf("|____/|_|\\__,_|\\___|_|\\_\\___/ \\__,_|\\___|_|\\_\\	\n");
	printf("\n\n");	
	return ;
}
void welcm(){
	header();
	printf("	  Press  ENTER  to  Start\n");
	printf("		by stonepage\n");
	printf("\n");
	printf("=========Winner winner, chicken dinner!=========\n");
	printf("\n\n\n");
	char ch=getchar();
	return ;
}
int main_menu_ui(){
	header();
	printf("************************************************\n");	
	printf("*               1. SINGLE PLAYER               *\n");	
	printf("*               2. NETWORK                     *\n");
	printf("*               3. OPTION                      *\n");
	printf("*               4. HELP                        *\n");
	printf("*               5. EXIT                        *\n");
	printf("************************************************\n");	
	printf("\n");
	printf("=========Winner winner, chicken dinner!=========\n");
	printf("\n\n\n");
	int res; scanf("%d",&res);
	while(res<1||res>5) scanf("%d",&res);
	return res;
}
int quit_ui(){
	header();
	printf("************************************************\n");	
	printf("*                                              *\n");	
	printf("*      Do you really want to quit?(y/n)        *\n");
	printf("*                              	               *\n");
	printf("************************************************\n");	
	printf("\n\n\n");
	return yORn();
}