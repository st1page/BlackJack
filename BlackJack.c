#include <stdio.h>

#include "UI.h"
struct card{
	int color,num;
} 
struct heap{
	int tot;
	card a[210];
}
void heap_init(heap *h,int sum){

}
void main_menu();
void quit(){
	int x = quit_ui();
	if(x) printf("Bye!\n");
	else main_menu(); 
	return ;
}
void main_menu(){
	int x = main_menu_ui();
	if(x==1);// sin_mode();
	else if(x==2);// ntwk();
	else if(x==3);// opt();
	else if(x==4);// hlp();
	else quit();
}
int main(){
	welcm();
	main_menu();
	return 0;
}