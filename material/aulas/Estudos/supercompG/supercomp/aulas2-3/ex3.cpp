#include<iostream>
#include<math.h>
#include<iomanip>      // std::setprecision
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x, y;

    vector<vector<int>> d;

    int dx,dy;
    for (int i=1; i<n; i++){
        for (int j=1; j<n; j++){
            dx = x[i] - x[j];
            dy = y[i] - y[j];
            d[i][j] = sqrt(dx*dx + dy*dy);
        }
    }
   

    
    
    
    return 0;
}

// g++ -Wall -O3 ex2-2.cpp -o ex2-2