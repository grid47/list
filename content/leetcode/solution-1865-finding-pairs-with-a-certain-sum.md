
+++
authors = ["grid47"]
title = "Leetcode 1865: Finding Pairs With a Certain Sum"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1865: Finding Pairs With a Certain Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class FindSumPairs {
public:
    vector<int> nums1, nums2;
    vector<vector<int>> mtx;
    map<int, int> mp;
    int m, n;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        m = nums2.size(), n = nums1.size();
        for(int i = 0; i < nums2.size(); i++) {
                mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int key = nums2[index];
        nums2[index] += val;
        mp[key]--;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += mp[tot - nums1[i]];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1865.md" >}}
---
{{< youtube T4yZIHISIYY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1869: Longer Contiguous Segments of Ones than Zeros](https://grid47.xyz/leetcode/solution-1869-longer-contiguous-segments-of-ones-than-zeros/) |
| --- |
