
+++
authors = ["grid47"]
title = "Leetcode 835: Image Overlap"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 835: Image Overlap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zfjBapE3Y6E"
youtube_upload_date="2020-09-06"
youtube_thumbnail="https://i.ytimg.com/vi/zfjBapE3Y6E/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGCwgTih_MA8=&rs=AOn4CLDYXzk8BIj-n6f1vDE8kuCRNpZ81A"
comments = true
+++



---
You are given two square binary matrices img1 and img2, both of size n x n. Each matrix consists of 0s and 1s. You are allowed to slide img1 over img2 in any direction (up, down, left, or right) without rotating the matrix. Your task is to find the maximum number of overlapping positions where both img1 and img2 have a 1 in the same position after performing a translation.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two n x n binary matrices img1 and img2, both representing images with 0s and 1s.
- **Example:** `Input: img1 = [[1,0,0], [1,0,0], [0,0,0]], img2 = [[0,1,0], [0,1,0], [0,0,0]]`
- **Constraints:**
	- 1 <= n <= 30
	- img1[i][j] is either 0 or 1.
	- img2[i][j] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the largest number of overlapping 1s after translating img1 over img2.
- **Example:** `Output: 2`
- **Constraints:**
	- The largest overlap can be calculated as the maximum number of 1s overlapping in both matrices after translation.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the maximum number of 1s that overlap after translating img1 over img2.

- Step 1: Extract the positions of 1s in both img1 and img2.
- Step 2: For each possible translation (i.e., shifts in horizontal and vertical directions), calculate the number of overlapping 1s.
- Step 3: Return the maximum overlap found across all translations.
{{< dots >}}
### Problem Assumptions ✅
- The matrices img1 and img2 are always of the same size.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: img1 = [[1,0,0], [1,0,0], [0,0,0]], img2 = [[0,1,0], [0,1,0], [0,0,0]]`  \
  **Explanation:** In this example, the translation that aligns the 1s in both images gives a maximum overlap of 2.

- **Input:** `Input: img1 = [[1,1,0], [0,1,0], [0,1,0]], img2 = [[0,0,0], [0,1,1], [0,0,1]]`  \
  **Explanation:** After translating img1 right and down by 1 unit, we obtain a maximum overlap of 3.

{{< dots >}}
## Approach 🚀
The key approach is to iterate over all possible translations of img1 and compute the overlap with img2. This can be achieved by iterating through all combinations of shifts along both axes and checking for the overlap of 1s.

### Initial Thoughts 💭
- We need to check all possible translations by sliding img1 over img2 in both horizontal and vertical directions.
- By extracting the positions of 1s and counting the overlaps for each translation, we can find the largest overlap efficiently.
{{< dots >}}
### Edge Cases 🌐
- An empty matrix (with all 0s) will result in no overlap.
- Ensure that the solution can handle the maximum input size (n=30).
- Consider cases where one matrix is completely filled with 1s and the other with 0s.
- Ensure that translations do not cause indices to go out of bounds.
{{< dots >}}
## Code 💻
```cpp
int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    vector<int> la, lb;
    int n = img1.size();
    for(int i = 0; i < n*n; i++)
        if(img1[i/n][i%n] == 1)
        la.push_back(i/n*100+ i%n);
    for(int i = 0; i < n*n; i++)
        if(img2[i/n][i%n] == 1)
        lb.push_back(i/n*100+ i%n);
    unordered_map<int, int> mp;
    for(int i : la)
    for(int j : lb)
        mp[i-j]++;
    int res = 0;
    for(auto it: mp)
    res = max(res, it.second);
    return res;
}
```

This function computes the largest overlap between two binary matrices by comparing their 1's at different relative positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
	```
	Function declaration: This function takes two 2D vectors `img1` and `img2` representing binary matrices, and returns an integer, the size of the largest overlap.

2. **Variable Initialization**
	```cpp
	    vector<int> la, lb;
	```
	Initialization of two vectors `la` and `lb` to store the positions of 1's in `img1` and `img2` respectively.

3. **Matrix Size**
	```cpp
	    int n = img1.size();
	```
	Here, `n` stores the size of the matrix, assuming both `img1` and `img2` are square matrices.

4. **Loop Through img1**
	```cpp
	    for(int i = 0; i < n*n; i++)
	```
	Looping over each index of the matrix `img1` to identify positions of 1's.

5. **Check Condition img1**
	```cpp
	        if(img1[i/n][i%n] == 1)
	```
	Checking if the current element in `img1` is 1.

6. **Store Position in la**
	```cpp
	        la.push_back(i/n*100+ i%n);
	```
	If the element is 1, store the position of 1 in `la` by encoding the row and column.

7. **Loop Through img2**
	```cpp
	    for(int i = 0; i < n*n; i++)
	```
	Looping over each index of the matrix `img2` to identify positions of 1's.

8. **Check Condition img2**
	```cpp
	        if(img2[i/n][i%n] == 1)
	```
	Checking if the current element in `img2` is 1.

9. **Store Position in lb**
	```cpp
	        lb.push_back(i/n*100+ i%n);
	```
	If the element is 1, store the position of 1 in `lb` by encoding the row and column.

10. **Map Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	Create an unordered map `mp` to store the differences of positions between `la` and `lb` and their frequencies.

11. **Nested Loop**
	```cpp
	    for(int i : la)
	```
	Loop through the elements in `la`.

12. **Nested Loop lb**
	```cpp
	    for(int j : lb)
	```
	For each element in `la`, loop through elements in `lb`.

13. **Update Map**
	```cpp
	        mp[i-j]++;
	```
	For each pair of positions from `la` and `lb`, calculate the difference and increment its count in the map `mp`.

14. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable `res` to store the maximum frequency of position differences.

15. **Loop Through Map**
	```cpp
	    for(auto it: mp)
	```
	Loop through the entries in the map `mp`.

16. **Update Result**
	```cpp
	    res = max(res, it.second);
	```
	Update the result `res` to store the maximum frequency of the position difference.

17. **Return Result**
	```cpp
	    return res;
	```
	Return the result `res`, which represents the largest overlap of 1's between `img1` and `img2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), when there are minimal 1s and no significant overlap.
- **Average Case:** O(n^4), due to iterating over all possible translations and computing overlaps.
- **Worst Case:** O(n^4), in the case where there are many 1s and the number of comparisons is large.

The time complexity is dominated by the nested loops that check each possible translation and overlap.

### Space Complexity 💾
- **Best Case:** O(n^2), in case we store all the positions of 1s from both matrices.
- **Worst Case:** O(n^2), to store the positions of the 1s in both matrices.

The space complexity is determined by the storage of the positions of 1s in both img1 and img2.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/image-overlap/description/)

---
{{< youtube zfjBapE3Y6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
