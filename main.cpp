#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3){
            return 0;
        }
        vector<int> maxleft(n);
        vector<int> maxright(n);
        maxleft[0]=height[0];
        for(int i=1; i<n; i++){
            maxleft[i]=max(maxleft[i-1], height[i]);
        }
        maxright[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--){
            maxright[i]=max(maxright[i+1], height[i]);
        }
        int waterArea=0;
        for(int i=1; i<n-1; i++){
            int minheight=min(maxleft[i-1], maxright[i+1]);
            if(minheight>height[i]){
                waterArea += minheight - height[i];
            }
        }
        return waterArea;
    }
};

int main(){

    return 0;
}

//height es el eje x, si es igual a un numero es obstaculo
//el eje y debe ser la altura de los obstaculos, otro vector