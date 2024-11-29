
+++
authors = ["grid47"]
title = "Leetcode 673: Number of Longest Increasing Subsequence"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 673: Number of Longest Increasing Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Binary Indexed Tree","Segment Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/673.webp"
youtube = "Tuc-rjJbsXU"
youtube_upload_date="2021-11-24"
youtube_thumbnail="https://i.ytimg.com/vi/Tuc-rjJbsXU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/673.webp" 
    alt="A sequence of numbers where the longest increasing subsequence is highlighted and softly glowing."
    caption="Solution to LeetCode 673: Number of Longest Increasing Subsequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array `nums`, return the number of distinct longest increasing subsequences.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers `nums`.
- **Example:** `nums = [3, 2, 6, 4, 5]`
- **Constraints:**
	- 1 <= nums.length <= 2000
	- -10^6 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct longest increasing subsequences.
- **Example:** `3`
- **Constraints:**
	- The answer is guaranteed to fit within a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the number of distinct longest increasing subsequences.

- 1. Use dynamic programming to track the length of the longest increasing subsequences ending at each element.
- 2. Maintain a count of how many subsequences achieve the longest length for each element.
- 3. Sum the counts for the subsequences that have the maximum length.
{{< dots >}}
### Problem Assumptions ✅
- Subsequences are strictly increasing, meaning each element in a subsequence must be greater than the previous element.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 3, 5, 4, 7]`  \
  **Explanation:** The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7], both of length 4.

- **Input:** `nums = [2, 2, 2, 2, 2]`  \
  **Explanation:** Since there are no strictly increasing subsequences, the longest subsequences are of length 1, and there are 5 such subsequences.

{{< dots >}}
## Approach 🚀
We use dynamic programming to track the length of the longest increasing subsequences at each index and count the number of such subsequences.

### Initial Thoughts 💭
- We can iterate through the array and for each element, compare it with previous elements to build subsequences.
- The key observation is that we need to track both the length and the count of subsequences for each element.
{{< dots >}}
### Edge Cases 🌐
- This problem doesn't have an empty input as `nums` is guaranteed to have at least one element.
- Ensure the solution can handle arrays up to the maximum size (2000 elements).
- If all elements in `nums` are equal, the longest subsequence length is 1, and the answer is the number of elements in `nums`.
- Handle large input sizes efficiently using dynamic programming.
{{< dots >}}
## Code 💻
```cpp
int findNumberOfLIS(vector<int>& nums) {
    
    int res = 0, n = nums.size(), max_len = 0;
    vector<int> len(n, 0), cnt(n, 0);
    
    for(int i = 0; i < n; i++) {
        cnt[i] = 1;
        len[i] = 1;
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                if(len[j] + 1 == len[i]) cnt[i] += cnt[j];
                if(len[j] + 1 >  len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }   
        }
        if(max_len == len[i]) res += cnt[i];
        if(max_len < len[i]) {
            res = cnt[i];
            max_len = len[i];
        }
        
    }
    
    return res;
    
}
```

This code implements a solution for finding the number of longest increasing subsequences (LIS) in a given sequence of integers. The algorithm calculates the length of the longest increasing subsequences and their counts using dynamic programming.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findNumberOfLIS(vector<int>& nums) {
	```
	This is the function definition for `findNumberOfLIS`, which calculates the number of longest increasing subsequences (LIS) in the input array `nums`.

2. **Variable Initialization**
	```cpp
	    
	```
	Initialize necessary variables to store the result, the size of the input array `nums`, the maximum length of increasing subsequences found, and two vectors `len` and `cnt` to store the lengths and counts of LIS for each element.

3. **Variable Initialization**
	```cpp
	    int res = 0, n = nums.size(), max_len = 0;
	```
	Here, we initialize `res` to 0 (to store the number of LIS), `n` to the size of the input array `nums`, and `max_len` to 0 (to store the maximum length of LIS found so far).

4. **Array Initialization**
	```cpp
	    vector<int> len(n, 0), cnt(n, 0);
	```
	The vectors `len` and `cnt` are initialized to size `n` with all elements set to 0. `len[i]` will store the length of the LIS ending at index `i`, and `cnt[i]` will store the count of such LIS.

5. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The outer loop iterates through each element of the array `nums`.

6. **Set Initial Values for Each Element**
	```cpp
	        cnt[i] = 1;
	```
	For each element `i`, we initialize `cnt[i]` to 1, as the minimum count of LIS that ends at `i` is 1 (the element itself).

7. **Set Initial Values for Each Element**
	```cpp
	        len[i] = 1;
	```
	Similarly, we initialize `len[i]` to 1, as the minimum length of LIS ending at `i` is 1 (the element itself).

8. **Inner Loop**
	```cpp
	        for(int j = 0; j < i; j++) {
	```
	The inner loop checks all previous elements `j` before index `i` to see if they form an increasing subsequence with `nums[i]`.

9. **Condition: Check for Increasing Subsequence**
	```cpp
	            if(nums[j] < nums[i]) {
	```
	This condition checks if `nums[j]` is less than `nums[i]`, meaning that `nums[i]` can extend an increasing subsequence ending at `j`.

10. **Update Count for Equal Lengths**
	```cpp
	                if(len[j] + 1 == len[i]) cnt[i] += cnt[j];
	```
	If the length of the LIS ending at `j` plus one equals the length of the LIS ending at `i`, we add the count of LIS ending at `j` to the count for `i`.

11. **Update Length and Count for Longer LIS**
	```cpp
	                if(len[j] + 1 >  len[i]) {
	```
	If the length of the LIS ending at `j` plus one is greater than the current length at `i`, we update `len[i]` and set `cnt[i]` to the count of LIS at `j`.

12. **Update Length and Count for Longer LIS**
	```cpp
	                    len[i] = len[j] + 1;
	```
	Update the length of the LIS ending at `i` to be the length of the LIS at `j` plus one.

13. **Update Length and Count for Longer LIS**
	```cpp
	                    cnt[i] = cnt[j];
	```
	Set the count of LIS ending at `i` to the count of LIS at `j`.

14. **Update Result for Maximum Length**
	```cpp
	        if(max_len == len[i]) res += cnt[i];
	```
	If the length of the LIS at `i` is equal to the maximum length found so far, add the count of LIS at `i` to the result `res`.

15. **Update Result for New Maximum Length**
	```cpp
	        if(max_len < len[i]) {
	```
	If the length of the LIS at `i` is greater than the current maximum length, update `res` and `max_len`.

16. **Update Result for New Maximum Length**
	```cpp
	            res = cnt[i];
	```
	Set `res` to the count of LIS at `i` since it's the new maximum length.

17. **Update Result for New Maximum Length**
	```cpp
	            max_len = len[i];
	```
	Update `max_len` to the length of the LIS at `i`.

18. **Return Result**
	```cpp
	    return res;
	```
	The final step is to return the number of LIS.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The worst-case time complexity is O(n^2) due to two nested loops iterating over the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the `len[]` and `cnt[]` arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)

---
{{< youtube Tuc-rjJbsXU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
