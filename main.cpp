#include <iostream>
#include <string>
#include <vector>

#include "Picture.h"

int main()
{
    std::cout << "Enter your first string picture: " << std::endl;
    std::vector<std::string> input;
    std::string s;
    while(std::cin >> s){
        input.push_back(s);
    }

    Picture p = input;
    Picture q = frame(p);
    Picture r = hcat(p, q);
    Picture s = vcat(q, r);
    std::cout << frame(hcat(s, vcat(r, q))) << std::endl;

    return 0;
}
