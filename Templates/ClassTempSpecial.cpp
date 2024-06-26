#include <iostream>
#include <vector>

template<typename T>
class PrettyPrinter
{
    T* data{};

public:
    PrettyPrinter(T* value)
    {
        data = value;
    }

    void Print()
    {
        std::cout << "{ "<<*data<<" }"<< std::endl;
    }

    T* GetData()
    {
        return data;
    }

};

template<>
void PrettyPrinter<std::vector<int>>::Print()
{
    std::cout <<" { ";
    for(const auto& iter : *data)
    {
        std::cout<< " "<<iter;
    }
    std::cout <<" } " <<std::endl;
}

template<> 
class PrettyPrinter<char *>
{
    char * data;
public:

    PrettyPrinter(char* value)
    {
        data = value;
    }

    void Print()
    {
        std::cout << "{ "<<data<<" }"<< std::endl;
    }

    char * GetData()
    {
        return data;
    }

};

int main()
{
    int d = 14;
    PrettyPrinter p{&d};
    p.Print();
    float f = 3.5;
    PrettyPrinter p2(&f);
    p2.Print();

    char * str {"HelloWorld"};
    PrettyPrinter<char *> p3(str);
    p3.Print();
    char * ptr = p3.GetData();

    std::vector<int> vec{1,2,3,4,5,6,7};
    PrettyPrinter p4(&vec);
    p4.Print();
    return 0;
}
