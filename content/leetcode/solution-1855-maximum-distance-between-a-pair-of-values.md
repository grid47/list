
+++
authors = ["grid47"]
title = "Leetcode 1855: Maximum Distance Between a Pair of Values"
date = "2024-05-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1855: Maximum Distance Between a Pair of Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ksN__viaDFs"
youtube_upload_date="2021-05-09"
youtube_thumbnail="https://i.ytimg.com/vi/ksN__viaDFs/maxresdefault.jpg"
comments = true
+++



---
You are given two non-increasing 0-indexed integer arrays `nums1` and `nums2`. A pair of indices `(i, j)` is valid if both `i <= j` and `nums1[i] <= nums2[j]`. The distance of the pair is `j - i`. You need to return the maximum distance of any valid pair `(i, j)`. If there are no valid pairs, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two non-increasing 0-indexed integer arrays `nums1` and `nums2`.
- **Example:** `[50,30,5,4,1], [100,20,10,10,5]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 10^5
	- 1 <= nums1[i], nums2[j] <= 10^5
	- Both nums1 and nums2 are non-increasing arrays.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum distance of any valid pair `(i, j)`.
- **Example:** `2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum distance between valid pairs where `i <= j` and `nums1[i] <= nums2[j]`.

- Use a two-pointer or binary search approach to efficiently find the maximum distance.
- For each element in `nums1`, use binary search or a pointer to find the largest index `j` where `nums2[j]` is greater than or equal to `nums1[i]`.
- Track the maximum distance `j - i`.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays will always follow the given constraints of being non-increasing.
{{< dots >}}
## Examples 🧩
- **Input:** `[50,30,5,4,1], [100,20,10,10,5]`  \
  **Explanation:** The valid pairs are `(0,0)`, `(2,2)`, `(2,3)`, `(2,4)`, `(3,3)`, `(3,4)`, and `(4,4)`. The pair `(2,4)` has the maximum distance, which is `2`.

{{< dots >}}
## Approach 🚀
To solve this problem, a binary search or two-pointer technique can be used to find the largest valid distance between pairs from `nums1` and `nums2`.

### Initial Thoughts 💭
- We need to find a valid pair `(i, j)` where `nums1[i] <= nums2[j]` and `i <= j`.
- The problem can be solved efficiently using binary search or a two-pointer technique to avoid checking each pair explicitly.
{{< dots >}}
### Edge Cases 🌐
- The input arrays will always contain at least one element.
- The solution must handle large inputs efficiently, as `nums1.length` and `nums2.length` can go up to 10^5.
- Consider cases where the arrays have only one element.
- Ensure that the solution can handle the non-increasing nature of the arrays.
{{< dots >}}
## Code 💻
```cpp
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;
    for(int i = 0; i < nums1.size(); i++) {
            
            int l = i, r = nums2.size() - 1, j = i;

            int target = nums1[i]; // find largest index which satisfies target <= nums[i]
        
            while(l <= r) {
                int mid = l + (r - l + 1) / 2;
                
                if(target < nums2[mid]) {
                    j = mid;
                    l = mid + 1;
                } else if(target > nums2[mid]) {
                    r = mid - 1;
                } else if(target == nums2[mid]) {
                    j = mid;
                    l = mid + 1;
                }

            }
            // cout << j - i;
            
            ans = max(ans, j - i);
    }
    return ans;
}
```

This function finds the maximum distance between indices i and j of two arrays, `nums1` and `nums2`, where `nums1[i] <= nums2[j]`. The approach uses binary search to find the largest valid `j` for each `i` in `nums1`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxDistance(vector<int>& nums1, vector<int>& nums2) {
	```
	Defines the function `maxDistance` which takes two input vectors `nums1` and `nums2`.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes the variable `ans` to store the maximum distance found, starting with a value of 0.

3. **Looping**
	```cpp
	    for(int i = 0; i < nums1.size(); i++) {
	```
	Starts a loop to iterate through each element `i` of the `nums1` array.

4. **Variable Initialization**
	```cpp
	            int l = i, r = nums2.size() - 1, j = i;
	```
	Initializes variables `l` (left pointer) to `i`, `r` (right pointer) to the last index of `nums2`, and `j` (the index of the largest valid `nums2` element) to `i`.

5. **Variable Assignment**
	```cpp
	            int target = nums1[i]; // find largest index which satisfies target <= nums1[i]
	```
	Sets `target` to `nums1[i]`, which is the current element from `nums1` that we need to find a match for in `nums2`.

6. **Looping**
	```cpp
	            while(l <= r) {
	```
	Starts a while loop to perform binary search on `nums2`.

7. **Variable Calculation**
	```cpp
	                int mid = l + (r - l + 1) / 2;
	```
	Calculates the middle index `mid` for the binary search range [l, r].

8. **Conditional Check**
	```cpp
	                if(target < nums2[mid]) {
	```
	Checks if the current target from `nums1` is less than the value at `nums2[mid]`.

9. **Variable Update**
	```cpp
	                    j = mid;
	```
	Updates `j` to `mid` because we found a larger value that satisfies `target <= nums2[mid]`.

10. **Variable Update**
	```cpp
	                    l = mid + 1;
	```
	Moves the left pointer `l` to the right of `mid` to continue searching for a larger index.

11. **Conditional Check**
	```cpp
	                } else if(target > nums2[mid]) {
	```
	Checks if the current target is greater than `nums2[mid]`.

12. **Variable Update**
	```cpp
	                    r = mid - 1;
	```
	Moves the right pointer `r` to the left of `mid` since `nums2[mid]` is too large.

13. **Conditional Check**
	```cpp
	                } else if(target == nums2[mid]) {
	```
	Checks if the current target is equal to `nums2[mid]`.

14. **Variable Update**
	```cpp
	                    j = mid;
	```
	Updates `j` to `mid` since we found an exact match for `target`.

15. **Variable Update**
	```cpp
	                    l = mid + 1;
	```
	Moves the left pointer `l` to the right to continue searching for larger valid indices.

16. **Variable Update**
	```cpp
	            ans = max(ans, j - i);
	```
	Updates `ans` with the maximum distance found between `i` and `j`.

17. **Return**
	```cpp
	    return ans;
	```
	Returns the maximum distance found between indices from `nums1` and `nums2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) in the worst case, where n is the length of the input arrays, due to binary search or two-pointer traversal.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we are using a constant amount of extra space apart from the input arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/)

---
{{< youtube ksN__viaDFs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
