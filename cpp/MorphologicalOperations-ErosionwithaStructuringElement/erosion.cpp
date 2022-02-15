#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <tuple>

using namespace std;

namespace cv{
    typedef vector<int> _Vec;
    typedef vector<vector<int>> _Mat;
    typedef tuple<int, int> _Shape;
    
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
            
            Vec& operator=(Vec& vec){
                if(this->shape() != vec.shape()){
                    this->_data.clear();
                    this->_data.resize(vec.shape());
                }
                for(int idx=0; idx < vec.shape(); idx++){
                    this->_data[idx] = vec[idx];
                }
                return *this;
            }
            
            int &operator[](int pos){
                return _data[pos];
            }
            
            _Vec data() const{
                return _data;
            }
            
            int shape() const{
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
            
            static Mat zeros(_Shape shape){
                auto row = get<0>(shape);
                auto col = get<1>(shape);
                _Mat data(row, vector<int>(col));
                return Mat(data);
            }
            
            static Mat ones(_Shape shape){
                auto row = get<0>(shape);
                auto col = get<1>(shape);
                _Mat data(row, vector<int>(col, 1));
                return Mat(data);
            }
            
            _Mat data() const{
                return _data;
            }
            
            int &operator[](_Shape pos){
                auto row = get<0>(pos);
                auto col = get<1>(pos);
                return _data[row][col];
            }
            
            Mat& operator=(Mat& mat){
                if(this->rows() != mat.rows() || this->cols() != mat.cols()){
                    
                    this->_data[0].clear();
                    this->_data.clear();
                    
                    this->_data.resize(mat.rows());
                    
                    for(int row=0; row < mat.rows(); row++){
                        this->_data[row].resize(mat.cols());
                        for(int col=0; col < mat.cols(); col++){
                            this->_data[row][col] = mat[{row, col}];
                        }
                    }
                }
                else{
                    for(int row=0; row < mat.rows(); row++){
                        for(int col=0; col < mat.cols(); col++){
                            this->_data[row][col] = mat[{row, col}];
                        }
                    }
                }
                
                return *this;
            }
            
            int rows() const{
                return _data.size();
            }
            
            int cols() const{
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
    
    _Shape DIRECTION[] = {
                        {-1, 0},    // UP
                        {0, -1},    // LEFT
                        {0, 1},     // RIGHT 
                        {1, 0},     // DOWN
                        {-1, -1},   // UP-LEFT
                        {-1, 1},    // UP-RIGHT
                        {1, -1},    // DOWN-LEFT 
                        {1, 1}      // DOWN-RIGHT  
                       };
                       
    void dilate(Mat img, Mat &dilated, Mat se, _Shape center = {0,0}){

        int row_center = get<0>(center);
        int col_center = get<1>(center);
        
        auto shapeSE = se.rows() * se.cols();
        auto rowSE = Vec::zeros(shapeSE);
        auto colSE = Vec::zeros(shapeSE);
        auto temp = Mat::zeros({img.rows(), img.cols()});
        
        for(int row=0; row < se.rows(); row++){
            for(int col=0; col < se.cols(); col++){
                if(se[{row, col}] == 1){
                    auto idx = row * se.cols() + col;
                    rowSE[idx] = row - row_center; // UP or DOWN
                    colSE[idx] = col - col_center; // LEFT or RIGHT
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
                            temp[{newrow, newcol}] = 1;
                        }
                    }
                }
            }
        }
        
        dilated = temp;
    }
    
    void erode(Mat img, Mat &eroded, Mat se, _Shape center = {0,0}){

        int row_center = get<0>(center);
        int col_center = get<1>(center);

        auto shapeSE = se.rows() * se.cols();
        auto rowSE = Vec::zeros(shapeSE);
        auto colSE = Vec::zeros(shapeSE);
        auto temp = Mat::ones({img.rows(), img.cols()});

        for(int row=0; row < se.rows(); row++){
            for(int col=0; col < se.cols(); col++){
                if(se[{row, col}] == 1){
                    auto idx = row * se.cols() + col;
                    rowSE[idx] = row - row_center; // UP or DOWN
                    colSE[idx] = col - col_center; // LEFT or RIGHT
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
                            temp[{newrow, newcol}] = 0;
                        }
                    }
                }
            }
        }

        eroded = temp;
    }
    
    void padding(Mat src, Mat& dst, _Shape shape, int element = 0, bool inverse = false){

        auto row = get<0>(shape);
        auto col = get<1>(shape);

        if(!inverse){
            _Mat temp(src.rows() + (row + 1), _Vec(src.cols() + (col + 1), element));
        
            for(int r=0; r < src.rows(); r++){
                for(int c=0; c < src.cols(); c++){
                    temp[r + row][c + col] = src[{r, c}];
                }
            }
            
            Mat mat(temp);
            dst = mat;  
        }
        else{
            _Mat temp(src.rows() - (row + 1), _Vec(src.cols() - (col + 1)));
        
            for(int r=0; r < src.rows() - (row + 1); r++){
                for(int c=0; c < src.cols() - (col + 1); c++){
                    temp[r][c] = src[{r + row, c + col}];
                }
            }
            
            Mat mat(temp);
            dst = mat;
        }

            
    }
    
}

cv::Mat image ({
    { 0,0,1,1,0 },
    { 0,0,1,1,0 },
    { 0,0,1,1,0 },
    { 1,1,1,1,1 }
});

cv::Mat structuringElement ({
    {1},
    {1},
    {1} 
});

int main() {
    cv::padding(image, image, {1,1});
    cv::erode(image, image, structuringElement, {1, 0});
    cv::padding(image, image, {1,1}, 0, true);
    cout << image;
}
