
+++
authors = ["Yasir"]
title = "Leetcode 2899: Last Visited Integers"
date = "2016-11-21"
description = "Solution to Leetcode 2899"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-visited-integers/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>v;
        vector<int>ans;
        int count=0;
        for(int i=0;i<words.size();i++){
            if(words[i]=="prev"){
                count++;
                if(count>v.size()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(v[v.size()-count]);
                }
            }
            else{
                count=0;
                v.push_back(stoi(words[i]));
            }
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

