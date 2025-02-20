class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return {}; 
        
        vector<int> newArray(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                newArray[i] = newArray[i - 1] + 1;
            }
        }

        vector<int> ans;
        for (int i = k - 1; i < n; ++i) {
            ans.push_back(newArray[i] >= k ? nums[i] : -1);
        }
        return ans;
    }
};