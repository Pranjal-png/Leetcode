class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ans =1;
        long long x = 20;
        long long k = n/2;
        while(k>0){
            if(k%2 == 1){
                ans = (ans*x)%1000000007;
            }
            x = (x*x)%1000000007;
            k = k/2;
        }
        if(n%2 == 1){
            ans = (ans*5)%1000000007;
        }
        return ans;
    }
};