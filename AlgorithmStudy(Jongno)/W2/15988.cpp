#include <iostream>

int main(int argc, const char* argv[])
{
    const int div = 1'000'000'009;
    
    int t;
    std::scanf("%d", &t);
    
    int set[1'000'000 + 1];
    {
        set[0] = 1;
        set[1] = 1;
        set[2] = 2;
        
        for(int i = 3; i <= 1'000'000; ++i)
        {
            set[i] = set[i - 1] + set[i - 2];
            
            if(set[i] >= div)
                set[i] -= div;
            
            set[i] += set[i - 3];
            
            if(set[i] >= div)
                set[i] -= div;
        }
    }
    
    for(int i = 0; i < t; ++i)
    {
        int n;
        std::scanf("%d", &n);
        
        const int r = set[n];
        std::printf("%d\n", set[n]);
    }
    
    return 0;
}
