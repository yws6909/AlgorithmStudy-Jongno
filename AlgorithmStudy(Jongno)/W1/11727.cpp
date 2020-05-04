#include <iostream>
#include <vector>
           
int main(int argc, const char* argv[])
{
    const int div = 10'007;
    
    int n;
    std::scanf("%d", &n);
    
    int set[1'000 + 1];
    {
        set[1] = 1;
        set[2] = 3;
    }
    
    for(int i = 3; i <= n; ++i)
    {
        set[i] = set[i - 1] + set[i - 2] * 2;
        
        if(set[i] >= div)
            set[i] %= div;
    }
    
    const int r = set[n];
    std::printf("%d", r);
    
    return 0;
}
