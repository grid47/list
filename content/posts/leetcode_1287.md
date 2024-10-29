
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1287: Element Appearing More Than 25% In Sorted Array"
date = "2021-04-22"
description = "Solution to Leetcode 1287"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		unordered_map<int, int> m;
		for(int i = 0; i < arr.size(); i++){
			m[arr[i]]++;
		}
		for(auto i : m){
			if(i.second > arr.size() / 4){
				return i.first;
			}
		}
		return arr[0];
	}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

