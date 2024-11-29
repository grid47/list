
+++
authors = ["grid47"]
title = "Leetcode 1431: Kids With the Greatest Number of Candies"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1431: Kids With the Greatest Number of Candies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "xBpYKQzjjnM"
youtube_upload_date="2023-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/xBpYKQzjjnM/maxresdefault.jpg"
comments = true
+++



---
You are given a list of integers representing the number of candies each kid has. You are also given an integer representing the number of extra candies. Your task is to return a boolean array indicating whether, after adding all the extra candies to each kid's total, they will have the greatest number of candies among all the kids.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers `candies` where each element represents the number of candies a kid has, and an integer `extraCandies` representing the extra candies to be distributed.
- **Example:** `[3, 5, 8, 2], extraCandies = 4`
- **Constraints:**
	- 2 <= n <= 100
	- 1 <= candies[i] <= 100
	- 1 <= extraCandies <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean array of length `n` where each element is true if, after receiving the extra candies, that kid will have the greatest number of candies, otherwise false.
- **Example:** `[true, true, true, false]`
- **Constraints:**
	- The output array has the same length as the input `candies` array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine whether each kid, after receiving all the extra candies, will have as many or more candies than every other kid.

- Step 1: Find the kid with the maximum number of candies.
- Step 2: For each kid, check if adding `extraCandies` makes their total candies greater than or equal to the maximum number of candies.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be valid, with the number of kids being at least 2.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, 5, 8, 2], extraCandies = 4`  \
  **Explanation:** Kid 1 will have 7 candies, Kid 2 will have 9 candies (greatest), Kid 3 will have 12 candies (greatest), and Kid 4 will have 6 candies.

- **Input:** `[6, 2, 7, 5], extraCandies = 3`  \
  **Explanation:** Kid 1 will have 9 candies (greatest), Kid 2 will have 5 candies, Kid 3 will have 10 candies (greatest), and Kid 4 will have 8 candies.

{{< dots >}}
## Approach 🚀
To solve this problem, we first find the maximum number of candies any kid has. Then, for each kid, we check if their total candies after adding the extra candies will be greater than or equal to this maximum.

### Initial Thoughts 💭
- The solution can be approached by finding the maximum number of candies first.
- Then, we can compare each kid's total after adding the extra candies to the maximum.
- The overall time complexity of this solution should be linear with respect to the number of kids.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that there will be at least two kids, so there will never be empty inputs.
- Ensure the solution can handle the upper limits of `n` and the values of candies efficiently.
- Consider scenarios where many kids have the same number of candies or when all kids receive the extra candies.
- Ensure the solution works within time and space constraints.
{{< dots >}}
## Code 💻
```cpp
vector<bool> kidsWithCandies(vector<int>& candies, int ext) {
    int n = candies.size();
    vector<bool> ans(n, false);
    int mx = *max_element(candies.begin(), candies.end());
    for(int i =0; i < n; i++)
        ans[i] = (candies[i]+ ext>= mx);
    return ans;
}
```

The `kidsWithCandies` function takes in a vector `candies` representing the number of candies each child has and an integer `ext` representing the extra candies. The function returns a vector of boolean values where each value indicates whether the child can have the greatest number of candies after receiving the extra candies.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<bool> kidsWithCandies(vector<int>& candies, int ext) {
	```
	Defines the function `kidsWithCandies` that takes a vector `candies` and an integer `ext` and returns a vector of booleans indicating whether each child can have the greatest number of candies after receiving the extra candies.

2. **Variable Initialization**
	```cpp
	    int n = candies.size();
	```
	Initializes the variable `n` to hold the size of the `candies` vector, representing the number of children.

3. **Vector Initialization**
	```cpp
	    vector<bool> ans(n, false);
	```
	Initializes a boolean vector `ans` of size `n` with all values set to `false`. This vector will store whether each child can have the greatest number of candies.

4. **Max Element Calculation**
	```cpp
	    int mx = *max_element(candies.begin(), candies.end());
	```
	Finds the maximum value in the `candies` vector, representing the greatest number of candies any child has.

5. **Loop Constructs**
	```cpp
	    for(int i =0; i < n; i++)
	```
	Starts a loop to iterate over each element in the `candies` vector.

6. **Condition Check**
	```cpp
	        ans[i] = (candies[i] + ext >= mx);
	```
	For each child, checks if the sum of their candies and the extra candies (`ext`) is greater than or equal to the maximum number of candies `mx`. If true, the corresponding entry in the `ans` vector is set to `true`.

7. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the `ans` vector, which contains `true` or `false` for each child, indicating whether they can have the greatest number of candies.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of kids.
- **Average Case:** O(n), as we have to iterate through all the kids.
- **Worst Case:** O(n), since we check each kid's total candies.

The time complexity is linear in the number of kids, i.e., O(n).

### Space Complexity 💾
- **Best Case:** O(n), as we store the result array.
- **Worst Case:** O(n), where n is the number of kids.

The space complexity is linear due to the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/)

---
{{< youtube xBpYKQzjjnM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
