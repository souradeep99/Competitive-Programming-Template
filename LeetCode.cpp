//problem link: https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> v = nums;
        int n = v.size();
        sort(v.begin(), v.end());
        int x = v[0] + v[1] + v[2];
        for(int i = 0; i < n; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int s = v[i] + v[l] + v[r];
                if(abs(target - s) < abs(target - x))
                    x = s;
                if(s > target)
                    r--;
                else
                    l++;
            }
        }
        return x;
    }
};
