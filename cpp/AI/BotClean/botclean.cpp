#include<iostream>
#include<vector>
#include <tuple>
#include <cmath>

using namespace std;

#define N 5
// #define MAX 4
// #define MIN 0
#define DIRT 'd'

/*
    LEFT -> 0, -1
    RIGHT -> 0, 1
    UP -> -1, 0
    DOWN -> 1, 0
*/

typedef tuple<int, int> Position;
typedef vector<Position> Dirt;


void next_move(int posr, int posc, vector <string> board) {
    /* Naive Approach
    if(posr%2==0){
        if(board[posr][posc] == 'd') cout << "CLEAN" << endl;
        else if(posc == MAX) cout << "DOWN" << endl;
        else cout << "RIGHT" << endl;
    }
    else{
        if(board[posr][posc] == 'd') cout << "CLEAN" << endl;
        else if(posc == MIN) cout << "DOWN" << endl;
        else cout << "LEFT" << endl;
    }
    */
    
    if(board[posr][posc] == DIRT){
        cout << "CLEAN" << endl;
        return;
    }
    
    Dirt dirt;
    for(int row=0; row < N; row++){
        for(int col=0; col < N; col++){
            if(board[row][col] == DIRT){
                dirt.push_back({row, col});
            }
        }
    }
    
    Position closest_dirt;
    float shortest_distance = 999999;
    for(auto d : dirt){
        float drow = get<0>(d) - posr;
        float dcol = get<1>(d) - posc;
        float distance = hypot(drow, dcol);
        if(distance < shortest_distance){
            shortest_distance = distance;
            closest_dirt = d;
        }
    }
    
    int drow = get<0>(closest_dirt) - posr;
    int dcol = get<1>(closest_dirt) - posc;
    
    if(dcol <= -1) cout << "LEFT" << endl;
    else if(dcol >= 1) cout << "RIGHT" << endl;
    else if(drow <= -1) cout<< "UP" << endl;
    else if(drow >= 1) cout<< "DOWN" << endl;
    
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
