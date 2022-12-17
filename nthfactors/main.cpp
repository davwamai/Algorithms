using namespace std;
#include <cmath>
#include <vector>
#include "primes.h"


int main(){
    for(int i=0; i < 100; i++){
        vector<int> numFactors;
        vector<int> fs;
        int n;
        int f = 2;
        while(n!=1){
            if(n%f!=0){
                ++f;
            } else {
                fs.push_back(f);
            }

        }
    }
    return 0;
}