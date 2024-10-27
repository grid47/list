
+++
authors = ["Yasir"]
title = "Leetcode 1947: Maximum Compatibility Score Sum"
date = "2019-06-30"
description = "Solution to Leetcode 1947"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-compatibility-score-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> pos;
        int ans = 0;
        for(int i = 0; i < students.size(); i++)
            pos.push_back(i);
        do {

            int curr = 0;
            for(int i = 0; i < students.size(); i++)
            for(int j = 0; j < students[pos[i]].size(); j++)
                curr += (students[pos[i]][j] == mentors[i][j]);
            ans = max(ans, curr);

        } while(next_permutation(pos.begin(), pos.end()));
        return ans;
    }
};
{{< /highlight >}}

