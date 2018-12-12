# Notes

## ASCII

ASCII indexing

```c++

vector<bool> alphabet(26, false);

alphabet['c' - 'a'] = true;

// third letter of alphabet, c, alphabet[2] == true

```

ASCII conversion

```c++

int number = 65;

cout << char(num); // A

int letter = char(num);

cout << int(letter); // 65

```

## Matrix

Initialize

```c++

vector <vector <int> > matrix;

vector <vector <int> > matrix(rows, vector<int> (columns)); // with size

vector <vector <int> > matrix(rows, vector<int> (columns, 0)); // with values 0

```

Rotate square matrix 90 deg clockwise

```c++
for(int r = 0; r < size; r++) {

    for(int c = 0; c < size; c++) {

        newMatrix[c][size - r - 1] = oldMatrix[r][c];

    }

}
```

## Stacks and Queues

### Stack (last in first out)

```c++
#include <stack>

/*
functions:

push, pop, top, size, empty

*/

stack<int> stacky;

stacky.push(69);

```

### Queue (first in first out)

```c++
#include <queue>

/*
functions:

push, pop, front, size, empty, emplace

*/

queue<int> q;

q.push(69);

```

## Bitsets

```c++

#include <bitset>;

bitset<8> num; // 8 bits initialized to 0

num.set();

cout << num; // 11111111

num.flip(3); // 11110111

num.set(2); // 11110111

num.set(3); // 11111111

num.set(3,0); // 11110111

num.reset(); // 00000000

bitset<8> num(string("10110100"));

bitset<32> num(0x7fffffff); // value of max int;

cout << num; // 01111111111111111111111111111111

cout << num.to_ulong(); // 2147483647

num.flip();

cout << num; // 10000000000000000000000000000000

cout << num.to_ulong(); // 2147483648

cout << num.to_string; // 10000000000000000000000000000000

```

## Sets

insertion O(log n) without hint

```c++

#include <set>

set<int> setty;

setty.insert(3); // 3

setty.insert(7); // 3 7

setty.insert(3); // 3 7

for (auto& s: setty) {
  cout << s << " ";
}

```

## Sieve of Eratosthenes

```c++

int sieve_size;

bitset<1000000> sieve;

vector<int> primes;

void buildSieve(int upperbound) {

    sieve_size = upperbound + 1;

    int root = sqrt(sieve_size);

    sieve.set();

    for (int i = 2; i <= root; i++) {

        if (sieve[i]) {

            for (int j = i * i; j <= sieve_size; j += i) {

                sieve[j] = 0;

            }

            primes.push_back((int)i);

        }

    }

}

```

## Horner's Rule

Evaluate polynomials

```c++
// example, construct int from string by reading one value at a time

string numberString = "2334476453";

long number = 0;

for(auto& digit: numberString) {

  number = number * 10 + (digit - '0');

}
```

## Geometry

### Radius of inscribed circle

a triangle has sides a, b, and c, and s is the semiperimeter

s = (a + b + c) / 2

r<sup>2</sup> = (s - a) * (s - b) * (s - c) / s

### Radius of circumbscribed circle

a triangle has sides a, b, and c

r = abc/(4A)

### Heron's Rule (area of a triangle)

a triangle has sides a, b, and c

s = (a + b + c) / 2

A<sup>2</sup> = s * (s - a) * (s - b) * (s - c)

### Area of a triangle with medians

a triangle has medians u, v, w

A = 4/3 * (s * (s - u) * (s - v) * (s - w))<sup>1/2</sup>

## Dynamic Programming

### 1d range sum

```c++
vector<int> list = {2, -4, -1, 5, 2, -1, 3, -4, 8};

int current, ans;

current = ans = 0;

for(auto& l: list) {

  current += l;

  ans = max(current, ans);

  current = current > 0 ? current : 0;

}

cout << ans;

return 0;
```

### Longest Common Subsequence

todo

### Shortest Path

todo

### Flood Fill

todo
