#include <iostream>

int main(int argc, const char* argv[])
{
    const int div = 10'007;
    
    int n;
    std::scanf("%d", &n);
    
    int set[9 + 1];
    {
        for(int i = 0; i <= 9; ++i)
            set[i] = 1;
    }
    
    for(int i = 1; i <= n; ++i)
    {
        int accum = 0;
        
        for(int j = 0; j <= 9; ++j)
        {
            accum += set[j];
            
            if(accum >= div)
                accum -= div;
            
            set[j] = accum;
        }
    }
    
    const int r = set[9];
    std::printf("%d\n", r);
    
    return 0;
}
