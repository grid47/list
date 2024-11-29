
+++
authors = ["grid47"]
title = "Leetcode 456: 132 Pattern"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 456: 132 Pattern in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Stack","Monotonic Stack","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/456.webp"
youtube = "TfgWauHLuRE"
youtube_upload_date="2023-09-30"
youtube_thumbnail="https://i.ytimg.com/vi/TfgWauHLuRE/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/456.webp" 
    alt="A sequence of numbers where the 132 pattern lights up, showing the correct order and placement of elements."
    caption="Solution to LeetCode 456: 132 Pattern Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers, determine if there exists a subsequence of three integers nums[i], nums[j], nums[k] where i < j < k and nums[i] < nums[k] < nums[j]. Return true if such a subsequence exists, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of integers.
- **Example:** `nums = [4, 1, 5, 3]`
- **Constraints:**
	- 1 <= n <= 2 * 10^5
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean indicating whether a 132 subsequence exists in the array.
- **Example:** `Output: true`
- **Constraints:**
	- The result should be a boolean indicating whether the pattern exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check for the existence of a subsequence that satisfies the condition nums[i] < nums[k] < nums[j].

- 1. Iterate through the array from right to left, keeping track of a potential 132 pattern.
- 2. Use a stack to keep track of numbers and find a valid pattern by checking if nums[i] < nums[k] < nums[j].
{{< dots >}}
### Problem Assumptions ✅
- The input array is not empty.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3, 4]`  \
  **Explanation:** No valid subsequence exists because the elements are in increasing order, which doesn't form a 132 pattern.

- **Input:** `nums = [6, 3, 4, 1]`  \
  **Explanation:** A valid 132 pattern exists in the subsequence [3, 4, 1], where 3 < 1 < 4.

{{< dots >}}
## Approach 🚀
We can use a stack to efficiently check if a valid 132 subsequence exists, iterating through the array from right to left.

### Initial Thoughts 💭
- We need to check for the pattern nums[i] < nums[k] < nums[j] efficiently.
- The stack can help by maintaining the potential nums[k] and allowing quick comparisons for nums[i].
{{< dots >}}
### Edge Cases 🌐
- If the array has less than 3 elements, the answer is false.
- Handle large arrays efficiently, making sure the solution scales with input size up to 2 * 10^5.
- Arrays with only increasing or decreasing values should return false.
- Ensure the solution runs in O(n) time for large inputs.
{{< dots >}}
## Code 💻
```cpp
bool find132pattern(vector<int>& nums) {
    
    int n = nums.size();
    int prv = INT_MIN;
    stack<int> stk;
    
    for(int i = n - 1; i >= 0; i--) {

        if (nums[i] < prv) return true;

        while(!stk.empty() && nums[i] > stk.top()) {

            prv = stk.top();
            stk.pop();

        }

        stk.push(nums[i]);
    }

    return false;
}
```

The `find132pattern` function checks if there is a subsequence in the array `nums` that follows the pattern 132, meaning that there exists three indices `i < j < k` such that `nums[i] < nums[k] < nums[j]`. It uses a stack to efficiently track potential values for the 132 pattern in a single pass through the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool find132pattern(vector<int>& nums) {
	```
	Defines the `find132pattern` function that takes a vector `nums` and returns a boolean indicating whether a 132 pattern exists in the array.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes variable `n` to store the size of the input array `nums`.

3. **Variable Initialization**
	```cpp
	    int prv = INT_MIN;
	```
	Initializes the variable `prv` to `INT_MIN`, which will be used to store the potential third element of the 132 pattern.

4. **Data Structure Initialization**
	```cpp
	    stack<int> stk;
	```
	Initializes a stack `stk` to help track the second element of the 132 pattern and assist in checking the 132 pattern.

5. **Loop**
	```cpp
	    for(int i = n - 1; i >= 0; i--) {
	```
	Starts a loop that iterates over the array `nums` from the last element to the first, checking potential 132 patterns in reverse.

6. **Pattern Check**
	```cpp
	        if (nums[i] < prv) return true;
	```
	Checks if the current element `nums[i]` is smaller than `prv` (which represents the third element of the pattern). If true, a 132 pattern is found and the function returns `true`.

7. **While Loop**
	```cpp
	        while(!stk.empty() && nums[i] > stk.top()) {
	```
	Enters a while loop to pop elements from the stack `stk` as long as the current element `nums[i]` is larger than the top of the stack, updating `prv` to the popped values.

8. **Stack Operations**
	```cpp
	            prv = stk.top();
	```
	Updates the value of `prv` to the top element of the stack, representing the second element of a potential 132 pattern.

9. **Stack Operations**
	```cpp
	            stk.pop();
	```
	Pops the top element from the stack, as it can no longer be part of a valid 132 pattern with the current element `nums[i]`.

10. **Stack Push**
	```cpp
	        }
	```
	Ends the while loop. All elements in the stack that are smaller than `nums[i]` have been removed.

11. **Stack Operations**
	```cpp
	        stk.push(nums[i]);
	```
	Pushes the current element `nums[i]` onto the stack, which may be used as a potential second element in a future 132 pattern.

12. **Return Statement**
	```cpp
	    return false;
	```
	Returns `false` if no 132 pattern was found after checking all elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate over the array once and perform constant-time stack operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the stack, which stores up to n elements in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/132-pattern/description/)

---
{{< youtube TfgWauHLuRE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
