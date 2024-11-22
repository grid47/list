
+++
authors = ["grid47"]
title = "Leetcode 319: Bulb Switcher"
date = "2024-10-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 319: Bulb Switcher in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/319.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/319.webp" 
    alt="A series of glowing bulbs switching on and off, with the final count of switched bulbs softly highlighted."
    caption="Solution to LeetCode 319: Bulb Switcher Problem"
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
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

Imagine a set of bulbs, all initially turned off. After `n` rounds of flipping, we need to determine how many bulbs remain **on**. In each round `i`, every `i`-th bulb is flipped (so round 1 flips all bulbs, round 2 flips every second bulb, and so on). By the end of all `n` rounds, how many bulbs are on? Let’s break it down and uncover a super efficient way to solve this!

---

### 🧠 Approach

At first glance, this might seem like a tricky problem, but there’s a neat mathematical trick that makes this much easier. Here's how we can think through the problem:

1. **Initial Setup**: All bulbs start **off**.
2. **Flipping Rule**: In round `i`, we flip every `i`-th bulb. So, in round 1, every bulb gets flipped (since every number is divisible by 1). In round 2, every second bulb gets flipped, and so on.
3. **Flipping Pattern**: A bulb gets flipped each time its index is divisible by a round number. For example, bulb 6 is flipped in rounds 1, 2, 3, and 6 (since those are the divisors of 6).
4. **Final Bulb State**: A bulb is **on** if it’s flipped an odd number of times. This only happens if its index is a **perfect square** because perfect squares have an odd number of divisors (1, 3, 5... etc.). For instance:
   - Bulb 1 is flipped once (perfect square).
   - Bulb 4 is flipped three times (perfect square).
   - Bulb 9 is flipped five times (perfect square).
5. **Result**: The number of bulbs left **on** is simply the number of perfect squares less than or equal to `n`. That’s the integer part of the square root of `n`!

---

### 🔨 Step-by-Step Code Breakdown

Let's walk through the code for this solution:

```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
```

1. **Function Signature**:
   - `bulbSwitch(int n)` takes an integer `n` (the number of bulbs) and returns the count of bulbs that are **on** after all rounds.

2. **Using `sqrt`**:
   - The key insight here is that only perfect squares will remain **on**.
   - The function `sqrt(n)` computes the square root of `n` and gives us the largest integer less than or equal to `sqrt(n)`. This integer represents the count of perfect squares (and hence, the number of bulbs **on**).

3. **Why Perfect Squares?**:
   - Bulbs at perfect square indices (1, 4, 9, 16, etc.) are the only ones flipped an odd number of times.
   - For example:
     - `1` has divisors 1 → flipped once.
     - `4` has divisors 1, 2, 4 → flipped three times.
     - `9` has divisors 1, 3, 9 → flipped five times.
   - Thus, the number of bulbs **on** is equal to the count of perfect squares less than or equal to `n`, which is simply `floor(sqrt(n))`.

---

### 📈 Complexity Analysis

- **Time Complexity**: **O(1)**  
  The core operation is computing the square root of `n`, which is a constant-time operation. There are no loops or complex operations involved.

- **Space Complexity**: **O(1)**  
  We only need space for the input `n` and the result (an integer). No additional space is required.

---

### 🏁 Conclusion

This is a **super efficient** solution that leverages the mathematical properties of perfect squares. By calculating the square root of `n`, we can instantly determine how many bulbs are **on** without needing to simulate the flipping rounds. It’s a constant-time solution, making it perfect for large values of `n`!

---

### 🔑 Key Takeaways

1. **Perfect Squares Rule**: Only bulbs at perfect square indices will remain **on**.
2. **Optimal Solution**: By calculating `sqrt(n)`, we can find the answer in **constant time**.
3. **Efficiency**: The solution is both **time-efficient** and **space-efficient**, making it scalable for large inputs.

Remember, sometimes the best solutions come from recognizing patterns or mathematical properties—this one is a great example of that! Keep up the great work, and let’s continue solving problems in clever ways! 🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/bulb-switcher/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
