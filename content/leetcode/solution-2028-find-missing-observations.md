
+++
authors = ["grid47"]
title = "Leetcode 2028: Find Missing Observations"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2028: Find Missing Observations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "86yKkaNi3sU"
youtube_upload_date="2021-10-03"
youtube_thumbnail="https://i.ytimg.com/vi/86yKkaNi3sU/maxresdefault.jpg"
comments = true
+++



---
You are given an array of `m` observations, each representing a die roll from a 6-sided die, and an average value `mean` of all `n + m` rolls. Your task is to calculate the missing `n` observations such that the overall average of all `n + m` rolls equals the provided `mean`. If multiple valid answers exist, return any of them. If it is impossible to achieve the desired average, return an empty array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `rolls` representing `m` observed die rolls, and two integers `mean` and `n`, where `n` is the number of missing rolls.
- **Example:** `rolls = [1, 2, 3], mean = 4, n = 3`
- **Constraints:**
	- 1 <= rolls.length <= 10^5
	- 1 <= rolls[i], mean <= 6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing the `n` missing observations such that the average of all `n + m` rolls is equal to `mean`. If no such array exists, return an empty array.
- **Example:** `Output: [5, 5, 5]`
- **Constraints:**
	- If multiple solutions exist, any valid array is acceptable.
	- If it's impossible to achieve the desired mean, return an empty array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the missing `n` observations whose sum, together with the sum of the observed rolls, results in the exact average of `mean`.

- 1. Compute the required sum of all `n + m` rolls by multiplying the mean by `n + m`.
- 2. Subtract the sum of the observed rolls from the required sum to get the sum of the missing rolls.
- 3. Check if the sum of the missing rolls is feasible (i.e., within the possible range of `n` die rolls).
- 4. If feasible, divide the sum by `n` to get the average roll value for the missing rolls and distribute any remainder evenly across the missing rolls.
{{< dots >}}
### Problem Assumptions ✅
- The value of `mean` is an integer and the sum of all rolls should be divisible by `n + m`.
{{< dots >}}
## Examples 🧩
- **Input:** `rolls = [1, 2, 3], mean = 4, n = 3`  \
  **Explanation:** The total sum needed is (1 + 2 + 3 + 5 + 5 + 5) = 24, and the average is 24 / 6 = 4.

- **Input:** `rolls = [1, 5, 6], mean = 3, n = 4`  \
  **Explanation:** The total sum needed is (1 + 5 + 6 + 2 + 3 + 2 + 2) = 21, and the average is 21 / 7 = 3.

- **Input:** `rolls = [1, 2, 3, 4], mean = 6, n = 4`  \
  **Explanation:** It is impossible to achieve an average of 6 because the sum would be too large for the missing rolls to fit the required range.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to determine the sum of the missing `n` rolls and ensure it fits within the possible range for `n` dice rolls. We then distribute this sum evenly and handle any remainder appropriately.

### Initial Thoughts 💭
- The sum of the missing rolls should be between `n` and `6 * n` (because each roll is between 1 and 6).
- We can compute the required sum and divide it evenly. The remainder can be distributed across the missing rolls.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as `rolls` cannot be empty.
- Ensure the solution is efficient enough for large inputs (up to 10^5).
- If `mean` is not achievable based on the sum of the rolls, return an empty array.
- Ensure the solution runs within time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
vector<map<int, bool>> memo;
vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    
    int m = rolls.size();
    
    int sum = 0;
    for(int i = 0; i < m; i++)
        sum += rolls[i];
    
    int net = mean * (m + n);
    
    sum = net - sum;
    
    // create an array of size n with sum = sum and elements 1 - 6
    
    if(sum < n || sum > 6 * n) return vector<int>{};

    int x = sum / n, rem = sum % n;
    vector<int> res(n, x);
    
    for(int i = 0; i < rem; i++) {
        res[i]++;
    }

    return res;
}

```

This function calculates the missing rolls in a dice game based on the provided rolls, mean, and the number of missing rolls. It distributes the remaining sum across the missing rolls, ensuring that each roll is between 1 and 6.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<map<int, bool>> memo;
	```
	A memoization table is declared, but it is not used in this function. It might be intended for optimization in case of complex cases.

2. **Function Definition**
	```cpp
	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
	```
	This defines the function 'missingRolls' that takes a vector of rolls, the mean value, and the number of missing rolls 'n'. It returns a vector containing the missing rolls that would satisfy the mean.

3. **Array Size**
	```cpp
	    int m = rolls.size();
	```
	This calculates the size of the 'rolls' vector to determine how many rolls have already been made.

4. **Sum Initialization**
	```cpp
	    int sum = 0;
	```
	This initializes a variable 'sum' to accumulate the total of the current rolls.

5. **Loop Start**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This starts a loop to iterate over each of the current rolls.

6. **Accumulate Rolls**
	```cpp
	        sum += rolls[i];
	```
	This adds the value of the current roll to the 'sum' variable.

7. **Net Calculation**
	```cpp
	    int net = mean * (m + n);
	```
	This calculates the total sum required to achieve the given mean, based on the number of rolls (m) and missing rolls (n).

8. **Sum Adjustment**
	```cpp
	    sum = net - sum;
	```
	This adjusts the sum to reflect the remaining total needed to achieve the required mean.

9. **Condition Check**
	```cpp
	    if(sum < n || sum > 6 * n) return vector<int>{};
	```
	This checks if the sum is impossible to achieve with 'n' rolls. If the sum is less than 'n' or greater than the maximum possible sum (6 * n), it returns an empty vector.

10. **Variable Initialization**
	```cpp
	    int x = sum / n, rem = sum % n;
	```
	This calculates the base value 'x' that each roll will have and the remainder 'rem' that needs to be distributed across the rolls.

11. **Vector Initialization**
	```cpp
	    vector<int> res(n, x);
	```
	This initializes the result vector 'res' of size 'n', with each element set to the base value 'x'.

12. **Loop Start**
	```cpp
	    for(int i = 0; i < rem; i++) {
	```
	This starts a loop to distribute the remainder 'rem' across the result vector.

13. **Distribute Remainder**
	```cpp
	        res[i]++;
	```
	This increments the first 'rem' elements of the result vector by 1 to properly distribute the remainder.

14. **Return Statement**
	```cpp
	    return res;
	```
	This returns the result vector containing the missing rolls that satisfy the mean.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The algorithm runs in linear time relative to the number of rolls and missing observations.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear, as we need to store the missing rolls.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-missing-observations/description/)

---
{{< youtube 86yKkaNi3sU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
