
+++
authors = ["grid47"]
title = "Leetcode 287: Find the Duplicate Number"
date = "2024-10-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 287: Find the Duplicate Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/287.webp"
youtube = "P5Knc5OmL2o"
youtube_upload_date="2023-09-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/P5Knc5OmL2o/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/287.webp" 
    alt="A series of numbers, with the duplicate gently glowing and standing out from the rest."
    caption="Solution to LeetCode 287: Find the Duplicate Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array `nums` of `n + 1` integers where each integer is in the range [1, n]. The array contains exactly one duplicate number. Find and return this duplicate number without modifying the array and using constant extra space.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array `nums` containing `n + 1` integers. Each element is between 1 and `n` (inclusive).
- **Example:** `For example, `nums = [1, 2, 3, 4, 2]`.`
- **Constraints:**
	- 1 <= n <= 10^5
	- nums.length == n + 1
	- 1 <= nums[i] <= n
	- All integers in `nums` appear only once except for one duplicate number.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the duplicate number found in the array.
- **Example:** `For `nums = [1, 2, 3, 4, 2]`, the output should be `2`.`
- **Constraints:**
	- The solution must be performed without modifying the array and using constant extra space.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the duplicate number in the array using the given constraints.

- We will use a cycle detection approach (Floyd's Tortoise and Hare algorithm) to detect the duplicate number.
- Initialize two pointers `slow` and `fast`. The slow pointer moves one step at a time, while the fast pointer moves two steps.
- When both pointers meet, we reset one pointer to the start and move both pointers one step at a time until they meet again. The meeting point will be the duplicate number.
{{< dots >}}
### Problem Assumptions ✅
- There is exactly one duplicate number in the array.
- The input array meets the constraints of having `n + 1` elements, with values between 1 and `n`.
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [1, 2, 3, 4, 2]``  \
  **Explanation:** The duplicate number in the array is `2`, as it appears twice.

- **Input:** `For `nums = [5, 1, 3, 4, 5]``  \
  **Explanation:** The duplicate number in the array is `5`, as it appears twice.

- **Input:** `For `nums = [6, 6, 6, 6, 6]``  \
  **Explanation:** All the numbers in the array are the same, and the duplicate number is `6`.

{{< dots >}}
## Approach 🚀
We can use Floyd's Tortoise and Hare algorithm (cycle detection) to detect the duplicate number in the array in linear time and constant space.

### Initial Thoughts 💭
- The problem can be reduced to finding a cycle in a linked list.
- Using two pointers at different speeds, we can detect a cycle and determine the duplicate number.
{{< dots >}}
### Edge Cases 🌐
- An empty array will not be provided based on the problem constraints.
- The solution should be able to handle large arrays with up to 100,000 elements.
- The array may contain all elements equal, in which case the duplicate will be the only number in the array.
- The solution must meet the constraints of constant extra space and linear runtime complexity.
{{< dots >}}
## Code 💻
```cpp
int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[nums[0]];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = 0;
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}
```

This function uses the Floyd's Tortoise and Hare algorithm to detect a duplicate number in an array where each number is between 1 and n-1 and appears at least once.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findDuplicate(vector<int>& nums) {
	```
	Defines the function `findDuplicate`, which accepts a reference to a vector `nums` and finds the duplicate number using Floyd's Cycle-Finding Algorithm.

2. **Initialize Slow and Fast Pointers**
	```cpp
	    int slow = nums[0], fast = nums[nums[0]];
	```
	Initializes two pointers: `slow` and `fast`. `slow` moves one step at a time, while `fast` moves two steps at a time.

3. **Cycle Detection Loop**
	```cpp
	    while(slow != fast) {
	```
	Starts a loop to detect if there is a cycle. The loop continues until the slow and fast pointers meet.

4. **Move Slow Pointer**
	```cpp
	        slow = nums[slow];
	```
	Moves the `slow` pointer one step ahead in the array.

5. **Move Fast Pointer**
	```cpp
	        fast = nums[nums[fast]];
	```
	Moves the `fast` pointer two steps ahead by accessing the element at `nums[fast]` and then moving to `nums[nums[fast]]`.

6. **Reinitialize Fast Pointer**
	```cpp
	    fast = 0;
	```
	Reinitializes the `fast` pointer to the beginning of the array to find the entrance to the cycle.

7. **Start Second Loop**
	```cpp
	    while(slow != fast) {
	```
	Starts a second loop to find the starting point of the cycle, which is where the duplicate number lies.

8. **Move Slow Pointer Again**
	```cpp
	        slow = nums[slow];
	```
	Moves the `slow` pointer one step ahead.

9. **Move Fast Pointer Again**
	```cpp
	        fast = nums[fast];
	```
	Moves the `fast` pointer one step ahead.

10. **Return Duplicate Number**
	```cpp
	    return fast;
	```
	Returns the `fast` pointer, which now points to the duplicate number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the array a constant number of times.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we are only using two pointers, regardless of the array size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-duplicate-number/description/)

---
{{< youtube P5Knc5OmL2o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
