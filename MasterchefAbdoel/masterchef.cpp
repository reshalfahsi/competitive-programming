#include <vector>
#include <tuple>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#define INIT_VALUE -1

typedef struct {
    int maxA;
    int maxB;
    int maxC;
    int cost;
    int index;
} Cuisine;

typedef std::vector<Cuisine> Menu;
Menu menu;

std::map<std::string, int> memo;

int N, K;
int totA, totB, totC;

std::string generate_key(int a, int b, int c, int cost, int prev, int prev_k){
    
    std::stringstream ss;
    std::string ret;
    ss << a << '|' << b << '|' << c << '|' << cost << '|' << prev << '|' << prev_k;
    ret = ss.str();
    return ret;
    
}

int cook(int a, int b, int c, int cost, int prev, int prev_k, int choosen[]){
   
    int ret;
    int max = INIT_VALUE;
    int cpy_choosen[N];
    
    for(int n = 0; n<N; n++)
        cpy_choosen[n] = choosen[n];
    
    auto key = generate_key(a, b, c, cost, prev, prev_k);
    
    if(memo[key] != 0) return memo[key];
   
    for(int i = 0; i < N; i++ ){
        auto A = a-menu[i].maxA;
        auto B = b-menu[i].maxB;
        auto C = c-menu[i].maxC;
        if(choosen[i]<K && A>=0 && B>=0 && C>=0){
            cpy_choosen[i]++;
            ret = (cook(A, B, C, cost + menu[i].cost, i, cpy_choosen[i], cpy_choosen));
        }
        else if(choosen[i] >= K || 
                (A < 0 || B < 0 || C < 0) ){
                ret = cost;
        }
        
        if(max < ret) max = ret;
    }
    
    memo[key] = max;
    
    return max;
    
}

int main(){

    std::cin >> N >> K;
    std::cin >> totA >> totB >> totC;
        
    for(int i = 0; i<N; i++){
        int tempA, tempB, tempC, tempCost;
        std::cin >> tempA >> tempB >> tempC >> tempCost;
        Cuisine c;
        c.maxA = tempA;
        c.maxB = tempB;
        c.maxC = tempC;
        c.cost = tempCost;
        c.index = i;
        menu.push_back(c);
    }
    
    int choosen[N];
    for(int i=0; i<N; i++)
        choosen[i] = 0;
    std::cout << cook(totA, totB, totC, 0, INIT_VALUE, INIT_VALUE, choosen) << std::endl;    
}
