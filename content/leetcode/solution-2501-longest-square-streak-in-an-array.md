
+++
authors = ["grid47"]
title = "Leetcode 2501: Longest Square Streak in an Array"
date = "2024-03-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2501: Longest Square Streak in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "prcJMNtokGI"
youtube_upload_date="2022-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/prcJMNtokGI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i= 0; i < n; i++) {
            long long tmp = (long long) nums[i] * nums[i];
            if(tmp > INT_MAX) break;
            auto it = lower_bound(nums.begin(), nums.end(), tmp);
            if(it == nums.end()) break;
            int pos = it - nums.begin();
            while(pos < n && nums[i] * nums[i] == nums[pos]) {
                    dp[pos] = max(dp[pos], 1 + dp[i]);                
                    mx = max(mx, dp[pos]);  
                    pos++;
            }
        }
        return mx == 1? -1: mx;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the length of the longest streak of elements in an array such that each element is the square of the previous element in the streak. In other words, for each number `x`, we need to find a sequence where each subsequent number is `x^2`. If such a streak doesn't exist, return `-1`. If a streak exists, return the length of the longest streak.

### Approach

The approach for solving this problem involves:
1. **Sorting the input array**: Sorting the array allows us to efficiently check for each number whether its square exists in the array.
2. **Dynamic Programming**: Use dynamic programming (`dp`) to track the length of the longest streak ending at each element of the array.
3. **Efficient Search with Binary Search**: To find the square of each number, we can use binary search (`lower_bound`) to quickly check if the square of the current element exists in the array.
4. **Updating the Longest Streak**: As we go through the array, we update the longest streak (`mx`) whenever we find a valid streak.

### Code Breakdown (Step by Step)

#### Step 1: Sorting the Input Array

```cpp
int n = nums.size();
sort(nums.begin(), nums.end());
```

The first step is to sort the array. Sorting helps us efficiently check if a number's square exists in the array, as the array is ordered.

- Sorting ensures that when we look for the square of a number, it will be positioned in a way that allows binary search to work effectively. This reduces the complexity of checking for squares.

#### Step 2: Initialize Dynamic Programming Array

```cpp
vector<int> dp(n, 1);
int mx = 1;
```

- **dp**: This is a dynamic programming array that stores the length of the longest streak ending at each element of the array. Initially, each element has a streak of length 1 (itself).
- **mx**: This variable tracks the maximum length of any streak found during the iteration.

#### Step 3: Iterate Through the Array and Check for Squares

```cpp
for(int i = 0; i < n; i++) {
    long long tmp = (long long) nums[i] * nums[i];
    if(tmp > INT_MAX) break;
    auto it = lower_bound(nums.begin(), nums.end(), tmp);
    if(it == nums.end()) break;
    int pos = it - nums.begin();
    while(pos < n && nums[i] * nums[i] == nums[pos]) {
        dp[pos] = max(dp[pos], 1 + dp[i]);                
        mx = max(mx, dp[pos]);  
        pos++;
    }
}
```

- **Iterating over each element**: For each element `nums[i]`, we check whether its square exists in the array.
  
  1. **Calculate the square of the number**: We calculate the square of `nums[i]` and store it in `tmp`.
  
  2. **Check for overflow**: If the square of the number exceeds `INT_MAX`, we break out of the loop since squares larger than this would not be valid for a 32-bit integer range.

  3. **Find the position using binary search**: We use `lower_bound` to find the smallest position `it` in the array where `tmp` (the square of `nums[i]`) could be inserted. If `it == nums.end()`, it means the square does not exist in the array, so we exit the loop.

  4. **Updating the DP array**: We start from the position `pos` and check if the value at `pos` is equal to the square of the current number (`nums[i] * nums[i]`). If it is, we update the `dp` array to record the maximum streak length for that number. We update `mx` accordingly, keeping track of the longest streak found so far.

#### Step 4: Handle Edge Case and Return Result

```cpp
return mx == 1? -1: mx;
```

Once the loop completes, we check if the longest streak `mx` is still `1`. If it is, it means no valid streak of length greater than 1 was found, and we return `-1`. Otherwise, we return `mx`, the length of the longest streak found.

### Complexity Analysis

#### Time Complexity:

- **Sorting the array**: The sorting step takes \(O(n \log n)\), where \(n\) is the number of elements in the input array.
- **Binary search for each element**: For each element, we perform a binary search (`lower_bound`) to find the position of its square in the array. This binary search takes \(O(\log n)\).
- **Updating the DP array**: The inner while loop runs once for each occurrence of the square of the current element, but at most it runs \(n\) times across all elements. In the worst case, the complexity of updating the `dp` array is \(O(n)\).

Thus, the overall time complexity is dominated by the sorting step, giving a total complexity of \(O(n \log n)\).

#### Space Complexity:

- **Space for the `dp` array**: The `dp` array has a size of \(n\), so it requires \(O(n)\) space.
- **Auxiliary space for the binary search**: The binary search uses \(O(1)\) extra space, so it doesn't contribute significantly to space complexity.

Therefore, the overall space complexity is \(O(n)\), where \(n\) is the number of elements in the array.

### Conclusion

In conclusion, this solution efficiently calculates the longest streak of elements where each element is the square of the previous element using sorting, binary search, and dynamic programming. The approach works in \(O(n \log n)\) time complexity, making it suitable for moderately large inputs. 

Key highlights:
- **Time Complexity**: \(O(n \log n)\), due to sorting and binary search.
- **Space Complexity**: \(O(n)\), due to the `dp` array.

This solution is both time-efficient and space-efficient, providing an optimal approach to solving the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-square-streak-in-an-array/description/)

---
{{< youtube prcJMNtokGI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
