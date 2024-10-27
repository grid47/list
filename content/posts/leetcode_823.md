
+++
authors = ["Yasir"]
title = "Leetcode 823: Binary Trees With Factors"
date = "2022-07-28"
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

{{< highlight html >}}
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

