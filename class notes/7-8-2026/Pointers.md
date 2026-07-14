# Pointers

Ford & Topp Ch. 5

## Data Addresses in Memory

integer 50 stored at memory position 5000

etc.

## Assigning Values to Pointers

A pointer is a special variable that stores the address of memory

```
&x
```
Is the address of the integer in memory
```
int x = 50;
```

Set `p1` to point at an actual data item.
```
int *p1;
p1 = &x;
cin >> *p1;
y = 2 + *p1;
*p1 = *p1 + 1;
cout << *p1;
```

`*p1` and `x` refer to the same memory location. 
* `*` the dereference operator
* `&` the "address of" operator

Another Example

```
int *p1, *p2;
int x, y;
x = y = 5;
p1 = &x;
p2 = &y;

cin >> *p1; // 15
cin >> *p2; // 10
*p1 = *p1 + *p2; // 15 + 10 -> p1
cout << x; // 25
cout << y; // 10

float *p3;
string *p4;
time24 *p5;
```

```
int *p1;
int x;
p1 = &x

p1 = 76; // should be *p1 = 76; compiler will give invalid conversion from int to int pointer

cout << p1;
cout << *p1;
```

the `*` and `&` operators are inverse of each other

```
&(*p1) -> &x
*(&x) -> *p1 -> x
```

Pass by value
```
void clear(int x)
{
    x = 0;
}
int main()
{
    int n = 10;
    clear(n);
    cout << n; // 10
    return 0;
}
```

Pass by reference
```
void clear (int &x)
...
```

Pass by pointer
```
void clear(int *p1)
{
    *p1 = 0;
}
int main()
{
    int n = 10;
    clear(&n);
    cout << n; // 0
    return 0;
}
```
Both pass by pointer and pass by reference can be used to change the variable outside the function.

What is wrong with this?
```
int x;   // Fix
int *p1; // error: p1 is not initialized. Points to nothing
p1 = &x; // Fix: now p1 has something to point to
*p1 = 9;
cout << "The value at address:" << p1 << "is" << *p1;

int y = 5;
cout << "y's value is" << y;
int *yptr = &y;
yptr = 9; // invalid conversion from int to int*
*yptr = 9; // fix
cout << "y's value is now" << *yptr;
```