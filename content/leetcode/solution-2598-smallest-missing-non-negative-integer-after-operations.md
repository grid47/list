
+++
authors = ["grid47"]
title = "Leetcode 2598: Smallest Missing Non-negative Integer After Operations"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2598: Smallest Missing Non-negative Integer After Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NztQwlNn1XA"
youtube_upload_date="2023-03-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/NztQwlNn1XA/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums` and a positive integer `value`. In one operation, you can either add or subtract the integer `value` from any element of the array `nums`. The MEX (Minimum Excluded Value) of an array is the smallest non-negative integer that does not appear in the array. Your task is to determine the maximum possible MEX of the array `nums` after performing the mentioned operations any number of times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and an integer `value`.
- **Example:** `For `nums = [3, -10, 9, 15, 8]` and `value = 4`.`
- **Constraints:**
	- 1 <= nums.length, value <= 10^5
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible MEX of the array `nums` after applying the allowed operations.
- **Example:** `For `nums = [3, -10, 9, 15, 8]` and `value = 4`, the output should be `5`.`
- **Constraints:**
	- The result will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to apply the allowed operations to maximize the MEX of the array `nums`.

- 1. For each element in `nums`, calculate the possible new values after adding or subtracting `value` any number of times.
- 2. Track the occurrences of all numbers after the operations.
- 3. Find the smallest non-negative integer not present in the array to determine the MEX.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` contains integers between -10^9 and 10^9.
- The value of `value` is always a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [3, -10, 9, 15, 8]` and `value = 4``  \
  **Explanation:** By applying the operations as described, you can achieve a maximum MEX of 5.

- **Input:** `For `nums = [1, -15, 5, 14, 7]` and `value = 5``  \
  **Explanation:** After applying the allowed operations, the maximum MEX of the array is 3.

{{< dots >}}
## Approach 🚀
The approach involves tracking the possible new values after applying the allowed operations and determining the MEX of the array.

### Initial Thoughts 💭
- The operation can add or subtract `value` multiple times.
- The number of possible distinct numbers in the array will be limited by the size of the array and the value of `value`.
- Efficiently track which numbers are present in the modified array.
{{< dots >}}
### Edge Cases 🌐
- The array will always contain at least one element as per the problem constraints.
- The solution should handle large arrays efficiently, with `nums.length` up to 10^5.
- If `value` is large relative to the elements in `nums`, fewer operations may be needed.
- Handle negative and large positive values in `nums` efficiently.
{{< dots >}}
## Code 💻
```cpp
int findSmallestInteger(vector<int>& nums, int value) {
    map<int, int> mp;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        mp[(nums[i] < 0? (nums[i] % value + value)%value: nums[i]%value)]++;
    }
    int idx = 0, mn = INT_MAX;
    for(int i = 0; i < value; i++) {
        if(mp[i] < mn) {
            idx = i;
            mn = mp[i];
        }
    }
    return mn * value + idx;
}
```

This function finds the smallest integer that can be formed by adjusting the values in the input vector 'nums' based on a modular operation with 'value'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findSmallestInteger(vector<int>& nums, int value) {
	```
	Defines the function 'findSmallestInteger' that takes an array of integers 'nums' and an integer 'value' as inputs.

2. **Variable Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes a map 'mp' that will be used to count the occurrences of the modular results of the elements in 'nums'.

3. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculates the size of the 'nums' vector and stores it in the variable 'n'.

4. **Loop to Populate Map**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates over each element in the 'nums' vector.

5. **Map Update**
	```cpp
	        mp[(nums[i] < 0? (nums[i] % value + value)%value: nums[i]%value)]++;
	```
	Calculates the modular value of each element in 'nums' (adjusting for negative values) and increments its count in the map 'mp'.

6. **Variable Initialization**
	```cpp
	    int idx = 0, mn = INT_MAX;
	```
	Initializes two variables, 'idx' to 0 and 'mn' to the maximum possible integer value, to track the smallest count and its index.

7. **Loop to Find Minimum**
	```cpp
	    for(int i = 0; i < value; i++) {
	```
	Iterates over the possible modular values (from 0 to value-1).

8. **Condition to Update Min**
	```cpp
	        if(mp[i] < mn) {
	```
	Checks if the count for the current modular value is less than the current minimum count.

9. **Update Min Index**
	```cpp
	            idx = i;
	```
	Updates the index 'idx' to the current modular value if it has a smaller count.

10. **Update Min Count**
	```cpp
	            mn = mp[i];
	```
	Updates the minimum count 'mn' to the count of the current modular value.

11. **Return Result**
	```cpp
	    return mn * value + idx;
	```
	Returns the smallest integer formed by multiplying the minimum count 'mn' by the 'value' and adding the index 'idx'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the size of the array `nums`.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is proportional to the number of elements in `nums`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/)

---
{{< youtube NztQwlNn1XA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
