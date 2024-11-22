
+++
authors = ["grid47"]
title = "Leetcode 39: Combination Sum"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 39: Combination Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/39.webp"
youtube = "utBw5FbYswk"
youtube_upload_date="2024-04-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/utBw5FbYswk/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/39.webp" 
    alt="A sequence of glowing paths merging together, forming a combination with a gentle light."
    caption="Solution to LeetCode 39: Combination Sum Problem"
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
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        bt(ans, tmp, 0, target, cand);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, vector<int> &tmp, int idx, int sum, vector<int> &cand) {
        if(idx == cand.size() || sum == 0) {
            if(sum == 0) ans.push_back(tmp);
            return;
        }
        if(sum < 0) return;
        tmp.push_back(cand[idx]);
        bt(ans, tmp, idx, sum - cand[idx], cand);
        tmp.pop_back();
        
        bt(ans, tmp, idx + 1, sum, cand);
    }
};
{{< /highlight >}}
---

### 📝 Problem Statement

The task is to solve the **Combination Sum** problem, where we are given a list of candidate numbers and a target number. The objective is to find **all unique combinations** of the candidates that sum up to the target. The twist is that each number from the list can be used **multiple times** in a combination.

### 🛠️ Approach

We’ll use **backtracking** here—a powerful technique for generating all possible combinations by trying out each possibility and stepping back when necessary. The idea is to build combinations step-by-step, adding numbers from the candidates and checking if the sum matches the target.

If the current sum exceeds the target, we backtrack, removing the last added number. If the sum hits the target, we store that combination as a valid solution. By considering all possibilities, we explore every potential combination.

### 🔍 Code Breakdown (Step by Step)

#### Function: `combinationSum`

```cpp
vector<vector<int>> combinationSum(vector<int>& cand, int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    bt(ans, tmp, 0, target, cand);
    return ans;
}
```

- **Input:** The function takes the candidates list `cand` and the target sum `target`.
- **Goal:** It initializes an empty result vector `ans` and a temporary vector `tmp` to build combinations. Then, it calls the **backtracking helper function** `bt` to explore all combinations starting from index `0` with the initial target sum.

#### Function: `bt` (Backtracking Helper)

```cpp
void bt(vector<vector<int>> &ans, vector<int> &tmp, int idx, int sum, vector<int> &cand) {
    if(idx == cand.size() || sum == 0) {
        if(sum == 0) ans.push_back(tmp);
        return;
    }
    if(sum < 0) return;
    tmp.push_back(cand[idx]);
    bt(ans, tmp, idx, sum - cand[idx], cand);
    tmp.pop_back();

    bt(ans, tmp, idx + 1, sum, cand);
}
```

- **Base Case 1:** If `sum == 0`, we’ve found a valid combination. We add `tmp` (the current combination) to the result `ans` and return.
  
- **Base Case 2:** If `sum < 0`, this combination exceeds the target, so we stop and return without further exploration.

- **Recursive Step 1:** We try to include `cand[idx]` in the combination:
  - Add `cand[idx]` to `tmp`.
  - Recursively call `bt` with the same index `idx` (allowing repeated use of the same candidate) and reduce the target sum by `cand[idx]`.
  - After the recursive call, backtrack by removing the last added number from `tmp`.

- **Recursive Step 2:** We try excluding `cand[idx]` and move to the next candidate by increasing the index (`idx + 1`).

The recursive calls ensure we explore both options (including or excluding a candidate) for every number in the list, generating all valid combinations.

### 🌱 Example Walkthrough

Let’s walk through an example to see how the algorithm works.

**Example Input:**
- `cand = [2, 3, 6, 7]`
- `target = 7`

**Steps:**
1. Start with an empty combination `[]` and `target = 7`.
2. Include `2`:
   - New combination: `[2]`, new target: `5`.
3. Include `2` again:
   - New combination: `[2, 2]`, new target: `3`.
4. Include `2` again:
   - New combination: `[2, 2, 2]`, new target: `1`.
5. Backtrack since `1` is less than `0`.
6. Now, try `3` (next candidate) with combination `[2, 2]`:
   - New combination: `[2, 2, 3]`, new target: `0`. This is a valid solution!
7. Backtrack and explore other candidates `6` and `7`.
8. Continue this process until all combinations are explored.

### ⏱️ Complexity Analysis

#### Time Complexity:
- The time complexity is **O(2^n)**, where `n` is the number of candidates. This is because at each candidate, we have two choices: include or exclude it. Thus, the total number of combinations is at most `2^n`.

#### Space Complexity:
- The space complexity is **O(n + 2^n)**, where `n` is the number of candidates. The `2^n` accounts for the possible combinations, and `n` represents the maximum depth of the recursion stack.

### 🚀 Conclusion

This approach effectively uses backtracking to explore all possible combinations, ensuring we find all solutions that sum up to the target. Each recursive step tries adding or excluding a number, efficiently exploring all paths. With a time complexity of **O(2^n)** and space complexity of **O(n + 2^n)**, this solution is optimal for reasonable-sized inputs.

---

**Remember:** "Practice makes perfect!" Understanding recursion and backtracking will make problems like this feel more intuitive. 🌟

[`Link to LeetCode Lab`](https://leetcode.com/problems/combination-sum/description/)

---
{{< youtube utBw5FbYswk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
