#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printBoard(int board[5][5]);
int idxArr[25] = {0, };

void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void setup(int board[5][5]){
	srand(time(NULL));
	int random = 0;
	int nums[25] = {0, };
	for(int i = 1; i < 26; i++){ nums[i-1] = i; }
	
	for(int i = 24; i > -1; i--){
		random = rand() % (i+1) ;
		board[i/5][i%5] = nums[random];
		idxArr[nums[random]-1] = i;
		swap(&nums[random], &nums[i]);
	}
}



int isEnd(int board[5][5]){
	int result = 0;
	for(int i = 0; i < 5; i++){
		int row = 0;
		int col = 0;
		for(int j = 0; j < 5; j++){
			if((board[i][j]) > 0) row++;
			if((board[j][i]) > 0) col++;
		}
		
		if(row >= 5) result++;
		if(col >= 5) result++; 
		
	}
	int l = 0, r= 0;
	for(int i = 0; i < 5; i++){
		if(board[i][i] > 0) l++;
		if(board[i][4-i] > 0) r++; 
	}
	
	if(l >= 5) result++;
	if(r >= 5) result++; 
	printf("result = %d\n", result);
    return result < 3 ? 1 : 0;
}
void printBoard(int board[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int board[5][5];
    setup(board);
    
    int bingoBoard[5][5] = {0, };
    printBoard(board);
	int bingo = 0;

    int inp = 0;
    do{
        printf("칠할 블럭을 1~25사이에 입력해 주세용 (-1 입력시 탈출): ");
        scanf("%d", &inp);
        if(inp < 1 || inp > 25){
            printf("아니 1~25 사이를 입력하라니까\n");
            continue;
        }else if(bingoBoard[idxArr[inp-1] / 5][idxArr[inp-1] % 5]) printf("이미 선택한 번호 입니둥");
		inp--;
        bingoBoard[idxArr[inp] / 5][idxArr[inp] % 5] = 1;
        printBoard(bingoBoard);
    }while(isEnd(bingoBoard) && inp != -1);
    if(inp == -1) return 0;
	printf("축하합니다 당신이 했던 보드판은 \n");
	printBoard(board);
	
    return 0;
}

