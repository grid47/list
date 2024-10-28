class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int num1 = nums1[0];
        set<int> cnt;
        int mn = 10;

        for(int i = 0; i < nums1.size(); i++) {
            cnt.insert(nums1[i]);
            num1 = min(nums1[i], num1);
        }
        
        int num2 = nums2[0];
        for(int i = 0; i < nums2.size(); i++) {
            if(cnt.count(nums2[i])) {
                mn = min(mn, nums2[i]);
            };
            num2 = min(nums2[i], num2);
        }
        if(mn < 10) return mn;
        if(num1 < num2) {
            return num1 * 10 + num2;
        } else {
            return num2 * 10 + num1;            
        }
    }
};