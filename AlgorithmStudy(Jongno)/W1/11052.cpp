#include <iostream>
#include <vector>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    std::vector<int> p;
    {
        p.resize(n + 1, 0);
        
        for(int i = 1; i <= n; ++i)
            std::scanf("%d", &p[i]);
    }
    
    std::vector<int> opt;
    {
        opt.resize(n + 1, 0);
        opt[1] = p[1];
    }
    
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
            opt[i] = std::max(opt[i], opt[i - j] + p[j]);
    }
    
    const int r = opt[n];
    std::printf("%d", r);
    
    return 0;
}
