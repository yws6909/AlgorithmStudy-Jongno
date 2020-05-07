#include <iostream>
#include <algorithm>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int opt[10'000 + 1];
    {
        int set[10'000 + 1];
        {
            for(int i = 1; i <= n; ++i)
                std::scanf("%d", set + i);
        }
        
        opt[0] = 0;
        opt[1] = set[1];
        opt[2] = opt[1] + set[2];
        
        for(int i = 3; i <= n; ++i)
        {
            opt[i] = std::max({
                opt[i - 1],
                opt[i - 2] + set[i],
                opt[i - 3] + set[i - 1] + set[i]
            });
        }
    }
    
    const int r = opt[n];
    std::printf("%d", r);
    
    return 0;
}
