#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void startGame(void);       //
void easyLevel(void);       //    
void mediumLevel(void);     //  All  
void hardLevel(void);       //  function 
void showRule(void);        //  prototypes 
void winFunction(void);     //
void loseFunction(void);    //

int main(int argc, char *argv[]) {
	
	char name[20];      //for name of the player and menu option
	int option, game_run = 0;
	
	system("color 1f");
	
	printf("Enter Your Name: ");                                     
	scanf("%[ a-zA-z]", &name);                                          
	printf("\n\n\t-----------------------------------\n\n");     //  greet the player with 
	printf("\t  Hi %s! Get ready for the fun!", name);            //   a line above and  
	printf("\n\n\t-----------------------------------\n\n");     //    below the text  
	
	/*  menu loop of the game starts here  */
	
	do {
		printf("\n\nPlease choose an option from the below menu:");
		
		/* game options */
		
		printf("\n\n1: Start the game");
		printf("\n2: What's my name?");
		printf("\n3: Sing a song");
		printf("\n4: Exit\n\n");
		
		scanf("%d", &option);
		
		/* check of input is not from the options above */
		
		switch(option) {
		   case 1: startGame();        //if option is correct start the game
		           game_run = 0;
				   break;
		   case 2: printf("\n\nYour name is %s\n\n", name);
		           game_run = 0; 
		           break;
		   case 3: printf("\n\nSorry %s I cannot sing a song\n\n", name);
		           game_run = 0;
				   break;
		   case 4: printf("\n\n\tGoodbye!\n");
		           exit(0);
		           game_run = 0; 
				   break;
				   
		   default: printf("\n\nPlease select the right option\n\n");
		            game_run = 1; 
		            break;      
		}
		
	} while(game_run != 0);
	
	getch();
	return 0;
}

void startGame(void) {
	
	system("cls");   //clear the screen
	printf("\n\n\t----------------------------");
	printf("\n\t\tGame Started");     //game start message
    printf("\n\t----------------------------\n\n");
    
    int level_op, start = 0;
    
    printf("\n\nPlease choose the level of game\n\n");
    
   do {
       /* menu for choosing the level of game */
       printf("1: Easy\n");
	   printf("2: Medium\n");
	   printf("3: Hard\n");
	   printf("4: See Game Rule\n");
	   printf("5: Leave\n\n");
	
	   scanf("%d", &level_op);	  
	   
   	   switch(level_op) {
		 	case 1: easyLevel();
		 	         start = 0; 
					 break;
	        case 2: mediumLevel();																							
		 	         start = 0; 
					 break;
		    case 3: hardLevel();
		 	         start = 0;
					 break;
		    case 4: showRule();
		            start = 0;
					break;
		    case 5: printf("\n\n\tGoodbye!\n");
			        exit(0);
		 	        break;
		    default: start = 1;
		             break;
	   }
   } while( start != 0);
}

/* code for easy level starts here */

void easyLevel(void) {
	
	int guess, rand_num;
	
	system("cls");       //clear the screen
	
	printf("\n\nInside easy game level\n\n");
	printf("Hi I have chosen a number that lies between 1-10\n");
	printf("Guess this number, you have 4 chances only\n");
	
	srand(time(NULL));                  
	rand_num = (rand() % 10)+1;  //code for generating random number
	
	printf("\n\nEnter your guess below: \n\n");
	
	int counter = 0;
	
	do {
		
		scanf("%d", &guess);
		
		if(guess == rand_num) {
			winFunction();                          //if guess equals rand_num show win message  
			break;
		}
		
		else if(guess < rand_num && counter != 3) {      //      checks if  
			printf("\nYour guess is smaller\n");         //      guess number is
			printf("\nTry another number: \n\n");        //      smaller than 
		}                                                //      random number
		
		else if(guess > rand_num && counter != 3) {      //      checks if 
			printf("\nYour guess is bigger\n");          //      guess number is 
			printf("\nTry another number: \n\n");        //      bigger than 
		}                                                //      random number
		
		else if(guess != rand_num && counter == 3) {
			loseFunction();                               //if guess not equal to rand_num show lose message   
		}
		
		counter++;
		
	} while(counter < 4);
}

/* code for medium level starts here */

void mediumLevel(void) {
	
	int guess, rand_num;
	
	system("cls");       //clear the screen
	
	printf("\n\nInside medium game level\n\n");
	printf("Hi I have chosen a number that lies between 1-20\n");
	printf("Guess this number, you have 5 chances only\n");
	
	srand(time(NULL));                  
	rand_num = (rand() % 20)+1;  //code for generating random number
	
	printf("\n\nEnter your guess below: \n\n");
	
	int counter = 0;
	
	do {
		
		scanf("%d", &guess);
		
		if(guess == rand_num) {
			winFunction();                          //if guess equals rand_num show win message  
			break;
		}
		
		else if(guess < rand_num && counter != 4) {      //      checks if  
			printf("\nYour guess is smaller\n");         //      guess number is
			printf("\nTry another number: \n\n");        //      smaller than 
		}                                                //      random number
		
		else if(guess > rand_num && counter != 4) {      //      checks if 
			printf("\nYour guess is bigger\n");          //      guess number is 
			printf("\nTry another number: \n\n");        //      bigger than 
		}                                                //      random number
		
		else if(guess != rand_num && counter == 4) {
			loseFunction();                               //if guess not equal to rand_num show lose message   
		}
		
		counter++;
		
	} while(counter < 5);
}

/* code for hard level starts here */

void hardLevel(void) {
	
	int guess, rand_num;
	
	system("cls");       //clear the screen
	printf("\n\nInside hard game level\n\n");
	printf("Hi I have chosen a number that lies between 1-30\n");
	printf("Guess this number, you have 6 chances only\n");
	
	srand(time(NULL));                  
	rand_num = (rand() % 30)+1;  //code for generating random number
	
	printf("\n\nEnter your guess below: \n\n");
	
	int counter = 0;
	
	do {
		
		scanf("%d", &guess);
		
		if(guess == rand_num) {
			winFunction();                          //if guess equals rand_num show win message  
			break;
		}
		
		else if(guess < rand_num && counter != 5) {      //      checks if  
			printf("\nYour guess is smaller\n");         //      guess number is
			printf("\nTry another number: \n\n");        //      smaller than 
		}                                                //      random number
		
		else if(guess > rand_num && counter != 5) {      //      checks if 
			printf("\nYour guess is bigger\n");          //      guess number is 
			printf("\nTry another number: \n\n");        //      bigger than 
		}                                                //      random number
		
		else if(guess != rand_num && counter == 5) {
			loseFunction();                               //if guess not equal to rand_num show lose message   
		}
		
		counter++;
		
	} while(counter < 6);
}

/* function for game tutorial */

void showRule(void) {
	system("cls");
	printf("\nWelcome to Guess The Number game tutorial!\n\n");
	printf("\nThe rule is simple what you need to do is guess");
	printf("\na number based on the level you choose. After choosing");
	printf("\nthe number you get 4, 5, or 6 chances, depending on");
	printf("\nthe level you've chosen, to guess what the");
	printf("\nnumber could be. If you guess the right number within");
	printf("\nthe stipulated chances you win or else loose the game."); 
	printf("\n the computer will also tell you if the number you guess");
	printf("\nis smaller or bigger, this is to help you get an idea of");
	printf("\nof the number and you will guess accordingly.");
	printf("\n\nLet's understand the rule by an example. Suppose you ");
	printf("\nchoose Easy level then computer will choose a number ");
	printf("\nin between 1-10 you will have to guess the number that ");
	printf("\ncomputer have chosen. Meanwhile the computer will tell");
	printf("\nwhether the number is smaller or bigger. You get some");
	printf("\nchances to guess the right number, you win when");
	printf("\nyou guess the number correctly.");
}

/* functions for showing winning and losing messages */ 

void winFunction(void) {
	printf("\n\n\tHurray! You won the game!");
}

void loseFunction(void) {
	printf("\n\n\tSorry! You lose the game!");
}
