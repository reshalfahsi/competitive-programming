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
            
            Vec& operator=(Vec& vec){
                assert(this->shape()==vec.shape());
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
            
            _Mat data() const{
                return _data;
            }
            
            int &operator[](_Position pos){
                auto row = get<0>(pos);
                auto col = get<1>(pos);
                return _data[row][col];
            }
            
            Mat& operator=(Mat& mat){
                assert(this->rows()==mat.rows());
                assert(this->cols()==mat.cols());
                
                for(int row=0; row < mat.rows(); row++){
                    for(int col=0; col < mat.cols(); col++){
                        this->_data[row][col] = mat[{row, col}];
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
        auto temp = Mat::zeros({img.rows(), img.cols()});
        
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
                            temp[{newrow, newcol}] = 1;
                        }
                    }
                }
            }
        }
        
        dilated = temp;
    }
    
    void erode(Mat img, Mat &eroded, Mat se){
        
        assert(se.rows() == se.cols());
        assert( se.rows() % 2 == 1);

        int center = (se.rows() - 1)/2;

        auto shapeSE = se.rows() * se.cols();
        auto rowSE = Vec::zeros(shapeSE);
        auto colSE = Vec::zeros(shapeSE);
        auto temp = Mat::ones({img.rows(), img.cols()});

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
                            temp[{newrow, newcol}] = 0;
                        }
                    }
                }
            }
        }
        
        eroded = temp;
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
    auto dst_img = cv::Mat::zeros({image.rows(), image.cols()});
    cv::erode(image, dst_img, structuringElement);
    // cout<< dst_img << endl;
    cv::dilate(dst_img, dst_img, structuringElement);
    
    int count = 0;
    for(int row=0; row < dst_img.rows(); row++){
        for(int col=0; col < dst_img.cols(); col++){
            if(dst_img[{row, col}] == 1){
                count++;
            }
        }
    }
    // cout << dst_img << endl;
    cout << count << endl;
}
