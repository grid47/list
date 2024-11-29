
+++
authors = ["grid47"]
title = "Leetcode 1854: Maximum Population Year"
date = "2024-05-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1854: Maximum Population Year in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Counting","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "2W2yijatcTY"
youtube_upload_date="2021-05-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2W2yijatcTY/maxresdefault.webp"
comments = true
+++



---
You are given a 2D array `logs` where each entry represents the birth and death years of a person. You need to determine the earliest year that has the maximum population, where population is defined as the number of people alive in a given year.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array `logs` where each element is a list `[birthi, deathi]`, representing the birth and death years of a person.
- **Example:** `[[1980, 1990], [1985, 1995], [1990, 2000]]`
- **Constraints:**
	- 1 <= logs.length <= 100
	- 1950 <= birthi < deathi <= 2050

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the earliest year with the maximum population.
- **Example:** `1990`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the earliest year where the population is maximized. This involves counting the number of people alive in each year and finding the year with the highest population.

- Use an array to track population changes by year. Increase the population at birth years and decrease it at death years.
- Accumulate population over the years and find the year with the maximum population.
- If there are multiple years with the same population, return the earliest year.
{{< dots >}}
### Problem Assumptions ✅
- The input array `logs` will always contain valid birth and death years.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1980,1990], [1985,1995], [1990,2000]]`  \
  **Explanation:** In this example, the population is maximized in the year 1990, as all three people are alive during that year. Hence, the earliest year with the maximum population is 1990.

{{< dots >}}
## Approach 🚀
To solve this problem, track population changes over time by incrementing the population at birth years and decrementing it at death years. Then, accumulate the population for each year and return the earliest year with the highest population.

### Initial Thoughts 💭
- We need to calculate population changes for each year and determine the year with the highest population.
- A simple way to approach this is by using an array to track changes in population by year.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one entry in the input array `logs`.
- The input array can have up to 100 entries, so the algorithm should handle this efficiently.
- Consider cases where multiple years have the same maximum population.
- Ensure that the solution can handle the range of years from 1950 to 2050 efficiently.
{{< dots >}}
## Code 💻
```cpp
int maximumPopulation(vector<vector<int>>& logs) {
    vector<int> sum(102, 0);
    
    for(auto v: logs) {
        sum[v[1] - 1950]--;
        sum[v[0] - 1950]++;
    }
    
    for(int i = 1; i < 102; i++) {
        sum[i] += sum[i - 1];
        cout << sum[i] << " ";
    }
    
    int mx = 0, yr = 2050;
    for(int i = 101; i >= 0; i--) {
        if(sum[i] >= mx) {
            yr = i + 1950;
            mx = sum[i];
        }
    }
    return yr;
}
```

This code calculates the year with the maximum population, given a list of birth and death years in the format of `logs`. It computes population changes over the years using a difference array and then calculates the cumulative population at each year to determine the year with the maximum population.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumPopulation(vector<vector<int>>& logs) {
	```
	Defines the `maximumPopulation` function that takes a 2D vector `logs` representing the birth and death years of individuals.

2. **Variable Initialization**
	```cpp
	    vector<int> sum(102, 0);
	```
	Initializes a vector `sum` of size 102 (for years 1950 to 2050) to track the population changes, with all values initially set to 0.

3. **Looping**
	```cpp
	    for(auto v: logs) {
	```
	Iterates through each element `v` in the `logs` vector, where each element represents a pair of birth and death years.

4. **Array Manipulation**
	```cpp
	        sum[v[1] - 1950]--;
	```
	Decreases the population at the death year (adjusted for the base year 1950).

5. **Array Manipulation**
	```cpp
	        sum[v[0] - 1950]++;
	```
	Increases the population at the birth year (adjusted for the base year 1950).

6. **Looping**
	```cpp
	    for(int i = 1; i < 102; i++) {
	```
	A loop that calculates the cumulative population for each year by adding the current value of `sum[i]` to `sum[i - 1]`.

7. **Array Manipulation**
	```cpp
	        sum[i] += sum[i - 1];
	```
	Adds the population change at year `i` to the cumulative population up to that year.

8. **Variable Initialization**
	```cpp
	    int mx = 0, yr = 2050;
	```
	Initializes `mx` to track the maximum population and `yr` to store the year with the maximum population, initially set to 2050.

9. **Looping**
	```cpp
	    for(int i = 101; i >= 0; i--) {
	```
	Starts a loop that runs backward from year 2050 (index 101) to 1950 (index 0) to find the year with the maximum population.

10. **Conditional Check**
	```cpp
	        if(sum[i] >= mx) {
	```
	Checks if the population at the current year `i` is greater than or equal to the current maximum population `mx`.

11. **Variable Update**
	```cpp
	            yr = i + 1950;
	```
	Updates the year `yr` to the current year (adjusted back to the actual year) when a new maximum population is found.

12. **Variable Update**
	```cpp
	            mx = sum[i];
	```
	Updates the maximum population `mx` to the current population at year `i`.

13. **Return**
	```cpp
	    return yr;
	```
	Returns the year `yr` that has the maximum population.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N)
- **Average Case:** O(N)
- **Worst Case:** O(N)

The time complexity is O(N), where N is the number of people in the `logs` array, as we are iterating over each person's birth and death year.

### Space Complexity 💾
- **Best Case:** O(102)
- **Worst Case:** O(102)

The space complexity is O(102), as we use an array of fixed size to track population changes over the years.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-population-year/description/)

---
{{< youtube 2W2yijatcTY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
