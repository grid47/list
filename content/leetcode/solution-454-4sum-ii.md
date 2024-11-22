
+++
authors = ["grid47"]
title = "Leetcode 454: 4Sum II"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 454: 4Sum II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/454.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/454.webp" 
    alt="A sequence of quadruples where each valid sum is softly highlighted to show the results."
    caption="Solution to LeetCode 454: 4Sum II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int a : A)
        for(int b : B)
        mp[a+b]++;
        for(int c : C)
        for(int d : D)
        if(mp.count(-c-d)) res+= mp[-c-d];
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the total number of quadruplets `(A[i], B[j], C[k], D[l])` such that the sum of these four elements equals zero, i.e., `A[i] + B[j] + C[k] + D[l] = 0`. The arrays `A`, `B`, `C`, and `D` are all given as input, and the goal is to compute how many such quadruplets exist in these arrays.

### Approach

To solve this problem efficiently, a brute force approach of checking all possible quadruplets would take `O(n^4)` time complexity, where `n` is the size of each array. This would be inefficient for large input sizes. Instead, we can reduce the complexity using a **hash map** to store the sum of pairs of elements from arrays `A` and `B`, and then check for matching sums from pairs of elements from arrays `C` and `D`.

1. **Key Insight**:
   - We can take advantage of the fact that the sum of four numbers equals zero:
     \[
     A[i] + B[j] + C[k] + D[l] = 0
     \]
     This can be rewritten as:
     \[
     (A[i] + B[j]) = -(C[k] + D[l])
     \]
   - Therefore, if we precompute the sums of pairs `(A[i] + B[j])` and store their frequency in a hash map, we can later look for matching pairs `(C[k] + D[l])` that give the negative of a previously computed sum.

2. **Detailed Plan**:
   - **Step 1**: Create a hash map `mp` where the key is the sum of `A[i] + B[j]` and the value is the count of how often that sum appears.
   - **Step 2**: Iterate over all pairs of elements from arrays `C` and `D`, calculate their sum, and check if the negative of this sum is present in the hash map `mp`.
   - **Step 3**: If the negative sum exists in the hash map, it means there is a quadruplet whose sum equals zero. The frequency of that sum in the hash map tells us how many such quadruplets can be formed.

### Code Breakdown (Step by Step)

#### Step 1: Create the Hash Map for Pair Sums

```cpp
unordered_map<int, int> mp;
for (int a : A)
    for (int b : B)
        mp[a + b]++;
```

- We first initialize an empty hash map `mp`.
- Then, we loop through every element `a` in array `A` and every element `b` in array `B`. For each pair `(a, b)`, we calculate the sum `a + b` and store the frequency of that sum in the map. The key is `a + b` and the value is the count of how many times this sum appears in the pairwise combinations of `A` and `B`.

#### Step 2: Check for Matching Pairs from Arrays C and D

```cpp
for (int c : C)
    for (int d : D)
        if (mp.count(-c - d)) 
            res += mp[-c - d];
```

- After creating the hash map with sums from arrays `A` and `B`, we move on to check the sums of pairs from arrays `C` and `D`.
- For each element `c` in array `C` and each element `d` in array `D`, we compute the sum `c + d`.
- We then look for the negative of this sum (`-c - d`) in the hash map `mp`. If it exists, it means there are `mp[-c - d]` quadruplets where the sum of elements from arrays `A`, `B`, `C`, and `D` equals zero. We add `mp[-c - d]` to the result count `res`.

#### Step 3: Return the Result

```cpp
return res;
```

- Finally, we return the result `res`, which contains the count of quadruplets where the sum of the elements equals zero.

### Complexity

#### Time Complexity:

- **Precomputing Pair Sums**: The first nested loop iterating over arrays `A` and `B` takes `O(n^2)` time, where `n` is the length of each array.
- **Checking for Matching Pair Sums**: The second nested loop iterating over arrays `C` and `D` also takes `O(n^2)` time.
- Overall, the time complexity is `O(n^2)`, where `n` is the length of each array.

#### Space Complexity:

- We are using an unordered map `mp` to store the sums of pairs from arrays `A` and `B`. In the worst case, each sum can be unique, so the space required for the hash map is `O(n^2)`, where `n` is the length of the arrays.
- Therefore, the space complexity is `O(n^2)`.

### Conclusion

This solution efficiently solves the problem of counting quadruplets that sum to zero by leveraging the power of hash maps. By precomputing the sums of pairs from two arrays (`A` and `B`) and checking for matching sums from pairs of arrays (`C` and `D`), the algorithm reduces the problem from a brute-force `O(n^4)` solution to a more efficient `O(n^2)` solution. This approach is ideal for large inputs, making it both time and space efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/4sum-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
