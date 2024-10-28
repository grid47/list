class Solution {
public:
    int maxArea(int h, int w, vector<int>& hr, vector<int>& vt) {
        
        int mx1 = 0, mx2 = 0;
        sort(hr.begin(), hr.end());
        sort(vt.begin(), vt.end());
        mx1 = h - hr.back();
        mx2 = w - vt.back();
        int prv = 0;
        for(int i = 0; i < hr.size(); i++) {
            mx1 = max(mx1, hr[i] - prv);
            prv = hr[i];
        }
        prv= 0;
        for(int i = 0; i < vt.size(); i++) {
            mx2 = max(mx2, vt[i] - prv);
            prv = vt[i];
        }      
        long long mxa = mx1, mxb = mx2;
        return (mxa * mxb) % 1000000007;
    }
};