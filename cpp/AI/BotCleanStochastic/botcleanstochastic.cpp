#include<iostream>
#include<vector>
#include <tuple>
#include <cmath>

using namespace std;

#define N 5
#define DIRT 'd'

/*
    LEFT -> 0, -1
    RIGHT -> 0, 1
    UP -> -1, 0
    DOWN -> 1, 0
*/

typedef tuple<int, int> Position;


void next_move(int posr, int posc, vector <string> board) {
    
    if(board[posr][posc] == DIRT){
        cout << "CLEAN" << endl;
        return;
    }
    
    Position dirt;
    for(int row=0; row < N; row++){
        for(int col=0; col < N; col++){
            if(board[row][col] == DIRT){
                dirt = {row, col};
            }
        }
    }
    
    int drow = get<0>(dirt) - posr;
    int dcol = get<1>(dirt) - posc;
    
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
