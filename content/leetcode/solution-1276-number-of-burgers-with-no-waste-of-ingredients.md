
+++
authors = ["grid47"]
title = "Leetcode 1276: Number of Burgers with No Waste of Ingredients"
date = "2024-07-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1276: Number of Burgers with No Waste of Ingredients in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> ans;
    map<int, map<int, bool>> mp;
    bool dp(int tmt, int chs, int one, int two) {
        if(tmt <= 0 || chs <= 0) {
            if(tmt == 0 && chs == 0) {
                ans = {one, two};
                return true;
            }
            return false;
        }
        
        if(mp.count(tmt) && mp[tmt].count(chs)) return mp[tmt][chs];
        
        if(tmt >= 4 && chs >= 1) {
            if(dp(tmt - 4, chs -1, one + 1, two))
                return mp[tmt][chs] = true;
            if(dp(tmt - 2, chs -1, one, two + 1))
                return mp[tmt][chs] = true;
        } else if(tmt >= 2 && chs >= 1) {
            if(dp(tmt - 2, chs -1, one, two + 1))
                return mp[tmt][chs] = true;            
        }
        return mp[tmt][chs] = false;
    }
    
    vector<int> numOfBurgers(int tmt, int chs) {
        ans = {};
        // dp(tmt, chs, 0, 0);
        int net = chs;
        int jumbo = (tmt - 2 * chs ) / 2;
 
        if(((tmt - 2 * chs ) < 0) || ((tmt - 2 * chs ) % 2) || (net - jumbo < 0)) return ans;
        
        return {jumbo, net - jumbo};
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to determine how many types of burgers can be made given a specific total number of ingredients (tmt) and a specific number of cheese slices (chs). There are two types of burgers:
1. **Jumbo Burger**: Requires 4 ingredients and 1 cheese slice.
2. **Small Burger**: Requires 2 ingredients and 1 cheese slice.

Given `tmt` (total ingredients) and `chs` (cheese slices), the goal is to compute how many Jumbo and Small burgers can be made such that all ingredients and cheese slices are used up, and return this as a vector containing the count of Jumbo and Small burgers.

### Approach
The approach to solve this problem relies on deriving a mathematical relationship rather than brute-forcing through combinations of burger types. The idea is to calculate how many Jumbo burgers can be made from the available ingredients and cheese slices, and then determine how many Small burgers can be made with the remaining resources.

1. **Calculate Potential Jumbo Burgers**:
   - Given that a Jumbo burger requires 4 ingredients and 1 cheese slice, the maximum number of Jumbo burgers is limited by the number of cheese slices and the total ingredients available.
2. **Compute Remaining Ingredients**:
   - After determining how many Jumbo burgers can be made, calculate how many ingredients remain and then find how many Small burgers can be made with the remaining ingredients and cheese slices.
3. **Constraints Checking**:
   - Ensure that the calculated values for the number of burgers do not violate any ingredient or cheese slice limits.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<int> ans;
    map<int, map<int, bool>> mp;
```
- **Lines 1-3**: We define the `Solution` class. `ans` is initialized as an empty vector to store the result, and `mp` is a nested map used for memoization (though it's not utilized in the final implementation).

```cpp
    bool dp(int tmt, int chs, int one, int two) {
        if(tmt <= 0 || chs <= 0) {
            if(tmt == 0 && chs == 0) {
                ans = {one, two};
                return true;
            }
            return false;
        }
        
        if(mp.count(tmt) && mp[tmt].count(chs)) return mp[tmt][chs];
```
- **Lines 4-11**: This is a recursive helper function `dp` which aims to explore combinations of burgers (though it's commented out in the main function). 
  - The base case checks if `tmt` (total ingredients) or `chs` (cheese slices) are non-positive.
  - If both are exactly zero, it stores the current counts of burgers (`one`, `two`) in `ans` and returns true, indicating a valid combination has been found.

```cpp
        if(tmt >= 4 && chs >= 1) {
            if(dp(tmt - 4, chs -1, one + 1, two))
                return mp[tmt][chs] = true;
            if(dp(tmt - 2, chs -1, one, two + 1))
                return mp[tmt][chs] = true;
        } else if(tmt >= 2 && chs >= 1) {
            if(dp(tmt - 2, chs -1, one, two + 1))
                return mp[tmt][chs] = true;            
        }
        return mp[tmt][chs] = false;
    }
```
- **Lines 12-23**: This section evaluates possible burger combinations recursively.
  - If there are enough ingredients and cheese for a Jumbo burger, it calls `dp` recursively while subtracting the respective counts.
  - If not, but there are enough for a Small burger, it similarly makes that call.
  - If neither condition can be met, it marks this state in `mp` as false, indicating no valid combination was found.

```cpp
    vector<int> numOfBurgers(int tmt, int chs) {
        ans = {};
        int net = chs;
        int jumbo = (tmt - 2 * chs ) / 2;
```
- **Lines 24-28**: The main function `numOfBurgers` initializes the `ans` vector. It computes the maximum potential number of Jumbo burgers using the formula `(tmt - 2 * chs) / 2`. This formula derives from the constraints that a Jumbo burger uses 4 ingredients and 1 cheese slice, while the remaining ingredients after using cheese for the Small burgers will dictate the count of Jumbo burgers.

```cpp
        if(((tmt - 2 * chs ) < 0) || ((tmt - 2 * chs ) % 2) || (net - jumbo < 0)) return ans;
        
        return {jumbo, net - jumbo};
    }
};
```
- **Lines 29-32**: Here, the function checks several conditions:
  - If `tmt - 2 * chs < 0`, it indicates that the total ingredients cannot even support the cheese slices, and thus an empty result is returned.
  - If `tmt - 2 * chs` is odd, it cannot be evenly split between the burger types, so it also returns an empty result.
  - Finally, if the number of cheese slices is less than the number of Jumbo burgers computed, it also returns an empty vector.
- If all conditions are satisfied, it returns a vector containing the counts of Jumbo and Small burgers.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity of this implementation is \(O(1)\) as the calculations performed involve simple arithmetic operations and logical checks, regardless of input size.
2. **Space Complexity**:
   - The space complexity is \(O(1)\) since no additional data structures grow with input size; all calculations are done in constant space.

### Conclusion
The `numOfBurgers` function provides an efficient method to determine the number of Jumbo and Small burgers that can be made with given ingredients and cheese slices by leveraging arithmetic relations rather than exhaustive search techniques. The approach is optimal, ensuring constant time complexity, making it suitable for scenarios with large input values. 

This solution exemplifies a clean and concise application of logic to solve a combinatorial problem effectively, demonstrating the importance of understanding constraints and conditions in mathematical problems. Overall, the code is well-structured, and the comments help clarify the thought process behind each section, making it approachable for readers looking to understand the solution.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
