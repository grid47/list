
+++
authors = ["grid47"]
title = "Leetcode 2523: Closest Prime Numbers in Range"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2523: Closest Prime Numbers in Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HqSBI1RVM8c"
youtube_upload_date="2023-01-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HqSBI1RVM8c/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool seive[1000001] = {};
    vector<int> p = {2};
    vector<int> closestPrimes(int left, int right) {
        
        for(int i = 3; i < 1000001; i += 2) {
            if(!seive[i]) {
                p.push_back(i);
                for (long long j = (long long) i * i; j < 1000001; j += i) {
                    seive[j] = true;
                }
            }
        }
        
        int n1 = -1, n2 = -1, i = lower_bound(p.begin(), p.end(), left) - p.begin();
        
        for(; i + 1 < p.size() && p[i + 1] <= right; i++) {
            if(n1 == -1 || n2 - n1 > p[i + 1] - p[i]) {
                n1 = p[i];
                n2 = p[i + 1];
                if(n2 - n1 < 3) break;
            }
        }
        return {n1, n2};
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the closest pair of prime numbers in a given range `[left, right]` where the difference between the primes is at least 2 but as small as possible. If no such pair exists, the function should return `[-1, -1]`. The given range is inclusive of both `left` and `right`.

### Approach

To solve this problem, the algorithm can be divided into the following steps:

1. **Sieve of Eratosthenes**:
   We will first use the **Sieve of Eratosthenes** to generate all prime numbers up to `1,000,000`. This sieve will help us identify all the primes efficiently.

2. **Prime Number Collection**:
   After marking all the primes using the sieve, we store the prime numbers in a vector for quick access.

3. **Finding the Closest Primes**:
   The algorithm then proceeds to find the closest primes in the given range `[left, right]`. We do this by:
   - Searching for the smallest prime number that is greater than or equal to `left`.
   - Then, checking the next prime to see if it is less than or equal to `right`.
   - Keeping track of the smallest difference between consecutive primes in the range.

4. **Edge Case Handling**:
   If there are no two primes found within the given range that satisfy the condition (i.e., the difference is at least 2), we return `[-1, -1]`.

### Code Breakdown (Step by Step)

#### Class Definition and Member Variables:

```cpp
class Solution {
public:
    bool seive[1000001] = {};
    vector<int> p = {2};
```

- The `seive` array is used to mark non-prime numbers. It is initialized with `false` to represent all numbers as prime initially.
- The `p` vector stores the prime numbers. The prime `2` is added initially because `2` is the smallest prime number.

#### Sieve of Eratosthenes:

```cpp
    for(int i = 3; i < 1000001; i += 2) {
        if(!seive[i]) {
            p.push_back(i);
            for (long long j = (long long) i * i; j < 1000001; j += i) {
                seive[j] = true;
            }
        }
    }
```

- The loop iterates through all numbers starting from `3` up to `1,000,000`. It only checks odd numbers (`i += 2`), since even numbers greater than `2` are not prime.
- For each number `i` that is still marked as prime (i.e., `seive[i] == false`), it adds `i` to the list of primes `p`.
- The inner loop marks all multiples of `i` as non-prime (i.e., it marks all `j = i * i, i * i + i, ...` as `true` in the `seive` array).

#### Finding the Closest Primes:

```cpp
    int n1 = -1, n2 = -1, i = lower_bound(p.begin(), p.end(), left) - p.begin();
```

- `n1` and `n2` are initialized to `-1`, representing the closest primes found so far.
- The variable `i` is initialized to the index of the first prime number in the `p` vector that is greater than or equal to `left`. This is done using the `lower_bound` function, which efficiently finds the index of the first element that is not less than `left`.

```cpp
    for(; i + 1 < p.size() && p[i + 1] <= right; i++) {
        if(n1 == -1 || n2 - n1 > p[i + 1] - p[i]) {
            n1 = p[i];
            n2 = p[i + 1];
            if(n2 - n1 < 3) break;
        }
    }
```

- The loop iterates through the prime numbers in the `p` vector starting from index `i` and checks for consecutive primes `p[i]` and `p[i + 1]`.
- If the difference between the two primes is smaller than the previous closest pair, it updates `n1` and `n2` to store the current closest primes.
- If the difference between the primes is less than `3`, the loop breaks, as we are only interested in pairs of primes with a difference of at least 2.

#### Return the Result:

```cpp
    return {n1, n2};
}
```

- After the loop, the closest pair of primes `n1` and `n2` is returned. If no such pair was found, `n1` and `n2` will remain `-1`, and the function will return `[-1, -1]`.

### Time Complexity:

1. **Sieve of Eratosthenes**:
   - The sieve runs in \( O(n \log(\log(n))) \) time, where `n = 1,000,000`. This is because the sieve algorithm involves iterating over all numbers up to `n`, and for each prime `i`, it marks all of its multiples as non-prime.
   - The sieve is efficient and works in nearly linear time with respect to the size of the range, making it feasible for `n = 1,000,000`.

2. **Prime Search Using Binary Search**:
   - After generating the list of primes, we use `lower_bound` to find the first prime greater than or equal to `left`. The `lower_bound` operation runs in \( O(\log(p)) \), where `p` is the number of primes found up to `1,000,000`. Since there are approximately `78,498` primes up to `1,000,000`, this operation runs in logarithmic time with respect to the number of primes.
   - The subsequent loop also runs in \( O(p) \), where `p` is the number of primes in the range `[left, right]`. This loop checks each pair of consecutive primes in the range, making it linear in terms of the number of primes between `left` and `right`.

3. **Overall Time Complexity**:
   - The total time complexity is dominated by the sieve, which is \( O(n \log(\log(n))) \), and the prime search using binary search, which is \( O(p) \), where `n = 1,000,000` and `p` is the number of primes between `left` and `right`. Thus, the overall complexity is \( O(n \log(\log(n))) \), which is efficient for the input limits.

### Space Complexity:

- The space complexity is primarily determined by the space used to store the sieve array and the list of primes.
- The sieve array takes \( O(n) \) space, where `n = 1,000,000`.
- The list of primes `p` takes \( O(p) \) space, where `p` is the number of primes up to `1,000,000`. This is approximately `78,498`.
- Therefore, the total space complexity is \( O(n) \), which is \( O(1,000,000) \).

### Conclusion

This solution efficiently solves the problem of finding the closest pair of primes in a given range `[left, right]` using the **Sieve of Eratosthenes** to precompute the primes up to `1,000,000`. The solution uses a combination of binary search (`lower_bound`) and linear iteration through primes to find the closest pair of primes within the range. The approach is optimal with respect to both time and space complexity, handling the constraints effectively.

[`Link to LeetCode Lab`](https://leetcode.com/problems/closest-prime-numbers-in-range/description/)

---
{{< youtube HqSBI1RVM8c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
