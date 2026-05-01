#include <map>
#include <array>
#include <algorithm>
#include <iostream>

const double base = 8.0;

struct book_state
{
    std::array<int, 5> nums{0};

    bool operator<(const book_state &others) const
    {
        return this->nums < others.nums;
    }
};

book_state buy(const book_state &input, size_t num)
{
    book_state result = input;
    for (size_t i = 0; i < num; ++i)
    {
        result.nums[i] -= 1;
    }
    std::sort(result.nums.begin(), result.nums.end(), std::greater<int>());
    return result;
}

std::map<book_state, double> memory;

double dp(const book_state &state)
{
    if (state.nums[0] <= 0)
    {
        return 0.0;
    }
    auto itr = memory.find(state);
    if (itr != memory.end())
    {
        return itr->second;
    }
    double best = 1e9;
    if (state.nums[4] > 0)
    {
        book_state next = buy(state, 5);
        best = std::min(best, 5 * base * 0.75 + dp(next));
    }
    if (state.nums[3] > 0)
    {
        book_state next = buy(state, 4);
        best = std::min(best, 4 * base * 0.8 + dp(next));
    }
    if (state.nums[2] > 0)
    {
        book_state next = buy(state, 3);
        best = std::min(best, 3 * base * 0.9 + dp(next));
    }
    if (state.nums[1] > 0)
    {
        book_state next = buy(state, 2);
        best = std::min(best, 2 * base * 0.95 + dp(next));
    }

    {
        book_state next = buy(state, 1);
        best = std::min(best, base + dp(next));
    }
    memory[state] = best;
    return best;
}

double min_price(book_state &state)
{
    std::sort(state.nums.begin(), state.nums.end(), std::greater<int>());
    memory.clear();
    return dp(state);
}

int main()
{
    book_state state;
    state.nums = {2, 2, 2, 1, 1};
    std::cout << min_price(state) << std::endl;
    return 0;
}