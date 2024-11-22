
+++
authors = ["grid47"]
title = "Leetcode 390: Elimination Game"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 390: Elimination Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/390.webp"
youtube = "0U5Lenn_vMo"
youtube_upload_date="2021-04-21"
youtube_thumbnail="https://i.ytimg.com/vi/0U5Lenn_vMo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/390.webp" 
    alt="A series of elements being eliminated one by one, with each eliminated element glowing as it is removed."
    caption="Solution to LeetCode 390: Elimination Game Problem"
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
    int lastRemaining(int n) {
        bool left = true;
        int rm = n;
        int step = 1;
        int head = 1;
        while(rm > 1) {
            if(left || rm % 2 == 1) {
                head += step;
            }
            rm /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The task is to find the **last remaining number** in a sequence after repeatedly eliminating every second number. Starting with an array of integers from 1 to `n`, we eliminate every other number (either from left to right or right to left) in successive rounds. Our goal is to determine which number remains after all rounds are completed.

---

### 🧠 Approach

This problem can be simplified by recognizing a predictable pattern in the elimination process. Rather than simulating each round, we can use a mathematical approach to find the last number left standing.

#### Key Observations:
1. **Direction alternation**: The elimination direction alternates between left-to-right and right-to-left in successive rounds.
2. **Halving the sequence**: Each round halves the remaining sequence, as every second number is eliminated.
3. **Elimination based on parity**: The sequence behaves differently when the number of elements is odd vs. even. In cases where the length is odd, the last element is eliminated first in the left-to-right direction.

By recognizing these patterns, we can use an efficient iterative approach to calculate the last remaining number without simulating the entire process.

---

### 🔨 Step-by-Step Code Breakdown

Here’s the code that implements this approach:

```cpp
class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;  // Tracks elimination direction (left-to-right or right-to-left)
        int rm = n;        // Number of remaining elements
        int step = 1;      // The step size (initially 1 for eliminating every second number)
        int head = 1;      // The first number in the sequence (initially 1)

        // Continue until only one number remains
        while (rm > 1) {
            if (left || rm % 2 == 1) {
                head += step;  // Update the first remaining number
            }
            rm /= 2;       // Halve the sequence length
            step *= 2;     // Double the step size
            left = !left;  // Alternate the direction of elimination
        }

        return head;  // Return the last remaining number
    }
};
```

#### Step-by-Step Explanation:
1. **Initialize Variables**:
   - `left`: This flag indicates whether the current round is left-to-right (`true`) or right-to-left (`false`).
   - `rm`: The number of remaining elements in the sequence, initially set to `n`.
   - `step`: The step size, which starts at 1 (eliminate every second number). It doubles with each round to account for the halving of the sequence.
   - `head`: The first number of the sequence, initially 1.

2. **Iterative Process**:
   - The `while` loop runs as long as there is more than one element (`rm > 1`).
   - On each iteration:
     - If the direction is `left` or the number of remaining elements is odd, we update the first remaining number (`head`) by adding the `step`.
     - We then halve the sequence (`rm /= 2`) and double the step size (`step *= 2`).
     - The direction is toggled (`left = !left`) for the next round.
     
3. **Return the Result**:
   - When the loop finishes, `head` contains the last remaining number, which is returned.

---

### 📈 Complexity Analysis

#### Time Complexity:
The time complexity of this solution is **O(log n)**. The sequence length (`rm`) is halved in each round, meaning the loop runs approximately **log n** times, where `n` is the initial size of the sequence.

#### Space Complexity:
The space complexity is **O(1)** because we are using only a few integer variables (`left`, `rm`, `step`, `head`) that occupy constant space, regardless of the size of `n`.

---

### 🏁 Conclusion

This approach efficiently computes the **last remaining number** in the sequence after repeatedly eliminating every second number. By leveraging the predictable halving pattern and alternating direction, we can solve the problem in **O(log n)** time, making it suitable for large inputs.

### 🎯 Key Takeaways:
- **Optimized Iteration**: Instead of simulating the elimination process, we use mathematical observations to reduce the problem to a logarithmic number of steps.
- **Constant Space**: The solution only uses a few integer variables, ensuring minimal space usage.
- **Logarithmic Time**: The process runs in **O(log n)** time, making it highly efficient for large values of `n`.

With this solution, you can confidently handle the problem even with very large inputs. Keep up the great work, and happy coding! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/elimination-game/description/)

---
{{< youtube 0U5Lenn_vMo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
