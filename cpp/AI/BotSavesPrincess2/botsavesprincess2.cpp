#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;


typedef tuple<int, int> Position;


void nextMove(int n, int r, int c, vector <string> grid){
    Position princess;
    Position mario = {r, c};
    
    for(int row=0; row < n; row++){
        for(int col=0; col < n; col++){
            if(grid[row][col] == 'p'){
                princess = {row, col};
                break;
            }
        }
    }
    
    int drow = get<0>(princess) - get<0>(mario);
    int dcol = get<1>(princess) - get<1>(mario);
    
    if(dcol <= -1) cout << "LEFT" << endl;
    else if(dcol >= 1) cout << "RIGHT" << endl;
    else if(drow <= -1) cout<< "UP" << endl;
    else if(drow >= 1) cout<< "DOWN" << endl;
}


int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
