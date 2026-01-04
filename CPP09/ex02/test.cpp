#include <iostream>
#include <vector>


static size_t jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t a = 0, b = 1;
    for (size_t i = 2; i <= n; ++i)
    {
        size_t c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}


static std::vector<size_t> buildInsertionOrder(size_t pendSize)
{
    std::vector<size_t> order;
    if (pendSize == 0)
        return order;

    order.push_back(0);
    for (size_t k = 2; order.size() < pendSize; ++k)
    {
        size_t jk = jacobsthal(k);
        size_t jprev = jacobsthal(k - 1);
        size_t limit = jk > pendSize ? pendSize : jk;
        for (size_t idx = limit; idx > jprev && order.size() < pendSize; --idx)
            order.push_back(idx - 1);
    }
    return order;
}



int main()
{
    std::vector<size_t> order = buildInsertionOrder(6);
    std::cout << "Jacobsthal Insertion Order for pend size 10:\n";
    for (size_t idx : order)
    {
        std::cout << idx << " ";
    }
    std::cout << "\n";
    return 0;
}