#include <iostream>
#include <vector>

int main(int argc, const char* argv[])
{
    int t;
    std::scanf("%d", &t);
    
    int set[11 + 1];
    {
        set[1] = 1;
        set[2] = 2;
        set[3] = 4;
        
        for(int i = 4; i <= 11; ++i)
            set[i] = set[i - 1] + set[i - 2] + set[i - 3];
    }
    
    for(int i = 0; i < t; ++i)
    {
        int n;
        std::scanf("%d", &n);
        
        const int r = set[n];
        std::printf("%d\n", r);
    }
    
    return 0;
}
