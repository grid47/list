class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        int fx1=rect1[0];
        int fx2=rect1[2];
        int fy1=rect1[1];
        int fy2=rect1[3];

        int sx1=rect2[0];
        int sx2=rect2[2];
        int sy1=rect2[1];
        int sy2=rect2[3];

        return !((sy1>=fy2) ||
               (fy1>=sy2) ||
               (fx1>=sx2) ||
               (fx2<=sx1));
    }
};