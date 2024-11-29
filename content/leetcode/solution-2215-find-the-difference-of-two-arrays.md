
+++
authors = ["grid47"]
title = "Leetcode 2215: Find the Difference of Two Arrays"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2215: Find the Difference of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "oypp_RzI69w"
youtube_upload_date="2023-05-03"
youtube_thumbnail="https://i.ytimg.com/vi/oypp_RzI69w/maxresdefault.jpg"
comments = true
+++



---
You are given two integer arrays, nums1 and nums2. Your task is to return a list of two arrays. The first array should contain all distinct integers that are in nums1 but not in nums2. The second array should contain all distinct integers that are in nums2 but not in nums1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays nums1 and nums2.
- **Example:** `nums1 = [5, 8, 3, 5], nums2 = [1, 3, 8, 8]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 1000
	- -1000 <= nums1[i], nums2[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list with two sublists. The first sublist contains integers from nums1 that are not in nums2, and the second sublist contains integers from nums2 that are not in nums1.
- **Example:** `[[5], [1]]`
- **Constraints:**
	- The integers in the lists may be returned in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the distinct integers in each array that are not present in the other.

- Convert both arrays into sets to eliminate duplicates.
- Check for integers that are in nums1 but not in nums2.
- Check for integers that are in nums2 but not in nums1.
- Return the result as a list of two sublists.
{{< dots >}}
### Problem Assumptions ✅
- The arrays may contain negative values.
- Arrays may have duplicates that need to be ignored in the result.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums1 = [5, 8, 3, 5], nums2 = [1, 3, 8, 8]`  \
  **Explanation:** For nums1, the distinct numbers are 5 and 3, but 8 is common in nums2. So, the first sublist in the result will be [5]. For nums2, the distinct number is 1, which is not in nums1, so the second sublist will be [1].

{{< dots >}}
## Approach 🚀
We will use sets to identify the distinct elements and easily check for differences between the two arrays.

### Initial Thoughts 💭
- Sets automatically remove duplicates, so we don't need to handle duplicates manually.
- We can efficiently compute the difference between two sets using set operations like difference.
{{< dots >}}
### Edge Cases 🌐
- If either nums1 or nums2 is empty, the result should be the other array as a distinct set.
- If the arrays are large, ensure the solution works efficiently within the given time limits.
- Arrays with all common elements or all unique elements should still return the correct results.
- Make sure to handle negative numbers and large arrays efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> ans(2);
    set<int> s1, s2;
    for(int i = 0; i < nums1.size(); i++) {
        s1.insert(nums1[i]);
    }
    for(int i = 0; i < nums2.size(); i++) {
        s2.insert(nums2[i]);
    }
    for(int x: s1) {
        if(!s2.count(x))
            ans[0].push_back(x);
    }
    for(int x: s2) {
        if(!s1.count(x))
            ans[1].push_back(x);
    }        
    return ans;
}
```

This is the complete solution for finding the difference between two arrays. It compares the elements of two vectors, `nums1` and `nums2`, and returns a vector containing the unique elements from each array that are not present in the other.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
	```
	This is the function declaration for `findDifference`. It takes two vectors of integers, `nums1` and `nums2`, and returns a 2D vector containing the unique elements of each array.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> ans(2);
	```
	The variable `ans` is initialized as a 2D vector with two rows to store the differences from `nums1` and `nums2`.

3. **Variable Initialization**
	```cpp
	    set<int> s1, s2;
	```
	Two sets, `s1` and `s2`, are initialized to store the unique elements of `nums1` and `nums2` respectively.

4. **For Loop**
	```cpp
	    for(int i = 0; i < nums1.size(); i++) {
	```
	This loop iterates over the elements of `nums1`.

5. **Set Insertion**
	```cpp
	        s1.insert(nums1[i]);
	```
	Each element of `nums1` is inserted into the set `s1` to ensure uniqueness.

6. **For Loop**
	```cpp
	    for(int i = 0; i < nums2.size(); i++) {
	```
	This loop iterates over the elements of `nums2`.

7. **Set Insertion**
	```cpp
	        s2.insert(nums2[i]);
	```
	Each element of `nums2` is inserted into the set `s2` to ensure uniqueness.

8. **For Loop**
	```cpp
	    for(int x: s1) {
	```
	This loop iterates over the elements in set `s1`.

9. **Conditional Check**
	```cpp
	        if(!s2.count(x))
	```
	This checks if the element `x` from `s1` does not exist in `s2`.

10. **Set Insertion**
	```cpp
	            ans[0].push_back(x);
	```
	If the element `x` from `s1` is not found in `s2`, it is added to the first row of `ans`.

11. **For Loop**
	```cpp
	    for(int x: s2) {
	```
	This loop iterates over the elements in set `s2`.

12. **Conditional Check**
	```cpp
	        if(!s1.count(x))
	```
	This checks if the element `x` from `s2` does not exist in `s1`.

13. **Set Insertion**
	```cpp
	            ans[1].push_back(x);
	```
	If the element `x` from `s2` is not found in `s1`, it is added to the second row of `ans`.

14. **Return Statement**
	```cpp
	    return ans;
	```
	Return the 2D vector `ans`, which contains the elements found in `nums1` but not in `nums2` (first row) and the elements found in `nums2` but not in `nums1` (second row).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m) where n and m are the lengths of nums1 and nums2 respectively.
- **Average Case:** O(n + m) where n and m are the lengths of nums1 and nums2 respectively.
- **Worst Case:** O(n + m) where n and m are the lengths of nums1 and nums2 respectively.

We iterate through each array once to convert them to sets and then compute the differences.

### Space Complexity 💾
- **Best Case:** O(n + m) for the sets created from nums1 and nums2.
- **Worst Case:** O(n + m) for the sets created from nums1 and nums2.

The space complexity is dependent on the size of the input arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/)

---
{{< youtube oypp_RzI69w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
