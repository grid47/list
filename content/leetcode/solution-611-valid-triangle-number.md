
+++
authors = ["grid47"]
title = "Leetcode 611: Valid Triangle Number"
date = "2024-09-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 611: Valid Triangle Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/611.webp"
youtube = "AZrQMv5ne54"
youtube_upload_date="2021-02-27"
youtube_thumbnail="https://i.ytimg.com/vi/AZrQMv5ne54/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/611.webp" 
    alt="A set of triangle side lengths where the valid triangles glow softly, and invalid ones fade."
    caption="Solution to LeetCode 611: Valid Triangle Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers, return the number of triplets that can form a valid triangle. A valid triangle is formed when the sum of any two sides is greater than the third side.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers representing the side lengths of the triangle.
- **Example:** `nums = [1, 2, 3, 4]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 0 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of triplets from the array that can form a valid triangle.
- **Example:** `3`
- **Constraints:**
	- The result is an integer representing the number of valid triplets.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine how many triplets from the array satisfy the triangle inequality property.

- Sort the array in non-decreasing order.
- For each element in the array, consider it as the largest side of the triangle.
- Use two pointers to find pairs of smaller sides that form a valid triangle with the largest side.
{{< dots >}}
### Problem Assumptions ✅
- The numbers in the array represent side lengths of a potential triangle.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3, 4]`  \
  **Explanation:** In this case, there are three valid triangles that can be formed by picking different combinations of side lengths.

{{< dots >}}
## Approach 🚀
The approach is to first sort the array and then use a two-pointer technique to find valid triplets that satisfy the triangle inequality.

### Initial Thoughts 💭
- Sorting the array helps us efficiently check for valid triplets by leveraging the triangle inequality.
- By sorting the array and iterating through it, we can reduce the time complexity and find the triplets in linear time.
{{< dots >}}
### Edge Cases 🌐
- An empty input array.
- Handling arrays of size 1000 with large values.
- Arrays with duplicate values or elements that cannot form a triangle.
- Ensure that the algorithm works within the time limits for large arrays.
{{< dots >}}
## Code 💻
```cpp
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int cnt = 0, n = nums.size();
    
    for(int i = n - 1; i >= 0; i--)
        for(int j = 0, k = i - 1; j < k;) {
            if(nums[i] < nums[j] + nums[k]) {
                cnt+= k - j;
                k--;
            } else j++;
        }
    
    return cnt;
}
```

The `triangleNumber` function counts the number of valid triangles that can be formed from an array of side lengths. A valid triangle satisfies the triangle inequality theorem, where the sum of the lengths of any two sides must be greater than the third side.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int triangleNumber(vector<int>& nums) {
	```
	Defines the function `triangleNumber` that takes a vector of integers (`nums`) representing side lengths and returns an integer count of valid triangles that can be formed.

2. **Sort Input**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the input array `nums` in ascending order to facilitate the triangle validation process. Sorting helps reduce the number of checks needed when evaluating potential triangles.

3. **Variable Initialization (cnt, n)**
	```cpp
	    int cnt = 0, n = nums.size();
	```
	Initializes a counter `cnt` to 0, which will track the number of valid triangles. It also stores the size of the array `nums` in the variable `n`.

4. **Outer Loop (i)**
	```cpp
	    for(int i = n - 1; i >= 0; i--)
	```
	The outer loop starts from the largest element in the sorted array (`i = n - 1`) and iterates downwards. This loop helps in checking the largest side of the triangle first.

5. **Inner Loop (j, k)**
	```cpp
	        for(int j = 0, k = i - 1; j < k;) {
	```
	The inner loop uses two pointers, `j` and `k`, to check potential pairs of sides (`nums[j]`, `nums[k]`) with the current largest side (`nums[i]`). The pointers move towards each other to check all possible pairs.

6. **Triangle Validation Check**
	```cpp
	            if(nums[i] < nums[j] + nums[k]) {
	```
	Checks if the current set of sides (`nums[i]`, `nums[j]`, `nums[k]`) forms a valid triangle based on the triangle inequality theorem (sum of two sides must be greater than the third side).

7. **Update Count**
	```cpp
	                cnt+= k - j;
	```
	If the sides form a valid triangle, the count `cnt` is updated. The number of valid triangles is incremented by `k - j` because all pairs of sides between `j` and `k` form valid triangles with the current `i`.

8. **Move Pointer k**
	```cpp
	                k--;
	```
	Decrements the pointer `k` to check the next possible smaller side for forming valid triangles.

9. **Move Pointer j**
	```cpp
	            } else j++;
	```
	If the sides do not form a valid triangle, increment the pointer `j` to check the next possible larger side.

10. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the total count `cnt` of valid triangles that can be formed from the input side lengths.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N^2)
- **Average Case:** O(N^2)
- **Worst Case:** O(N^2)

The time complexity is O(N^2) due to the two-pointer approach after sorting the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a constant amount of space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-triangle-number/description/)

---
{{< youtube AZrQMv5ne54 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
