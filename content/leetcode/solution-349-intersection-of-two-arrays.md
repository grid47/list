
+++
authors = ["grid47"]
title = "Leetcode 349: Intersection of Two Arrays"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 349: Intersection of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/349.webp"
youtube = "XxStWmfXJRs"
youtube_upload_date="2020-01-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XxStWmfXJRs/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/349.webp" 
    alt="Two arrays intersecting with glowing elements where they overlap, gently highlighting the intersection points."
    caption="Solution to LeetCode 349: Intersection of Two Arrays Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique, and you may return the result in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays, nums1 and nums2. The arrays contain integer elements.
- **Example:** `Input: nums1 = [3, 1, 4, 4], nums2 = [4, 3, 5]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 1000
	- 0 <= nums1[i], nums2[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of unique integers representing the intersection of the two input arrays.
- **Example:** `Output: [3, 4]`
- **Constraints:**
	- The output array must contain only unique elements.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to return the intersection of the two arrays as a list of unique elements.

- Create a set from the first array to ensure uniqueness and facilitate quick lookup.
- Iterate through the second array and check if each element exists in the set from the first array.
- If an element exists in both arrays, add it to the result array and remove it from the set to ensure uniqueness in the result.
{{< dots >}}
### Problem Assumptions ✅
- Both input arrays are non-empty, and they contain valid integers within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums1 = [3, 1, 4, 4], nums2 = [4, 3, 5]`  \
  **Explanation:** The intersection of the two arrays is [3, 4] because both 3 and 4 appear in both arrays.

- **Input:** `Input: nums1 = [1, 3, 7, 8], nums2 = [9, 7, 3, 1]`  \
  **Explanation:** The intersection of the two arrays is [1, 3, 7] because these elements appear in both arrays.

- **Input:** `Input: nums1 = [2, 2, 1], nums2 = [2, 3]`  \
  **Explanation:** The intersection of the two arrays is [2] because 2 is the only common element in both arrays.

{{< dots >}}
## Approach 🚀
The approach involves converting one of the arrays into a set to ensure uniqueness and facilitate fast lookups. Then, we iterate through the second array to find common elements.

### Initial Thoughts 💭
- Using a set for the first array will allow for efficient checking of elements in the second array.
- By iterating over the second array, we can check each element's presence in the first array using the set and ensure uniqueness in the result.
{{< dots >}}
### Edge Cases 🌐
- If either nums1 or nums2 is empty, the result should be an empty array.
- Ensure that the solution efficiently handles large arrays with sizes up to 1000.
- Handle arrays with no common elements by returning an empty array.
- The algorithm should work efficiently with arrays up to the maximum constraint of 1000 elements.
{{< dots >}}
## Code 💻
```cpp
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto a : nums2)
        if (m.count(a)) {
            res.push_back(a);
            m.erase(a);
        }
    return res;
}
```

This function returns the intersection of two integer arrays, `nums1` and `nums2`. It uses an unordered set to efficiently find common elements, ensuring each element appears only once in the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	```
	The function `intersection` takes two integer vectors `nums1` and `nums2` as input and returns a vector containing their intersection, i.e., elements common to both vectors.

2. **Set Initialization**
	```cpp
	    unordered_set<int> m(nums1.begin(), nums1.end());
	```
	Create an unordered set `m` initialized with the elements from `nums1`. This allows for efficient O(1) lookups when checking for element existence.

3. **Result Vector Declaration**
	```cpp
	    vector<int> res;
	```
	Declare an empty vector `res` to store the elements that are part of the intersection of `nums1` and `nums2`.

4. **Loop Over Second Array**
	```cpp
	    for (auto a : nums2)
	```
	Iterate through each element `a` in the second array `nums2`.

5. **Check if Element Exists in Set**
	```cpp
	        if (m.count(a)) {
	```
	For each element `a` in `nums2`, check if it exists in the set `m` (i.e., if it is also in `nums1`).

6. **Add to Result**
	```cpp
	            res.push_back(a);
	```
	If the element `a` exists in `m`, add it to the result vector `res`.

7. **Erase from Set**
	```cpp
	            m.erase(a);
	```
	Remove the element `a` from the set `m` to ensure that each element is added to the result only once, preventing duplicates.

8. **Return Result**
	```cpp
	    return res;
	```
	After iterating through `nums2`, return the vector `res` which now contains the intersection of `nums1` and `nums2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The solution iterates through both arrays once, where n and m are the lengths of nums1 and nums2, respectively.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the elements of nums1 in a set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/intersection-of-two-arrays/description/)

---
{{< youtube XxStWmfXJRs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
