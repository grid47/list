
+++
authors = ["Yasir"]
title = "Leetcode 1207: Unique Number of Occurrences"
date = "2021-07-09"
description = "Solution to Leetcode 1207"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-number-of-occurrences/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i = 0;
        sort(arr.begin(),arr.end());
        vector<int> ans;
        while (i < arr.size()){
            int count = 1;
            for (int j = i+1; j< arr.size(); j++){
                if (arr[i] == arr[j])
                    count++;
            }
            ans.push_back(count);
            i = i + count;
        }
        sort(ans.begin(),ans.end());
        for (int i = 0; i < ans.size() - 1; i++){
            if (ans[i] == ans [i+1])
                return false;
        }
        return true;        
    }
};
{{< /highlight >}}

