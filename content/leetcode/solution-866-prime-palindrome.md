
+++
authors = ["grid47"]
title = "Leetcode 866: Prime Palindrome"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 866: Prime Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MZSbndVpxH8"
youtube_upload_date="2019-11-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MZSbndVpxH8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int primePalindrome(int n) {
        if(8 <= n && n <= 11) return 11;
        for(int x = 1; x < 100000; x++) {
            string s = to_string(x), r(s.rbegin(), s.rend());
            int y = stoi(s + r.substr(1));
            if(y >= n && isPrime(y)) return y;
        }
        return -1;
    }
    
    bool isPrime(int num) {
        if(num < 2 || num %2 == 0) return num == 2;
        for(int i = 3; i * i <= num; i += 2) {
            if(num%i == 0) return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the **smallest prime palindrome** number greater than or equal to a given integer `n`. A prime palindrome is a number that is both a palindrome and a prime number. A **palindrome** is a number that reads the same forward and backward, while a **prime number** is a number greater than 1 that has no positive divisors other than 1 and itself. The task is to return the smallest prime palindrome number greater than or equal to `n`.

### Problem Explanation

To clarify, the task requires us to:
1. Find the smallest palindrome number that is greater than or equal to `n`.
2. Check if the palindrome is also a prime number.
3. If it is prime, return that palindrome number.
4. If no such number exists, return `-1`.

A **palindrome** number is one that reads the same backward as forward, e.g., `121`, `12321`. A **prime** number is one that has no divisors other than 1 and itself, e.g., `2`, `3`, `5`, `7`.

### Approach

To solve this problem, we can break it down into a couple of simple steps:
1. **Generate Palindromes**: We need a way to generate numbers that are palindromes. This can be done efficiently by generating half of the number and reflecting it to form the full number.
2. **Check Primality**: For each palindrome number, we check if it is prime. If it is, we return that number.
3. **Optimization**: Since we are interested in the smallest palindrome greater than or equal to `n`, we should start generating palindromes from numbers greater than or equal to `n` and stop as soon as we find a prime palindrome.

The main challenge is generating the palindromes and checking whether they are prime. The method involves creating palindromes from numbers and checking if they are prime until we find one that is greater than or equal to `n`.

### Code Breakdown (Step by Step)

#### Step 1: Handling Small Cases (Special Case for Numbers Between 8 and 11)

```cpp
if (8 <= n && n <= 11) return 11;
```

- The function first handles a special case for numbers between 8 and 11 (inclusive). These numbers are small and can be handled quickly because the smallest prime palindrome greater than or equal to these values is `11`.

#### Step 2: Loop to Generate Palindromes and Check for Primality

```cpp
for(int x = 1; x < 100000; x++) {
    string s = to_string(x), r(s.rbegin(), s.rend());
    int y = stoi(s + r.substr(1));
    if (y >= n && isPrime(y)) return y;
}
```

- We use a loop that generates numbers `x` from `1` to `99999`. For each number `x`:
  - Convert `x` into a string `s`.
  - Reverse the string `s` to create a string `r`.
  - Construct the palindrome `y` by concatenating `s` and the substring of `r` starting from the second character. This creates a palindrome where the second half mirrors the first half (excluding the middle character).
  - If `y` is greater than or equal to `n` and is prime (checked in the next step), return `y` as the result.

#### Step 3: Prime Checking Function

```cpp
bool isPrime(int num) {
    if (num < 2 || num % 2 == 0) return num == 2;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}
```

- This is a helper function that checks whether a number `num` is prime.
  - If `num` is less than 2 or an even number greater than 2, it returns `false` because even numbers greater than 2 cannot be prime.
  - Then, the function iterates over odd numbers starting from 3 up to the square root of `num`, checking if `num` is divisible by any of them. If it finds a divisor, it returns `false`, indicating that `num` is not prime.
  - If no divisors are found, the function returns `true`, indicating that `num` is prime.

#### Step 4: Return `-1` if No Prime Palindrome is Found

```cpp
return -1;
```

- If the loop completes without finding any prime palindrome greater than or equal to `n`, the function returns `-1`. However, this case is highly unlikely because we expect that there are prime palindromes greater than `n`.

### Complexity

#### Time Complexity:
- **Generating Palindromes**: For each number `x`, we generate a palindrome by concatenating the string `s` and a portion of the string `r`. This takes linear time relative to the number of digits in `x`. Since `x` ranges from `1` to `99999`, the number of digits in `x` is at most 5, which is constant. Thus, generating palindromes is effectively O(1).
- **Prime Checking**: The `isPrime` function checks whether a number `y` is prime. For each number `y`, the prime check function performs up to `O(sqrt(y))` operations. However, the number of prime checks we perform is limited, as the palindrome numbers are generally quite large, so the prime checking function operates efficiently on a smaller set of values.
- **Overall Time Complexity**: The overall time complexity is dominated by the number of palindromes generated and the time it takes to check each for primality. Given the loop runs for at most 100,000 iterations and each prime check takes O(sqrt(y)), the overall complexity is approximately **O(k * sqrt(y))**, where `k` is the number of palindrome numbers checked, and `y` is the value being tested for primality.

#### Space Complexity:
- **Space Complexity**: The space complexity is O(1) because we are only using a small amount of extra space (for variables like `s`, `r`, `y`, etc.) and do not store any additional large data structures.

### Conclusion

The solution is efficient and solves the problem of finding the smallest prime palindrome greater than or equal to a given number `n`. The approach of generating palindromes from numbers and checking them for primality ensures that we efficiently find the answer. The time complexity is dominated by the prime-checking step, but given the constraints, the solution works efficiently for a wide range of inputs. This approach leverages the fact that palindrome numbers have a predictable structure, making the problem solvable in a reasonable amount of time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/prime-palindrome/description/)

---
{{< youtube MZSbndVpxH8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
