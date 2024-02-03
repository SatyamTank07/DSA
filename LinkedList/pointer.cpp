#include<iostream>

int  main()
{
    int input;
    input = 10;
    int*pointer=&input;
    std::cout<<"address of input with \\&:"<<&input<<std::endl;
    std::cout<<"Printing POinter only: "<<pointer<<std::endl;
    std::cout<<"Printing POinter with \\&: "<<&pointer<<std::endl;
    std::cout<<"Printing POinter with \\*: "<<*pointer<<std::endl;

}