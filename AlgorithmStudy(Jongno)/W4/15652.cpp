#include <iostream>

int n, m;
int set[9];

void print(int begin, int depth)
{
    if(depth > m)
    {
        for(int i = 1; i <= m; ++i)
            std::printf("%d ", set[i]);
        std::printf("\n");
        return;
    }
    
    
    for(int i = begin; i <= n; ++i)
    {
        set[depth] = i;
        print(i, depth + 1);
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &m);
    
    print(1, 1);
    
    return 0;
}
