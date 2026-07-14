#include <stack>
#include <string>

template <typename T>
bool uncouple(std::stack<T>& s, const T& target) {
    std::stack<T> tmpStk;
    bool foundTarget = true;
    while (!s.empty() && s.top() != target) {
        tmpStk.push(s.top());
        s.pop();
    }
    if (!s.empty())  s.pop();
    else             foundTarget = false;
    while (!tmpStk.empty()) {
        s.push(tmpStk.top());
        tmpStk.pop();
    }
    return foundTarget;
};

int main()
{
    std::stack<std::string> s;
    // push elements so that top is "E"
    s.push("A");
    s.push("B");
    s.push("C");
    s.push("D");
    s.push("E");

    uncouple(s, std::string("C"));
    return 0;
}