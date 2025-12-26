#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define RESET "\x1b[0m"
#define Tb 4


//my functions
void generate_level();
void check_win();
void user_input();
char get_first_color();
void print_tubes();
int get_free_position();

//my variables
int moves = 0;
int Tb_num = 0;
int color_num = 0;
bool running = true;
int last_move[1];
int stored_moves[50][50];

/*
//old Testing array XD 
char tubes[Tb][Tb] = {{'0','0','r','g'},
					{'0','0','g','r'},
					{'0','0','0','0'},
					{'0','0','0','0'}};
*/
char tubes[7][Tb];
		
int main(){
	
	//game logics by Yas
	generate_level();
	print_tubes(tubes);
	
	while(running){
		user_input(tubes);
		moves++;
		print_tubes(tubes);
		check_win(tubes);
	}
	return 0;
}


void print_tubes(char tubes[Tb][Tb]){
	system("clear");
	printf("===[WELCOME TO COLORS SORTING GAME]===\n\n");
	
	for(int j = 0; j<Tb; j++){
		for(int i = 0; i<Tb_num; i++){
			switch(tubes[i][j]){
				case 'r':
					printf("|" RED "\u2588\u2588\u2588" RESET "|  ");
					break;
				case 'b':
					printf("|" BLUE "\u2588\u2588\u2588" RESET "|  ");
					break;
				case 'g':
					printf("|" GREEN "\u2588\u2588\u2588" RESET "|  ");
					break;
				case 'y':
					printf("|" YELLOW "\u2588\u2588\u2588" RESET "|  ");
					break;
				case 'm':
					printf("|" MAGENTA "\u2588\u2588\u2588" RESET "|  ");
					break;
				case '0':
					printf("|   |  ");
					break;
				default:
					printf("|   |  ");
					break;
			}
			
		}
		printf("\n");
	}
	 //close tubes

	 for(int i = 0; i<Tb_num; i++){
		 printf("|___|  ");
	 }
	 
	 //print tubes number
	 printf("\n  ");
	 for(int i = 0; i<Tb_num; i++){
		 printf("%d      ", i+1);
	 }
	 printf("\n");
	
}

void check_win(char tubes[Tb][Tb]){
	//char tube[4];
	
	int count = 0;
	for(int i =0; i<Tb_num ; i++){
		if(tubes[i][3]==tubes[i][2] && tubes[i][2]==tubes[i][1] && tubes[i][1] == tubes[i][0] && (tubes[i][2] != '0')){
			count ++;
		}
		if(count == color_num){
			printf("\n  YOU WIN -- %d Colors are sorted will !  ", color_num);
			printf("\n      You completed in %d moves", moves);
			running = false;
			break;
		}
	}
}

void user_input(char tubes[Tb][Tb]){
	int tube_in = 0;
	int tube_out = 0;
	printf("\n");
	do{
		printf("enter tube you want to get the color from : \n");
		scanf("%d", &tube_out);
	}while(tube_out <= 0);
	do{
		printf("enter tube you want to put the color in : \n");
		scanf("%d", &tube_in);
	}while(tube_in <= 0);
	
	
	tube_in -= 1, tube_out -= 1;
	
	for(int i= 0; i<Tb ; i++){
	    if(get_first_color(tubes[tube_in])=='0' && get_first_color(tubes[tube_out])!= '0'){
	        tubes[tube_in][Tb-1] = get_first_color(tubes[tube_out]);
	        tubes[tube_out][get_free_position(tubes[tube_out])+1] = '0';
	    } if(get_first_color(tubes[tube_in])==get_first_color(tubes[tube_out]) && get_free_position(tubes[tube_in])!=-1){
	        tubes[tube_in][get_free_position(tubes[tube_in])] = get_first_color(tubes[tube_out]);
		    tubes[tube_out][get_free_position(tubes[tube_out])+1] = '0';
	    }else{
	        break;
	    }
	}
}

char get_first_color(char t[Tb]){
	
	for(int i = 0; i<Tb; i++){
		if(t[i]!= '0'){
			return t[i];
			//break;
		}	
	}
	
	return '0';
}

int get_free_position(char t[Tb]){
	
	for(int i=0; i<Tb; i++){
		if(t[i]!= '0'){
			return i-1;
			//break;
		}
	}
	return -1;
}

//I will create level generator and more tubes possibility inshallah
//now , with v3 we have level generator الحمد لله

void generate_level(){
	
	srand(time(NULL));
	
	color_num = 2 + rand() % 4;
	if(color_num == 2){
		Tb_num = color_num + 1;
	}else{
		Tb_num = color_num + 2;
	}
	int swap = 0;
	
	//creating the tubes with colors
	for(int i=0; i<Tb_num; i++){
		for(int j=0; j<Tb; j++){
			tubes[i][j] = '0';
		}
	}
	
	for(int i=0; i<color_num; i++){
		for(int j=0; j<Tb; j++){
			switch (i){
				case 0:
					tubes[i][j] = 'r';
					break;
				case 1:
					tubes[i][j] = 'g';
					break;
				case 2:
					tubes[i][j] = 'y';
					break;
				case 3:
					tubes[i][j] = 'b';
					break;
				case 4:
					tubes[i][j] = 'm';
					break;
				default:
					printf("\n ERROR IN TUBES CREATING !!!");
					break;
			}
		}
	}
	//random the values (my own method )
	
	for(int i=0; i<Tb; i++){
		for(int j=0; j<Tb_num; j++){
			char tmp = '\0';
			swap = rand() % 2;
			//printf("%d", swap);
			if(i>0 && swap == 1 && tubes[i][j]!= '0'){
				tmp = tubes[i][j];
				tubes[i][j] = tubes[i-1][j];
				tubes[i-1][j]=tmp;
			}
		}
	}

}

//next features : undo choice - hints system •_•