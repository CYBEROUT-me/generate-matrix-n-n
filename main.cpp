#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void print(vector<vector<int>> n){
    cout << endl;
    for(int i = 0; i < n.size(); i++){
        for(auto item : n[i]){
            cout << item << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
enum direct
    {
        right = 0,
        down = 1,
        left = 2,
        up = 3
    };
    int d = 0;

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans (n, vector<int>(n));
        cout << d << endl;
        int r_lim = n;
        int d_lim = n;
        int l_lim = -1;
        int u_lim = -1;
        int num = 1;
        while(num <= pow(n,2)){
            cout << "d: " << d << endl;
            switch(d)
            {
                case right:
                {
                    for(int i = l_lim + 1; i < r_lim; i++){
                        ans[u_lim+1][i] = num;
                        num++;
                    }
                    print(ans);
                    u_lim++;
                    break;
                }
                case down:
                {
                    for(int i = u_lim+1; i < d_lim; i++){
                        ans[i][r_lim-1] = num;
                        num++;
                    }
                    print(ans);
                    r_lim--;
                    break;
                }
                case left:
                {
                    for(int i = r_lim - 1; i > l_lim; i--){
                        ans[d_lim-1][i] = num;
                        num++;
                    }
                    print(ans);
                    d_lim--;
                    break;
                }
                case up:
                {
                    for(int i = d_lim-1; i > u_lim; i--){
                        ans[i][l_lim+1] = num;
                        num++;
                    }
                    print(ans);
                    l_lim++;
                    break;
                }
            }
            if(d != 3) d++;
            else d = 0;
        }
        return ans;
    }
};


int main() {
    Solution a;
    int n = 4;
    a.generateMatrix(n);
}
