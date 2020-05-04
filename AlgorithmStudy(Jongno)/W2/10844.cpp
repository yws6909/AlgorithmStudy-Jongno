#include <iostream>

int main(int argc, const char* argv[])
{
    const int div = 1'000'000'000;
    
    int n;
    std::scanf("%d", &n);
    
    int set0[9 + 1];
    {
        set0[0] = 0;
        
        for(int i = 1; i <= 9; ++i)
            set0[i] = 1;
    }
    int* before = set0;
    
    int set1[9 + 1];
    int* after = set1;
    
    for(int i = 1; i < n; ++i)
    {
        after[0] = before[1];
        
        for(int j = 1; j <= 8; ++j)
        {
            after[j] = before[j + 1] + before[j - 1];
            
            if(after[j] >= div)
                after[j] -= div;
        }
        
        after[9] = before[8];
        
        std::swap(before, after);
    }
    
    int r;
    {
        r = 0;
        
        for(int i = 0; i <= 9; ++i)
        {
            r += before[i];
            
            if(r >= div)
                r -= div;
        }
    }
    std::printf("%d", r);
    
    return 0;
}
