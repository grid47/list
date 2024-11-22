
+++
authors = ["grid47"]
title = "Leetcode 2048: Next Greater Numerically Balanced Number"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2048: Next Greater Numerically Balanced Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "VLLBGEWCHqs"
youtube_upload_date="2021-10-24"
youtube_thumbnail="https://i.ytimg.com/vi/VLLBGEWCHqs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> base = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666 };
    int nextBeautifulNumber(int n) {
        int res = 1224444;
        
        string s = to_string(n);
        for(auto it: base) {
            string ss = to_string(it);
            if(ss.size() < s.size()) continue;
            if(ss.size() > s.size()) res = min(res, it);
            else {
                do {
                    if(ss > s) {
                        res = min(res, stoi(ss));
                    }
                } while(next_permutation(ss.begin(), ss.end()));
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the smallest "beautiful number" that is greater than a given integer `n`. A number is defined as "beautiful" if each digit `d` in the number appears exactly `d` times (for example, `122333` is beautiful because `1` appears once, `2` appears twice, and `3` appears three times). The task is to efficiently locate the next beautiful number after `n`.

### Approach

This code leverages a precomputed list of beautiful numbers, `base`, and performs minimal computations by iterating over possible beautiful numbers in `base` and checking if they exceed `n`. If a number in `base` is greater than `n` and is minimal among all candidates that meet this criterion, it is chosen as the result.

Here’s a summary of the approach:
1. **Base List of Beautiful Numbers**: We use a predefined list of known beautiful numbers up to the smallest number larger than `n`.
2. **Comparing Digits**: For numbers with the same length as `n`, we generate all permutations to check if any permutation is greater than `n`.
3. **Return the Smallest Valid Result**: After checking all potential beautiful numbers, the smallest valid number greater than `n` is returned as the result.

### Code Breakdown (Step by Step)

1. **Class and Method Definition**: The class `Solution` contains a vector `base` with precomputed beautiful numbers and the function `nextBeautifulNumber`, which takes an integer `n` and returns the next beautiful number.

    ```cpp
    class Solution {
    public:
        vector<int> base = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666 };
        int nextBeautifulNumber(int n) {
    ```

2. **Initialize Result to Large Default**: The variable `res` is set to `1224444`, which is the smallest beautiful number beyond the values in `base`. This will store the final result.

    ```cpp
    int res = 1224444;
    ```

3. **Convert `n` to String for Comparison**: Converting `n` to a string simplifies length comparison with each beautiful number in `base`.

    ```cpp
    string s = to_string(n);
    ```

4. **Iterate Over Beautiful Numbers**: Using a loop, the code checks each number `it` in `base`:
   - **If Shorter Length**: If `it` has fewer digits than `n`, it’s skipped as it can’t be the next beautiful number.
   - **If Longer Length**: If `it` has more digits, it’s added to the result if it’s the smallest number larger than `n`.
   - **If Same Length**: For numbers of the same length as `n`, permutations are checked to see if any permutation is greater than `n`.

    ```cpp
    for(auto it: base) {
        string ss = to_string(it);
        if(ss.size() < s.size()) continue;
        if(ss.size() > s.size()) res = min(res, it);
    ```

5. **Handle Permutations for Same-Length Numbers**: For numbers of the same length, we check if any permutation of the digits forms a valid number greater than `n`. `next_permutation` helps generate these permutations in lexicographical order.

    ```cpp
    else {
        do {
            if(ss > s) {
                res = min(res, stoi(ss));
            }
        } while(next_permutation(ss.begin(), ss.end()));
    }
    ```

6. **Return the Result**: Once the loop completes, `res` holds the next beautiful number greater than `n`, which is returned.

    ```cpp
    return res;
    ```

### Complexity

- **Time Complexity**: The time complexity is O(K \* P), where `K` is the number of elements in `base` and `P` is the number of permutations for numbers with the same length as `n`. Given the limited size of `base`, this is efficient for the problem constraints.
- **Space Complexity**: The space complexity is O(N) due to string storage and permutation generation, making it manageable.

### Conclusion

This solution provides an efficient approach to finding the next beautiful number after `n` by utilizing a precomputed base list of beautiful numbers. By leveraging `next_permutation`, the code efficiently handles comparisons with numbers of the same length. This approach minimizes unnecessary computations and ensures that the smallest valid number is returned. This solution is both time-efficient and space-efficient, making it suitable for competitive programming and efficient number generation tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/next-greater-numerically-balanced-number/description/)

---
{{< youtube VLLBGEWCHqs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
