#include <iostream>
#include <vector>
#include <math.h>
int main() {
    class Solution {
public:
    double distance(int x1,int y1,int x2,int y2){
        return (double)sqrt((double)pow(x2 - x1, 2) +  (double)pow(y2 - y1, 2) );
    }
     vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int max_distance=0;
        vector<int> ans(2,0);
        int n=towers.size();
        
        for(int i=0;i<n;i++){
            int curr_distance=0;
            for(int j=0;j<n;j++){
                double d=distance(towers[i][0],towers[i][1],towers[j][0],towers[j][1]);
                if(d<=radius) 
                    curr_distance+=(towers[j][2]/(1+d));
            }
            if(curr_distance>max_distance){
                max_distance=curr_distance;
                ans[0]=towers[i][0];
                ans[1]=towers[i][1];
            }
            else if(curr_distance==max_distance){
                
                if(ans[0]>towers[i][0] || (ans[0]==towers[i][0] && ans[1]>towers[i][1]) ){
                    ans[0]=towers[i][0],ans[1]=towers[i][1];
                }
            }
        }
        return ans;
    }
};

    return 0;
}