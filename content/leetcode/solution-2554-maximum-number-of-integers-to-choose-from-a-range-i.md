
+++
authors = ["grid47"]
title = "Leetcode 2554: Maximum Number of Integers to Choose From a Range I"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2554: Maximum Number of Integers to Choose From a Range I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iLU7ZBtjc-k"
youtube_upload_date="2023-02-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/iLU7ZBtjc-k/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    unordered_map<int, bool> mp;
    
    int maxCount(vector<int>& ban, int n, int mxS) {
        // this->n = n;
        for(int x: ban)
            mp[x] = true;

        // memset(memo, -1, sizeof(memo));
        // memo.resize(n + 1);
        // return dp(1, mxS);
        int cnt = 0;
        for(int i = 1; i < n + 1; i++) {
            if(!mp.count(i) && mxS >= i) {
                cnt++;
                mxS -= i;
            }
            if(mxS < 0) break;
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the maximum number of integers starting from 1 that can be included in a subset, given a set of integers that are banned, and a maximum sum limit (`mxS`). The goal is to maximize the count of integers from 1 to `n` (inclusive), such that no integer in the subset is banned, and the sum of the integers in the subset does not exceed the given limit `mxS`.

For example:
- Input: `ban = [1, 2, 4]`, `n = 7`, `mxS = 10`
- Output: The maximum number of integers from 1 to `7` that can be included without exceeding the sum `mxS` is `3`. The subset could be `[3, 5, 6]` (sum = 3 + 5 + 6 = 10).

### Approach

To solve the problem, we can approach it step by step:

1. **Mark Banned Elements**: The first task is to mark all the banned elements. This can be done using a hash set (or unordered map) where the banned elements are stored. This allows for constant time checking if an integer is banned.

2. **Greedy Approach**: We will use a greedy strategy to maximize the number of integers we can select. Starting from the smallest integer (1), we will include it in the subset as long as:
   - The integer is not banned.
   - The sum of the selected integers does not exceed `mxS`.

3. **Iterate Through Numbers**: We will iterate over all numbers from 1 to `n`. For each number, check if it's banned. If it's not banned and its inclusion doesn't exceed the maximum sum (`mxS`), include it in the subset. If including the current number causes the sum to exceed `mxS`, stop the process.

4. **Return the Result**: The result will be the count of the numbers that can be included in the subset without exceeding `mxS`.

### Code Breakdown (Step by Step)

Let's break down the code into its individual components:

#### Step 1: Define the Function and Variables

```cpp
int n;
unordered_map<int, bool> mp;
```
- The function `maxCount` takes three parameters: `ban`, `n`, and `mxS`.
  - `ban`: A vector of integers representing the banned numbers.
  - `n`: The upper limit for the numbers we can consider (1 to `n`).
  - `mxS`: The maximum sum we are allowed to include.

- We also define `mp`, an unordered map, to store the banned numbers for quick lookups. The key is the number, and the value is a boolean indicating whether the number is banned.

#### Step 2: Mark Banned Elements

```cpp
for(int x: ban)
    mp[x] = true;
```
- This loop marks all the elements in the `ban` array as banned by adding them to the unordered map `mp`. Each banned number is stored with a value `true`.

#### Step 3: Initialize Count and Iterate Over Numbers

```cpp
int cnt = 0;
for(int i = 1; i < n + 1; i++) {
    if(!mp.count(i) && mxS >= i) {
        cnt++;
        mxS -= i;
    }
    if(mxS < 0) break;
}
```
- We initialize `cnt` to 0, which will hold the count of numbers we can select.
- We loop over each number `i` from 1 to `n` (inclusive).
  - If `i` is not in the `mp` map (i.e., not banned) and if adding `i` to the current subset will not exceed the sum `mxS`, we include it in the subset:
    - Increment `cnt` to account for the selected number.
    - Subtract `i` from `mxS` to update the remaining sum.
  - If at any point, `mxS` becomes negative, it means including any more numbers would exceed the sum limit, so we break out of the loop.

#### Step 4: Return the Result

```cpp
return cnt;
```
- After the loop finishes, the value of `cnt` represents the maximum number of integers that can be selected without exceeding the sum `mxS`. We return this value.

### Complexity

#### Time Complexity:
- **Marking Banned Elements**: The time complexity for marking the banned elements is \( O(b) \), where `b` is the number of banned elements.
- **Iterating Through Numbers from 1 to `n`**: The loop iterates from 1 to `n`, checking each number to see if it's banned and if it can be included in the subset. This results in a time complexity of \( O(n) \).
- **Overall Time Complexity**: The overall time complexity of the function is \( O(b + n) \), where `b` is the number of banned numbers and `n` is the total number of integers we consider.

#### Space Complexity:
- **Space for the `mp` Map**: We use an unordered map `mp` to store the banned numbers. In the worst case, if all numbers from 1 to `n` are banned, the space complexity of the map is \( O(b) \), where `b` is the number of banned numbers.
- **Space for Variables**: The space used by the other variables (like `cnt` and the loop counters) is constant, \( O(1) \).
- **Overall Space Complexity**: The overall space complexity is \( O(b) \), where `b` is the number of banned numbers.

### Conclusion

The solution efficiently solves the problem using a greedy strategy. The steps are straightforward:
1. Mark the banned numbers.
2. Iterate through all numbers from 1 to `n`, trying to include as many as possible without exceeding the sum `mxS`.
3. The greedy approach ensures we always select the smallest available numbers first, maximizing the number of integers that can be included.

The time complexity is linear in terms of the size of the input (`O(n)`), and the space complexity is also linear in terms of the number of banned numbers (`O(b)`).

This solution is optimal for the problem and ensures that we can handle large inputs effectively within the given constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/)

---
{{< youtube iLU7ZBtjc-k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
