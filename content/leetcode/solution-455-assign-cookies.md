
+++
authors = ["grid47"]
title = "Leetcode 455: Assign Cookies"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 455: Assign Cookies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/455.webp"
youtube = "AXaPmVMkVAE"
youtube_upload_date="2019-11-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AXaPmVMkVAE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/455.webp" 
    alt="A series of cookies and children with glowing indicators of the best cookie assignment."
    caption="Solution to LeetCode 455: Assign Cookies Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are a parent with several children and a set of cookies. Each child has a greed factor, which is the minimum size of a cookie they will be happy with. Each cookie also has a size. Your task is to distribute the cookies such that you maximize the number of content children. Each child can receive at most one cookie, and each cookie can only be given to one child.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: one representing the greed factors of children and another representing the sizes of cookies.
- **Example:** `g = [1, 2, 3], s = [1, 1]`
- **Constraints:**
	- 1 <= g.length <= 3 * 10^4
	- 0 <= s.length <= 3 * 10^4
	- 1 <= g[i], s[j] <= 231 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of content children that can be satisfied by the cookies.
- **Example:** `Output: 1`
- **Constraints:**
	- The result should be the number of content children that can be satisfied.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum number of children that can be satisfied by distributing the cookies.

- 1. Sort both the greed factors and the sizes of cookies in ascending order.
- 2. Use a two-pointer approach: one pointer for the children and one for the cookies.
- 3. Iterate through the sorted arrays and try to match the smallest available cookie that can satisfy each child. If a match is found, move to the next child and the next cookie.
{{< dots >}}
### Problem Assumptions ✅
- Each child and cookie has a non-negative greed factor and size respectively.
- Cookies may not be large enough to satisfy all children.
{{< dots >}}
## Examples 🧩
- **Input:** `g = [1, 2, 3], s = [1, 1]`  \
  **Explanation:** In this case, you can only satisfy one child, as both cookies are too small to satisfy the children with greed factors of 2 and 3.

- **Input:** `g = [1, 2], s = [1, 2, 3]`  \
  **Explanation:** Here, both children can be satisfied because there are enough cookies of suitable size.

{{< dots >}}
## Approach 🚀
This approach aims to maximize the number of children that can be satisfied by greedily assigning the smallest possible cookie that satisfies each child's greed.

### Initial Thoughts 💭
- Sorting the greed factors and cookie sizes will allow for an efficient greedy approach.
- Using a two-pointer technique ensures that we can match children to cookies in O(n log n) time.
{{< dots >}}
### Edge Cases 🌐
- If there are no cookies (s.length = 0), the result is 0.
- The algorithm must be optimized to handle large inputs efficiently, ensuring time complexity remains manageable for large arrays.
- If all cookies are too small to satisfy any child, the result should be 0.
- The solution should run in O(n log n) time due to sorting.
{{< dots >}}
## Code 💻
```cpp
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i = 0, j=0;
    while(i<g.size() && j<s.size()){
        if(s[j]>=g[i])
            i++; // when the child get the cookie, foward child by 1
        j++;
    }
    return i;
}
```

The `findContentChildren` function solves the problem where children with a certain greed factor are trying to get cookies of various sizes. The goal is to maximize the number of children that can be satisfied with the available cookies using a greedy algorithm.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findContentChildren(vector<int>& g, vector<int>& s) {
	```
	Defines the function `findContentChildren` that takes two integer vectors `g` (greed factors of children) and `s` (sizes of cookies), and returns the maximum number of children that can be satisfied.

2. **Sorting**
	```cpp
	    sort(g.begin(),g.end());
	```
	Sorts the greed factors of the children in ascending order so that the child with the smallest greed factor gets the smallest available cookie.

3. **Sorting**
	```cpp
	    sort(s.begin(),s.end());
	```
	Sorts the sizes of the cookies in ascending order, ensuring that we start from the smallest available cookie to try to satisfy the children.

4. **Variable Initialization**
	```cpp
	    int i = 0, j=0;
	```
	Initializes two indices: `i` for the children array `g` and `j` for the cookies array `s`. Both indices start from 0.

5. **Loop**
	```cpp
	    while(i<g.size() && j<s.size()){
	```
	Starts a while loop that continues as long as there are unprocessed children and cookies.

6. **Condition Check**
	```cpp
	        if(s[j]>=g[i])
	```
	Checks if the current cookie `s[j]` can satisfy the child `i` (i.e., if the size of the cookie is greater than or equal to the child's greed factor).

7. **Greedy Algorithm**
	```cpp
	            i++; // when the child get the cookie, foward child by 1
	```
	If the cookie satisfies the child, increments `i` to move to the next child.

8. **Greedy Algorithm**
	```cpp
	        j++;
	```
	Increments `j` to check the next available cookie.

9. **Return Statement**
	```cpp
	    return i;
	```
	Returns the value of `i`, which represents the number of children that were satisfied with cookies.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) to store the greed factors and cookie sizes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/assign-cookies/description/)

---
{{< youtube AXaPmVMkVAE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
