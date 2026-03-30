#ifndef GAME_H
#define GAME_H
#define BOX_ROWS 4
#define BOX_COLS 5
#define DOT_ROWS (BOX_ROWS + 1)
#define DOT_COLS (BOX_COLS + 1)

void init_boxes(void);
int is_validMove(int r1, int c1, int r2, int c2);
void save_move(int r1, int c1, int r2, int c2);
int box_completed(int r, int c);
int update_boxes_score(int r1, int c1, int r2, int c2, char player);
void print_board(void);
int game_over(void);

extern int score_a;
extern int score_b;
int total_claimedboxes(void);
#endif