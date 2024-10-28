class Solution {
public:
    int poorPigs(int bckt, int die, int test) {
        int pigs = 0;
        
        while(pow((test/die + 1), pigs) < bckt) pigs++;
         
        return pigs;        
    }
};