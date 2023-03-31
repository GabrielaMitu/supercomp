#include<iostream>
#include<cmath>
#include <iomanip>      // std::setprecision
#include<vector>
#include<algorithm>  //para uso do sort

using namespace std;
// float retorna_mi(int n, vector<float> nums);
// float sigma_quadrado(int n, vector<float> nums, float mi);

int main(){
    int n;
    cin >> n;

    vector<float> nums;
    for(int i=0; i<n; i++){
        float x;
        cin >> x;
        nums.push_back(x);
    }

    vector<float> nums2;
    for(int i=0; i<n; i++){
        float x;
        cin >> x;
        nums2.push_back(x);
    }

    for(auto& e: nums)
        cout << e << endl;

    float mi;
    float sigma;
    mi = retorna_mi(n, nums);
    sigma = sigma_quadrado(n, nums, mi);

    cout << fixed;
    cout << setprecision(10) << mi << endl;

    cout << fixed;
    cout << setprecision(10) << sigma << endl;
    
    
    return 0;
}

float retorna_mi(int n, vector<float> nums){
    float total=0.0;
    for(auto& e: nums)
        total+= e;
    return total/n;
}

float sigma_quadrado(int n, vector<float> nums, float mi){
    float total=0.0;
    for(auto& e: nums)
        total+= pow((e-mi),2);
    return total/n;
}

// g++ -Wall -O3 ex2.cpp -o ex2