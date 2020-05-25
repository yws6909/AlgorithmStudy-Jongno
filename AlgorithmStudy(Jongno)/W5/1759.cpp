#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define repeat_for(V,N) \
for (int V = 0; V < N; ++V)

#define L_MAX 15

int T, L, C;
std::string I;
std::vector <std::string> R;

void init ()
{
    T = 1;
    L = C = 0;
    I.reserve(L_MAX);
    std::ios_base::sync_with_stdio(false);
}

void input ()
{
    std::cin >> L >> C;
    
    char t;
    repeat_for(i, C)
    {
        std::cin >> t;
        I.push_back(t);
    }
    
    std::sort(I.begin(), I.end(), std::less<char>{});
}

bool is_vowel (char c)
{
    switch(c)
    {
        case 'a': case 'e':
        case 'i': case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

using str_iter = std::string::iterator;

void solve (int c = 0, int vowel = 0,
            std::string&& str = {},
            str_iter i = I.begin())
{
    if (c == L)
    {
        if ( (vowel >= 1) && ((c - vowel) >= 2) )
        {
            R.push_back(str);
        }
    }
    else
    {
        ++c;
        for (; i < I.end(); ++i)
        {
            solve(c, vowel + is_vowel(*i), str + (*i), i + 1);
        }
    }
}

void output ()
{
    for (auto elem : R)
    {
        std::cout << elem << "\n";
    }
}

int main (int argc, const char* argv[])
{
    init();
    repeat_for(i, T)
    {
        input();
        solve();
        output();
    }
    return 0;
}
