#include <iostream>
#include <cmath>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int opt[100'000 + 1];
    {
        int sq[(size_t)(std::sqrt(100'000)) + 1];
        {
            const int sz = (int)(std::sqrt(100'000)) + 1;
            
            for(int i = 0; i <= sz; ++i)
                sq[i] = i * i;
        }
        
        for(int i = 1; i <= n; ++i)
        {
            opt[i] = i;
            
            for(int j = 2; sq[j] <= i; ++j)
                opt[i] = std::min(opt[i], opt[i - sq[j]] + 1);
        }
    }
    
    const int r = opt[n];
    std::printf("%d", r);
    
    return 0;
}
