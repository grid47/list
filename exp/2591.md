class Solution {
public:
    int distMoney(int num, int kid) {
        if(num < kid) return -1;
        int avg = num / kid;
        if(avg > 8) return kid - 1;
        if(avg == 8) {
            if(num % kid == 0) return kid;
            return kid - 1;
        }
        if(avg > 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;
        }
        
        if(avg == 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;
        }
        
        if(avg < 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;            
        }
        
        return -1;
    }
};