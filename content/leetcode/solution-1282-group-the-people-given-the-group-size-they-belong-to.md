
+++
authors = ["grid47"]
title = "Leetcode 1282: Group the People Given the Group Size They Belong To"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1282: Group the People Given the Group Size They Belong To in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "RrnhHjJmzj8"
youtube_upload_date="2023-09-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RrnhHjJmzj8/maxresdefault.webp"
comments = true
+++



---
Given an array where each element represents the required size of the group for each person, group the people accordingly and return the groups. Each person must be in exactly one group.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array where each element represents the group size that each person is assigned to.
- **Example:** `Input: groupSizes = [3,3,3,3,3,1,3]`
- **Constraints:**
	- 1 <= n <= 500
	- 1 <= groupSizes[i] <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of lists, where each list represents a group containing the people who belong to that group.
- **Example:** `Output: [[5], [0,1,2], [3,4,6]]`
- **Constraints:**
	- Each person should appear in exactly one group.
	- The number of people in each group must match the values in the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** To group people based on the sizes specified in the input array.

- Iterate through the input array and maintain a list of people for each group size.
- Once a group reaches the required size, add it to the result and start a new group for the next people.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain valid values and have a valid solution.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: groupSizes = [3,3,3,3,3,1,3]`  \
  **Explanation:** In this example, we must group people such that the sizes of the groups correspond to the values in the groupSizes array. For example, the first three people (0, 1, and 2) must form a group of size 3, while the last person (5) must be in a group of size 1.

{{< dots >}}
## Approach 🚀
The solution uses a greedy approach where people are grouped in batches according to the specified group sizes.

### Initial Thoughts 💭
- We need to keep track of people who are yet to be grouped based on their required group size.
- Iterate through the groupSizes array, and as each person is processed, maintain a list of current groups. Once a group reaches its specified size, move on to the next group.
{{< dots >}}
### Edge Cases 🌐
- If the groupSizes array is empty, there should be no groups formed.
- Ensure that the solution efficiently handles input sizes up to the maximum allowed (500).
- If all people are required to be in groups of size 1, each person will form their own group.
- Each group will always have the correct number of people as per the input constraints.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> groupThePeople(vector<int>& gz) {
    vector<vector<int>> res, gzs(gz.size() + 1);
    for(auto i = 0; i < gz.size(); i++) {
        gzs[gz[i]].push_back(i);
        if(gzs[gz[i]].size() == gz[i]) {
            res.push_back({});
            swap(res.back(), gzs[gz[i]]);
        }
    }
    return res;
}
```

This function groups individuals into subgroups based on their group size preferences, using a dynamic grouping mechanism.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> groupThePeople(vector<int>& gz) {
	```
	Defines a function that takes a vector of group sizes as input and returns grouped indices.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> res, gzs(gz.size() + 1);
	```
	Initializes a result vector and an auxiliary grouping vector for grouping based on sizes.

3. **Loop Setup**
	```cpp
	    for(auto i = 0; i < gz.size(); i++) {
	```
	Loops through each index in the group size vector.

4. **Group Assignment**
	```cpp
	        gzs[gz[i]].push_back(i);
	```
	Assigns the current index to the group corresponding to its size.

5. **Conditional Check**
	```cpp
	        if(gzs[gz[i]].size() == gz[i]) {
	```
	Checks if the current group has reached the required size.

6. **Add Group to Result**
	```cpp
	            res.push_back({});
	```
	Creates a new subgroup in the result vector.

7. **Swap Operation**
	```cpp
	            swap(res.back(), gzs[gz[i]]);
	```
	Swaps the last group in the result vector with the filled group.

8. **Return Statement**
	```cpp
	    return res;
	```
	Returns the final grouped result vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes each person once, so the time complexity is O(n), where n is the number of people.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the groups in a result list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/)

---
{{< youtube RrnhHjJmzj8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
