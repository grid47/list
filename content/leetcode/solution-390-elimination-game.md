
+++
authors = ["grid47"]
title = "Leetcode 390: Elimination Game"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 390: Elimination Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/390.webp"
youtube = "0U5Lenn_vMo"
youtube_upload_date="2021-04-21"
youtube_thumbnail="https://i.ytimg.com/vi/0U5Lenn_vMo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/390.webp" 
    alt="A series of elements being eliminated one by one, with each eliminated element glowing as it is removed."
    caption="Solution to LeetCode 390: Elimination Game Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, simulate a process on a list of integers from 1 to n where every other number is removed, alternating the direction from left to right and right to left until only one number remains. Return the last remaining number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer n representing the length of a list starting from 1 to n.
- **Example:** `input = 10`
- **Constraints:**
	- 1 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the last remaining number in the list after applying the alternating removal process.
- **Example:** `Output: 4`
- **Constraints:**
	- The last number should be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the last remaining number after alternating removal of numbers from the list.

- Simulate the process of removing every other number starting from the left, then from the right, and alternate until only one number remains.
- Keep track of the position of the remaining number after each step.
{{< dots >}}
### Problem Assumptions ✅
- The input is guaranteed to be a positive integer n where 1 <= n <= 10^9.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: 10`  \
  **Explanation:** Start with a list of numbers from 1 to 10, and simulate the alternating removal process. The last remaining number is 4.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we can use a mathematical approach that exploits the alternating removal pattern without having to simulate the entire process for large inputs.

### Initial Thoughts 💭
- Simulating the alternating process for large values of n would be computationally expensive, so we need to optimize.
- The problem follows a predictable pattern, and the answer can be determined using mathematical reasoning rather than directly simulating the process.
{{< dots >}}
### Edge Cases 🌐
- There will always be a valid input where n >= 1.
- Ensure the solution can handle values of n up to 10^9 efficiently.
- When n = 1, the result is trivially 1.
- The algorithm must handle large values of n without directly simulating the process.
{{< dots >}}
## Code 💻
```cpp
int lastRemaining(int n) {
    bool left = true;
    int rm = n;
    int step = 1;
    int head = 1;
    while(rm > 1) {
        if(left || rm % 2 == 1) {
            head += step;
        }
        rm /= 2;
        step *= 2;
        left = !left;
    }
    return head;
}
```

This code finds the last remaining number in a sequence after repeatedly removing numbers according to a specific rule, either from the left or right.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int lastRemaining(int n) {
	```
	Define the function 'lastRemaining' which takes an integer 'n' representing the number of elements in the sequence, and returns the last remaining element.

2. **Variable Initialization**
	```cpp
	    bool left = true;
	```
	Initialize 'left' as true to track whether numbers should be removed from the left or right in each step.

3. **Variable Initialization**
	```cpp
	    int rm = n;
	```
	Initialize 'rm' as the total number of elements 'n'. This will keep track of the remaining elements in each step.

4. **Variable Initialization**
	```cpp
	    int step = 1;
	```
	Initialize 'step' to 1. This will track the step size by which elements are removed in each iteration.

5. **Variable Initialization**
	```cpp
	    int head = 1;
	```
	Initialize 'head' to 1. This variable represents the first element in the sequence that will be returned as the last remaining element.

6. **While Loop**
	```cpp
	    while(rm > 1) {
	```
	Start a while loop that runs until only one element remains in the sequence (i.e., rm > 1).

7. **Conditional Check**
	```cpp
	        if(left || rm % 2 == 1) {
	```
	Check if we are removing elements from the left side or if the remaining number of elements is odd, in which case the element at the 'head' should be included in the remaining sequence.

8. **Path Update**
	```cpp
	            head += step;
	```
	If removing from the left or the number of remaining elements is odd, update 'head' to include the next element to be kept in the sequence.

9. **Division**
	```cpp
	        rm /= 2;
	```
	Divide 'rm' by 2 to halve the remaining elements in the sequence after each round of removals.

10. **Step Increase**
	```cpp
	        step *= 2;
	```
	Double the 'step' after each round of removals to account for the increasing gap between remaining elements.

11. **Switch Direction**
	```cpp
	        left = !left;
	```
	Switch the direction of removal (from left to right or right to left) by toggling the 'left' flag.

12. **Return Statement**
	```cpp
	    return head;
	```
	Return the value of 'head', which represents the last remaining number in the sequence.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) as we reduce the number of elements by half in each step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we do not need extra space other than a few variables to track the current state.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/elimination-game/description/)

---
{{< youtube 0U5Lenn_vMo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
