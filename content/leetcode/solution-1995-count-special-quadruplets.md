
+++
authors = ["grid47"]
title = "Leetcode 1995: Count Special Quadruplets"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1995: Count Special Quadruplets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "H06N-OsxpoE"
youtube_upload_date="2021-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/H06N-OsxpoE/maxresdefault.jpg"
comments = true
+++



---
Given a 0-indexed integer array 'nums', return the number of distinct quadruplets (a, b, c, d) such that:

- nums[a] + nums[b] + nums[c] == nums[d], and
- a < b < c < d.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array nums of length n (4 <= n <= 50) where each element nums[i] satisfies 1 <= nums[i] <= 100.
- **Example:** `nums = [1, 2, 3, 6]`
- **Constraints:**
	- 4 <= nums.length <= 50
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct quadruplets (a, b, c, d) such that nums[a] + nums[b] + nums[c] == nums[d], with a < b < c < d.
- **Example:** `1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to find quadruplets where the sum of three elements equals the fourth element, and the indices are in increasing order.

- 1. Iterate through the array starting from the end.
- 2. Use a hashmap to track previous sums and their frequencies.
- 3. For each new element, check if the sum of two previous elements matches any previously tracked sum.
- 4. Update the result accordingly.
{{< dots >}}
### Problem Assumptions ✅
- All quadruplets should have distinct indices.
- The array is non-empty and follows the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 1, 1, 3, 5]`  \
  **Explanation:** Here, there are 4 valid quadruplets: (0, 1, 2, 3), (0, 1, 3, 4), (0, 2, 3, 4), and (1, 2, 3, 4).

{{< dots >}}
## Approach 🚀
We can solve this problem efficiently using a hashmap to track sums of pairs and their frequencies as we iterate through the array.

### Initial Thoughts 💭
- The problem requires us to check sums of three elements against another element.
- A brute-force approach would involve checking all possible quadruplets, but this would be inefficient for larger arrays. A hashmap can help reduce the complexity.
{{< dots >}}
### Edge Cases 🌐
- There are no edge cases involving empty inputs since the array length is guaranteed to be at least 4.
- For larger inputs, the algorithm should perform efficiently due to the hashmap optimization.
- The input values can be the same, so we need to handle duplicates.
- The constraints are manageable for the given approach.
{{< dots >}}
## Code 💻
```cpp
int countQuadruplets(vector<int>& nums) {
    const auto n = nums.size();
    unordered_map<int, int> freq;
    
    freq[nums[n - 1]] = 1;
    size_t answ = 0;
    for (int i = n - 2; i > 1; --i)
    {
        for (int j = i - 1; j > 0; --j)
        {
            for (int k = j - 1; k >= 0; --k)
            {
                if (freq.count(nums[i] + nums[j] + nums[k]))
                {
                    answ += freq[nums[i] + nums[j] + nums[k]];
                }
            }
        }
        freq[nums[i]] += 1;
    }
    return answ;
}
```

This function counts the number of quadruplets in the input array `nums` such that their sum equals a previously encountered value in the array. It uses a hashmap to track the frequency of sums and iterates through the array using three nested loops.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countQuadruplets(vector<int>& nums) {
	```
	The function definition for `countQuadruplets` that takes in a vector of integers, `nums`, and returns the count of quadruplets.

2. **Variable Initialization**
	```cpp
	    const auto n = nums.size();
	```
	This initializes the variable `n` to hold the size of the `nums` vector, which is used to control the iteration limits.

3. **Variable Initialization**
	```cpp
	    unordered_map<int, int> freq;
	```
	An unordered map `freq` is initialized to store the frequency of sum values encountered during iteration.

4. **Map Update**
	```cpp
	    freq[nums[n - 1]] = 1;
	```
	The last element of `nums` is added to the `freq` map with an initial count of 1. This prepares the map to store the frequencies of potential sums.

5. **Variable Initialization**
	```cpp
	    size_t answ = 0;
	```
	A variable `answ` is initialized to 0 to keep track of the count of quadruplets that satisfy the required sum condition.

6. **Outer Loop**
	```cpp
	    for (int i = n - 2; i > 1; --i)
	```
	The outer loop starts from the second last element of the array `nums` and iterates backwards.

7. **Middle Loop**
	```cpp
	        for (int j = i - 1; j > 0; --j)
	```
	The middle loop iterates backwards from one element before the current element in the outer loop.

8. **Inner Loop**
	```cpp
	            for (int k = j - 1; k >= 0; --k)
	```
	The inner loop iterates backwards from one element before the current element in the middle loop.

9. **Condition Check**
	```cpp
	                if (freq.count(nums[i] + nums[j] + nums[k]))
	```
	Checks if the sum of `nums[i] + nums[j] + nums[k]` is present in the `freq` map.

10. **Block Start**
	```cpp
	                {
	```
	Marks the start of the block for the condition where a sum is found in the `freq` map.

11. **Count Update**
	```cpp
	                    answ += freq[nums[i] + nums[j] + nums[k]];
	```
	If the sum exists in `freq`, the corresponding frequency is added to the `answ` variable, incrementing the count of valid quadruplets.

12. **Map Update**
	```cpp
	        freq[nums[i]] += 1;
	```
	Updates the frequency of the current element `nums[i]` in the `freq` map.

13. **Return Statement**
	```cpp
	    return answ;
	```
	Returns the total count of quadruplets that satisfy the given condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^3)
- **Average Case:** O(n^3)
- **Worst Case:** O(n^3)

In the worst case, we check all pairs of elements in the array, leading to a time complexity of O(n^3).

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the hashmap used for storing sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-special-quadruplets/description/)

---
{{< youtube H06N-OsxpoE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
