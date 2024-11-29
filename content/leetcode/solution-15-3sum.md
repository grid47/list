
+++
authors = ["grid47"]
title = "Leetcode 15: 3Sum"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 15: 3Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/15.webp"
youtube = "8IjCNFIo8YI"
youtube_upload_date="2024-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8IjCNFIo8YI/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/15.webp" 
    alt="Three circles of light coming together in harmony, overlapping in a gentle glow."
    caption="Solution to LeetCode 15: 3Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array nums, find all unique triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. The solution set must not contain duplicate triplets.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers nums.
- **Example:** `nums = [-2, 0, 2, 1, -1, -3]`
- **Constraints:**
	- 3 <= nums.length <= 3000
	- -10^5 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of all unique triplets such that their sum is zero.
- **Example:** `[[-3, 1, 2], [-2, 0, 2]]`
- **Constraints:**
	- The triplets should be unique and not repeated in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find all unique triplets that sum to zero.

- Sort the input array.
- Iterate over the array using the first element as the fixed one and use a two-pointer technique for the remaining part of the array.
- Avoid duplicates by skipping the same elements while iterating over the array.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least three elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [-2, 0, 2, 1, -1, -3]`  \
  **Explanation:** The valid triplets are [-3, 1, 2] and [-2, 0, 2], as both sum to zero.

- **Input:** `nums = [0, 2, 3, 1]`  \
  **Explanation:** No valid triplets exist as no combination sums to zero.

- **Input:** `nums = [-1, 0, 1, -1, 2, 0]`  \
  **Explanation:** The valid triplets are [-1, 0, 1], [-1, -1, 2], and [0, 0, 0], all of which sum to zero.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves sorting the array first and then using a two-pointer technique to find triplets that sum to zero.

### Initial Thoughts 💭
- Sorting helps in efficiently finding the triplets using the two-pointer technique.
- Duplicates can be avoided by skipping over equal elements while iterating.
- The problem is a variation of the 3-sum problem that can be solved in O(n^2) time.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least 3 elements, as stated in the problem constraints.
- The solution should efficiently handle up to 3000 elements in the input array.
- The array may contain duplicate elements, which should be handled to ensure unique triplets.
- The solution should avoid adding duplicate triplets.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
        int target = -nums[i];
        int s = i + 1;
        int e = nums.size() - 1;
        while(s < e) {
            if(nums[s] + nums[e] < target) {
               s++;
            } else if (nums[s] + nums[e] > target) {
                e--;
            } else {
                vector<int> res = {nums[i], nums[s], nums[e]};
                ans.push_back(res);
                while(s < e && nums[s] == res[1]) s++;
                while(s < e && res[2] == nums[e]) e--;                    
            }
        }
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    }
    return ans;
}
```

This code implements the `threeSum` function, which finds all unique triplets in the array `nums` that add up to zero.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> threeSum(vector<int>& nums) {
	```
	Declare the `threeSum` function, which takes a vector of integers `nums` as input and returns a vector of vectors representing the unique triplets.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	Initialize an empty vector `ans` to store the triplets.

3. **Sorting Operations**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the `nums` vector in ascending order.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Start a loop to iterate through each element `nums[i]` in the sorted array.

5. **Variable Initialization**
	```cpp
	        int target = -nums[i];
	```
	Calculate the target sum for the remaining two numbers: `target = -nums[i]`.

6. **Variable Initialization**
	```cpp
	        int s = i + 1;
	```
	Initialize two pointers `s` and `e` to point to the elements after `nums[i]`. `s` will move from the left, and `e` will move from the right.

7. **Variable Initialization**
	```cpp
	        int e = nums.size() - 1;
	```
	Initialize `e` to point to the last element of the array.

8. **Loop Iteration**
	```cpp
	        while(s < e) {
	```
	Start a two-pointer loop to find pairs of numbers that add up to the `target`.

9. **Conditional Check**
	```cpp
	            if(nums[s] + nums[e] < target) {
	```
	If the sum of `nums[s]` and `nums[e]` is less than the `target`, move `s` to the right to increase the sum.

10. **Index Update**
	```cpp
	               s++;
	```
	Increment `s` to consider the next larger number.

11. **Conditional Check**
	```cpp
	            } else if (nums[s] + nums[e] > target) {
	```
	If the sum of `nums[s]` and `nums[e]` is greater than the `target`, move `e` to the left to decrease the sum.

12. **Index Update**
	```cpp
	                e--;
	```
	Decrement `e` to consider the next smaller number.

13. **Conditional Check**
	```cpp
	            } else {
	```
	If the sum is equal to the `target`, a triplet is found.

14. **Array Manipulation**
	```cpp
	                vector<int> res = {nums[i], nums[s], nums[e]};
	```
	Create a new vector `res` to store the triplet.

15. **Array Manipulation**
	```cpp
	                ans.push_back(res);
	```
	Add the triplet `res` to the `ans` vector.

16. **Loop Iteration**
	```cpp
	                while(s < e && nums[s] == res[1]) s++;
	```
	Skip duplicate elements at `s` to avoid redundant triplets.

17. **Loop Iteration**
	```cpp
	                while(s < e && res[2] == nums[e]) e--;                    
	```
	Skip duplicate elements at `e` to avoid redundant triplets.

18. **Loop Iteration**
	```cpp
	        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
	```
	Skip duplicate elements at the current position `i` to avoid redundant triplets.

19. **Return Value**
	```cpp
	    return ans;
	```
	Return the vector `ans` containing all unique triplets.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we iterate through the array and use a two-pointer technique to find valid triplets.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a few pointers and do not use any additional data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/3sum/description/)

---
{{< youtube 8IjCNFIo8YI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
