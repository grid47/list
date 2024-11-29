
+++
authors = ["grid47"]
title = "Leetcode 1011: Capacity To Ship Packages Within D Days"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1011: Capacity To Ship Packages Within D Days in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ER_oLmdc-nw"
youtube_upload_date="2023-02-22"
youtube_thumbnail="https://i.ytimg.com/vi/ER_oLmdc-nw/maxresdefault.jpg"
comments = true
+++



---
You are tasked with shipping packages using a ship with a limited weight capacity. Each package has a given weight and must be shipped in order within a specified number of days. Your objective is to determine the minimum weight capacity of the ship that allows all the packages to be shipped within the given days, without exceeding the ship's weight capacity on any single day.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two components: an array of integers representing the weights of the packages, and an integer representing the number of days available to ship all the packages.
- **Example:** `weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5`
- **Constraints:**
	- 1 <= days <= weights.length <= 5 * 10^4
	- 1 <= weights[i] <= 500

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the minimum ship capacity required to ship all packages within the given days.
- **Example:** `Output: 15`
- **Constraints:**
	- The result should be an integer representing the minimum weight capacity.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the least weight capacity of the ship that ensures all the packages are shipped within the given days without exceeding the capacity each day.

- Use binary search to determine the minimum ship capacity.
- Start with a lower bound of the heaviest package weight and an upper bound that is the sum of all package weights.
- For each mid value (representing a ship's weight capacity), simulate shipping the packages within the given days and check if it's feasible to ship them all without exceeding the capacity each day.
{{< dots >}}
### Problem Assumptions ✅
- The packages must be shipped in the given order, meaning they cannot be rearranged.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5`  \
  **Explanation:** In this case, the minimum ship capacity needed is 15, as the packages can be distributed across the days as follows: (1, 2, 3, 4, 5) on day 1, (6, 7) on day 2, (8) on day 3, (9) on day 4, and (10) on day 5. The total weight each day does not exceed 15, and all packages are shipped within 5 days.

- **Input:** `Input: weights = [3, 2, 2, 4, 1, 4], days = 3`  \
  **Explanation:** For this input, a ship capacity of 6 is enough to ship all the packages within 3 days. The packages can be shipped as follows: (3, 2) on day 1, (2, 4) on day 2, and (1, 4) on day 3.

- **Input:** `Input: weights = [1, 2, 3, 1, 1], days = 4`  \
  **Explanation:** For this case, the minimum ship capacity is 3, which is sufficient to ship the packages within 4 days as follows: (1) on day 1, (2) on day 2, (3) on day 3, and (1, 1) on day 4.

{{< dots >}}
## Approach 🚀
We use a binary search approach to find the minimum ship capacity that allows all packages to be shipped within the given days. The key observation is that the ship's capacity should be between the heaviest package and the sum of all package weights. We simulate the loading process for each candidate capacity to check if it's feasible to ship the packages within the given days.

### Initial Thoughts 💭
- A binary search is suitable because we're searching for a minimum value (ship capacity) in a range, and we can test the feasibility for any candidate capacity.
- By checking whether it's feasible to ship the packages with a given capacity, we can adjust our search space accordingly to find the minimum required capacity.
{{< dots >}}
### Edge Cases 🌐
- The problem specifies that the input will never be empty.
- The solution should be efficient enough to handle the largest input sizes, up to 50,000 packages.
- If all package weights are the same, the solution will still work by distributing them evenly across the days.
- The weight of each package must be between 1 and 500.
{{< dots >}}
## Code 💻
```cpp
int shipWithinDays(vector<int>& weights, int days) {
    int left = 0, right = 25000000;
    for(int w: weights)
    left = max(left, w);

    while(left < right) {
        int mid = (left + right) / 2;
        int need =1, cur = 0;
        for(int i = 0; i <  weights.size() && need <= days; cur += weights[i++])
            if(cur + weights[i] > mid)
            cur = 0, need++;
        if(need > days) left = mid + 1;
        else right = mid;
    }
    return left;
}
```

This function calculates the minimum weight capacity needed to ship the given weights within a specified number of days using binary search.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int shipWithinDays(vector<int>& weights, int days) {
	```
	Declares the function `shipWithinDays` which takes a vector of integers `weights` representing the weights of packages and an integer `days` indicating the number of days within which the packages must be shipped. The function returns the minimum weight capacity required to ship all packages within the given days.

2. **Variable Initialization**
	```cpp
	    int left = 0, right = 25000000;
	```
	Initializes the binary search bounds. `left` represents the minimum possible weight capacity (starting from 0), and `right` is the maximum possible weight capacity (25000000, an arbitrary large number).

3. **Loop Over Weights**
	```cpp
	    for(int w: weights)
	```
	Iterates over each weight `w` in the `weights` vector to determine the maximum weight.

4. **Max Weight Calculation**
	```cpp
	    left = max(left, w);
	```
	Updates the `left` variable to store the maximum weight found in the `weights` vector. This ensures the minimum weight capacity (`left`) is at least the largest single package weight.

5. **Midpoint Calculation**
	```cpp
	    while(left < right) {
	```
	Initiates a binary search loop where the search space is narrowed down by calculating the midpoint `mid` between `left` and `right`.

6. **Mid Calculation**
	```cpp
	        int mid = (left + right) / 2;
	```
	Calculates the midpoint `mid` between the current values of `left` and `right`. This midpoint represents the current guess for the minimum weight capacity.

7. **Tracking Shipments**
	```cpp
	        int need = 1, cur = 0;
	```
	Initializes two variables: `need` tracks the number of days required to ship the packages, and `cur` tracks the current cumulative weight of the packages being shipped on a single day.

8. **Iterating Through Weights**
	```cpp
	        for(int i = 0; i <  weights.size() && need <= days; cur += weights[i++])
	```
	Iterates through the `weights` vector, adding each weight to the current day's total (`cur`). If the total exceeds `mid`, a new day is started by resetting `cur` to 0.

9. **Capacity Check**
	```cpp
	            if(cur + weights[i] > mid)
	```
	Checks if adding the current weight `weights[i]` to `cur` exceeds the current midpoint `mid`. If so, a new day is required, and the `cur` variable is reset to 0.

10. **Increment Day Count**
	```cpp
	            cur = 0, need++;
	```
	Increments the `need` counter, which tracks the number of days required to ship the packages, as a new day is needed to accommodate the current weight.

11. **Adjust Search Bounds**
	```cpp
	        if(need > days) left = mid + 1;
	```
	If the number of days required exceeds the given `days`, it means the current weight capacity `mid` is too low. Thus, `left` is adjusted to `mid + 1`.

12. **Update Right Bound**
	```cpp
	        else right = mid;
	```
	If the number of days is within the limit, it means the current capacity `mid` might be sufficient, so the right bound `right` is adjusted to `mid`.

13. **Return Minimum Capacity**
	```cpp
	    return left;
	```
	Returns the final value of `left`, which represents the minimum weight capacity required to ship the packages within the given number of days.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log W)
- **Average Case:** O(n log W)
- **Worst Case:** O(n log W)

Where n is the number of packages and W is the sum of all package weights. The binary search runs in O(log W) and for each mid value, we simulate the shipping process in O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a few variables to track the bounds and the current ship load during the simulation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/)

---
{{< youtube ER_oLmdc-nw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
