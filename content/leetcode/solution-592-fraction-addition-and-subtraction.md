
+++
authors = ["grid47"]
title = "Leetcode 592: Fraction Addition and Subtraction"
date = "2024-09-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 592: Fraction Addition and Subtraction in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/592.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/592.webp" 
    alt="A series of fractions being added and subtracted, with each operation softly glowing as it is performed."
    caption="Solution to LeetCode 592: Fraction Addition and Subtraction Problem"
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
    string fractionAddition(string expression) {
        istringstream in(expression);
        int A = 0, B = 1, a, b;
        char _;
        while(in >> a >> _ >> b) {
            
            cout << a << '-' << b << '\n';

            A = A * b + a * B;  // numerator in A denomiator in B
            B = B*b; //b*B      // A / B + a/b
                                // 0/1 + a/b
                                // (A*b+a*B)/bB
            // A hold small a, B hold b
            // But cancel their greatest common divisor.
            /*
            a = -1/2
            b =  1/2
            A = 0 * 1/2 + -1/2 * 1 = -1/2
            B = 1/2
            */
            int g = abs(__gcd(A, B));
            cout<< "-0<"<< g<< ">0-"<< '\n';
            A /= g;
            B /= g;
            cout<< "-0{"<< A << "}0-"<< '\n';            
            cout<< "-0{"<< B << "}0-"<< '\n';                        
        }
        return to_string(A) + "/" + to_string(B);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to implement a function that adds a series of fractions represented as a string and returns the sum in its simplest fractional form. The input string will consist of fractions in the format `a/b`, where `a` is the numerator and `b` is the denominator. The goal is to sum all the fractions and return the result in the simplest form, meaning that the greatest common divisor (GCD) of the numerator and denominator should be used to reduce the fraction.

### Approach

To solve this problem, we can break the task down into the following steps:

1. **Input Parsing**: Extract the individual fractions from the input string.
2. **Adding Fractions**: Use a common denominator to sum the fractions. This can be achieved by converting each fraction to have the same denominator and summing the numerators.
3. **Simplification**: Once the fractions are added, simplify the resulting fraction by dividing the numerator and denominator by their greatest common divisor (GCD).
4. **Return the Result**: Convert the simplified result into the format `a/b` and return it.

### Code Breakdown (Step by Step)

#### Step 1: Input Parsing
```cpp
istringstream in(expression);
int A = 0, B = 1, a, b;
char _;
```
- We start by creating an `istringstream` object to read the input `expression`. This allows us to extract each fraction in the format `a/b`.
- We initialize variables `A` and `B`, which will hold the cumulative numerator and denominator respectively. Initially, `A` is set to `0` (since the sum of fractions starts at 0) and `B` is set to `1` (since we are working with fractions).
- We also define `a` and `b` to store the numerator and denominator of each individual fraction, and `_` as a placeholder to capture the `/` character between the numerator and denominator.

#### Step 2: Adding Fractions
```cpp
while(in >> a >> _ >> b) {
    cout << a << '-' << b << '\n';

    A = A * b + a * B;  // Update numerator: A * b + a * B
    B = B * b;          // Update denominator: B * b
}
```
- The loop continues while there are fractions to process. Inside the loop, we extract the numerator (`a`) and denominator (`b`) of each fraction.
- The formula used to add two fractions `A/B` and `a/b` is:
  \[
  \frac{A}{B} + \frac{a}{b} = \frac{A \times b + a \times B}{B \times b}
  \]
  - The numerator is updated by multiplying `A` by `b` and adding `a` multiplied by `B`.
  - The denominator is updated by multiplying `B` by `b`.

#### Step 3: Simplification
```cpp
int g = abs(__gcd(A, B)); // Find GCD of A and B
cout<< "-0<"<< g<< ">0-"<< '\n';
A /= g;  // Simplify numerator
B /= g;  // Simplify denominator
cout<< "-0{"<< A << "}0-"<< '\n';
cout<< "-0{"<< B << "}0-"<< '\n';
```
- After the fractions are added, we need to simplify the result by dividing both the numerator and denominator by their greatest common divisor (GCD).
- The `__gcd()` function is used to find the GCD of `A` and `B`. We then divide both `A` and `B` by this GCD to ensure the fraction is in its simplest form.
- For example, if the resulting fraction is `6/8`, the GCD of `6` and `8` is `2`, so we divide both by `2`, resulting in the fraction `3/4`.

#### Step 4: Return the Result
```cpp
return to_string(A) + "/" + to_string(B);
```
- Finally, we convert the simplified numerator and denominator back into a string in the format `a/b` and return the result.

### Complexity

#### Time Complexity:
- **O(n)**, where `n` is the number of fractions in the input string. 
  - The `while` loop processes each fraction exactly once, and each fraction is processed in constant time. The simplification step, which involves finding the GCD, also takes constant time for each operation since the maximum size of the numbers involved is bounded by the input.
  - Therefore, the overall time complexity is linear in terms of the number of fractions.

#### Space Complexity:
- **O(1)**, aside from the input string. The space complexity is constant because we only use a fixed number of variables (`A`, `B`, `a`, `b`, `g`, etc.), and no additional data structures that grow with the input are used. The space required for storing the result is constant as well.

### Conclusion

This solution efficiently handles the task of adding multiple fractions and reducing the result to its simplest form. It utilizes basic operations such as GCD computation and fractional arithmetic to achieve the desired result. The approach ensures that the solution is both time-efficient and space-efficient, making it suitable for processing a large number of fractions.

In summary:
- The input string is parsed to extract individual fractions.
- Fractions are added by finding a common denominator and updating the numerator accordingly.
- The result is simplified by dividing both the numerator and denominator by their GCD.
- The final simplified fraction is returned as a string in the format `a/b`.

This approach ensures correctness and efficiency, and the solution can handle large inputs with ease.

[`Link to LeetCode Lab`](https://leetcode.com/problems/fraction-addition-and-subtraction/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
