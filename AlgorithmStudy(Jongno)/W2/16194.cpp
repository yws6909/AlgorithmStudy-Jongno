#include <iostream>
#include <vector>
#include <limits>

int main(int argc, const char* argv[])
{
    const int int_max = std::numeric_limits<int>::max();
    
    int n;
    std::scanf("%d", &n);
    
    int opt[1'000 + 1];
    {
        opt[0] = 0;
        
        int p[1'000 + 1];
        {
            for(int i = 1; i <= n; ++i)
                std::scanf("%d", p + i);
        }
        
        for(int i = 1; i <= n; ++i)
        {
            opt[i] = int_max;
            
            for(int j = 1; j <= i; ++j)
                opt[i] = std::min(opt[i], opt[i - j] + p[j]);
        }
    }
    
    const int r = opt[n];
    std::printf("%d", r);
    
    return 0;
}
