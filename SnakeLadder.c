#include <stdio.h>
#include <stdbool.h> 
int columnIndex,rowIndex,rest;
int playerOneColumn=0;
int playerOneRow=0;
int playerTwoColumn=0;
int playerTwoRow=0;
int playerOneRolls=0;
int playerTwoRolls=0;
char *previousOne,*previousTwo;
bool won=false; 
char *board[10][10]={
    {"≫","·","·","·","·","·","·","·","·","·"},
    {"·","·","·", "·","·","·","·","·","·","·"},
    {"·","·","·","ǁ","·","·","·","·","·","·"},
    {"·","·","·","ǁ","·","·","·","·","·","·"},
    {"·","·","·","ǁ","·","·","·","·","·","§"},
    {"·","·","·","ǁ","·","·","·","·","§","·"},
    {"·","·","·","ǁ","·","·","·","§","·","·"},
    {"·","·","·","ǁ","·","·","§","·","·","·"},
    {"·","·","·","·","·","§","·","·","·","·"},
    {"·","·","·","·","·","·","·","·","·","≫"}
    
};

int rollDice(){
    srand(time(0)); //seed to generate a different random number 
    int dice=(rand()%6)+1;
    return dice;
}

void printBoard(){
    printf("\n");
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%s",board[i][j]);
        }
        printf("\n");
    }
}

bool game(){
    printf( "Enter player number to roll dice :");
    int player; 
    scanf("%d", &player);
    int dice=rollDice();
    printf( "\nPlayer %d ", player);
    printf(" rolled a %d \n", dice);
    if(player == 1){
        columnIndex=playerOneColumn;
        rowIndex=playerOneRow;
        }
    else{
        columnIndex=playerTwoColumn;
        rowIndex=playerTwoRow;
        }
    if((columnIndex+dice)>9){
        rowIndex+=1;
        rest=(playerOneColumn+dice)-10;
        columnIndex=rest;
        if(rowIndex>9 || (rowIndex==9 && columnIndex==9)){
            printf( "\nPlayer %d won!",player);
            return won=true;
            }
        }
    else{
        columnIndex+=dice;
        }
    if(rowIndex==2 && columnIndex==3){
        rowIndex=7;
        columnIndex=3;
        printf( "\nPlayer %d climbed the ladder",player);
        }
    else if(rowIndex==8 && columnIndex==5){
        rowIndex=4;
        columnIndex=9;
        printf( "\nPlayer %d went down the snake",player);
        }
    if(player == 1){
        if(playerOneRolls>0){
            board[playerOneRow][playerOneColumn]=previousOne; 
        }
        previousOne=board[rowIndex][columnIndex];
        board[rowIndex][columnIndex]="█";
        playerOneColumn=columnIndex;
        playerOneRow=rowIndex;
        playerOneRolls+=1;
        }
    else{
        if(playerTwoRolls>0){
            board[playerTwoRow][playerTwoColumn]=previousTwo;
        }
        previousTwo=board[rowIndex][columnIndex];
        board[rowIndex][columnIndex]="░";
        playerTwoColumn=columnIndex;
        playerTwoRow=rowIndex;
        playerTwoRolls+=1;
        }
    if(dice==6){
        printf( "\n Player %d rolled a 6 and can play again",player);
    }
}

void main(){
    printBoard();
    while(won==false){
        game();
        printBoard();
        printf( "Player 1 rolled %d time(s)",playerOneRolls);
        printf( " and Player 2 rolled %d time(s) \n",playerTwoRolls);
    }
}