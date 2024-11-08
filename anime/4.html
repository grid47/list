class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> A = (m < n)? nums1 : nums2;
        vector<int> B = (m < n)? nums2 : nums1;
        m = (nums1.size() < nums2.size())? nums1.size() : nums2.size();
        n = (nums1.size() < nums2.size())? nums2.size() : nums1.size();

        int imin = 0, imax = m, i, j;

        while(imin <= imax)
        {
            i = ((imin + imax) / 2);
            j = ((m + n + 1)/ 2) - i;

                 if((i < m) && (B[j - 1] > A[i]))
                    imin = i + 1;
            else if((i > 0) && (A[i - 1] > B[j]))
                    imax = i - 1;
            else
            {
                int lmax;
                     if(i == 0) lmax = B[j - 1];
                else if(j == 0) lmax = A[i - 1];
                else            lmax = max(A[i - 1], B[j - 1]);

                if(((m + n) % 2) == 1) return lmax;

                int rmin;
                     if(i == m) rmin = B[j];
                else if(j == n) rmin = A[i];
                else            rmin = min(A[i], B[j]);

                return (double)(lmax + rmin) / 2;
            }
        }
        return 0;
    }
};