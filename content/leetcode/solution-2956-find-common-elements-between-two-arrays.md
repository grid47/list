
+++
authors = ["grid47"]
title = "Leetcode 2956: Find Common Elements Between Two Arrays"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2956: Find Common Elements Between Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jb1IbKe3bPE"
youtube_upload_date="2023-12-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jb1IbKe3bPE/maxresdefault.webp"
comments = true
+++



---
You are given two integer arrays, nums1 and nums2, with sizes n and m respectively. Your task is to find the number of indices i such that nums1[i] exists in nums2 and the number of indices i such that nums2[i] exists in nums1. Return both values as an array [answer1, answer2].
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two integer arrays nums1 and nums2.
- **Example:** `nums1 = [2, 3, 2], nums2 = [1, 2]`
- **Constraints:**
	- 1 <= n, m <= 100
	- 1 <= nums1[i], nums2[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of two integers: [answer1, answer2]. answer1 is the number of elements from nums1 that are present in nums2, and answer2 is the number of elements from nums2 that are present in nums1.
- **Example:** `[2, 1]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the count of matching elements between the two arrays in both directions.

- Convert nums1 and nums2 into sets for efficient lookup.
- Iterate through nums1 and count how many of its elements exist in nums2.
- Similarly, iterate through nums2 and count how many of its elements exist in nums1.
{{< dots >}}
### Problem Assumptions ✅
- Both input arrays will have at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums1 = [2, 3, 2], nums2 = [1, 2]`  \
  **Explanation:** The elements in nums1 that exist in nums2 are 2 and 2, so answer1 is 2. The element 2 in nums2 exists in nums1, so answer2 is 1.

{{< dots >}}
## Approach 🚀
The approach is to count the number of matching elements between nums1 and nums2 by using set lookups for efficient matching.

### Initial Thoughts 💭
- Using sets will allow for O(1) average-time lookups.
- We can use two sets to check how many elements from nums1 exist in nums2 and vice versa.
{{< dots >}}
### Edge Cases 🌐
- If one or both arrays are empty, the result will be [0, 0].
- Ensure the solution runs efficiently when n and m are at their maximum size of 100.
- Arrays with no common elements should return [0, 0].
- n and m are guaranteed to be between 1 and 100.
{{< dots >}}
## Code 💻
```cpp
vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    set<int> n1, n2;
    for(int x: nums1) n1.insert(x);
    for(int x: nums2) n2.insert(x);
    int cnt1 = 0;
    for(int x: nums1) if(n2.count(x)) cnt1++;
    int cnt2 = 0;
    for(int x: nums2) if(n1.count(x)) cnt2++;        
    return vector<int>{cnt1, cnt2};
}
```

This function calculates the number of common elements between two arrays, 'nums1' and 'nums2', and returns a vector with the counts of common elements for each array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
	```
	Defines the function 'findIntersectionValues', which takes two vectors of integers, 'nums1' and 'nums2', and returns a vector of integers with the counts of common elements from each array.

2. **Declare Sets**
	```cpp
	    set<int> n1, n2;
	```
	Declares two sets, 'n1' and 'n2', to store the unique elements from 'nums1' and 'nums2', respectively. Sets automatically handle duplicates.

3. **Populate Set n1**
	```cpp
	    for(int x: nums1) n1.insert(x);
	```
	Iterates over 'nums1' and inserts each element into the set 'n1'. This ensures all elements in 'nums1' are unique.

4. **Populate Set n2**
	```cpp
	    for(int x: nums2) n2.insert(x);
	```
	Iterates over 'nums2' and inserts each element into the set 'n2'. This ensures all elements in 'nums2' are unique.

5. **Initialize Count Variables**
	```cpp
	    int cnt1 = 0;
	```
	Initializes 'cnt1' to zero. This variable will keep track of the number of common elements between 'nums1' and 'nums2'.

6. **Count Common Elements from nums1**
	```cpp
	    for(int x: nums1) if(n2.count(x)) cnt1++;
	```
	Iterates over 'nums1' and checks if each element exists in 'n2'. If it does, it increments 'cnt1', counting how many elements in 'nums1' are also in 'nums2'.

7. **Initialize Second Count Variable**
	```cpp
	    int cnt2 = 0;
	```
	Initializes 'cnt2' to zero. This variable will keep track of the number of common elements between 'nums2' and 'nums1'.

8. **Count Common Elements from nums2**
	```cpp
	    for(int x: nums2) if(n1.count(x)) cnt2++;
	```
	Iterates over 'nums2' and checks if each element exists in 'n1'. If it does, it increments 'cnt2', counting how many elements in 'nums2' are also in 'nums1'.

9. **Return Result**
	```cpp
	    return vector<int>{cnt1, cnt2};
	```
	Returns a vector containing the counts of common elements: 'cnt1' (common elements from 'nums1') and 'cnt2' (common elements from 'nums2').

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

Converting arrays into sets takes O(n) and O(m) time, and each lookup is O(1).

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is O(n + m) due to the storage of the sets.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-common-elements-between-two-arrays/description/)

---
{{< youtube jb1IbKe3bPE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
