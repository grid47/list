
+++
authors = ["grid47"]
title = "Leetcode 1664: Ways to Make a Fair Array"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1664: Ways to Make a Fair Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GS9BQo3-1mg"
youtube_upload_date="2020-11-22"
youtube_thumbnail="https://i.ytimg.com/vi/GS9BQo3-1mg/maxresdefault.jpg"
comments = true
+++



---
You are given an array `nums` of integers. You are allowed to remove one element from the array at any index. After removing the element, the remaining array is called 'fair' if the sum of the values at the odd indices is equal to the sum of the values at the even indices. The task is to find how many indices you can remove such that the resulting array is fair.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums`.
- **Example:** `nums = [3, 2, 7, 5]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of indices such that after the removal, the array becomes fair.
- **Example:** `2`
- **Constraints:**
	- The array must be fair after removing one index.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find how many indices can be removed such that the array becomes fair after removal.

- Compute the sum of the elements at even and odd indices of the original array.
- Iterate through the array and simulate removing each index, checking if the remaining array is fair.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always have at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 2, 7, 5]`  \
  **Explanation:** The two valid indices to remove are 2 and 3 where the resulting array becomes fair.

- **Input:** `nums = [4, 4, 4]`  \
  **Explanation:** Since all elements are the same, removing any element results in a fair array.

{{< dots >}}
## Approach 🚀
We will use a prefix sum approach to efficiently calculate the sum of even and odd indexed elements and check for fairness after removing each index.

### Initial Thoughts 💭
- Removing an element affects both the even and odd indexed sums. We need to track these sums while removing each element.
- We can calculate the total even and odd indexed sums first, then iteratively simulate removing each element and check if the remaining sums are equal.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one element, so we do not need to handle an empty input.
- Ensure that the solution handles arrays of size up to 10^5 efficiently.
- If all elements in the array are the same, any index removal will lead to a fair array.
- The solution must be efficient for large arrays and handle the maximum constraint sizes.
{{< dots >}}
## Code 💻
```cpp

int waysToMakeFair(vector<int>& nums) {

    vector<int> left(2, 0), right(2, 0);
    
    int n= nums.size(), res = 0;
    
    for(int i = 0; i < n; i++)
        right[i%2] += nums[i];
    
    for(int i = 0; i < n; i++) {
        right[i%2] -= nums[i];
        
        if(left[0] + right[1] == right[0] + left[1]) res++;
        
        left[i%2] += nums[i];
    }

    return res;
}
```

This function calculates the number of ways to make an array fair by removing one element. It uses prefix and suffix sums for odd and even indices to determine fairness after each removal.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int waysToMakeFair(vector<int>& nums) {
	```
	Defines the function `waysToMakeFair` which takes an integer vector `nums` and returns the number of ways the array can be made fair by removing one element.

2. **Variable Initialization**
	```cpp
	    vector<int> left(2, 0), right(2, 0);
	```
	Initializes two vectors `left` and `right` to track prefix and suffix sums for odd and even indices.

3. **Variable Initialization**
	```cpp
	    int n= nums.size(), res = 0;
	```
	Initializes `n` as the size of the input array and `res` to count the number of valid removals.

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Begins a loop to calculate the initial suffix sums for odd and even indices.

5. **Suffix Sum Calculation**
	```cpp
	        right[i%2] += nums[i];
	```
	Adds the value at index `i` to the appropriate even or odd suffix sum in the `right` vector.

6. **Loop Iteration**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop to iterate through each element, simulating its removal and updating the prefix and suffix sums.

7. **Update Suffix Sum**
	```cpp
	        right[i%2] -= nums[i];
	```
	Subtracts the current element from the appropriate even or odd suffix sum in the `right` vector to simulate its removal.

8. **Fairness Check**
	```cpp
	        if(left[0] + right[1] == right[0] + left[1]) res++;
	```
	Checks if the prefix and suffix sums for odd and even indices are equal after removing the current element. If true, increments the result counter.

9. **Update Prefix Sum**
	```cpp
	        left[i%2] += nums[i];
	```
	Adds the current element to the appropriate even or odd prefix sum in the `left` vector.

10. **Return Result**
	```cpp
	    return res;
	```
	Returns the total number of ways to make the array fair.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we process each element once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for prefix sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/ways-to-make-a-fair-array/description/)

---
{{< youtube GS9BQo3-1mg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
