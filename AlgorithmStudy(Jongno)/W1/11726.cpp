#include <iostream>
#include <vector>
           
int main(int argc, const char* argv[])
{
    const int div = 10'007;
    
    int n;
    std::scanf("%d", &n);
    
    std::vector<int> set;
    {
        set.resize(n + 1, 0);
        set[1] = 1;
        set[2] = 2;
    }
    
    for(int i = 3; i <= n; ++i)
    {
        set[i] = set[i - 1] + set[i - 2];
        
        if(set[i] >= div)
            set[i] -= div;
    }
    
    const int r = set[n];
    std::printf("%d", r);
    
    return 0;
}
