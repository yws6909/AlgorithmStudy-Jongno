#include <iostream>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int opt[500 + 1];
    {
        std::scanf("%d", opt + 1);
        
        int input[500 + 1];
        
        for (int i = 2; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
                std::scanf("%d", input + j);
            
            opt[i] = opt[i - 1] + input[i];
            
            for(int j = i - 1; j > 1; --j)
                opt[j] = std::max(opt[j], opt[j - 1]) + input[j];
            
            opt[1] = opt[1] + input[1];
        }
    }
    
    int r;
    {
        r = 0;
        
        for(int i = 1; i <= n; ++i)
            r = std::max(r, opt[i]);
    }
    std::printf("%d", r);
        
    
    return 0;
}
