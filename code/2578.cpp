class Solution {
public:
    int splitNum(int num) {
        int num1 = 0, num2 = 0, x = 1;
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num /= 10;
        }
        sort(v.begin(),v.end());
        num = 0;
        for(auto &i: v){
            num *= 10;
            num += i;
        }
        while(num){
            num1 += x*(num%10);
            num /= 10;
            num2 += x*(num%10);
            num /= 10;
            x *= 10;
        }
        return num1+num2;
    }
};