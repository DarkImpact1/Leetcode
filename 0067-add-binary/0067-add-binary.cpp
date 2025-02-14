class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size()-1, n2 = b.size()-1, carry = 0;
        string ans = "";
        while(n1 >= 0  || n2 >= 0){
            int s = carry;
            if(n1 >= 0){
                s += a[n1--] - '0';
            }
            if(n2 >= 0){
                s += b[n2--] - '0';
            }
            ans += s%2 +'0';
            carry = s/2;
        }
        if(carry){
            ans += carry + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};