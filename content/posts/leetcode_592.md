
+++
authors = ["Yasir"]
title = "Leetcode 592: Fraction Addition and Subtraction"
date = "2023-03-16"
description = "Solution to Leetcode 592"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/fraction-addition-and-subtraction/description/)

---

**Code:**

{{< highlight html >}}
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

