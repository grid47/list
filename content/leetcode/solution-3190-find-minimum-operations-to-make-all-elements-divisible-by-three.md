
+++
authors = ["grid47"]
title = "Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three"
date = "2023-12-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "b-UBMai1bGM"
youtube_upload_date="2024-06-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b-UBMai1bGM/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers `nums`. In each operation, you can either add or subtract 1 from any element in `nums`. Your task is to determine the minimum number of operations required to make all elements of `nums` divisible by 3.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` containing `n` elements.
- **Example:** `Example 1:
Input: nums = [2, 5, 8, 11]
Output: 6
Explanation: You need 6 operations to make each number divisible by 3: subtract 1 from 2, subtract 1 from 5, subtract 1 from 8, and subtract 1 from 11.`
- **Constraints:**
	- 1 <= nums.length <= 50
	- 1 <= nums[i] <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations to make all elements of `nums` divisible by 3.
- **Example:** `Example 2:
Input: nums = [3, 6, 9]
Output: 0
Explanation: All numbers are already divisible by 3, so no operations are needed.`
- **Constraints:**
	- The result is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum number of operations to make each number divisible by 3.

- For each element in the array, calculate the remainder when divided by 3 (i.e., `num % 3`).
- If the remainder is 1, one operation is needed to either add or subtract 1 to make the number divisible by 3.
- If the remainder is 2, two operations are needed (either subtract 2 or add 1).
- Sum all the operations for the entire array and return the total.
{{< dots >}}
### Problem Assumptions ✅
- All array elements are between 1 and 50.
- The minimum number of operations will be calculated based on how much each element deviates from being divisible by 3.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For `nums = [2, 5, 8, 11]`, the remainders when divided by 3 are [2, 2, 2, 2]. Each element needs 2 operations (subtracting 1) to become divisible by 3. Therefore, the total number of operations is 2 + 2 + 2 + 2 = 8.

- **Input:** `Example 2:`  \
  **Explanation:** For `nums = [3, 6, 9]`, all elements are already divisible by 3. Thus, no operations are needed, and the result is 0.

{{< dots >}}
## Approach 🚀
The solution can be efficiently implemented by iterating through the array, calculating the remainder of each element when divided by 3, and applying the necessary number of operations based on the remainder.

### Initial Thoughts 💭
- The remainder of each number when divided by 3 determines how many operations are required to make it divisible by 3.
- A straightforward approach will be to iterate over the array, sum up the required operations for each number, and return the total.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs in this problem, as `nums.length >= 1`.
- The approach should handle the maximum input size efficiently.
- When all elements are already divisible by 3 (i.e., when `nums[i] % 3 == 0`), no operations are needed.
- The solution must work for arrays of size up to 50 and for numbers between 1 and 50.
{{< dots >}}
## Code 💻
```cpp
int minimumOperations(vector<int>& nums) {
    int ans = 0;
    for(int i=0;i<nums.size();i++) ans+=min(3-(nums[i]%3),nums[i]%3);
    return ans;
}
```

The function `minimumOperations` calculates the minimum number of operations required to make all elements of the array divisible by 3. For each element, it finds the minimum operations needed to make it divisible by 3, either by adding or subtracting a small value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumOperations(vector<int>& nums) {
	```
	The function `minimumOperations` is defined, taking a reference to a vector of integers `nums` as its parameter.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	The variable `ans` is initialized to `0` to store the total number of operations.

3. **Loop Start**
	```cpp
	    for(int i=0;i<nums.size();i++) ans+=min(3-(nums[i]%3),nums[i]%3);
	```
	A loop iterates over the elements of `nums`. For each element, the number of operations required to make it divisible by 3 is calculated and added to `ans`. The minimum between adding the difference to 3 or subtracting the element's remainder when divided by 3 is considered.

4. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the total number of operations stored in `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array `nums`. We perform a constant-time operation for each element in the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a few variables to track the total number of operations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/)

---
{{< youtube b-UBMai1bGM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
