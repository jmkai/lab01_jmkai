#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            vector<vector<int>> result;
            int n = nums.size();
            
            sort(nums.begin(), nums.end());
            
            for (int i = 0; i < n - 2; i++) {
                if (i > 0 && nums[i] == nums[i - 1]){
                    continue;
                }
                for (int j = i + 1; j < n - 1; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]){
                        continue;
                    }
                    for (int k = j + 1; k < n; k++) {
                        if (k > j + 1 && nums[k] == nums[k - 1]){
                            continue;
                        }

                        if (nums[i] + nums[j] + nums[k] == 0) {
                            result.push_back({nums[i], nums[j], nums[k]});
                        }
                    }
                }
            }
            
            return result;
        }
};

int main(){
    vector<int> nums = {};

    for(int i = 100; i <= 1600 ; i *= 2){
        auto start = chrono::high_resolution_clock::now();
        
        for(int j = 0; j < i; j++){
            nums.push_back(rand() - RAND_MAX / 2);
        }
        
        Solution obj;
        vector<vector<int>> result = obj.threeSum(nums);

        auto end = chrono::high_resolution_clock::now();
        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

        cout << time_ms << endl;
    }

    return 0;
}