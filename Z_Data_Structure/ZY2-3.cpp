#include <bits/stdc++.h>

typedef struct Node {
    int id;
    struct Node *next;
    struct Node *prev;
} Node;

Node *init_list(int n){
    Node *head = (Node*)malloc(sizeof(Node));
    head->id = 1;
    Node *p = head;
    for (int i = 2; i <= n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->id = i;
        p->next = newNode;
        newNode->prev = p;
        p = newNode;
    }
    p->next = head;
    head->prev = p;
    return head;
}

int main() {
    // freopen("input/ZY2-3.txt","r",stdin);

    int n, k, m;
    scanf("%d,%d,%d", &n, &k, &m);

    if (n <= 0 || k <= 0 || m <= 0) {
        printf("n,m,k must bigger than 0.\n");
        return 0;
    }
    if (k > n) {
        printf("k should not bigger than n.\n");
        return 0;
    }
    if (n == 1) {
        printf("1\n");
        return 0;
    }

    Node *head = init_list(n);
    Node *p_clockwise = head;
    Node *p_counter_clockwise = head;
    while (p_clockwise->id != k) {
        p_clockwise = p_clockwise->next;
    }
    p_counter_clockwise = p_clockwise;

    int current_n = n;
    bool is_first_output = true;
    while (current_n > 1) {
        for (int i = 0; i < m - 1; i++) {
            p_clockwise = p_clockwise->next;
            p_counter_clockwise = p_counter_clockwise->prev;
        }

        int id1 = p_clockwise->id;
        int id2 = p_counter_clockwise->id;

        if (!is_first_output) {
            printf(",");
        }
        is_first_output = false;
        
        if (id1 == id2) {
            printf("%d", id1);
            
            Node *next_start_c = p_clockwise->next;
            Node *next_start_counter = p_counter_clockwise->prev;

            p_clockwise->prev->next = p_clockwise->next;
            p_clockwise->next->prev = p_clockwise->prev;
            free(p_clockwise);
            
            p_clockwise = next_start_c;
            p_counter_clockwise = next_start_counter;
            current_n--;

        }
        else {
            printf("%d-%d", id1, id2);

            Node *next_start_c = p_clockwise->next;
            Node *next_start_counter = p_counter_clockwise->prev;

            if (next_start_c == p_counter_clockwise) {
                p_clockwise->prev->next = p_counter_clockwise;
                p_counter_clockwise->prev = p_clockwise->prev;
                free(p_clockwise);
                current_n--;
                Node *tmp = p_counter_clockwise->next;
                p_counter_clockwise->prev->next = tmp;
                tmp->prev = p_counter_clockwise->prev;
                free(p_counter_clockwise);
                current_n--;
                p_clockwise = tmp;
                p_counter_clockwise = next_start_counter;
            }
            else if (next_start_counter == p_clockwise) {
                p_counter_clockwise->prev->next = p_clockwise;
                p_clockwise->prev = p_counter_clockwise->prev;
                free(p_counter_clockwise);
                current_n--;
                Node *tmp = p_clockwise->next;
                p_clockwise->prev->next = tmp;
                tmp->prev = p_clockwise->prev;
                free(p_clockwise);
                current_n--;
                p_clockwise = tmp;
                p_counter_clockwise = next_start_counter;
            }
            else {
                p_clockwise->prev->next = p_clockwise->next;
                p_clockwise->next->prev = p_clockwise->prev;
                free(p_clockwise);
                current_n--;

                p_counter_clockwise->prev->next = p_counter_clockwise->next;
                p_counter_clockwise->next->prev = p_counter_clockwise->prev;
                free(p_counter_clockwise);
                current_n--;

                p_clockwise = next_start_c;
                p_counter_clockwise = next_start_counter;
            }
        }
        if (current_n <= 1) break;
    }

    if (current_n == 1) {
        if (!is_first_output) {
            printf(",");
        }
        printf("%d", p_clockwise->id);
        free(p_clockwise);
    }
    printf(",\n");

    // freopen("CON","r",stdin);
    // system("pause");
    
    return 0;
}