
+++
authors = ["grid47"]
title = "Leetcode 2550: Count Collisions of Monkeys on a Polygon"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2550: Count Collisions of Monkeys on a Polygon in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fwdV-VrFRiA"
youtube_upload_date="2023-01-29"
youtube_thumbnail="https://i.ytimg.com/vi/fwdV-VrFRiA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    
    int power(int a, int n) {
        if(n == 0) return 1;
        long long res = power(a, n/2) % mod;

        long long y = (res * res) %mod;
        // cout << (int) y << " " ;
        if(n & 1) {
            y = (a * y) % mod;
            return y;            
        }
        return y % mod;
    }
    
    int monkeyMove(int n) {
        
        int res = power(2, n);
        
        return (res - 2)<0? mod - res:res-2 ;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks for the number of distinct ways a monkey can make a move, where each move is represented as a power of 2. Specifically, we need to calculate the number of distinct ways the monkey can make a move after performing `n` moves, under a modulo operation. Additionally, we need to subtract 2 from the result since there are two distinct moves (or ways) that don't contribute to the overall distinct count.

Given the number of moves `n`, we are required to compute the number of distinct moves modulo \( 10^9 + 7 \), while also ensuring that we account for the base cases properly and return the result correctly.

### Approach

The key idea behind this problem is to utilize modular exponentiation to efficiently compute powers of 2. Given that the number of distinct ways the monkey can move can be expressed as \( 2^n \), the goal is to compute \( 2^n \mod (10^9 + 7) \), then subtract 2 from the result to account for the two invalid moves.

Let's break the problem down into the following steps:

1. **Power Calculation**:
   - We need to calculate \( 2^n \mod (10^9 + 7) \), which can be efficiently computed using modular exponentiation. This is a method that allows us to calculate large powers in logarithmic time by breaking down the exponentiation using divide-and-conquer.
   
2. **Subtracting Invalid Moves**:
   - Once we calculate \( 2^n \mod (10^9 + 7) \), we subtract 2 from the result to account for the two invalid moves (base cases where the monkey doesn't make any valid move).
   - If the result is negative after subtracting 2, we adjust by adding \( 10^9 + 7 \) to bring it within the valid range.

3. **Handling Large Exponents**:
   - Given that the exponent can be very large, we rely on the efficiency of modular exponentiation (which reduces the time complexity from \( O(n) \) to \( O(\log n) \)).

### Code Breakdown (Step by Step)

#### Step 1: Modular Exponentiation Function (`power`)

```cpp
int power(int a, int n) {
    if(n == 0) return 1;
    long long res = power(a, n/2) % mod;
    long long y = (res * res) % mod;
    if(n & 1) {
        y = (a * y) % mod;
        return y;            
    }
    return y % mod;
}
```

- This function calculates \( a^n \mod \text{mod} \) using a recursive approach based on the divide-and-conquer method (also called "exponentiation by squaring").
  
- **Base Case**: When `n == 0`, we return `1` because any number raised to the power of 0 is 1.
  
- **Recursive Case**: For even `n`, we calculate \( \text{res} = (a^{n/2} \mod \text{mod}) \) and then square it to get \( a^n \mod \text{mod} \).
  
- If `n` is odd, we multiply the result by `a` after squaring it, since \( a^{n} = a \times a^{n-1} \). This ensures the calculation is accurate and respects the modulo.

#### Step 2: Main Function (`monkeyMove`)

```cpp
int monkeyMove(int n) {
    int res = power(2, n);
    return (res - 2) < 0 ? mod - res : res - 2;
}
```

- This function calculates \( 2^n \mod (10^9 + 7) \) using the `power` function defined earlier.
  
- **Subtracting 2**: After calculating the result, we subtract 2 to account for the two invalid moves (those where no actual movement is made). This is done using `res - 2`.
  
- **Modulo Adjustment**: If the result after subtracting 2 is negative, we adjust by adding \( 10^9 + 7 \) to ensure the result stays within the valid range.

### Complexity

#### Time Complexity:
- The time complexity for the `power` function is \( O(\log n) \) because we divide the exponent `n` by 2 at each recursive call.
- The time complexity of the main function `monkeyMove` is dominated by the `power` function, so it is also \( O(\log n) \).

#### Space Complexity:
- The space complexity is \( O(\log n) \) due to the recursive calls made by the `power` function. Each recursive call adds a new frame to the stack, so the depth of recursion is logarithmic in terms of `n`.

### Conclusion

The `monkeyMove` function uses modular exponentiation to efficiently calculate the number of distinct moves the monkey can make after performing `n` moves, accounting for the base cases properly and ensuring the result is within the valid range. By applying the principle of "exponentiation by squaring," the solution computes large powers in logarithmic time, making it efficient even for large values of `n`.

This approach ensures that the problem is solved optimally with both time and space complexity reduced to \( O(\log n) \). The logic for subtracting 2 and handling negative results ensures that we can compute the correct number of distinct moves while taking care of edge cases.

This solution is efficient and scalable, making it suitable for problems where `n` can be large, and modulo operations are required for large results.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/)

---
{{< youtube fwdV-VrFRiA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
