#include <iostream>
#include <vector>

template <typename T>

void join(std::vector<T> &vA, const std::vector<T> &vB)
{
    size_t sizeA = vA.size();
    size_t sizeB = vB.size();
    vA.resize(sizeA + sizeB);
    for(size_t a = 0; a < sizeB; a++)
    {
        vA.at(sizeA + a) = vB.at(a);
    }
}


int main()
{
    std::vector<int> vA = {1, 2, 3, 4};
    std::vector<int> vB = {5, 6, 7};

    join(vA, vB);
    for (int val : vA) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}