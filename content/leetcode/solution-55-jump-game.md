
+++
authors = ["grid47"]
title = "Leetcode 55: Jump Game"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 55: Jump Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/55.webp"
youtube = "Yan0cv2cLy8"
youtube_upload_date="2021-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/Yan0cv2cLy8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/55.webp" 
    alt="A glowing, serene path with various stepping stones, symbolizing overcoming obstacles."
    caption="Solution to LeetCode 55: Jump Game Problem"
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
    bool canJump(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mx < i) return false;
            mx = max(mx, i + nums[i]);
            cout << mx << ' ';
            if(mx >= nums.size() - 1) return true;
        }
        return false;
    }
};
{{< /highlight >}}
---

### 🚀 **Jump Game**

The problem asks whether it is possible to reach the last index of an array starting from the first index, given that each element in the array represents the maximum jump length you can make from that position. You can jump forward, but the goal is to determine if you can make it to the last element.

For example, given the input array:

```
[2, 3, 1, 1, 4]
```

In this case, you can jump from index 0 to index 1 (since `nums[0] = 2`), then from index 1 to index 4 (since `nums[1] = 3`), and thus reach the last index. The output for this example would be `true`.

### 🧑‍💻 **Approach**

We solve this problem using a **greedy approach**. The core idea is to iterate through the array and track the maximum index (`mx`) that can be reached at each step. If at any point the current index exceeds this maximum reachable index (`mx`), then it is impossible to reach the end, and we return `false`. If we reach or exceed the last index, we return `true`.

The key insight is that each element in the array tells you the maximum distance you can jump from that index. As you progress through the array, you keep updating the farthest index you can reach. If at any point the farthest reachable index is less than the current index, it means you are "stuck" and cannot proceed further.

### 📝 **Code Breakdown**

#### Step 1: Initialize Variables

```cpp
int mx = 0;
int n = nums.size();
```

- `mx` represents the maximum index that can be reached so far. It is initialized to `0`, meaning we start at the first index.
- `n` stores the size of the input array `nums`.

#### Step 2: Loop Through the Array

```cpp
for(int i = 0; i < n; i++) {
    if(mx < i) return false;
    mx = max(mx, i + nums[i]);
    cout << mx << ' ';
    if(mx >= nums.size() - 1) return true;
}
```

- **For loop:** We iterate through each index `i` in the array `nums`.

- **Check if stuck:** The condition `if(mx < i)` checks if the maximum reachable index is less than the current index `i`. This means that we cannot progress to the current index, so we return `false`.

- **Update maximum reachable index:** The line `mx = max(mx, i + nums[i]);` updates the maximum index that can be reached by considering the current index `i` and the jump length `nums[i]`. The `max` function ensures that `mx` holds the farthest index we can reach at any point.

- **Debug output:** The `cout << mx << ' '` outputs the current value of `mx` for debugging purposes, showing how the maximum reachable index changes as we iterate through the array.

- **Check if last index is reachable:** The condition `if(mx >= nums.size() - 1)` checks if the maximum reachable index `mx` has reached or exceeded the last index (`nums.size() - 1`). If it has, we return `true`, indicating that the last index is reachable.

#### Step 3: Return `false` if Loop Completes

```cpp
return false;
```

- If the loop completes without returning `true`, it means that it is not possible to reach the last index, so we return `false`.

### 📊 **Complexity Analysis**

#### Time Complexity:
- **O(n):** The algorithm makes a single pass over the array, iterating from 0 to `n-1`. For each index, constant-time operations (comparison, maximum update, and print) are performed. Thus, the time complexity is **O(n)**, where `n` is the length of the input array.

#### Space Complexity:
- **O(1):** The solution uses only a few additional variables (`mx` and `n`), regardless of the size of the input array. Therefore, the space complexity is **O(1)**.

### 🌟 **Conclusion**

This solution efficiently determines whether it is possible to reach the last index of the array using a **greedy approach**. The key idea is to keep track of the farthest index that can be reached at each step and ensure that the current index is always reachable. If at any point the current index exceeds the maximum reachable index, it is impossible to continue, and we return `false`. If we can reach or exceed the last index, we return `true`.

The approach runs in **linear time** (O(n)) and uses **constant space** (O(1)), making it highly efficient for large input sizes. This simplicity and efficiency make it a great solution for problems involving array traversal and jump-based algorithms.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/jump-game/description/)

---
{{< youtube Yan0cv2cLy8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
