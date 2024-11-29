
+++
authors = ["grid47"]
title = "Leetcode 2202: Maximize the Topmost Element After K Moves"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2202: Maximize the Topmost Element After K Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ViliZpbLtbE"
youtube_upload_date="2022-03-13"
youtube_thumbnail="https://i.ytimg.com/vi/ViliZpbLtbE/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `nums` representing a pile, where `nums[0]` is the topmost element. You can perform the following operations in exactly `k` moves:

1. Remove the topmost element of the pile (if it's not empty).
2. If any elements have been removed, you can add any one of them back onto the pile as the new topmost element.

Your goal is to determine the maximum value that can be at the top of the pile after exactly `k` moves. If it is not possible to have any elements left in the pile after `k` moves, return `-1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two inputs: `nums`, a list of integers representing the pile, and `k`, the number of moves you are allowed to make.
- **Example:** `Input: nums = [3, 1, 4, 6, 2], k = 4`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i], k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** You must return the maximum value that can be at the top of the pile after exactly `k` moves. If it is not possible to have any elements left in the pile after `k` moves, return -1.
- **Example:** `Output: 6`
- **Constraints:**
	- If `k` is less than the number of elements in the pile, it's possible to remove and add elements back.
	- If `k` is greater than or equal to the size of the pile and the pile becomes empty, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the maximum value that can be on top of the pile after exactly `k` moves.

- 1. If `k` is 0, return the first element of `nums` if it's not empty.
- 2. If `k` is 1 and the pile has only one element, return -1 since it will be removed.
- 3. For other cases, check the elements that can be accessed by performing the `k` moves and return the maximum among them.
{{< dots >}}
### Problem Assumptions ✅
- It is guaranteed that `nums` is a valid list of integers with at least one element.
- You are required to make exactly `k` moves, no more or less.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, after performing the four moves (removing the first three elements and then adding 6 back onto the pile), the largest element on top of the pile is 6.

- **Input:** `Example 2`  \
  **Explanation:** In this case, the only element in the pile is removed, and thus, no elements are left to add back, resulting in -1.

{{< dots >}}
## Approach 🚀
The strategy involves simulating the sequence of operations based on the value of `k`. Depending on the number of moves allowed, we calculate which element can be placed at the top after performing the moves.

### Initial Thoughts 💭
- When `k` is less than the number of elements in the pile, it's possible to remove elements and potentially add them back.
- If `k` exceeds the number of elements in the pile, the pile will become empty after `k` moves, and the answer will be -1.
- We should identify the maximum value that can remain at the top based on the number of moves left.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is empty, return -1.
- If the input size is large (up to 10^5 elements), ensure the solution is efficient.
- If `k` is 0, we return the topmost element without performing any operations.
- Ensure that the solution respects the constraints on `nums.length` and `k`.
{{< dots >}}
## Code 💻
```cpp
int maximumTop(vector<int>& nums, int k) {

    int ans = 0;
    
    int n = nums.size();
    
    if (k == 0) return (n >= 1) ? nums[0] : -1;
    if (k == 1) return (n == 1) ? -1 : nums[1];
    if (n == 1) return (k % 2 == 1) ? -1 : nums[0];
    
    int mx = *max_element(begin(nums), begin(nums) + min(n, k - 1));
    if(k < n) mx = max(mx, nums[k]);
    
    return mx;
}
```

This function aims to find the maximum possible number after performing at most 'k' operations. The operations involve removing the first element in the array, so the task is to maximize the top number after performing these operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumTop(vector<int>& nums, int k) {
	```
	This line defines the function 'maximumTop' which takes a vector 'nums' and an integer 'k' as input parameters. The function aims to return the maximum possible number after performing at most 'k' operations on the input array.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	This line initializes the variable 'ans' which will hold the result of the maximum number after 'k' operations.

3. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	This line stores the size of the vector 'nums' in the variable 'n', which is used to determine the bounds of the input array.

4. **Edge Case Check**
	```cpp
	    if (k == 0) return (n >= 1) ? nums[0] : -1;
	```
	This checks if 'k' is 0, meaning no operations are allowed. It then returns the first element of the array if there is at least one element; otherwise, it returns -1.

5. **Edge Case Check**
	```cpp
	    if (k == 1) return (n == 1) ? -1 : nums[1];
	```
	This checks if 'k' is 1, meaning only one operation is allowed. It returns -1 if there's only one element in the array; otherwise, it returns the second element.

6. **Edge Case Check**
	```cpp
	    if (n == 1) return (k % 2 == 1) ? -1 : nums[0];
	```
	This checks if there's only one element in the array. If 'k' is odd, it returns -1, otherwise it returns the first element.

7. **Main Logic**
	```cpp
	    int mx = *max_element(begin(nums), begin(nums) + min(n, k - 1));
	```
	This line calculates the maximum value in the first 'k-1' elements of the vector 'nums', ensuring that the index does not exceed the size of the array.

8. **Main Logic**
	```cpp
	    if(k < n) mx = max(mx, nums[k]);
	```
	This checks if 'k' is less than the size of the array. If true, it compares the current maximum with the element at index 'k' and updates the maximum value.

9. **Return Statement**
	```cpp
	    return mx;
	```
	This returns the maximum value found during the algorithm.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the number of elements in `nums` because we check a subset of the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we do not require extra space apart from variables used to store the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/description/)

---
{{< youtube ViliZpbLtbE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
