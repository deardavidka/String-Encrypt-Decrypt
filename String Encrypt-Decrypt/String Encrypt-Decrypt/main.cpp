/*
Hello! This is an easy example of how you can implement authorization on your xenforo forum using
    native C++. I will take this opportunity to inform you that if you want to make your loader,
    cheat, or C++ program and you are having trouble with the design, then feel free to contact
    RebornStudio (link below), using the "GITHUB" promo code you will receive an additional 5% discount%

RebornStudio: https://discord.gg/SKSBGsqfZy
*/

#include "encrypt-decrypt.h"
#include <iostream>


std::string str = "Hello from RebornStudio!"; 

int main() {
    str = encdec.encode(str);//encoding str
    std::cout << "EnCoded string: " << str << std::endl; 

    str = encdec.decode(str);//decoding str
    std::cout << "DeCoded string: " << str << std::endl; 


    std::cin.get();
}