#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

namespace cv{
    typedef vector<vector<int>> _Mat;
    typedef tuple<int, int> _Position;
    
    class Mat{
        
        public:
            Mat(_Mat data){
                _data = data;
            }
            
            _Mat data(){
                return _data;
            }
            
            int &operator[](_Position pos){
                auto row = get<0>(pos);
                auto col = get<1>(pos);
                return _data[row][col];
            }
            
            int rows(){
                return _data.size();
            }
            
            int cols(){
                return _data[0].size();
            }
        
        private:
            _Mat _data;
        
    };
    
    _Position DIRECTION[] = {
                        {-1, 0},    // UP
                        {0, -1},    // LEFT
                        {0, 1},     // RIGHT 
                        {1, 0},     // DOWN
                        {-1, -1},   // UP-LEFT
                        {-1, 1},    // UP-RIGHT
                        {1, -1},    // DOWN-LEFT 
                        {1, 1}      // DOWN-RIGHT  
                       }; 
}

int MAX_ROW = 0;
int MAX_COL = 0;

cv::Mat Image ({
    { 0,0,0,1,1,0,0,0,1,0,1,0 },
    { 1,1,1,0,1,1,1,1,0,0,0,1 },
    { 1,1,1,0,1,0,0,1,0,0,1,0 },
    { 1,0,0,0,0,0,0,0,0,1,0,0 }
    });
    
cv::Mat ImageOut = Image;

int connectivity_label = 0;

void findPixelConnectivity(int row, int col, cv::Mat &image, cv::Mat &imageOut){
    
    image[{row, col}] = 0;
    imageOut[{row, col}] = connectivity_label;
    
    for (auto direction : cv::DIRECTION){
        auto newrow = row + get<0>(direction);
        auto newcol = col + get<1>(direction);
        
        if((newrow >= 0) && (newrow < MAX_ROW) && 
            (newcol >= 0) && (newcol < MAX_COL)){
           if(image[{newrow, newcol}] == 1){
               findPixelConnectivity(newrow, newcol, image, imageOut);
           } 
        }
    }
    
}

int main() {
    
    MAX_ROW = Image.rows();
    MAX_COL = Image.cols();
    
    for(int row=0; row < MAX_ROW; row++){
        for(int col=0; col < MAX_COL; col++){
            if (Image[{row, col}] == 1){
                connectivity_label++;
                findPixelConnectivity(row, col, Image, ImageOut);                
            }
        }
    }
    
    /*
    for(int row=0; row < ImageOut.rows(); row++){
        for(int col=0; col < ImageOut.cols(); col++){
            cout << ImageOut[{row, col}];
        }
        cout << endl;
    }
    */
    
    cout << connectivity_label << endl;
     
    return 0;
}
