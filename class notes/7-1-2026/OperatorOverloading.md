# Operator Overloading

Ch 2.4 Ford & Topp

reference codes 
* d_time24.h
* prg2_3.cpp

## Function Overloading

Define more than one function
* same name
* same scope
* different input parameters

example:
```
class Rectangle
{
    public:
        void setSize(int, int);
        void setSize(int);
        void setSize();
        void setSize(float, float);
        void setSize(int, float);
        void setSize(float, int);
        void setSize(float);

    private:
        int width, height;
}
```
## Function Signature
The compiler identifies different versions of the function by its unique signature.
1. function name
2. parameter types in order

e.g. setSize-int-int, setSize-int, setSize-int-float, etc.

Overloaded functions can have a different return type

## Using Overloaded Functions

```
int main()
{
    Rectangle myRectangle1;
    Rectangle myRectangle2;
    ...

    myRectangle1.setSize();
    myRectangle2.setSize(3.7, 4);
    ...
}
```

## Operator Overloading

Same idea as function overloading, but applied to operators like +, -, =, *, ==, <<, >>.

```
int x, y, z; string str1, str2, str3;
y = x + z; cout << x;
str1 = str2 + str3; cout << str3;
```
The same operator is doing different things to different types -> **operator overloading**

## Code Clarity

```
time24 class1, class2, freeTime;
class1.readTime();
class2.readTime();

class1.addTime(50);

freeTime = class1.duration(class2);
freeTime.writeTime();
```

```
time24 class1, class2, freeTime;
cin >> class1 >> class2;
class1 = class1 + 50;

freetime = class1 - class2;
cout << freeTime();
```

Bottom one is more familiar

Expressions for binary operators like +, -, *, <: lhs op rhs operands

> Note: =, & are automatically implemented for all classes

Implement our own version of op

```
returnType operator op (type1 lhs, type2 rhs);
```

example:

```
bool operator == (const time24 &lhs, const time24 &rhs)
{
    return ((lhs.getHour() == rhs.getHour()) && (lhs.getMinute() == rhs.getMinute()));
} 
// this function is outside the class and therefore cannot access the private members

bool operator != (const time24 &lhs ...)
{
    return !(lhs == rhs);
}

time24 timeA, timeB;

if(timeA == timeB)
{
    ...
}
```

```
timeA + timeB;
timeA + 10;
10 + timeA;
```
need 3 functions for this

1. free functions
2. friend function
3. class member function

```
time24 operator + (const time24& lhs, const time24& rhs)
{
    return time24(lhs.getHour() + rhs.getHour(),lhs.getMinute() + rhs.getMinute());
}

time24 operator + (const time24& lhs, int min)
{
    return time24(lhs.getHour(), lhs.getMinute() + min);
}

time24 operator + (int min, const time24& rhs)
{
    return time24(rhs.getHour(), rhs.getMinute() + min);
}
```