
+++
authors = ["grid47"]
title = "Leetcode 645: Set Mismatch"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 645: Set Mismatch in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/645.webp"
youtube = "d-ulaeRBA64"
youtube_upload_date="2024-01-22"
youtube_thumbnail="https://i.ytimg.com/vi/d-ulaeRBA64/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/645.webp" 
    alt="Two sets where the mismatch is found and highlighted, with each mismatched element glowing softly."
    caption="Solution to LeetCode 645: Set Mismatch Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a list of integers that should originally represent all numbers from 1 to n. However, one number appears twice and another number is missing. Your task is to find the number that is duplicated and the one that is missing.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers, nums, where each element is between 1 and n. The list has n elements, but one of the numbers appears twice and another is missing.
- **Example:** `nums = [1, 2, 2, 4]`
- **Constraints:**
	- 2 <= nums.length <= 10^4
	- 1 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing two elements: the number that is repeated and the number that is missing.
- **Example:** `[2, 3]`
- **Constraints:**
	- The result array should contain exactly two integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the duplicate and the missing number in the list.

- 1. Traverse the list and for each number, mark it as visited by negating the number at its index.
- 2. If you encounter a negative number, it means that number has already appeared, so it's the duplicate.
- 3. The missing number is the index that was never visited.
{{< dots >}}
### Problem Assumptions ✅
- There will always be exactly one missing number and one duplicate number in the list.
{{< dots >}}
## Examples 🧩
- **Input:** `[1, 2, 2, 4]`  \
  **Explanation:** Here, 2 is repeated and the missing number is 3, so the output is [2, 3].

{{< dots >}}
## Approach 🚀
The solution leverages the fact that the numbers should be between 1 and n and the duplicate and missing numbers can be identified via index manipulation.

### Initial Thoughts 💭
- We can use index manipulation to mark visited numbers.
- By negating the number at the corresponding index, we can identify duplicates by encountering already negated numbers. The missing number is the index whose value is not negated.
{{< dots >}}
### Edge Cases 🌐
- Input array will never be empty.
- The solution should be efficient enough to handle up to 10^4 elements.
- The input will always have one missing and one duplicate number.
- Ensure that the algorithm runs in O(n) time and uses O(1) space.
{{< dots >}}
## Code 💻
```cpp
vector<int> findErrorNums(vector<int>& nums) {
    vector<int> ans(2, 0);
    for(int i = 0; i < nums.size(); i++) {
        int val = abs(nums[i]);
        ans[1] ^= (i+1) ^ val;
        if (nums[val-1] < 0) ans[0] = val;
        else nums[val-1] = -nums[val-1];
    }
    ans[1] ^= ans[0];
    return ans;        
}
```

This is the complete code for the 'Find the Error Numbers in an Array' problem. It efficiently identifies the duplicate and missing numbers in an array using XOR operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findErrorNums(vector<int>& nums) {
	```
	This is the function definition. The function takes a reference to a vector of integers and returns a vector of integers containing the duplicate and missing number.

2. **Variable Declaration**
	```cpp
	    vector<int> ans(2, 0);
	```
	Declares a vector 'ans' of size 2 initialized to zero. This will store the duplicate number at index 0 and the missing number at index 1.

3. **Loop Initialization**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop that iterates over each element in the input vector 'nums'.

4. **Absolute Value Calculation**
	```cpp
	        int val = abs(nums[i]);
	```
	Takes the absolute value of the current element in the array, 'nums[i]', to avoid issues with previously modified elements.

5. **XOR Operation for Duplicate/Non-Duplicate**
	```cpp
	        ans[1] ^= (i+1) ^ val;
	```
	Performs an XOR operation between the current index (i+1) and the absolute value 'val'. This helps identify the duplicate and missing numbers in the array.

6. **Duplicate Check**
	```cpp
	        if (nums[val-1] < 0) ans[0] = val;
	```
	Checks if the element at the index corresponding to 'val-1' is negative. If it is, this means the number 'val' is a duplicate, so it is stored in 'ans[0]'.

7. **Mark Number as Visited**
	```cpp
	        else nums[val-1] = -nums[val-1];
	```
	If 'val' is not a duplicate, it negates the element at the index 'val-1' to mark that this number has been visited.

8. **Final XOR for Missing Number**
	```cpp
	    ans[1] ^= ans[0];
	```
	Performs a final XOR operation between the two numbers, ensuring that the missing number is correctly identified.

9. **Return Statement**
	```cpp
	    return ans;        
	```
	Returns the vector 'ans' containing the duplicate number at index 0 and the missing number at index 1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm always takes linear time to find the duplicate and the missing number.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/set-mismatch/description/)

---
{{< youtube d-ulaeRBA64 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
