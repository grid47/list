
+++
authors = ["grid47"]
title = "Leetcode 2300: Successful Pairs of Spells and Potions"
date = "2024-03-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2300: Successful Pairs of Spells and Potions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vO6FxLZpKg4"
youtube_upload_date="2023-04-02"
youtube_thumbnail="https://i.ytimg.com/vi/vO6FxLZpKg4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potion, long long success) {
        
        int n = spells.size();
        
        vector<int> ans(n, 0);
        
        sort(potion.begin(), potion.end());
        
        for(int i = 0; i < n; i++) {
            
            long long tgt = success % spells[i]? (success/ spells[i]) + 1 : (success/ spells[i]);
            
            ans[i] = potion.end() - lower_bound(potion.begin(), potion.end(), tgt);
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement
In this problem, you are given two arrays: `spells` and `potion`. You are also given a `success` value. The goal is to calculate the number of successful pairs of `(spell, potion)` such that the product of each spell and a potion is greater than or equal to the given `success` value. Specifically, for each spell, we want to find how many potions can pair with it such that their product meets or exceeds the `success` threshold.

### Approach
The key to solving this problem efficiently lies in leveraging sorting and binary search. Here’s the detailed approach:
1. **Sorting the Potions**: Sorting the `potion` array allows us to use binary search to efficiently find the first potion that meets the required threshold for a given spell.
2. **Binary Search**: For each spell, we calculate the minimum potion value needed to achieve the `success` threshold. Using binary search (`lower_bound`), we can quickly determine how many potions satisfy this condition.
3. **Efficient Calculation**: Instead of directly iterating over each potion for every spell, binary search provides a much faster way to find the smallest valid potion for each spell.

### Code Breakdown (Step by Step)
1. **Initialization:**
   ```cpp
   int n = spells.size();
   vector<int> ans(n, 0);
   sort(potion.begin(), potion.end());
   ```
   - `n` stores the number of spells.
   - `ans` is a vector initialized to zero, which will store the result: the number of successful pairs for each spell.
   - The `potion` array is sorted to prepare for efficient binary searching.

2. **Main Loop - Iterate Over Spells:**
   ```cpp
   for (int i = 0; i < n; i++) {
   ```
   - We iterate through each spell in the `spells` array to calculate how many potions can pair successfully with it.

3. **Calculating the Target Potion for Each Spell:**
   ```cpp
   long long tgt = success % spells[i] ? (success / spells[i]) + 1 : (success / spells[i]);
   ```
   - For each spell, we calculate the minimum potion value `tgt` such that the product of `spells[i]` and `tgt` is greater than or equal to the `success` threshold.
   - If the success is not perfectly divisible by `spells[i]`, we round up the result by adding 1 to ensure that the potion’s product with the spell is at least `success`.

4. **Finding Valid Potions with Binary Search:**
   ```cpp
   ans[i] = potion.end() - lower_bound(potion.begin(), potion.end(), tgt);
   ```
   - The `lower_bound` function finds the first potion in the sorted `potion` array that is greater than or equal to `tgt`. This is a crucial step because it allows us to efficiently count how many potions meet the condition.
   - The expression `potion.end() - lower_bound(potion.begin(), potion.end(), tgt)` computes the number of potions that are valid for the current spell. This is done by finding the distance between the end of the `potion` array and the position returned by `lower_bound`.

5. **Return Result:**
   ```cpp
   return ans;
   ```
   - After processing all spells, we return the `ans` array, which contains the number of successful pairs for each spell.

### Complexity
- **Time Complexity**:
  - Sorting the `potion` array takes O(m log m), where `m` is the length of the `potion` array.
  - For each spell, the binary search (`lower_bound`) on the sorted `potion` array takes O(log m). Since there are `n` spells, the overall time complexity is O(n log m + m log m).
  - Therefore, the time complexity is O(n log m + m log m), which is efficient for large inputs.

- **Space Complexity**:
  - The space complexity is O(m) due to the space used by the sorted `potion` array and O(n) for the result array `ans`.
  - Therefore, the overall space complexity is O(m + n), which is acceptable for typical input sizes.

### Conclusion
This solution efficiently solves the problem of counting successful pairs of spells and potions using sorting and binary search. By sorting the `potion` array and applying binary search for each spell, the solution achieves optimal time complexity of O(n log m + m log m), which is much more efficient than brute force approaches. This method ensures that even for larger inputs, the solution remains performant.

The use of binary search to find the first valid potion for each spell dramatically reduces the time complexity compared to iterating through each potion for every spell, making the algorithm both fast and scalable. The approach guarantees correctness by ensuring that all spells and potions are processed in a manner that respects the condition of achieving the success threshold.

[`Link to LeetCode Lab`](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/)

---
{{< youtube vO6FxLZpKg4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
