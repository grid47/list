
+++
authors = ["grid47"]
title = "Leetcode 454: 4Sum II"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 454: 4Sum II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/454.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/454.webp" 
    alt="A sequence of quadruples where each valid sum is softly highlighted to show the results."
    caption="Solution to LeetCode 454: 4Sum II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given four integer arrays nums1, nums2, nums3, and nums4 all of length n. Your task is to find the number of quadruples (i, j, k, l) such that nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0. The indices i, j, k, and l should be between 0 and n-1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of four arrays nums1, nums2, nums3, nums4 of length n, where each array contains integers.
- **Example:** `nums1 = [1, 2], nums2 = [-2, -1], nums3 = [-1, 2], nums4 = [0, 2]`
- **Constraints:**
	- 1 <= n <= 200
	- -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of quadruples (i, j, k, l) such that nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0.
- **Example:** `Output: 2`
- **Constraints:**
	- The result should be the count of all valid quadruples.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently find the number of quadruples whose sum is zero.

- 1. Iterate through all possible pairs of sums from nums1 and nums2, and store their results in a hash map.
- 2. Iterate through all pairs of sums from nums3 and nums4, and for each pair, check if the negative of the sum exists in the hash map from step 1.
- 3. Count how many such pairs exist and return the total count.
{{< dots >}}
### Problem Assumptions ✅
- The arrays nums1, nums2, nums3, and nums4 are all of equal length.
- All values in the arrays are integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums1 = [1, 2], nums2 = [-2, -1], nums3 = [-1, 2], nums4 = [0, 2]`  \
  **Explanation:** In this case, the two valid quadruples are (0, 0, 0, 1) and (1, 1, 0, 0).

- **Input:** `nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]`  \
  **Explanation:** Here, the only valid quadruple is (0, 0, 0, 0).

{{< dots >}}
## Approach 🚀
The approach involves using a hash map to efficiently find and count the valid quadruples.

### Initial Thoughts 💭
- The problem can be reduced to finding pairs of sums that add up to zero.
- Using a hash map to store pairs of sums will allow us to quickly check if the negative of a given sum exists, reducing the time complexity.
{{< dots >}}
### Edge Cases 🌐
- If the arrays are empty, the result should be zero.
- The algorithm must handle arrays of size up to 200 efficiently.
- If the sum of four numbers equals zero, it should be counted as a valid quadruple.
- The solution should operate within a time complexity of O(n^2).
{{< dots >}}
## Code 💻
```cpp
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int res = 0;
    unordered_map<int, int> mp;
    for(int a : A)
    for(int b : B)
    mp[a+b]++;
    for(int c : C)
    for(int d : D)
    if(mp.count(-c-d)) res+= mp[-c-d];
    return res;
}
```

The `fourSumCount` function calculates the number of tuples (i, j, k, l) such that A[i] + B[j] + C[k] + D[l] = 0 using hashing. It builds a map of pair sums from the first two arrays and checks if the negated sum of pairs from the last two arrays exists in the map.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	```
	Defines the function `fourSumCount` that takes four integer vectors as input and returns the number of valid quadruples where the sum of elements from the arrays is zero.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes a variable `res` to 0, which will hold the count of valid quadruples.

3. **Map Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	Declares an unordered map `mp` that will store the sum of pairs from arrays A and B as keys, and their frequency as values.

4. **Outer Loop (Array A)**
	```cpp
	    for(int a : A)
	```
	Starts a loop that iterates through each element of array `A`.

5. **Inner Loop (Array B)**
	```cpp
	    for(int b : B)
	```
	Starts a nested loop that iterates through each element of array `B` for every element in `A`.

6. **Map Update**
	```cpp
	    mp[a+b]++;
	```
	Adds the sum of `a` and `b` to the map `mp`, incrementing its count. This stores the frequency of each pair sum from arrays `A` and `B`.

7. **Outer Loop (Array C)**
	```cpp
	    for(int c : C)
	```
	Starts a loop that iterates through each element of array `C`.

8. **Inner Loop (Array D)**
	```cpp
	    for(int d : D)
	```
	Starts a nested loop that iterates through each element of array `D` for every element in `C`.

9. **Map Lookup and Update**
	```cpp
	    if(mp.count(-c-d)) res+= mp[-c-d];
	```
	Checks if the negated sum `-c-d` exists in the map `mp`. If it does, it adds the frequency of that sum to `res`, indicating the number of valid quadruples found.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the count of valid quadruples stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we need to check all pairs of sums from the four arrays.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the storage of pairs of sums in the hash map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/4sum-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
