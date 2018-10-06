#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "UI.h"
typedef struct{
	int color,num;
} card;
void swap(card *x,card *y){
	card t; t=*x; *x=*y; *y=t; return ;
}
void print(card x) {
	if(x.color == 0) printf("Heart ");
	else if(x.color == 1) printf("Spade ");
	else if(x.color == 2) printf("Diamond ");
	else if(x.color == 3) printf("Club ");
	if(2 <= x.num && x.num <= 10) printf("%d\n",x.num);
	else if(x.num == 1) printf("A\n");
	else if(x.num == 11) printf("J\n");
	else if(x.num == 12) printf("Q\n");
	else if(x.num == 13) printf("K\n");
}
card gen_card(int x){ //x 0..51
	card res; 
	res.color = (x/13)%4;
	res.num = x%13+1;
	return res;
}
int ctot,ctot0;
card heap[210]; 
void heap_init(int sum) {
	ctot0 = ctot = sum;
	for(int i=0;i<sum;i++) heap[i] = gen_card(i);
	srand(time(0));
	for(int i=1;i<=sum;i++) {
		int x=rand()%sum, y=rand()%sum;
		swap(&heap[x],&heap[y]);
	}
	heap[sum] = heap[0];
	return ;
}
typedef struct {
	card a[15];
	int ACE;
	int tot;
	int sum;
} hand;
void hprint(hand x){
	for(int i=1;i<=x.tot;i++) print(x.a[i]);
}
int min(int x,int y){
	if(x<y) return x; 
	else return y;
}
void add(hand *x,card y){
	x -> a[++ x->tot] = y;
	if(y.num == 1) {
		x -> ACE++;
		x -> sum += 11;
	} else {
		x -> sum += min(y.num,10);
	} return ;
}

int AI_judge(hand x){
	if(x.sum-x.ACE*10<17) return 1;
	else return 0;
}
int isbust(hand x){
	return x.sum-x.ACE*10>21;
}
int bst(hand x){
	int res = x.sum, t = x.ACE;
	while(res>21 && t){
		res-=10; t--;
	}
	return res;
}
//结算
void jie_suan(hand x,hand y){
	printf("==============Computer=============\n");
	hprint(x);
	printf("sum %d\n",bst(x));
	printf("==============Player===============\n");
	hprint(y);
	printf("sum %d\n",bst(y));
	return ;
}
void main_menu();
int sin_game(){
	printf("=========Winner winner, chicken dinner!=========\n");
	if(ctot*2<ctot0) {
		printf("reshuffle !\n");
		heap_init(52);
	}
	hand player,AI;
	player.tot=player.sum=player.ACE=0;
	AI.tot=AI.sum=AI.ACE=0;
	printf("******************Round 1******************\n");
	card x = heap[ctot--]; 
	add(&AI,x); 
	printf("Computer get a "); 
	print(x);
	x = heap[ctot--];
	add(&player,x);
	printf("You get a ");
	print(x); 
	ctn_ui();
	int flag1=0,flag2=0;
	for(int i=2;;i++) {
		printf("******************Round %d******************\n",i);
		int t = AI_judge(AI);
		if(t){
			printf("Computer : HIT!\n");
			x = heap[ctot--]; 
			add(&AI,x);
		} else {
			printf("Computer : STAND!\n");
			flag1=1;
		}
		if(isbust(AI)){
			printf("Computer BUST!\n");
			jie_suan(AI,player);
			printf("==============YOU WIN==============\n");
			ctn_ui();
			break;
		}
		if(flag1&&flag2){
			int x = bst(AI), y = bst(player);
			jie_suan(AI,player);
			if(x>y) 	 printf("==============YOU LOSE=============\n");
			else if(x<y) printf("==============YOU WIN==============\n");
			else 		 printf("================PUSH===============\n");
			ctn_ui();
			break;
		}
		
		t = turn_ui();
		while(t!=1&&t!=2){
			if(t==3){
				hprint(player);
				ctn_ui();
			}
			t = turn_ui();
		}
		if(t==1) {
			printf("Player : HIT!\n");
			x = heap[ctot--];
			add(&player,x); 
			printf("You get a ");
			print(x); 
			ctn_ui();
		} else if(t==2){
			printf("Player : STAND!\n");
			flag2=1;
		} 
		if(isbust(player)){
			printf("You BUST!\n");
			jie_suan(AI,player);
			printf("==============YOU LOSE=============\n");
			ctn_ui();
			break;
		}
		if(flag1&&flag2){
			int x = bst(AI), y = bst(player);
			jie_suan(AI,player);
			if(x>y) 	 printf("==============YOU LOSE=============\n");
			else if(x<y) printf("==============YOU WIN==============\n");
			else 		 printf("================PUSH===============\n");
			ctn_ui();
			break;
		}
	}
	int t = again_ui();
	while(t==-1) t = again_ui(); 
	return t;
}
void sin_mode(){
	heap_init(52);
	int x=sin_game();
	while(x) x=sin_game();
	main_menu();
}
void ntwk(){
	ntwk_ui();
	main_menu();
	return ;
}
void quit(){
	int x = quit_ui();
	while(x==-1) x = quit_ui(); 
	if(x) printf("Bye!\n");
	else main_menu(); 
	return ;
}
void hlp(){
	hlp_ui();
	main_menu();
}
void main_menu(){
	int x = main_menu_ui();
	while(x<1||x>4) x = main_menu_ui();
	if(x==1) sin_mode();
	else if(x==2) ntwk();
	else if(x==3) hlp();
	else quit();
}

int main(){
	welcm();
	main_menu();
	return 0;
}