# 🔢 Largest Odd Number in String

## 📌 Problem Statement

You are given a string `num` representing a **large integer**.

Return the **largest-valued odd integer (as a string)** that is a **non-empty substring** of `num`.

If no odd number exists, return an empty string `""`.

---

## 📝 Examples

### Example 1

**Input**

```text
num = "52"
```

**Output**

```text
"5"
```

**Explanation**

- `52` is even because it ends with `2`.
- Remove the last digit.
- `5` is odd, so the answer is `"5"`.

---

### Example 2

**Input**

```text
num = "35427"
```

**Output**

```text
"35427"
```

**Explanation**

The last digit is `7`, which is already odd.

So the entire string is the largest odd number.

---

### Example 3

**Input**

```text
num = "4206"
```

**Output**

```text
""
```

**Explanation**

All digits are even.

Hence no odd substring exists.

---

# 💡 Intuition

A number is **odd** if its **last digit** is odd.

Odd digits are:

```text
1 3 5 7 9
```

Instead of checking every possible substring, we simply start from the **last digit** and move left until we find an odd digit.

The moment we find an odd digit, everything before it can remain because that gives us the **largest possible odd number**.

---

# ✅ C++ Solution

```cpp
class Solution {
public:
    string largestOddNumber(string num) {

        int n = num.length();

        for(int i = n - 1; i >= 0; i--) {

            if((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};
```

---

# 🔍 Step-by-Step Explanation

## Step 1: Find the Length of the String

```cpp
int n = num.length();
```

Example

```text
num = "35420"

Length = 5
```

---

## Step 2: Traverse from Right to Left

```cpp
for(int i = n - 1; i >= 0; i--)
```

We start from the last digit because only the **last digit determines whether a number is odd or even**.

### Diagram

```text
3 5 4 2 0
        ↑
Start Here
```

---

## Step 3: Convert Character to Integer

```cpp
num[i] - '0'
```

Characters are stored using ASCII values.

Example

```text
Character

'7'

↓

ASCII = 55

↓

55 - 48

↓

7
```

Now we can perform mathematical operations.

---

## Step 4: Check Whether the Digit is Odd

```cpp
(num[i] - '0') % 2 != 0
```

### Example

```text
Digit = 8

8 % 2 = 0

Even
```

### Example

```text
Digit = 5

5 % 2 = 1

Odd
```

---

## Step 5: Return the Prefix

```cpp
return num.substr(0, i + 1);
```

`substr(start, length)`

Here,

```cpp
substr(0, i + 1)
```

means

- Start from index `0`
- Take `i + 1` characters

---

# 📊 Dry Run

## Input

```text
35420
```

### Initial State

```text
i = 4
```

| Index | Digit | Odd/Even | Action |
|------:|------:|----------|--------|
| 4 | 0 | Even | Move Left |
| 3 | 2 | Even | Move Left |
| 2 | 4 | Even | Move Left |
| 1 | 5 | Odd | Return `"35"` |

### Output

```text
35
```

---

# 🎯 Visual Explanation

## Example 1

### Input

```text
35420
```

```
Index

0 1 2 3 4
3 5 4 2 0
        ↑

0 → Even
```

Move Left

```
0 1 2 3 4
3 5 4 2 0
      ↑

2 → Even
```

Move Left

```
0 1 2 3 4
3 5 4 2 0
    ↑

4 → Even
```

Move Left

```
0 1 2 3 4
3 5 4 2 0
  ↑

5 → Odd ✅
```

Return

```text
35
```

---

## Example 2

### Input

```text
42057
```

```
4 2 0 5 7
        ↑

7 is Odd
```

Since the last digit is already odd,

Return

```text
42057
```

---

## Example 3

### Input

```text
4206
```

```
4 2 0 6
      ↑

6 → Even

↓

4 2 0 6
    ↑

0 → Even

↓

4 2 0 6
  ↑

2 → Even

↓

4 2 0 6
↑

4 → Even
```

No odd digit exists.

Return

```text
""
```

---

# 🧠 Why Do We Start from the End?

Suppose

```text
1234567
```

The last digit is

```text
7
```

Since `7` is odd,

the whole number is already the largest odd number.

If we started from the beginning, we might return

```text
1
```

which is odd but **not the largest**.

Therefore, scanning from **right to left** ensures we keep as many digits as possible.

---

# 🌟 Complete Flow Diagram

```
Input

35420

        │
        ▼

Check Last Digit

0 → Even

        │
        ▼

Move Left

2 → Even

        │
        ▼

Move Left

4 → Even

        │
        ▼

Move Left

5 → Odd ✅

        │
        ▼

Return Prefix

35
```

---

# ⏱ Time Complexity

We scan the string only once.

```text
O(n)
```

---

# 💾 Space Complexity

No extra space is used.

```text
O(1)
```

---

# ✅ Key Points

- A number is odd if its **last digit is odd**.
- Traverse the string from **right to left**.
- The **first odd digit** found from the end gives the answer.
- Use `substr(0, i + 1)` to return the largest odd prefix.
- If no odd digit exists, return an empty string.

---

# 📌 Summary

✔ Traverse from right to left.

✔ Check whether each digit is odd.

✔ Return the substring from index `0` to the first odd digit found.

✔ Time Complexity: **O(n)**

✔ Space Complexity: **O(1)**
