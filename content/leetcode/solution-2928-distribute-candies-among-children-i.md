
+++
authors = ["grid47"]
title = "Leetcode 2928: Distribute Candies Among Children I"
date = "2024-01-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2928: Distribute Candies Among Children I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Combinatorics","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hVNcZKh8r40"
youtube_upload_date="2023-11-14"
youtube_thumbnail="https://i.ytimg.com/vi/hVNcZKh8r40/maxresdefault.jpg"
comments = true
+++



---
You are given two positive integers, 'n' (number of candies) and 'limit' (maximum number of candies each child can receive). Your task is to calculate how many different ways you can distribute 'n' candies among 3 children such that no child receives more than 'limit' candies.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers: 'n' representing the total number of candies and 'limit' representing the maximum number of candies any child can receive.
- **Example:** `For n = 4 and limit = 2, the result will be 10.`
- **Constraints:**
	- 1 <= n <= 50
	- 1 <= limit <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of valid ways to distribute the candies among the children such that no child receives more than 'limit' candies.
- **Example:** `For n = 3 and limit = 3, the output will be 10.`
- **Constraints:**
	- The result will be a positive integer or zero, depending on the number of valid distributions.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all valid distributions of 'n' candies among 3 children such that no child gets more than 'limit' candies.

- Iterate through all possible distributions of candies among the 3 children (i, j, k) where i + j + k = n.
- For each combination, check if i, j, and k are within the limit specified.
- Count all valid combinations and return the total.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that n and limit are both positive integers within the specified ranges.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: n = 5, limit = 2`  \
  **Explanation:** In this case, we are distributing 5 candies among 3 children, and no child can receive more than 2 candies. The valid distributions are: (1, 2, 2), (2, 1, 2), and (2, 2, 1), making the total number of ways = 3.

- **Input:** `Example 2: n = 4, limit = 2`  \
  **Explanation:** Here, we are distributing 4 candies among 3 children, where no child can receive more than 2 candies. The valid distributions are: (2, 1, 1), (1, 2, 1), (1, 1, 2), and permutations, which give a total of 10 ways.

{{< dots >}}
## Approach 🚀
The task is to calculate how many ways we can distribute the candies among 3 children while respecting the limit condition.

### Initial Thoughts 💭
- This is a problem that can be solved by brute force by checking all possible combinations of candies for the three children.
- Since the total number of candies 'n' and the limit are both small, checking each combination is computationally feasible.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that n and limit are both positive integers, so no need to handle empty inputs.
- The problem constraints ensure that 'n' and 'limit' are small, so large inputs do not need to be considered.
- When n = 1, there is only one way to distribute 1 candy among the three children: (1, 0, 0), and permutations.
- The approach should handle edge cases like when n equals limit or when there is only one possible distribution.
{{< dots >}}
## Code 💻
```cpp
int distributeCandies(int n, int limit) {
    int res = 0;
    for(int i = 0; i <= limit; ++i){
        for(int j = 0; j <= limit; ++j){
            for(int k = 0; k <= limit; ++k){
                if(i + j + k == n) { res++; }
            }
        }
    }
    return res;
}
```

This function calculates how many ways 'n' candies can be distributed to three people such that no person receives more than 'limit' candies. The function uses a brute-force approach with three nested loops to check all possible distributions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int distributeCandies(int n, int limit) {
	```
	Defines the function 'distributeCandies' which takes in two parameters: the total number of candies 'n' and the maximum limit 'limit' for each person.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes a variable 'res' to store the number of valid distributions where the sum of candies given to three people equals 'n'. Initially, it's set to 0.

3. **First Loop**
	```cpp
	    for(int i = 0; i <= limit; ++i){
	```
	Starts the first loop over 'i', representing the number of candies given to the first person. The loop iterates from 0 to 'limit' candies.

4. **Second Loop**
	```cpp
	        for(int j = 0; j <= limit; ++j){
	```
	Starts the second loop over 'j', representing the number of candies given to the second person. This loop also iterates from 0 to 'limit'.

5. **Third Loop**
	```cpp
	            for(int k = 0; k <= limit; ++k){
	```
	Starts the third loop over 'k', representing the number of candies given to the third person. Like the other loops, it iterates from 0 to 'limit'.

6. **Condition Check**
	```cpp
	                if(i + j + k == n) { res++; }
	```
	Checks if the total number of candies given to the three people (i + j + k) equals 'n'. If so, increments 'res' to count this valid distribution.

7. **Return Result**
	```cpp
	    return res;
	```
	Returns the total count of valid distributions stored in 'res'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is quadratic in nature due to the nested loops for iterating through possible candy distributions.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we only need a few variables to keep track of the counts and limits.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/distribute-candies-among-children-i/description/)

---
{{< youtube hVNcZKh8r40 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
