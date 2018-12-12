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

Stack (last in first out)

```c++
#include <stack>

/*
functions:

push, pop, top, size, empty

*/

stack<int> stacky;

stacky.push(69);

```

Queue (first in first out)

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

# Sets

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
