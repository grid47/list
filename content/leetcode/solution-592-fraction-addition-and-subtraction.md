
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
comments = true
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
Given a string expression representing a mathematical expression with fractions involving addition and subtraction, compute the result of the expression. The result should be simplified and returned in the form of a fraction. If the result is an integer, represent it as a fraction with denominator 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string expression that contains fractions in the form ±numerator/denominator, with '+' and '-' operators separating the fractions. Each fraction is an irreducible fraction. The input only contains valid fractions, where the numerator and denominator are between 1 and 10, and the denominator is not zero.
- **Example:** `Input: expression = '1/3-1/2'`
- **Constraints:**
	- The input contains only valid fractions with numerators and denominators in the range [1, 10].
	- The input contains only the characters '0'-'9', '/', '+', and '-'.
	- There are no more than 10 fractions in the expression.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the result as a string in the form of a simplified fraction 'numerator/denominator'. If the result is an integer, return it as 'numerator/1'.
- **Example:** `Output: '1/3'`
- **Constraints:**
	- The output should always be in the form 'numerator/denominator'. If the result is an integer, represent it as 'numerator/1'.

{{< dots >}}
### Core Logic 🔍
**Goal:** Compute the sum or difference of the fractions in the expression and return the result as a simplified fraction.

- Parse the expression to extract fractions and operators.
- Convert each fraction into its numerator and denominator.
- Perform the addition and subtraction of fractions according to the expression.
- Simplify the result by dividing the numerator and denominator by their greatest common divisor (GCD).
{{< dots >}}
### Problem Assumptions ✅
- The input expression will always be valid and contain only fractions and arithmetic operators ('+', '-') with no spaces.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: expression = '-1/2+1/2'`  \
  **Explanation:** The expression adds -1/2 and 1/2, resulting in 0. Since 0 is an integer, it is represented as '0/1'.

- **Input:** `Input: expression = '1/3-1/2'`  \
  **Explanation:** The expression subtracts 1/2 from 1/3, resulting in -1/6. The result is already in irreducible form.

{{< dots >}}
## Approach 🚀
The problem can be solved by parsing the input expression, performing the necessary operations (addition or subtraction) on the fractions, and simplifying the result using the greatest common divisor (GCD).

### Initial Thoughts 💭
- Each fraction needs to be represented with a numerator and denominator.
- We need to ensure proper handling of both addition and subtraction of fractions.
- The result must be simplified by reducing the numerator and denominator by their GCD.
- We can iterate over the expression to parse each fraction and operator, update the result fraction step by step, and simplify the result at the end.
{{< dots >}}
### Edge Cases 🌐
- The input expression will always contain at least one fraction, so empty input is not a concern.
- The number of fractions is capped at 10, so the solution will handle all inputs efficiently.
- If the result is an integer, it should be represented as 'numerator/1'.
- The final result should fit within the bounds of a 32-bit integer.
{{< dots >}}
## Code 💻
```cpp
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
```

This function performs addition of fractions provided in string format. It calculates the sum of the fractions step by step, simplifying the result at the end using the greatest common divisor (GCD).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string fractionAddition(string expression) {
	```
	Declares the `fractionAddition` function which takes a string expression containing fractions and computes their sum.

2. **String Parsing**
	```cpp
	    istringstream in(expression);
	```
	Initializes an input string stream to parse the fractions in the given string expression.

3. **Variable Initialization**
	```cpp
	    int A = 0, B = 1, a, b;
	```
	Declares and initializes integer variables `A` and `B` to hold the numerator and denominator of the result, and `a` and `b` for temporary storage during parsing.

4. **Variable Declaration**
	```cpp
	    char _;
	```
	Declares a character variable `_` used to store the '/' separator while parsing fractions.

5. **While Loop**
	```cpp
	    while(in >> a >> _ >> b) {
	```
	Iterates through each fraction in the expression, extracting the numerator `a`, the separator `_`, and the denominator `b`.

6. **Empty Step**
	```cpp
	        
	```
	Empty line for readability.

7. **Output Debugging**
	```cpp
	        cout << a << '-' << b << '\n';
	```
	Outputs the current fraction being processed for debugging purposes.

8. **Numerator and Denominator Calculation**
	```cpp
	        A = A * b + a * B;  // numerator in A denomiator in B
	```
	Updates the numerator `A` using the formula (A * b + a * B), where `a/b` is the current fraction to be added.

9. **Denominator Calculation**
	```cpp
	        B = B*b; //b*B      // A / B + a/b
	```
	Updates the denominator `B` by multiplying it with `b`, the denominator of the current fraction.

10. **Addition Explanation**
	```cpp
	                            // 0/1 + a/b
	```
	Explanation of the fraction addition process, where `0/1` is the initial fraction and `a/b` is the current fraction being processed.

11. **Result Formula**
	```cpp
	                            // (A*b+a*B)/bB
	```
	This formula represents the result of adding two fractions A/B and a/b: the numerator is (A*b + a*B), and the denominator is B*b.

12. **Comment**
	```cpp
	        // A hold small a, B hold b
	```
	Comment explaining that `A` holds the numerator and `B` holds the denominator of the result after addition.

13. **GCD Simplification**
	```cpp
	        // But cancel their greatest common divisor.
	```
	The result is simplified by dividing both `A` and `B` by their greatest common divisor (GCD).

14. **Code Comment Block Start**
	```cpp
	        /*
	```
	A commented-out block explaining the example computation for adding two fractions.

15. **Example Code**
	```cpp
	        a = -1/2
	```
	An example showing fraction `a/b` where a = -1 and b = 2.

16. **Example Code**
	```cpp
	        b =  1/2
	```
	An example showing fraction `b/b` where b = 1 and b = 2.

17. **Example Code**
	```cpp
	        A = 0 * 1/2 + -1/2 * 1 = -1/2
	```
	An example calculation where the numerator `A` is updated during fraction addition.

18. **Example Code**
	```cpp
	        B = 1/2
	```
	The denominator `B` is updated during the fraction addition process.

19. **Code Comment Block End**
	```cpp
	        */
	```
	End of the commented-out block explaining the example computation.

20. **GCD Calculation**
	```cpp
	        int g = abs(__gcd(A, B));
	```
	Computes the absolute value of the greatest common divisor (GCD) of `A` and `B` to simplify the result.

21. **Output Debugging**
	```cpp
	        cout<< "-0<"<< g<< ">0-"<< '\n';
	```
	Outputs the GCD for debugging purposes.

22. **Simplification Step**
	```cpp
	        A /= g;
	```
	Divides `A` by the GCD to simplify the fraction.

23. **Simplification Step**
	```cpp
	        B /= g;
	```
	Divides `B` by the GCD to simplify the fraction.

24. **Output Debugging**
	```cpp
	        cout<< "-0{"<< A << "}0-"<< '\n';            
	```
	Outputs the simplified numerator for debugging purposes.

25. **Output Debugging**
	```cpp
	        cout<< "-0{"<< B << "}0-"<< '\n';                        
	```
	Outputs the simplified denominator for debugging purposes.

26. **End Loop**
	```cpp
	    }
	```
	Marks the end of the loop that processes each fraction in the input expression.

27. **Return Result**
	```cpp
	    return to_string(A) + "/" + to_string(B);
	```
	Returns the final result of the fraction addition as a string in the form of 'numerator/denominator'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of fractions in the expression.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we are only maintaining a few variables to store the current result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/fraction-addition-and-subtraction/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
