
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 823: Binary Trees With Factors"
date = "2022-07-29"
description = "Solution to Leetcode 823"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-trees-with-factors/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> rootWithCount;
        rootWithCount[arr[0]] = 1;
        for(int i = 0; i < arr.size(); i++) {
            long count = 1;
            for(auto j : rootWithCount) {
                int root = j.first;
                if((arr[i] % root == 0) && (rootWithCount.find(arr[i]/root) != rootWithCount.end())) {
                    count += rootWithCount[root] * rootWithCount[arr[i]/root];
                }
            }
            rootWithCount[arr[i]] = count;
        }
        int no = 0;
        for(auto it: rootWithCount) no = (no + it.second) % (int)(1e9+7);
        return no;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

