#include <iostream>
#include <algorithm>
#include <string>

int l, c;
std::string ret;
char input[15];

void solve(int idx, int depth, int vowel, int consonant)
{
    if(depth == l)
    {
        if(vowel >= 1 && consonant >= 2)
            std::printf("%s\n", ret.c_str());
        
        return;
    }
    
    for(int i = idx; i < c; ++i)
    {
        ret[depth] = input[i];
        
        if(input[i] == 'a' || input[i] == 'e' ||
           input[i] == 'i' || input[i] == 'o' ||
           input[i] == 'u')
            solve(i + 1, depth + 1, vowel + 1, consonant);
        else
            solve(i + 1, depth + 1, vowel, consonant + 1);
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &l, &c);
    
    ret.resize(c);
    
    for(int i = 0; i < c; ++i)
        std::scanf(" %c", input + i);
    
    std::sort(input, input + c);
    
    solve(0, 0, 0, 0);
    
    return 0;
}
