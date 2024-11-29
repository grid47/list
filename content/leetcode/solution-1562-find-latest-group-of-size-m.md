
+++
authors = ["grid47"]
title = "Leetcode 1562: Find Latest Group of Size M"
date = "2024-06-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1562: Find Latest Group of Size M in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jUindlyYRuA"
youtube_upload_date="2020-08-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jUindlyYRuA/maxresdefault.webp"
comments = true
+++



---
You are given a permutation of integers from 1 to n, where each integer represents a position in a binary string of size n that is initially filled with zeros. At each step, you will flip the bit at the position specified by the current element of the array. You are also given an integer m, and your task is to determine the latest step at which there exists a contiguous substring of exactly m ones in the binary string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array arr representing a permutation of numbers from 1 to n, and an integer m representing the length of the contiguous group of ones to look for.
- **Example:** `Input: arr = [4, 2, 5, 1, 3], m = 2`
- **Constraints:**
	- 1 <= arr.length == n <= 10^5
	- 1 <= m <= n
	- arr[i] is a distinct number between 1 and n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the latest step at which there exists a contiguous substring of exactly m ones. If no such group exists, return -1.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the latest step at which there is a group of exactly m consecutive 1's.

- Simulate each step where a bit is set to 1 based on the current position in arr.
- At each step, check if there is a group of exactly m ones.
- Track the step at which the first group of exactly m ones occurs, and return the latest step.
{{< dots >}}
### Problem Assumptions ✅
- The input array arr is a valid permutation of numbers from 1 to n.
- At each step, you only flip one bit.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: arr = [4, 2, 5, 1, 3], m = 2`  \
  **Explanation:** In this case, after the first 4 steps, the binary string looks like: 01100. At step 4, we have a group of exactly 2 ones (11), which is the latest occurrence of such a group. Hence, the output is 4.

- **Input:** `Example 2: arr = [1, 3, 2], m = 1`  \
  **Explanation:** In this case, the binary string evolves as: 100, 110, 111. After all steps, a group of size 1 can be found at each step, but the latest step when a group of size 1 exists is step 3. Hence, the output is 3.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we need to simulate the process of flipping bits at the positions specified by arr and then check for groups of ones at each step.

### Initial Thoughts 💭
- We need to track the contiguous groups of ones as we flip the bits at each step.
- We can use an auxiliary array to maintain the current lengths of contiguous groups of ones.
- Efficient checking for groups of exactly m ones is crucial to ensuring we stay within the time limits.
- Tracking the lengths of contiguous ones in the binary string dynamically as we flip bits can help us solve the problem efficiently.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element, so no need to handle empty inputs.
- For large inputs, ensure that the algorithm works efficiently within the time complexity limits.
- If no group of exactly m ones ever exists, return -1.
- Ensure that m is within the bounds of the array length and that arr is a valid permutation.
{{< dots >}}
## Code 💻
```cpp
int findLatestStep(vector<int>& arr, int m) {

    int n = arr.size();
    vector<int> len(n + 2, 0), cnt(n + 1, 0);
    
    int res = -1;
    
    for(int i = 0; i < n; i++) {
        
        int a = arr[i];
        int ll = len[a - 1];
        int rl = len[a + 1];
        len[a] = len[a - ll] = len[a + rl] = ll + rl + 1;
        
        cnt[ll]--;
        cnt[rl]--;
        
        cnt[len[a]]++;
        
        if(cnt[m] > 0) res = i + 1;
        
    }
    
    return res;
}
```

This function finds the latest step at which a particular group size of m can be formed after a series of steps where elements are merged into contiguous segments.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findLatestStep(vector<int>& arr, int m) {
	```
	Defines the function that takes an array `arr` and an integer `m`, where `arr` represents the sequence of steps and `m` represents the group size we are interested in.

2. **Variable Initialization**
	```cpp
	    int n = arr.size();
	```
	Initializes `n` as the size of the input array `arr`, representing the number of steps.

3. **Variable Initialization**
	```cpp
	    vector<int> len(n + 2, 0), cnt(n + 1, 0);
	```
	Creates two vectors: `len` for storing the lengths of segments and `cnt` for counting occurrences of segment lengths.

4. **Result Initialization**
	```cpp
	    int res = -1;
	```
	Initializes `res` to -1, which will later store the result (the latest step).

5. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop that iterates over each step in the input array `arr`.

6. **Array Access**
	```cpp
	        int a = arr[i];
	```
	Retrieves the current value `a` from the input array `arr` to process in the loop.

7. **Segment Length Calculation**
	```cpp
	        int ll = len[a - 1];
	```
	Calculates the length of the left segment (`ll`) adjacent to the current step `a`.

8. **Segment Length Calculation**
	```cpp
	        int rl = len[a + 1];
	```
	Calculates the length of the right segment (`rl`) adjacent to the current step `a`.

9. **Segment Merging**
	```cpp
	        len[a] = len[a - ll] = len[a + rl] = ll + rl + 1;
	```
	Merges the left and right segments with the current segment `a` and updates the lengths.

10. **Count Update**
	```cpp
	        cnt[ll]--;
	```
	Decreases the count of the left segment length (`ll`) after merging.

11. **Count Update**
	```cpp
	        cnt[rl]--;
	```
	Decreases the count of the right segment length (`rl`) after merging.

12. **Count Update**
	```cpp
	        cnt[len[a]]++;
	```
	Increases the count of the newly merged segment length.

13. **Result Check**
	```cpp
	        if(cnt[m] > 0) res = i + 1;
	```
	Checks if there is a segment of size `m` and updates `res` with the current step index if true.

14. **Return**
	```cpp
	    return res;
	```
	Returns the latest step where a segment of size `m` was formed, or -1 if no such segment was formed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate over the array and update the group lengths at each step.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space needed for storing the lengths of the groups of ones.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-latest-group-of-size-m/description/)

---
{{< youtube jUindlyYRuA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
