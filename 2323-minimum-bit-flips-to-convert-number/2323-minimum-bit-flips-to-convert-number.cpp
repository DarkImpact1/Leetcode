class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int result = start ^ goal;
        while(result != 0){
            result = result & (result-1);
            cnt++;
        }
        return cnt;
    }
};