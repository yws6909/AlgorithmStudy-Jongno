#include <iostream>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int set[10'000];
    {
        for(int i = 0; i < n; ++i)
            std::scanf("%d", set + i);
    }
    
    
    
    return 0;
}
