
+++
authors = ["grid47"]
title = "Leetcode 1: Two Sum"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1: Two Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/1.webp"
youtube = "Yyyi12oaK94"
youtube_upload_date="2022-08-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Yyyi12oaK94/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/1.webp" 
    alt="A pair of floating, glowing puzzle pieces coming together in a soft light."
    caption="Solution to LeetCode 1: Two Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers `nums` and a target integer `target`, find and return the indices of two distinct numbers in the array that sum up to the given target. The solution is guaranteed to exist for the given input. You can return the indices in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers and a target integer.
- **Example:** `nums = [1, 5, 7, 3], target = 8`
- **Constraints:**
	- 2 <= nums.length <= 10^4
	- -10^9 <= nums[i] <= 10^9
	- -10^9 <= target <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the indices of two numbers that add up to the target as an array of integers.
- **Example:** `[0, 2]`
- **Constraints:**
	- The indices returned should be valid for the given input array.
	- The two numbers must be distinct elements of the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the indices of two numbers that sum up to the given target.

- Iterate through the array while maintaining a mapping of the difference between the target and each number to its index.
- For each number, check if it exists in the map. If it does, return its index and the current index.
- If no pair is found during the iteration, return an error (though the problem guarantees a solution).
{{< dots >}}
### Problem Assumptions ✅
- All inputs are valid.
- There will always be exactly one solution.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 5, 7, 3], target = 8`  \
  **Explanation:** The numbers at indices 0 and 2 (1 and 7) sum to 8, so the output is [0, 2].

- **Input:** `nums = [4, 6, 10], target = 16`  \
  **Explanation:** The numbers at indices 1 and 2 (6 and 10) sum to 16, so the output is [1, 2].

- **Input:** `nums = [2, 8, 12], target = 10`  \
  **Explanation:** The numbers at indices 0 and 1 (2 and 8) sum to 10, so the output is [0, 1].

{{< dots >}}
## Approach 🚀
We use a hashmap to track the complement of each number as we iterate through the array.

### Initial Thoughts 💭
- Finding a pair of numbers that sum to the target is efficient with a hashmap.
- Each number's complement can be stored as we iterate through the array.
- If a number's complement exists in the hashmap, the pair has been found.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least two elements.
- The algorithm will efficiently handle arrays with up to 10^4 elements.
- Handles negative numbers, zeros, and large integers.
- There will always be a unique solution.
{{< dots >}}
## Code 💻
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(nums[i])) {
            return { mp[nums[i]], i };
        } else {
            mp[target - nums[i]] = i;
        }
    }
    return {-1, -1};
}
```

This code efficiently finds two numbers in an array that add up to a target sum. It utilizes a hash map to store numbers and their indices for quick lookup. If a complement is found, the function returns the indices of the pair. Otherwise, it continues iterating and updating the hash map.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> twoSum(vector<int>& nums, int target) {
	```
	Declares a function named `twoSum` that takes an integer vector `nums` and a target integer as input and returns a vector of two integers.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes an empty hash map `mp` to store numbers and their corresponding indices.

3. **Loop Initialization and Condition**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop to iterate over each number in the `nums` vector.

4. **Conditional Check**
	```cpp
	        if(mp.count(nums[i])) {
	```
	Checks if the current number's complement (target - current number) exists in the map.

5. **Return Result**
	```cpp
	            return { mp[nums[i]], i };
	```
	If the complement exists, returns a pair of indices: the index of the complement and the current index.

6. **Else Condition**
	```cpp
	        } else {
	```
	If the complement is not found, stores the current number and its index in the map.

7. **Map Insertion**
	```cpp
	            mp[target - nums[i]] = i;
	```
	Stores the current number's complement as the key and its index as the value in the map.

8. **Return Default Value**
	```cpp
	    return {-1, -1};
	```
	If no pair is found after iterating through the entire array, returns an empty pair to indicate no solution.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm iterates through the array once and performs constant-time operations for each element.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

Space is used to store the hashmap, which can grow linearly with the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/two-sum/description/)

---
{{< youtube Yyyi12oaK94 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
