#include <stdio.h>
#include "game.h"

int main(void){
    char current_player = 'A';
    int r1, c1, r2, c2;

    init_boxes();

    while (!game_over()){
        int completed;
        
        print_board();
        printf("Claimed boxes: %d / %d\n\n", total_claimedboxes(), BOX_ROWS*BOX_COLS);

        printf("Player %c's turn. Enter the row and column of the first dot and second dot: ", current_player);

        if (scanf("%d %d %d %d", &r1, &c1, &r2, &c2) != 4) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }
        if (!is_validMove(r1,c1,r2,c2)){
            printf("Invalid move! Try again.\n");
            continue;
        }

        save_move(r1, c1, r2, c2);
        completed = update_boxes_score(r1, c1, r2, c2, current_player);

        if (completed ==0){
            if (current_player =='A'){
            current_player = 'B';
        }
        else {
            current_player = 'A';
        }
    }
    else { 
        printf("Nice! Player %c completed %d box(es) and gets another turn!\n", current_player, completed);
    }
}
print_board();
printf("Claimed boxes: %d / %d\n\n", total_claimedboxes(), BOX_ROWS*BOX_COLS);
printf("**************************************************\n");

if (score_a> score_b){
    printf("Player A wins!\n");
}
else if (score_b>score_a){
    printf("Player B wins!\n");
}
else {
    printf("It's a draw!\n");
}
return 0;
}