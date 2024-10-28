class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while(left <= right) {
            long res = left * left + right * right;
            if(res < c)
            left++;
            else if(res > c) 
            right--;
            else return true;
        }
        return false;
    }
};