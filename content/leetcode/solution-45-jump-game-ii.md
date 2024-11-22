
+++
authors = ["grid47"]
title = "Leetcode 45: Jump Game II"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 45: Jump Game II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/45.webp"
youtube = "CsDI-yQuGeM"
youtube_upload_date="2024-08-08"
youtube_thumbnail="https://i.ytimg.com/vi/CsDI-yQuGeM/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/45.webp" 
    alt="A glowing path with multiple jumping stones, forming an easy, calming journey."
    caption="Solution to LeetCode 45: Jump Game II Problem"
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
    int jump(vector<int>& nums) {
        int jumps = 0;
        int cur = 0;
        int far = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            far = max(far, i + nums[i]);
            if(i == cur) {
                cur = far;
                jumps++;
            }
        }
        return jumps;
    }
};
{{< /highlight >}}
---

### 🏃‍♂️ **Minimum Jumps to Reach the End of the Array**

The problem asks to find the minimum number of jumps required to reach the end of an array starting from the first element. Each element in the array represents the maximum number of steps you can jump forward from that position. Our goal is to compute the least number of jumps needed to move from the start to the last element.

---

### 🚀 **Approach**

To solve this efficiently, we'll use a **greedy approach**. The key idea is to always make the jump that takes us as far as possible at each step. Instead of evaluating all potential jump combinations (which would be inefficient), we will track the farthest position reachable at each step and jump accordingly. Here's a step-by-step explanation of the approach:

1. **Current Position (`cur`)**: This variable tracks the farthest position we can reach with the current number of jumps.
2. **Farthest Position (`far`)**: This keeps track of the farthest position we can reach considering all possible jumps in the current iteration.
3. **Jumps (`jumps`)**: This variable counts the number of jumps made so far.
4. **When to Jump**: If the current position `i` reaches the farthest point `cur`, it means we need to make a jump to the farthest position (`cur = far`) and increment the `jumps` counter.

---

### 🖥️ **Code Breakdown (Step-by-Step)**

#### Step 1: Initializing Variables

```cpp
int jumps = 0;
int cur = 0;
int far = 0;
```

- `jumps`: Tracks the total number of jumps taken so far.
- `cur`: Represents the farthest index that can be reached with the current number of jumps.
- `far`: Stores the farthest position that can be reached with the current jump (considering all possible jumps from the current index).

#### Step 2: Looping Through the Array

```cpp
for (int i = 0; i < nums.size() - 1; i++) {
    far = max(far, i + nums[i]);
    if (i == cur) {
        cur = far;
        jumps++;
    }
}
```

- **Line 1**: We iterate through the array, stopping just before the last element (`nums.size() - 1`) because reaching the last element means we are done.
- **Line 2**: For each index `i`, we calculate the farthest we can reach from that index (`i + nums[i]`), and update the `far` variable to be the maximum of the current `far` and the new reachable position.
- **Line 3**: If `i` is equal to `cur`, it means we've exhausted all reachable positions with the current number of jumps. We increment `jumps` and set `cur` to `far`, which is the farthest we can reach with the next jump.

#### Step 3: Returning the Result

```cpp
return jumps;
```

- After the loop completes, the `jumps` variable contains the minimum number of jumps required to reach the last element of the array.

---

### 🧮 **Complexity Analysis**

#### Time Complexity

- The algorithm only makes a single pass through the array (`O(n)`), where `n` is the size of the input array `nums`. In each iteration, we perform constant-time operations to update `cur` and `far`, so the overall time complexity is:
  - **Time Complexity:** `O(n)`, where `n` is the length of the array.

#### Space Complexity

- We only use a few variables (`jumps`, `cur`, `far`), and no additional data structures are used. Therefore, the space complexity is constant:
  - **Space Complexity:** `O(1)`.

---

### 🏁 **Conclusion**

This greedy approach efficiently solves the problem of finding the minimum number of jumps required to reach the end of the array. By tracking the farthest positions reachable at each step, we ensure that we are always making the best choice at each step and minimize the number of jumps.

- **Time Complexity:** `O(n)` (linear time complexity, efficient for large arrays)
- **Space Complexity:** `O(1)` (constant space usage)

This solution is optimal in both time and space, making it suitable for large input arrays where an `O(n)` time complexity solution is essential.

[`Link to LeetCode Lab`](https://leetcode.com/problems/jump-game-ii/description/)

---
{{< youtube CsDI-yQuGeM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
