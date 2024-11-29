
+++
authors = ["grid47"]
title = "Leetcode 2908: Minimum Sum of Mountain Triplets I"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2908: Minimum Sum of Mountain Triplets I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "GegaVi1CeUM"
youtube_upload_date="2023-10-22"
youtube_thumbnail="https://i.ytimg.com/vi/GegaVi1CeUM/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers called nums. A mountain triplet consists of three indices (i, j, k) such that i < j < k, nums[i] < nums[j], and nums[k] < nums[j]. Your task is to return the minimum possible sum of any such mountain triplet. If no such triplet exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array nums of length n.
- **Example:** `nums = [7, 4, 8, 5, 2]`
- **Constraints:**
	- 3 <= nums.length <= 50
	- 1 <= nums[i] <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum sum of a valid mountain triplet (i, j, k), or -1 if no such triplet exists.
- **Example:** `For the input [7, 4, 8, 5, 2], the output should be 14.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the minimum sum of a valid mountain triplet in the array.

- Iterate through the array with three pointers: one for the left part (i), one for the peak (j), and one for the right part (k).
- Check if the triplet formed by the indices (i, j, k) satisfies the mountain condition: nums[i] < nums[j] and nums[k] < nums[j].
- If the condition holds, calculate the sum of nums[i] + nums[j] + nums[k], and track the minimum sum found.
- Return the minimum sum if any valid triplet is found, or -1 if no such triplet exists.
{{< dots >}}
### Problem Assumptions ✅
- The input will always have at least three numbers.
- The solution should work for all values within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [7, 4, 8, 5, 2]`  \
  **Explanation:** In this case, the mountain triplet (1, 2, 3) is valid because 4 < 8 and 5 < 8. The sum of this triplet is 7 + 8 + 5 = 14, which is the minimum sum.

{{< dots >}}
## Approach 🚀
The approach involves brute force checking of all triplets (i, j, k) to find the smallest valid sum.

### Initial Thoughts 💭
- We need to check every combination of triplets that satisfy the mountain condition.
- A brute-force solution will work within the problem's constraints since the array size is relatively small.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least three elements.
- The solution should work efficiently within the given constraints, which are n <= 50.
- Consider the case where no valid triplet exists in the array.
- All values of nums will be between 1 and 50.
{{< dots >}}
## Code 💻
```cpp
int minimumSum(vector<int>& nums) {
    int n=nums.size();
    int ans=INT_MAX;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i] < nums[j] && nums[k] < nums[j]) ans = min(ans,nums[i]+nums[j]+nums[k]);
            }
        }
    }
    
    return (ans==INT_MAX ? -1:ans);
}
```

The `minimumSum` function finds the minimum sum of three distinct elements from the vector `nums` where the first element is smaller than the second, and the third is smaller than the second. If no such triplet exists, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumSum(vector<int>& nums) {
	```
	Defines the function `minimumSum` which takes a vector of integers `nums` and returns the minimum sum of three distinct elements satisfying the given conditions.

2. **Variable Initialization**
	```cpp
	    int n=nums.size();
	```
	Initializes `n` with the size of the input vector `nums`.

3. **Variable Initialization**
	```cpp
	    int ans=INT_MAX;
	```
	Initializes `ans` to `INT_MAX` to represent the initial state where no valid triplet has been found.

4. **Triple Nested Loop**
	```cpp
	    for(int i=0;i<n-2;i++){
	```
	Starts the outer loop, iterating through each element of the vector except the last two.

5. **Triple Nested Loop**
	```cpp
	        for(int j=i+1;j<n-1;j++){
	```
	Starts the second loop, iterating through the elements of the vector starting from the element after `i`.

6. **Triple Nested Loop**
	```cpp
	            for(int k=j+1;k<n;k++){
	```
	Starts the third loop, iterating through the elements of the vector starting from the element after `j`.

7. **Conditional Check**
	```cpp
	                if(nums[i] < nums[j] && nums[k] < nums[j]) ans = min(ans,nums[i]+nums[j]+nums[k]);
	```
	Checks if `nums[i]` is smaller than `nums[j]` and `nums[k]` is smaller than `nums[j]`, and if true, updates `ans` with the minimum sum of the triplet.

8. **Return Statement**
	```cpp
	    return (ans==INT_MAX ? -1:ans);
	```
	Returns the value of `ans`, which is either the minimum sum found or `-1` if no valid triplet exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^3)
- **Average Case:** O(n^3)
- **Worst Case:** O(n^3)

The algorithm checks every combination of triplets, which results in a cubic time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

No additional space is required apart from a few variables to track the minimum sum.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/)

---
{{< youtube GegaVi1CeUM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
