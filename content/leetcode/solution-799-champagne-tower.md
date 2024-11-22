
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem is a simulation of pouring champagne into a triangular tower of glasses. The tower consists of rows of glasses, where each glass can hold at most 1 unit of champagne. The goal is to determine how much champagne will be in a specific glass after pouring a certain amount of champagne into the topmost glass.

### Problem Details:
- We are given an integer `poured` representing the amount of champagne to be poured into the topmost glass.
- We are also given `query_row` and `query_glass`, which specify the row and glass in the tower for which we need to determine the amount of champagne remaining after the pour.

The tower follows a specific structure:
- The first row contains one glass.
- The second row contains two glasses.
- The third row contains three glasses.
- And so on.

When champagne is poured into a glass, any excess champagne (overflow) is evenly distributed into the two glasses directly below it. If a glass exceeds its maximum capacity of 1 unit, the excess champagne overflows equally to the two glasses directly below it.

### Objective:
Determine the amount of champagne in the glass at the position `[query_row][query_glass]` after pouring `poured` units of champagne into the topmost glass.

### Approach

The problem requires simulating the pouring process into the champagne tower. We can break down the approach as follows:

1. **Simulate the pouring process**:
   - Start by pouring the champagne into the topmost glass.
   - For each row, calculate the overflow and distribute it equally into the glasses below.
   - The glasses below the current one can receive overflow from the current glass if it exceeds its capacity of 1 unit.

2. **Tracking the champagne in each glass**:
   - The glasses are modeled as rows of a list where each row contains an array representing the glasses in that row.
   - For each glass, if the amount of champagne exceeds 1, the excess champagne is split equally between the two glasses in the next row directly beneath it.

3. **Iterate through each row until reaching the row of interest**:
   - Each row has one more glass than the previous row, so it is important to track the pouring process row by row.
   - Once the simulation reaches the `query_row`, return the amount of champagne in the specified `query_glass` of that row.

4. **Optimized space usage**:
   - The solution avoids storing the entire tower structure for all rows. Instead, only the current row and the next row are kept in memory at any given time to reduce the space complexity.

### Code Breakdown (Step by Step)

Let’s walk through the code:

```cpp
double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> currRow(1, poured);  // Initialize the top row with poured champagne.

    // Loop through each row up to the query_row
    for(int i = 0; i <= query_row; i++) {
        vector<double> nextrow(i + 2, 0);  // Initialize the next row with 0 champagne.
```
- We start by initializing the `currRow` vector, which represents the glasses in the current row, and set the topmost glass to the amount of poured champagne.
- For each row up to the `query_row`, we create the next row (`nextrow`), which has one more glass than the current row.

```cpp
        for(int j = 0; j <= i; j++) {
            // Check if the current glass has more than 1 unit of champagne.
            if(currRow[j] >= 1) {
                nextrow[j]      += (currRow[j] - 1) / 2.0;  // Overflow to the left glass in the next row.
                nextrow[j + 1]  += (currRow[j] - 1) / 2.0;  // Overflow to the right glass in the next row.
                currRow[j]       = 1;  // Set current glass to 1 (maximum capacity).
            }
        }
```
- In this loop, we check each glass in the current row (`currRow`). If a glass contains more than 1 unit of champagne, the excess is distributed equally to the two glasses directly below it (in the next row).
- We update the `currRow` to reflect that the current glass has reached its maximum capacity of 1.

```cpp
        if(i != query_row) currRow = nextrow;  // Update the current row to the next row.
    }
```
- Once we have processed the current row, we update `currRow` to `nextrow` for the next iteration. If we've reached the row of interest (`query_row`), we stop updating `currRow`.

```cpp
    return currRow[query_glass];  // Return the amount of champagne in the queried glass.
}
```
- After the loop finishes, `currRow` contains the amount of champagne in each glass of the `query_row`. We simply return the amount in the `query_glass`.

### Complexity

#### Time Complexity:
The time complexity of the solution is **O(query_row)**, where `query_row` is the row we are interested in. This is because:
- For each row, we process each glass in the row, and the number of glasses in each row is `i + 1` (where `i` is the current row index).
- The total number of glasses we process is approximately the sum of the first `query_row` integers, which is O(query_row^2).
- Since we only need to process up to `query_row` and not all rows, the time complexity is O(query_row).

#### Space Complexity:
The space complexity is **O(query_row)** because:
- We only store the `currRow` and `nextrow` arrays, each of which can have at most `query_row + 1` elements.
- Thus, the space complexity is linear in the number of rows, i.e., O(query_row).

### Conclusion

The solution efficiently simulates the pouring process in the champagne tower using two arrays (`currRow` and `nextrow`) to track the amount of champagne in each glass at each stage. By iterating over each row up to the `query_row`, the solution determines the amount of champagne in the specified glass without needing to store the entire tower structure.

This approach is both time and space efficient, with a time complexity of O(query_row) and a space complexity of O(query_row). It effectively handles the problem constraints and provides the correct result for any valid input values.

[`Link to LeetCode Lab`](https://leetcode.com/problems/champagne-tower/description/)

---
{{< youtube LQ8TuG_QADM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
