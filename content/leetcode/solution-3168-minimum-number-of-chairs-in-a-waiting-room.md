
+++
authors = ["grid47"]
title = "Leetcode 3168: Minimum Number of Chairs in a Waiting Room"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3168: Minimum Number of Chairs in a Waiting Room in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "-VAEXKFWfXo"
youtube_upload_date="2024-06-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-VAEXKFWfXo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumChairs(string s) {
        int mx = 0, cnt = 0;
        for(char x: s) {
            cnt += (x == 'E'? 1: -1);
            mx = max(mx, cnt);
        }
        return mx;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine the minimum number of chairs needed in a room where people enter and exit at specific times, represented by a string `s`. Each character in the string represents an event: 'E' for entering the room and 'X' for exiting. The goal is to find out how many chairs are needed to accommodate the maximum number of people in the room at any given time.

### Approach

To solve this problem, the approach revolves around simulating the entry and exit of people based on the sequence of events. The core idea is to track the number of people currently in the room, and at each step, update this number when a person enters or exits. By tracking the maximum number of people in the room at any given time, we can determine the minimum number of chairs required.

The sequence of events (`s`) tells us when people enter ('E') and when they exit ('X'). We will maintain a count of how many people are in the room at each point. The maximum count during the simulation will indicate the peak number of people present in the room simultaneously, and this is the answer we are looking for.

### Code Breakdown (Step by Step)

1. **Initialization**:
   - We initialize two variables:
     - `mx`: This variable will store the maximum number of people in the room at any point.
     - `cnt`: This variable tracks the current number of people in the room as we process the events in the string `s`.

   ```cpp
   int mx = 0, cnt = 0;
   ```

2. **Iterating Over the String**:
   - We loop through each character of the string `s` using a `for` loop.
   - For each character:
     - If the character is `'E'`, a person enters the room, so we increment the `cnt` variable by 1.
     - If the character is `'X'`, a person exits the room, so we decrement the `cnt` variable by 1.
   - After updating `cnt`, we check whether it is greater than `mx`. If so, we update `mx` to be the new value of `cnt`.

   ```cpp
   for (char x: s) {
       cnt += (x == 'E' ? 1 : -1);  // Increment for 'E', Decrement for 'X'
       mx = max(mx, cnt);  // Update mx with the maximum number of people at any point
   }
   ```

3. **Return the Result**:
   - After processing all the events in the string, `mx` will hold the maximum number of people that were in the room at any time, which corresponds to the minimum number of chairs required. We then return the value of `mx` as the result.

   ```cpp
   return mx;
   ```

### Example Walkthrough

Let’s walk through an example of how this function works:

#### Input:
```cpp
string s = "EEXEXEEX";
```

#### Process:

1. **Initialization**:
   - `mx = 0`, `cnt = 0` (no one in the room initially).

2. **First Event (`E`)**:
   - A person enters the room, so `cnt = 1`.
   - We update `mx = max(0, 1)` → `mx = 1`.

3. **Second Event (`E`)**:
   - Another person enters the room, so `cnt = 2`.
   - We update `mx = max(1, 2)` → `mx = 2`.

4. **Third Event (`X`)**:
   - A person exits the room, so `cnt = 1`.
   - We update `mx = max(2, 1)` → `mx = 2`.

5. **Fourth Event (`E`)**:
   - A person enters the room, so `cnt = 2`.
   - We update `mx = max(2, 2)` → `mx = 2`.

6. **Fifth Event (`X`)**:
   - A person exits the room, so `cnt = 1`.
   - We update `mx = max(2, 1)` → `mx = 2`.

7. **Sixth Event (`E`)**:
   - A person enters the room, so `cnt = 2`.
   - We update `mx = max(2, 2)` → `mx = 2`.

8. **Seventh Event (`E`)**:
   - Another person enters the room, so `cnt = 3`.
   - We update `mx = max(2, 3)` → `mx = 3`.

9. **Eighth Event (`X`)**:
   - A person exits the room, so `cnt = 2`.
   - We update `mx = max(3, 2)` → `mx = 3`.

10. **Result**:
   - After processing all events, the maximum number of people in the room at any time was `3`. Therefore, the minimum number of chairs required is `3`.

#### Output:
```cpp
3
```

### Complexity

#### Time Complexity:
- **O(n)**: The time complexity is **O(n)**, where `n` is the length of the input string `s`. This is because we only need to iterate through the string once to process each event (either an entry or an exit). Each event takes constant time, so the total time complexity is linear with respect to the length of the string.

#### Space Complexity:
- **O(1)**: The space complexity is **O(1)** because we only use a few variables (`mx`, `cnt`), regardless of the size of the input string `s`. We do not need any additional data structures that depend on the input size, so the space usage is constant.

### Conclusion

This solution efficiently calculates the minimum number of chairs needed by simulating the entry and exit of people in a room. It tracks the number of people in the room at any given time and finds the maximum number, which corresponds to the minimum number of chairs required. The algorithm runs in linear time, making it efficient and scalable for large input sizes. The space complexity is constant, which makes this solution optimal in terms of space usage as well.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/)

---
{{< youtube -VAEXKFWfXo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
