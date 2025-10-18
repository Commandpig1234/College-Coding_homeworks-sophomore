#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r1, c1; 
    int r2, c2; 
    int r3, c3; 
    int top_row; 
    int top_col; 
} card;

int board[1025][1025];      
card cards[350000];
int temp_tile_id = 1;       

void layout_cards(int tr, int tc, int sr, int sc, int size)//top_row, top_colomn, special_row, special_colomn
{
    if (size == 1)
    {
        return;
    }
    int s = size / 2;
    int current_id = temp_tile_id++;
    if (sr < tr + s && sc < tc + s)//特殊点在左上角
    {
        cards[current_id] = (card){tr + s - 1, tc + s, tr + s, tc + s - 1, tr + s, tc + s};
        
        layout_cards(tr, tc, sr, sc, s);//左上
        layout_cards(tr, tc + s, tr + s - 1, tc + s, s);//右上
        layout_cards(tr + s, tc, tr + s, tc + s - 1, s);//左下
        layout_cards(tr + s, tc + s, tr + s, tc + s, s);//右下
    }
    //右上角
    else if (sr < tr + s && sc >= tc + s)
    {
        cards[current_id] = (card){tr + s - 1, tc + s - 1, tr + s, tc + s - 1, tr + s, tc + s};
        layout_cards(tr, tc, tr + s - 1, tc + s - 1, s);
        layout_cards(tr, tc + s, sr, sc, s);
        layout_cards(tr + s, tc, tr + s, tc + s - 1, s);
        layout_cards(tr + s, tc + s, tr + s, tc + s, s);
    }
    //左下角
    else if (sr >= tr + s && sc < tc + s)
    {
        cards[current_id] = (card){tr + s - 1, tc + s - 1, tr + s - 1, tc + s, tr + s, tc + s};
        layout_cards(tr, tc, tr + s - 1, tc + s - 1, s);
        layout_cards(tr, tc + s, tr + s - 1, tc + s, s);
        layout_cards(tr + s, tc, sr, sc, s);
        layout_cards(tr + s, tc + s, tr + s, tc + s, s);
    }
    //右下角
    else
    {
        cards[current_id] = (card){tr + s - 1, tc + s - 1, tr + s - 1, tc + s, tr + s, tc + s - 1};
        layout_cards(tr, tc, tr + s - 1, tc + s - 1, s);
        layout_cards(tr, tc + s, tr + s - 1, tc + s, s);
        layout_cards(tr + s, tc, tr + s, tc + s - 1, s);
        layout_cards(tr + s, tc + s, sr, sc, s);
    }
}


int compare_cards(const void *a, const void *b)//小于零：表示第一个元素小于第二个元素。等于零：表示两个元素相等。大于零：表示第一个元素大于第二个元素。
{
    card *tileA = (card *)a;
    card *tileB = (card *)b;
    
    if (tileA->top_row != tileB->top_row)
        return tileA->top_row - tileB->top_row;
    return tileA->top_col - tileB->top_col;
}

int min3(int a, int b, int c)
{
    int m = a;
    if (b < m)
        m = b;
    if (c < m)
        m = c;
    return m;
}

int main()
{

    // freopen("input/ZY17.txt","r",stdin);

    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    int size = 1 << n;
    int special_row = x - 1;
    int special_col = y - 1;

    layout_cards(0, 0, special_row, special_col, size);
    
    int card_num = (size * size - 1) / 3;

    for (int i = 1; i <= card_num; i++)//找最左上
    {
        cards[i].top_row = min3(cards[i].r1, cards[i].r2, cards[i].r3);
        
        int min_col = 1025;
        if (cards[i].r1 == cards[i].top_row) min_col = cards[i].c1;
        if (cards[i].r2 == cards[i].top_row && cards[i].c2 < min_col) min_col = cards[i].c2;
        if (cards[i].r3 == cards[i].top_row && cards[i].c3 < min_col) min_col = cards[i].c3;
        cards[i].top_col = min_col;
    }

    qsort(cards + 1, card_num, sizeof(card), compare_cards);//重排名

    board[special_row][special_col] = 0;
    for (int i = 1; i <= card_num; i++)//重命名
    {
        board[cards[i].r1][cards[i].c1] = i;
        board[cards[i].r2][cards[i].c2] = i;
        board[cards[i].r3][cards[i].c3] = i;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
            if(j==size-1)
                printf("\n");
        }
    }

    // freopen("CON","r",stdin);
    // system("pause");
    
}
