#include <iostream>
#include <vector>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int opt[1'000 + 1];
    {
        int p[1'000 + 1];
        {
            for(int i = 1; i <= n; ++i)
                std::scanf("%d", p + i);
        }
        
        opt[1] = p[1];
        
        for(int i = 2; i <= n; ++i)
        {
            opt[i] = 0;
            
            for(int j = 1; j <= i; ++j)
                opt[i] = std::max(opt[i], opt[i - j] + p[j]);
        }
    }
    
    const int r = opt[n];
    std::printf("%d", r);
    
    return 0;
}
