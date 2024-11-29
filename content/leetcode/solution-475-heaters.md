
+++
authors = ["grid47"]
title = "Leetcode 475: Heaters"
date = "2024-09-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 475: Heaters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/475.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/475.webp" 
    alt="A grid where heaters light up and warm nearby houses, with each heater softly illuminating its effect."
    caption="Solution to LeetCode 475: Heaters Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the positions of houses and heaters along a horizontal line. Your task is to find the minimum radius required for the heaters so that all houses are within the heater's warm radius.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: `houses` representing the positions of the houses and `heaters` representing the positions of the heaters.
- **Example:** `houses = [2, 5, 7, 10], heaters = [1, 8]`
- **Constraints:**
	- 1 <= houses.length, heaters.length <= 3 * 10^4
	- 1 <= houses[i], heaters[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum radius required for the heaters to cover all houses.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be an integer representing the minimum radius for heaters.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum radius required for heaters to ensure all houses are covered.

- 1. Sort the positions of both the houses and the heaters.
- 2. For each house, calculate the nearest heater and determine the distance between them.
- 3. The largest distance across all houses will determine the required radius of the heaters.
{{< dots >}}
### Problem Assumptions ✅
- The heaters can be placed at any position along the horizontal line.
- There is no overlap in the positions of houses and heaters.
{{< dots >}}
## Examples 🧩
- **Input:** `houses = [2, 5, 7, 10], heaters = [1, 8]`  \
  **Explanation:** Heaters at positions 1 and 8 with a radius of 3 can cover all the houses.

- **Input:** `houses = [5, 10], heaters = [6]`  \
  **Explanation:** A heater at position 6 with a radius of 4 can cover both houses at positions 5 and 10.

{{< dots >}}
## Approach 🚀
The approach involves sorting the house and heater positions, then calculating the minimum required radius by comparing distances.

### Initial Thoughts 💭
- Sorting the houses and heaters simplifies the task of finding the nearest heater for each house.
- A greedy approach that evaluates the closest heater to each house would be efficient.
- By calculating the distance from each house to its nearest heater, we can determine the minimum radius required for coverage.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one house and one heater, as per the constraints.
- Handle cases where the number of houses or heaters is large (up to 30,000).
- Consider cases where all heaters are clustered in one area or spread across a wide range.
- Ensure the solution works efficiently within the constraints of up to 30,000 houses and heaters.
{{< dots >}}
## Code 💻
```cpp
int findRadius(vector<int>& home, vector<int>& warm) {
    sort(home.begin(), home.end());
    sort(warm.begin(), warm.end());
    int m = home.size(), n = warm.size();
    
    vector<int> res(m, INT_MAX);
    
    for(int h = 0, w = 0; h < m && w < n; ) {
        if (home[h] <= warm[w]) {
            res[h] = warm[w] - home[h];
            h++;
        } else w++;
    }
    
    for(int h = m - 1, w = n - 1; h >= 0 && w >= 0; ) {
        if (home[h] >= warm[w]) {
            res[h] = min(res[h], home[h] - warm[w]);
            h--;
        } else w--;
    }
    
    return *max_element(res.begin(), res.end());
}
```

The `findRadius` function calculates the minimum radius for which all homes can be covered by warm heaters. The algorithm sorts both home and heater positions and uses two sweeps, from left to right and right to left, to find the closest heater for each home. Finally, the function returns the largest of these minimum distances.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findRadius(vector<int>& home, vector<int>& warm) {
	```
	Defines the `findRadius` function, which takes two vectors, `home` and `warm`, representing the positions of homes and warm heaters, and returns the minimum radius required to ensure every home is covered.

2. **Sorting**
	```cpp
	    sort(home.begin(), home.end());
	```
	Sorts the `home` vector to facilitate the process of finding the closest heater for each home.

3. **Sorting**
	```cpp
	    sort(warm.begin(), warm.end());
	```
	Sorts the `warm` vector to make it easier to check the closest heater to a given home.

4. **Variable Initialization**
	```cpp
	    int m = home.size(), n = warm.size();
	```
	Initializes `m` as the number of homes and `n` as the number of heaters.

5. **Vector Initialization**
	```cpp
	    vector<int> res(m, INT_MAX);
	```
	Initializes a vector `res` of size `m` (the number of homes), setting each element to `INT_MAX` as an initial placeholder for the minimum distances to the closest heater.

6. **Left to Right Sweep**
	```cpp
	    for(int h = 0, w = 0; h < m && w < n; ) {
	```
	Begins a loop that iterates over both homes (`h`) and heaters (`w`) from left to right to compute the closest heater to each home.

7. **Condition Check**
	```cpp
	        if (home[h] <= warm[w]) {
	```
	Checks if the current home is to the left of or at the current heater position.

8. **Update Distance**
	```cpp
	            res[h] = warm[w] - home[h];
	```
	Updates the minimum distance for home `h` to the current heater `w`.

9. **Increment Home Pointer**
	```cpp
	            h++;
	```
	Increments the home pointer `h` to consider the next home.

10. **Increment Heater Pointer**
	```cpp
	        } else w++;
	```
	If the current home is not covered by the current heater, increments the heater pointer `w` to check the next heater.

11. **Right to Left Sweep**
	```cpp
	    for(int h = m - 1, w = n - 1; h >= 0 && w >= 0; ) {
	```
	Begins a loop that iterates over both homes (`h`) and heaters (`w`) from right to left to compute the closest heater to each home in the reverse direction.

12. **Condition Check**
	```cpp
	        if (home[h] >= warm[w]) {
	```
	Checks if the current home is to the right of or at the current heater position.

13. **Update Distance**
	```cpp
	            res[h] = min(res[h], home[h] - warm[w]);
	```
	Updates the minimum distance for home `h` by considering the current heater `w` and taking the minimum between the previous calculated distance and the new one.

14. **Decrement Home Pointer**
	```cpp
	            h--;
	```
	Decrements the home pointer `h` to consider the next home in the reverse direction.

15. **Decrement Heater Pointer**
	```cpp
	        } else w--;
	```
	If the current home is not covered by the current heater, decrements the heater pointer `w` to check the next heater in the reverse direction.

16. **Final Calculation**
	```cpp
	    return *max_element(res.begin(), res.end());
	```
	Returns the maximum value from the `res` vector, which represents the largest of the minimum distances to the closest heater for all homes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the houses and heaters requires O(n log n) time, where n is the number of houses or heaters.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for sorting the arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/heaters/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
