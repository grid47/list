
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 327: Count of Range Sum"
date = "2023-12-08"
description = "Solution to Leetcode 327"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-of-range-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int cnt = 0, lower, upper;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        this->lower = lower;
        this->upper = upper;
        vector<long> sum(n + 1, 0), tmp(n + 1, 0);
        for(int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
        
        merge_sort(sum, 0, n, tmp);
        
        return cnt;
    }
    
    void merge_sort(vector<long> &sum, int left, int right, vector<long> &tmp) {
        if(left >= right) return;
        long mid = (left + right) / 2;
        merge_sort(sum, left, mid, tmp);
        merge_sort(sum, mid + 1, right, tmp);
        merge(sum, left, right, mid, tmp);
    }
    
    void merge(vector<long> &sum, int left, int right, int mid, vector<long> &tmp) {
        
        int k = mid + 1, j = mid + 1;
        
        int high = mid + 1, common = left;
        
        // Merge [left, right] on tmp;
        for(int low = left; low <= mid; low++) {
            
            while (k <= right && sum[k] - sum[low] <  lower) k++;
            /*
            low is i in the question, use of k is just to count
            how many j's are there which satified the condition given in question.
            note that i(low) is from first part of the merge slice
            and j is from second part.
            */
            while (j <= right && sum[j] - sum[low] <= upper) j++;
            cnt += j - k;
            
            while(high <= right && sum[high] < sum[low]) tmp[common++] = sum[high++];
            tmp[common++] = sum[low];
            
        }
        while(high <= right) tmp[common++] = sum[high++];        
        
        // Set sum slice with sorted piece;
        for(int pos = left; pos <= right; pos++)
            sum[pos] = tmp[pos];
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/327.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

