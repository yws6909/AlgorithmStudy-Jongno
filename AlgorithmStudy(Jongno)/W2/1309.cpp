#include <iostream>

int main(int argc, const char* argv[])
{
    const int div = 9'901;
    
    int n;
    std::scanf("%d", &n);
    
    int set0[3];
    int* before = set0;
    {
        before[0] = before[1] = before[2] = 1;
    }
    
    int set1[3];
    int* after = set1;
    
    for(int i = 1; i < n; ++i)
    {
        after[0] = (before[0] + before[1] + before[2]) % div;
        
        after[1] = (before[0] + before[2]);
        
        if(after[1] >= div)
            after[1] -= div;
        
        after[2] = (before[0] + before[1]) % div;
        
        if(after[2] >= div)
            after[2] -= div;
        
        std::swap(before, after);
    }
    
    const int r = (before[0] + before[1] + before[2]) % div;
    printf("%d", r);
    
    return 0;
}
