#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <tuple>

using namespace std;

namespace cv{
    typedef vector<int> _Vec;
    typedef vector<vector<int>> _Mat;
    typedef tuple<int, int> _Position;
    
    class Vec{
        
        public:
            Vec(_Vec data){
                _data = data;
            }
            
            static Vec zeros(int shape){
                _Vec data(shape);
                return Vec(data);
            }
            
            static Vec ones(int shape){
                _Vec data(shape, 1);
                return Vec(data);
            }
            
            int &operator[](int pos){
                return _data[pos];
            }
            
            _Vec data(){
                return _data;
            }
            
            int shape(){
                return _data.size();
            }
            
            friend ostream& operator<<(ostream& os, Vec& vec){
                for(int idx=0; idx < vec.shape(); idx++){
                    os << vec[idx];
                }
                os << endl;
                return os;
            }
            
        private:
            _Vec _data;
    };
    
    class Mat{
        
        public:
            Mat(_Mat data){
                _data = data;
            }
            
            static Mat zeros(_Position shape){
                auto row = get<0>(shape);
                auto col = get<1>(shape);
                _Mat data(row, vector<int>(col));
                return Mat(data);
            }
            
            static Mat ones(_Position shape){
                auto row = get<0>(shape);
                auto col = get<1>(shape);
                _Mat data(row, vector<int>(col, 1));
                return Mat(data);
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
            
            friend ostream& operator<<(ostream& os, Mat& mat){
                for(int row=0; row < mat.rows(); row++){
                    for(int col=0; col < mat.cols(); col++){
                        os << mat[{row, col}];
                    }
                        os << endl;
                }
                return os;
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
                       
    void dilate(Mat img, Mat &dilated, Mat se){
        
        assert(se.rows() == se.cols());
        assert( se.rows() % 2 == 1);
        
        int center = (se.rows() - 1)/2;
        
        auto shapeSE = se.rows() * se.cols();
        auto rowSE = Vec::zeros(shapeSE);
        auto colSE = Vec::zeros(shapeSE);
        
        for(int row=0; row < se.rows(); row++){
            for(int col=0; col < se.cols(); col++){
                if(se[{row, col}] == 1){
                    auto idx = row * se.rows() + col;
                    rowSE[idx] = row - center; // UP or DOWN
                    colSE[idx] = col - center; // LEFT or RIGHT
                }
            }
        }
        
        for(int row=0; row < img.rows(); row++){
            for(int col=0; col < img.cols(); col++){
                for(int idx=0; idx < shapeSE; idx++){
                    if(img[{row, col}] == 1){
                        auto newcol = col + colSE[idx];
                        auto newrow = row + rowSE[idx];
                        if((newcol >= 0) && (newcol < img.cols()) &&
                            (newrow >= 0) && (newrow < img.rows())){
                            dilated[{newrow, newcol}] = 1;
                        }
                    }
                }
            }
        }
    }
    
    void erode(Mat img, Mat &eroded, Mat se){
        
        assert(se.rows() == se.cols());
        assert( se.rows() % 2 == 1);

        int center = (se.rows() - 1)/2;

        auto shapeSE = se.rows() * se.cols();
        auto rowSE = Vec::zeros(shapeSE);
        auto colSE = Vec::zeros(shapeSE);

        for(int row=0; row < se.rows(); row++){
            for(int col=0; col < se.cols(); col++){
                if(se[{row, col}] == 1){
                    auto idx = row * se.rows() + col;
                    rowSE[idx] = row - center; // UP or DOWN
                    colSE[idx] = col - center; // LEFT or RIGHT
                }
            }
        }
        
        for(int row=0; row < img.rows(); row++){
            for(int col=0; col < img.cols(); col++){
                for(int idx=0; idx < shapeSE; idx++){
                    if(img[{row, col}] == 0){
                        auto newcol = col + colSE[idx];
                        auto newrow = row + rowSE[idx];
                        if((newcol >= 0) && (newcol < img.cols()) &&
                            (newrow >= 0) && (newrow < img.rows())){
                            eroded[{newrow, newcol}] = 0;
                        }
                    }
                }
            }
        }
    }
    
}

cv::Mat image ({
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,1,1,1,1,1,1,1,0,0 },
    { 0,0,0,0,1,1,1,1,0,0 },
    { 0,0,0,0,1,1,1,1,0,0 },
    { 0,0,0,1,1,1,1,1,0,0 },
    { 0,0,0,0,1,1,1,1,0,0 },
    { 0,0,0,1,1,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 }
});

cv::Mat structuringElement ({
    { 1,1,1 },
    { 1,1,1 },
    { 1,1,1 }    
});


int main() {
    auto erodedImage = cv::Mat::ones({image.rows(), image.cols()});
    cv::erode(image, erodedImage, structuringElement);
    
    int count = 0;
    for(int row=0; row < erodedImage.rows(); row++){
        for(int col=0; col < erodedImage.cols(); col++){
            if(erodedImage[{row, col}] == 1){
                count++;
            }
        }
    }
    // cout << erodedImage << endl;
    cout << count << endl;
}
