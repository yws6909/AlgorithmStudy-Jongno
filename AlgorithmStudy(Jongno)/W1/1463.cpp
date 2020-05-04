#include <iostream>
#include <vector>

int main(int argc, const char * argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int set[1'000'000 + 1];
    {
        set[0] = 0;
        set[1] = 0;
    }
    
    for(int i = 2; i <= n; ++i)
    {
        set[i] = set[i - 1] + 1;
        
        if(i % 3 == 0)
            set[i] =  std::min(set[i], set[i / 3] + 1);
        
        if(i % 2 == 0)
            set[i] =  std::min(set[i], set[i / 2] + 1);
    }
    
    const int r = set[n];
    std::printf("%d", r);
    
    return 0;
}
