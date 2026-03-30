#include <stdio.h>
#include  "game.h"

int h[DOT_ROWS][BOX_COLS]= {0};
int v[BOX_ROWS][DOT_COLS]= {0};
char boxes [BOX_ROWS] [ BOX_COLS];

int score_a =0;
int score_b = 0;

void init_boxes(void){
    int r, c;
    for (r=0; r<BOX_ROWS; r++){
        for (c = 0; c<BOX_COLS; c++){
            boxes[r][c] = ' ';
        }
    }
}



int is_validMove(int r1, int c1, int r2, int c2){
    if (r1<0 || r1 >=DOT_ROWS || r2<0 || r2>=DOT_ROWS || c1<0 || c1>=DOT_COLS || c2<0 || c2>=DOT_COLS){
        return 0;
    }
    
    int dr = r1-r2;
    if (dr<0) dr = -dr;

    int dc = c1-c2;
    if(dc<0) dc = -dc;

    if(dr + dc != 1){
        return 0;
    }
    if (r1==r2){
        int row = r1;
        int col = (c1<c2) ? c1 : c2;
        if (h[row][col] ==1){
            return 0;
        }
    }
    else {
        int row = (r1< r2) ? r1 : r2;
        int col = c1;
        if (v[row][col] == 1){
            return 0;
        }
    }
    return 1;
}


void save_move(int r1, int c1, int r2, int c2){
    if (r1 ==r2){
        int row =r1;
        int col = (c1<c2) ? c1:c2;
        h[row][col] = 1;
    } else {
        int row = (r1<r2)? r1 : r2;
        int col = c1;
        v [row][col] = 1;
    }
}


int box_completed (int r, int c){
    if (r<0 || r>=BOX_ROWS || c<0 || c>=BOX_COLS){
        return 0;
    }
return h[r][c] && h[r+1][c] && v[r][c] && v[r][c+1];
}


int update_boxes_score(int r1, int c1, int r2, int c2, char player){
    int completed = 0;

    if (r1==r2){
        int row = r1;
        int col = (c1<c2) ? c1:c2;

        if (row> 0 && boxes[row-1][col] == ' ' && box_completed(row-1, col)){
            boxes[row-1][col] = player;
            completed++;
        }
        if (row<BOX_ROWS && boxes[row][col] == ' ' && box_completed(row, col)){
            boxes[row][col] = player;
            completed++;
        }
    }
        else {
            int row = (r1<r2) ? r1: r2;
            int col = c1;

            if (col>0 && boxes[row][col-1] == ' ' && box_completed(row, col-1)) {
                boxes[row][col-1] = player;
                completed++;
            }
            if (col<BOX_COLS && boxes[row][col] == ' ' && box_completed(row, col)){
                boxes[row][col] = player;
                completed++;
            }
        }

        if (player == 'A'){
            score_a += completed;
        } else {
            score_b += completed;
        }

        return completed;
}


void print_board(void){
    int r,c;
    printf("\n    ");
    
    for (c=0; c< DOT_COLS; c++) {
        printf(" %d  ", c);
    }
    printf("\n");

    for (r=0; r <DOT_ROWS; r++) {
        printf(" %d  ", r);

        for (c=0; c< DOT_COLS; c++) {
            printf(".");
            if (c <BOX_COLS) {
                if (h[r][c]) {
                    printf("---");
                } else{
                    printf("   ");
                }
            }
        }
        printf("\n");

        if (r<BOX_ROWS) {
            printf("   ");
            for (c=0; c<DOT_COLS; c++) {
                if (v[r][c]) {
                    printf("|");
                } else {
                    printf(" ");
                }

                if (c<BOX_COLS) {
                    printf(" %c ", boxes[r][c]);
                }
            }
            printf("\n");
        }
    }

    printf("\nPlayer A score: %d\n", score_a);
    printf("Player B score: %d\n\n", score_b);
}

int total_claimedboxes(void){
    return score_a+score_b;
}

int game_over(void){
    return (score_a + score_b == BOX_ROWS * BOX_COLS);
}