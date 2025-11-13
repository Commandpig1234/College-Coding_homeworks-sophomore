#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node{
    char id;
    vector<Node*> children;
    map<char, Node*> child_map;
    int height;
    bool is_winning;

    Node(char _id) : id(_id), height(-1), is_winning(false) {}

    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }
};

Node* parse_tree(const string& s, int& index) {
    while (index < s.length() && (s[index] == ' ' || s[index] == ',' || s[index] == '(')) {
        index++;
    }
    if (index >= s.length()) return nullptr;

    char id = s[index++];
    Node* node = new Node(id);

    while (index < s.length() && s[index] != ')') {
        Node* child = parse_tree(s, index);
        if (child) {
            node->children.push_back(child);
            node->child_map[child->id] = child;
        }
        else {
             break;
        }
    }
    if (index < s.length() && s[index] == ')') {
        index++;
    }

    return node;
}

void calculate_properties(Node* node) {
    if (!node) return;

    if (node->children.empty()) {
        node->height = 0;
        node->is_winning = false; 
        return;
    }

    int max_child_height = -1;
    bool found_losing_child_for_opponent = false;

    for (Node* child : node->children) {
        calculate_properties(child);
        if (child->height > max_child_height) {
            max_child_height = child->height;
        }
        if (!child->is_winning) {
            found_losing_child_for_opponent = true;
        }
    }

    node->height = 1 + max_child_height;
    node->is_winning = found_losing_child_for_opponent;
}

Node* computer_move(Node* current_node) {
    vector<Node*> winning_moves; 
    vector<Node*> losing_moves;  

    for (Node* child : current_node->children) {
        if (!child->is_winning) {
            winning_moves.push_back(child);
        }
        else {
            losing_moves.push_back(child);
        }
    }

    if (!winning_moves.empty()) {
        Node* best_move = winning_moves[0];
        for (size_t i = 1; i < winning_moves.size(); ++i) {
            if (winning_moves[i]->height < best_move->height) {
                best_move = winning_moves[i];
            }
        }
        return best_move;
    }
    else {
        Node* best_move = losing_moves[0];
        for (size_t i = 1; i < losing_moves.size(); ++i) {
            if (losing_moves[i]->height > best_move->height) {
                best_move = losing_moves[i];
            }
        }
        return best_move;
    }
}

void print_preorder(Node* node) {
    if (!node) return;
    cout << node->id << endl;
    for (Node* child : node->children) {
        print_preorder(child);
    }
}

void solve(){
    string tree_string_line;
    getline(cin, tree_string_line);

    int index = 0;
    Node* root = parse_tree(tree_string_line, index);

    calculate_properties(root);
    
    print_preorder(root);

    char continue_choice = 'y';
    do {
        Node* current_node = root;
        bool is_player_turn = false;
        int first_player;

        cout << "Who play first(0: computer; 1: player )?" << endl;
        cin >> first_player;
        is_player_turn = (first_player == 1);

        bool game_over = false;
        while (!game_over) {
            if (current_node->children.empty()) {
                if (is_player_turn) {
                    cout << "Sorry, you lost." << endl;
                }
                else{
                    cout << "Congratulate, you win." << endl;
                }
                game_over = true;
                continue;
            }

            if (is_player_turn) {
                cout << "player:" << endl;
                char move_id;
                cin >> move_id;

                if (current_node->child_map.count(move_id)) {
                    current_node = current_node->child_map[move_id];
                    is_player_turn = !is_player_turn;
                }
                else {
                    cout << "illegal move." << endl;
                }
            }
            else{
                cout << "computer: ";
                Node* next_move = computer_move(current_node);
                cout << next_move->id << endl;
                current_node = next_move;
                is_player_turn = !is_player_turn;
            }
        }

        cout << "Continue(y/n)?" << endl;
        cin >> continue_choice;

    } while (continue_choice == 'y');

    delete root;
}

int main() {
    // freopen("input/3.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
    return 0;
}

