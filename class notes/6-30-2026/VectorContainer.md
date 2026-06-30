# The Vector Container

STL -> #include \<vector> API

vector -> stack -> queue -> priority queue -> list

## C++ Arrays

An array is a containter that stores the n (size) elements in a contiguous block of memory.

```
int arr[5] = {5, 6, 1, 2, 3};

arr[0] // address array member
```
What happened here?
1. space allocated for 5 integers
2. arr refers to the memory address of the start of the array

The size of an array cannot be changed during the runtime

## Vectors

Provide a lot of complex functions with a simple interface

Key feature: the size of the vector can change dynamically

very similar to an array

* [] operator
* 0 indexed

## Template-based vector class

Declare a vector object

Initialize by size:
```
vector<int> intVector(5);
vector<string> strVector(10);
```

Initialize by size + initial value:
```
vector<char> line(80, 'a');
vector<time24> openTime(7, time24(9,0));
```

No parameters
```
vector<int> intVector;
```