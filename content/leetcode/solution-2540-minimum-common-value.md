
+++
authors = ["grid47"]
title = "Leetcode 2540: Minimum Common Value"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2540: Minimum Common Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "pbKnQYJuSY0"
youtube_upload_date="2023-01-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pbKnQYJuSY0/maxresdefault.webp"
comments = true
+++



---
Given two integer arrays `nums1` and `nums2` sorted in non-decreasing order, return the smallest integer that is common to both arrays. If no such integer exists, return `-1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays `nums1` and `nums2`, both sorted in non-decreasing order.
- **Example:** `nums1 = [10, 15, 20], nums2 = [5, 10, 25]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 10^5
	- 1 <= nums1[i], nums2[j] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the smallest integer common to both arrays. If no common integer exists, return `-1`.
- **Example:** `10`
- **Constraints:**
	- The result should be an integer or -1 if no common integer exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the smallest integer that is common in both arrays.

- Initialize two pointers to traverse the arrays.
- Compare elements of both arrays at the current positions of the pointers.
- If the elements match, return the common element as the result.
- If the element in the first array is smaller, increment the pointer for the first array.
- If the element in the second array is smaller, increment the pointer for the second array.
- If no common elements are found, return -1.
{{< dots >}}
### Problem Assumptions ✅
- Both arrays `nums1` and `nums2` are valid and sorted in non-decreasing order.
- The arrays may contain duplicates.
{{< dots >}}
## Examples 🧩
- **Input:** `[4, 7, 9], [5, 7, 8]`  \
  **Explanation:** The smallest common element between both arrays is 7, so the output is 7.

- **Input:** `[10, 15, 20], [5, 10, 25]`  \
  **Explanation:** The smallest common element between both arrays is 10, so the output is 10.

{{< dots >}}
## Approach 🚀
The approach involves using a two-pointer technique to find the smallest common element efficiently.

### Initial Thoughts 💭
- The arrays are sorted, so we can use a two-pointer technique to compare elements in O(n) time.
- By traversing both arrays and comparing the current elements, we can find the smallest common element efficiently.
{{< dots >}}
### Edge Cases 🌐
- Both arrays are assumed to be non-empty.
- Ensure that the solution works efficiently for large inputs with up to 10^5 elements.
- Handle cases where there are no common elements.
- The solution must be efficient enough to handle the largest possible inputs.
{{< dots >}}
## Code 💻
```cpp
int getCommon(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    for(int x: nums1)
        mp[x] = true;
    for(int y: nums2)
        if(mp.count(y))
            return y;
    return -1;
}
```

The function 'getCommon' finds the first common element between two arrays, 'nums1' and 'nums2'. It uses a hash map to store elements from 'nums1' and checks if any element from 'nums2' exists in the map.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
	```
	The function 'getCommon' is defined, which takes two vectors 'nums1' and 'nums2' as input and returns the first common element between them, or -1 if no common element is found.

2. **Map Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	An unordered map 'mp' is initialized to store elements from 'nums1'. The map will help check if any element in 'nums2' is present in 'nums1'.

3. **Loop Through First Array**
	```cpp
	    for(int x: nums1)
	```
	A for loop iterates through each element 'x' of the first array 'nums1'.

4. **Map Population**
	```cpp
	        mp[x] = true;
	```
	For each element 'x' in 'nums1', it is added to the map 'mp' with the value 'true'. This marks the presence of the element in 'nums1'.

5. **Loop Through Second Array**
	```cpp
	    for(int y: nums2)
	```
	A second for loop iterates through each element 'y' in the second array 'nums2'.

6. **Check for Common Element**
	```cpp
	        if(mp.count(y))
	```
	This if statement checks whether the element 'y' from 'nums2' exists in the map 'mp'. The count function returns true if the element is present.

7. **Return Common Element**
	```cpp
	            return y;
	```
	If a common element 'y' is found, it is immediately returned as the first common element between 'nums1' and 'nums2'.

8. **Return -1**
	```cpp
	    return -1;
	```
	If no common element is found after checking all elements of 'nums2', the function returns -1 to indicate there is no common element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only traverse each array once using two pointers.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of extra space for the pointers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-common-value/description/)

---
{{< youtube pbKnQYJuSY0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
