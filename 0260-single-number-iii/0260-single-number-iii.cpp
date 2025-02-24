class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        
        // Step 1: XOR all elements
        for (int i : nums) {
            xr ^= i;
        }

        // Step 2: Convert to unsigned before negation
        unsigned int rightmostbit = xr & -(unsigned int)xr;  

        int num1 = 0, num2 = 0;
        
        // Step 3: Divide elements into two groups and XOR separately
        for (int i : nums) {
            if (i & rightmostbit) 
                num1 ^= i;
            else 
                num2 ^= i;
        }
        
        return {num1, num2};
    }
};
