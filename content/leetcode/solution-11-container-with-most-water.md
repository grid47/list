
+++
authors = ["grid47"]
title = "Leetcode 11: Container With Most Water"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 11: Container With Most Water in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/11.webp"
youtube = "Y_4_or0Sc7I"
youtube_upload_date="2024-02-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Y_4_or0Sc7I/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/11.webp" 
    alt="A serene water container being filled with calming light, symbolizing capacity and volume."
    caption="Solution to LeetCode 11: Container With Most Water Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of integers where each integer represents the height of a vertical line drawn on a 2D plane. The x-axis is represented by the index of the array, and each line's height corresponds to the value at that index. Your task is to find two lines that, along with the x-axis, form a container that can hold the most water. The container’s area is determined by the distance between the lines and the height of the shorter line.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array 'height' of length 'n'.
- **Example:** `height = [2, 5, 7, 3, 9, 4]`
- **Constraints:**
	- 2 <= n <= 10^5
	- 0 <= height[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum area of water that the container formed by two lines can hold.
- **Example:** `Output: 30`
- **Constraints:**
	- The maximum area must be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To maximize the water area, we need to find the optimal pair of lines and calculate the area between them.

- Start by initializing two pointers: one at the beginning and one at the end of the array.
- Calculate the area between the lines at the current pointers.
- Move the pointer pointing to the shorter line towards the other pointer to potentially find a larger area.
- Repeat the process until the two pointers meet.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains only non-negative integers representing heights.
{{< dots >}}
## Examples 🧩
- **Input:** `height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`  \
  **Explanation:** In this case, the maximum area is formed by the lines at index 1 and index 8. The area is calculated as min(8, 7) * (8 - 1) = 49.

- **Input:** `height = [3, 9, 1, 8, 6, 4]`  \
  **Explanation:** The maximum area is formed by the lines at index 1 and index 3. The area is calculated as min(9, 8) * (3 - 1) = 16.

{{< dots >}}
## Approach 🚀
We will use the two-pointer technique to efficiently find the maximum area.

### Initial Thoughts 💭
- To maximize the area, we need to consider the width between two lines and their heights.
- The height of the container is determined by the shorter of the two lines, so we need to focus on the smaller heights.
- The optimal solution involves checking the areas formed by lines at the current left and right pointers, then adjusting the pointers inward based on the shorter line.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least two elements, so no need to handle empty arrays.
- Ensure that the solution can handle the upper limit of the array size (100,000 elements).
- If all heights are equal, the largest area is formed by the first and last line.
- The algorithm should run efficiently with a time complexity of O(n).
{{< dots >}}
## Code 💻
```cpp
int maxArea(vector<int>& height) {
    int res = 0;
    int i = 0, j = height.size() -1;
    
    while(i < j) {
        res = max(res, min(height[i], height[j]) * (j - i));
        if(height[i] < height[j])
            i++;
        else j--;
    }
    return res;
}
```

This code implements the `maxArea` function, which finds the container with the most water.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxArea(vector<int>& height) {
	```
	Declare the `maxArea` function, which takes a vector of integers `height` representing the height of each container wall.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize a variable `res` to store the maximum area found so far.

3. **Variable Initialization**
	```cpp
	    int i = 0, j = height.size() -1;
	```
	Initialize two pointers `i` and `j` to point to the beginning and end of the vector, respectively.

4. **Loop Iteration**
	```cpp
	    while(i < j) {
	```
	Start the loop body.

5. **Mathematical Operations**
	```cpp
	        res = max(res, min(height[i], height[j]) * (j - i));
	```
	Calculate the area of the current container, which is the minimum of the heights at `i` and `j` multiplied by the distance between them. Update `res` if the current area is larger.

6. **Conditional Check**
	```cpp
	        if(height[i] < height[j])
	```
	Check if the height at `i` is less than the height at `j`.

7. **Index Update**
	```cpp
	            i++;
	```
	If the height at `i` is smaller, move `i` to the right to potentially find a larger container.

8. **Index Update**
	```cpp
	        else j--;
	```
	Otherwise, move `j` to the left to potentially find a larger container.

9. **Loop Iteration**
	```cpp
	    }
	```
	End of the loop.

10. **Return Value**
	```cpp
	    return res;
	```
	Return the maximum area found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm only requires a single pass through the array with two pointers, so it runs in linear time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only need a few variables to track the maximum area and the positions of the two pointers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/container-with-most-water/description/)

---
{{< youtube Y_4_or0Sc7I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
