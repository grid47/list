
+++
authors = ["grid47"]
title = "Leetcode 799: Champagne Tower"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 799: Champagne Tower in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/799.webp"
youtube = "LQ8TuG_QADM"
youtube_upload_date="2023-09-24"
youtube_thumbnail="https://i.ytimg.com/vi/LQ8TuG_QADM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/799.webp" 
    alt="A tower of champagne glasses where the champagne is poured, each glass softly glowing as it fills."
    caption="Solution to LeetCode 799: Champagne Tower Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a champagne tower in the shape of a pyramid. The topmost glass is filled with a specified amount of champagne. When a glass is full, the excess champagne spills equally into the two glasses directly beneath it. Given the total amount of champagne poured, determine how full a particular glass at row `query_row` and glass `query_glass` will be after the champagne has spilled.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three values: `poured`, the total amount of champagne poured into the topmost glass, and `query_row` and `query_glass`, which specify the row and position of the glass to query.
- **Example:** `Input: poured = 3, query_row = 2, query_glass = 1`
- **Constraints:**
	- 0 <= poured <= 10^9
	- 0 <= query_glass <= query_row < 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the amount of champagne in the queried glass, ensuring the result is rounded to five decimal places.
- **Example:** `Output: 0.50000`
- **Constraints:**
	- The returned result must be accurate to five decimal places.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the pouring and spilling process and determine how full a specific glass is.

- Initialize an array to represent the glasses, starting with the topmost glass filled with the specified amount of champagne.
- For each row, calculate the champagne that overflows from each glass, and distribute it equally between the two glasses directly beneath it.
- Repeat the process until the row of interest is reached, ensuring each glass's content is capped at 1 unit of champagne.
{{< dots >}}
### Problem Assumptions ✅
- The number of glasses in each row is incremental, with the ith row containing i+1 glasses.
- Champagne only spills to the glasses directly beneath, left and right.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: poured = 3, query_row = 2, query_glass = 1`  \
  **Explanation:** After pouring 3 cups of champagne, the first row has 1 cup, the second row has 1.5 cups (with each glass receiving 0.5 cups), and the third row has the second glass with 0.5 cups (because it receives a portion of the excess from the second row).

- **Input:** `Input: poured = 6, query_row = 2, query_glass = 0`  \
  **Explanation:** Pouring 6 cups results in the first row having 1 cup, the second row having 2 cups (with each glass full), and the third row has the two outer glasses each filled to 0.5 cups.

{{< dots >}}
## Approach 🚀
The solution simulates the process of pouring champagne into the tower row by row, from top to bottom, and computes how much champagne remains in a given glass.

### Initial Thoughts 💭
- The amount of champagne poured can be very large, so efficient simulation is necessary to avoid excessive computations.
- We can maintain an array of glasses for each row and keep track of the overflow from each glass, distributing it to the next row.
{{< dots >}}
### Edge Cases 🌐
- If poured equals 0, no champagne is poured, and all glasses remain empty.
- If poured is very large (e.g., 10^9), ensure the simulation still runs efficiently within time limits.
- If query_row is 0, the only glass of interest is the topmost glass, which will contain all the poured champagne if it's less than 1 cup.
- Make sure not to exceed the maximum capacity of any glass, as each glass can hold a maximum of 1 cup.
{{< dots >}}
## Code 💻
```cpp
double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> currRow(1, poured);

    for(int i = 0; i <= query_row; i++) {
        vector<double> nextrow(i + 2, 0);
        for(int j = 0; j <= i; j++) {
            if(currRow[j] >= 1) {
                nextrow[j]      += (currRow[j] - 1)/2.0;
                nextrow[j + 1]  += (currRow[j] - 1)/2.0;
                currRow[j]       = 1;
            }
        }
        if(i != query_row) currRow = nextrow;
    }
    return currRow[query_glass];
}
```

This code solves the champagne tower problem, simulating how champagne flows from a source glass to lower glasses. The function calculates the amount of champagne in a specific glass at a particular row in the tower after pouring a given amount of champagne.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	double champagneTower(int poured, int query_row, int query_glass) {
	```
	This is the function definition for `champagneTower`, which takes in three arguments: `poured` (total champagne poured), `query_row` (the row of the glass to query), and `query_glass` (the specific glass in that row).

2. **Initialization**
	```cpp
	    vector<double> currRow(1, poured);
	```
	Initializes a vector `currRow` to hold the current row of glasses, with the first glass containing all the poured champagne.

3. **Loop**
	```cpp
	    for(int i = 0; i <= query_row; i++) {
	```
	A loop that iterates through each row from the top to the queried row (`query_row`).

4. **Row Initialization**
	```cpp
	        vector<double> nextrow(i + 2, 0);
	```
	Creates a new row `nextrow` with `i + 2` glasses initialized to 0.0, where `i + 2` accounts for the maximum glasses at that row.

5. **Inner Loop**
	```cpp
	        for(int j = 0; j <= i; j++) {
	```
	A nested loop that iterates through each glass in the current row `i`.

6. **Champagne Overflow Check**
	```cpp
	            if(currRow[j] >= 1) {
	```
	Checks if the current glass `currRow[j]` contains more than or equal to 1 unit of champagne, indicating overflow.

7. **Champagne Redistribution**
	```cpp
	                nextrow[j]      += (currRow[j] - 1)/2.0;
	```
	Redistributes the overflow champagne to the left glass in the next row.

8. **Champagne Redistribution**
	```cpp
	                nextrow[j + 1]  += (currRow[j] - 1)/2.0;
	```
	Redistributes the overflow champagne to the right glass in the next row.

9. **Champagne Overflow Adjustment**
	```cpp
	                currRow[j]       = 1;
	```
	Sets the current glass to 1, as it can only hold a maximum of 1 unit of champagne.

10. **Row Transition**
	```cpp
	        if(i != query_row) currRow = nextrow;
	```
	Transfers the `nextrow` as `currRow` for the next iteration, unless the queried row has been reached.

11. **Return Statement**
	```cpp
	    return currRow[query_glass];
	```
	Returns the amount of champagne in the glass specified by `query_glass` in the `query_row`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(query_row), as we only need to process up to the queried row.
- **Average Case:** O(query_row), which is linear in terms of the number of rows up to the queried row.
- **Worst Case:** O(query_row), since we must process all glasses in each row up to the queried row.

The time complexity is linear with respect to the number of rows, as we process each row once.

### Space Complexity 💾
- **Best Case:** O(query_row), since we need space for each row's glasses.
- **Worst Case:** O(query_row), as we need to store the glasses for each row.

The space complexity is linear, as we need space to store the glasses for each row up to the queried row.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/champagne-tower/description/)

---
{{< youtube LQ8TuG_QADM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
