#include <iostream>
#include <cstdint>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int64_t set0[2];
    int64_t* before = set0;
    {
        before[0] = 0;
        before[1] = 1;
    }
    
    int64_t set1[2];
    int64_t after = set1;
    
    for(int i = 1; i < n; ++i)
    {
        after[0] = before[1] + before[0];
        after[1] = before[0];
        
        std::swap(before, after);
    }
    
    const int64_t r = before[0] + before[1];
    std::printf("%lld", r);
    
    return 0;
}
