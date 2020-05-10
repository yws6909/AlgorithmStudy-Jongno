#include <iostream>

int n, m;
int set[9];

void print(int depth)
{
    if(depth > m)
    {
        for(int i = 1; i <= m; ++i)
            std::printf("%d ", set[i]);
        
        std::printf("\n");
        
        return;
    }
    
    for(int i = 1; i <= n; ++i)
    {
        set[depth] = i;
        print(depth + 1);
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &m);
    
    print(1);
    
    return 0;
}
