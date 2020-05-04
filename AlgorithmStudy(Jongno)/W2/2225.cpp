#include <iostream>

int main(int argc, const char* argv[])
{
    const int div = 1'000'000'000;
    
    int n, k;
    std::scanf("%d %d", &n, &k);
    
    int opt[200 + 1];
    {
        for(int i = 0; i <= 200; ++i)
            opt[i] = 1;
    }
    
    for(int i = 1; i < k; ++i)
    {
        int accum = 0;
        
        for(int j = 0; j <= n; ++j)
        {
            accum += opt[j];
            
            if(accum >= div)
                accum -= div;
            
            opt[j] = accum;
        }
    }
    
    const int r = opt[n];
    std::printf("%d", r);
    
    return 0;
}
