#include <stdio.h>
#include<ctype.h>

#include "UI.h"

char tmps[200];
void gtline(char s[],int *len){
	*len=0;
	char ch = getchar();
	while(ch!='\n') {
		s[++(*len)] = ch;
		if(*len>190) *len = 0;
		ch = getchar();
	}
	return ;
}
int isYN(char ch){
	return (ch=='y'||ch=='Y'||ch=='n'||ch=='N');
}
int gtdigit(){
	int st=1,n; 
	gtline(tmps,&n);
	while(isspace(tmps[n]) && n>=st) n--;
	while(isspace(tmps[st]) && n>=st) st++;
	if(!isdigit(tmps[st])) return -1;
	if(n!=st) return -1;
	return tmps[st]-'0';
}
int gtYN(){
	int st=1,n; 
	gtline(tmps,&n);
	while(isspace(tmps[n]) && n>=st) n--;
	while(isspace(tmps[st]) && n>=st) st++;
	if(!isYN(tmps[st])) return -1;
	if(n!=st) return -1;
	if(tmps[st]=='Y'||tmps[st]=='y') return 1;
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
	int n;
	gtline(tmps,&n);
	return ;
}
int main_menu_ui(){
	header();
	printf("************************************************\n");	
	printf("*               1. SINGLE PLAYER               *\n");	
	printf("*               2. NETWORK                     *\n");
	printf("*               3. HELP                        *\n");
	printf("*               4. EXIT                        *\n");
	printf("************************************************\n");	
	printf("\n");
	printf("=========Winner winner, chicken dinner!=========\n");
	printf("\n\n\n");
	printf("Input the number\n");
	return gtdigit(); 
}
int quit_ui(){
	header();
	printf("************************************************\n");	
	printf("*                                              *\n");	
	printf("*      Do you really want to quit?(y/n)        *\n");
	printf("*                              	               *\n");
	printf("************************************************\n");	
	printf("\n\n\n");
	return gtYN();
}
void ntwk_ui(){
	header();
	printf("************************************************\n");	
	printf("*                                              *\n");	
	printf("*              Coming soon ...                 *\n");
	printf("*         Press  ENTER  to  Return             *\n");
	printf("*                              	               *\n");
	printf("************************************************\n");	
	printf("\n\n\n");
	int n; gtline(tmps,&n);
	return ;
}
int turn_ui(){
	printf("********************Your turn*******************\n");	
	printf("*               1. HIT                         *\n");	
	printf("*               2. STAND                       *\n");
	printf("*               3. WATCH MY HAND CARDS         *\n");
	printf("************************************************\n");	
	printf("Input the number\n");
	return gtdigit();
}
void ctn_ui(){
	printf("	  Press  ENTER  to  Continue\n");
	int n; gtline(tmps,&n);
	return ;
}
int again_ui(){
	header();
	printf("************************************************\n");	
	printf("*                                              *\n");	
	printf("*               Play again?(y/n)               *\n");
	printf("*                              	               *\n");
	printf("************************************************\n");	
	printf("\n\n\n");
	return gtYN();	
}
void hlp_ui(){
	header();
	printf("================规则介绍=========================\n");
	printf("拥有最高点数的玩家获胜,其点数必须等于或低于21点;\n");
	printf("超过21点的玩家称为爆牌。\n");
	printf("2点至10点的牌以牌面的点数计算,J、Q、K每张为10点,\n");
	printf("A可以记为1点或11点。\n");
	ctn_ui();
	printf("================术语介绍=========================\n");
	printf("HIT:要牌\n");
	printf("STAND:不要牌:\n");
	printf("BUST:爆牌 即点数超过21点\n");
	printf("PUSH:平局\n");
	ctn_ui();
	return;
}