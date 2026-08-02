# 🔄 Rotate String (LeetCode 796)

## 📌 Problem Statement

Given two strings `s` and `goal`, return **true** if and only if `goal` can be obtained by rotating `s`.

A **rotation** means moving the **first character** of the string to the **end**.

---

# 📝 Example 1

### Input

```text
s = "abcde"
goal = "cdeab"
```

### Output

```text
true
```

### Explanation

Rotate `"abcde"` step by step:

```
abcde

↓

bcdea

↓

cdeab
```

We obtained `"cdeab"`, so the answer is **true**.

---

# 📝 Example 2

### Input

```text
s = "abcde"
goal = "abced"
```

### Output

```text
false
```

### Explanation

No matter how many rotations we perform, `"abced"` can never be formed.

---

# 💡 Intuition

A simple way would be to rotate the string one character at a time and compare it with `goal`.

However, this is not efficient.

Instead, we use an important observation:

> **If `goal` is a rotation of `s`, then `goal` must be a substring of `s + s`.**

---

# 🧠 Why Does `s + s` Work?

Suppose

```text
s = "abcde"
```

Concatenate the string with itself.

```
abcde + abcde

↓

abcdeabcde
```

Now observe carefully.

```
abcdeabcde

abcde ✔

bcdea ✔

cdeab ✔

deabc ✔

eabcd ✔
```

Every possible rotation of `"abcde"` appears inside `"abcdeabcde"`.

Therefore, we only need to check whether `goal` exists inside `s + s`.

---

# ✅ C++ Solution

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length())
            return false;

        string doubledS = s + s;

        return doubledS.find(goal) != string::npos;
    }
};
```

---

# 🔍 Step-by-Step Explanation

## Step 1 : Check String Length

```cpp
if(s.length() != goal.length())
    return false;
```

### Why?

If the lengths are different, the strings can never be rotations of each other.

### Example

```
s = "abc"

goal = "abcd"
```

Lengths

```
3

4
```

Different lengths mean the answer is immediately

```
false
```

---

## Step 2 : Concatenate the String

```cpp
string doubledS = s + s;
```

### Example

```
s = "abcde"
```

Create

```
abcde

+

abcde

↓

abcdeabcde
```

This new string contains every possible rotation.

---

## Step 3 : Search for `goal`

```cpp
doubledS.find(goal)
```

The `find()` function searches whether `goal` exists inside `doubledS`.

If found, it returns the starting index.

Otherwise, it returns

```cpp
string::npos
```

which means **Not Found**.

---

## Step 4 : Return the Result

```cpp
return doubledS.find(goal) != string::npos;
```

If `goal` exists inside `doubledS`

```
Return true
```

Otherwise

```
Return false
```

---

# 📊 Dry Run

## Input

```text
s = "abcde"

goal = "cdeab"
```

---

## Step 1

Check lengths

```
Length of s = 5

Length of goal = 5
```

Equal ✔

Continue.

---

## Step 2

Create

```
abcde

+

abcde

↓

abcdeabcde
```

---

## Step 3

Search

```
abcdeabcde

  cdeab
```

Diagram

```
Index

0 1 2 3 4 5 6 7 8 9

a b c d e a b c d e
    | | | | |
    c d e a b
```

Found ✔

Return

```text
true
```

---

# 📊 Dry Run Table

| Step | Operation | Result |
|------|-----------|--------|
| 1 | Check Length | Equal |
| 2 | Create `s + s` | `abcdeabcde` |
| 3 | Search `"cdeab"` | Found |
| 4 | Return | `true` |

---

# 🎯 Example 2

### Input

```text
s = "abcde"

goal = "abced"
```

Create

```
abcdeabcde
```

Search

```
abced
```

Diagram

```
abcdeabcde

abced

❌ Not Found
```

Return

```text
false
```

---

# 🌟 Another Example

### Input

```text
s = "WATER"

goal = "TERWA"
```

Possible rotations

```
WATER

↓

ATERW

↓

TERWA

↓

ERWAT

↓

RWATE
```

Now create

```
WATERWATER
```

```
WATERWATER

WATER ✔

ATERW ✔

TERWA ✔

ERWAT ✔

RWATE ✔
```

Since `"TERWA"` exists inside `"WATERWATER"`,

Return

```
true
```

---

# 🎨 Visual Flow Diagram

```
Input

s

goal

      │
      ▼

Are lengths equal?

 ├── No
 │
 ▼
Return false

 └── Yes
      │
      ▼

Create

s + s

      │
      ▼

Search goal inside s+s

      │
      ▼

Found?

├── Yes
│
▼
Return true

└── No
    │
    ▼
Return false
```

---

# 🔍 Understanding `find()`

Example

```cpp
string s = "hello";
```

Search

```cpp
s.find("ll");
```

Output

```
2
```

because `"ll"` starts at index `2`.

Search

```cpp
s.find("xyz");
```

Output

```cpp
string::npos
```

Meaning

```
Not Found
```

Therefore,

```cpp
doubledS.find(goal) != string::npos
```

means

- Found → `true`
- Not Found → `false`

---

# ⚖️ Brute Force vs Optimized

## Brute Force

Rotate one character at a time.

```
abcde

↓

bcdea

↓

cdeab

↓

deabc

↓

eabcd
```

Compare after every rotation.

### Time Complexity

```
O(n²)
```

---

## Optimized Approach

Create

```
s + s
```

Search once using `find()`.

### Time Complexity

```
O(n)
```

---

# ⏱ Time Complexity

- Concatenation → **O(n)**
- Searching using `find()` → **O(n)**

### Overall

```
O(n)
```

---

# 💾 Space Complexity

We create one additional string of length `2n`.

```
O(n)
```

---

# ✅ Key Points

- Rotation means moving the first character to the end.
- Rotated strings always appear inside `s + s`.
- First check whether both strings have the same length.
- Create `s + s`.
- Search `goal` inside the new string using `find()`.
- If found, return `true`; otherwise, return `false`.

---

# 📌 Summary

✔ Check if the lengths are equal.

✔ Concatenate the string with itself.

✔ Search `goal` inside `s + s`.

✔ If found → return `true`.

✔ Otherwise → return `false`.

### Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`
