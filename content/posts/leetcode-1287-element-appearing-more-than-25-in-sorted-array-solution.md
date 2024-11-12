
+++
authors = ["grid47"]
title = "Leetcode 1287: Element Appearing More Than 25% In Sorted Array"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1287: Element Appearing More Than 25% In Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1287.md" >}}
---
{{< youtube G74W8v2yVjY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1288: Remove Covered Intervals](https://grid47.xyz/posts/leetcode-1288-remove-covered-intervals-solution/) |
| --- |
