#include <iostream>
#include "fstream"
#include "vector"
#include "string"
#include <../objects/objects.h>

std::vector<int> X{100, 120, 100, 80, 60};
std::vector<int> Y{320, 40, 80, 540, 30};

void read_file (char name_file[15])
{
    std::ifstream read (name_file);
    std::vector<int> buff;
    int Buff;
    while(!read.eof()) {
        read >> Buff;
        buff.push_back(Buff);
    }
    read.close();
    Buff = buff.size()/2;
    std::cout << "X: ";
    for (size_t i = 0; i < Buff; i++)
    {
        X.push_back(buff[i]);
    }
    std::cout << std::endl << "Y: ";
    for (size_t i = Buff; i < buff.size(); i++)
    {
        Y.push_back(buff[i]);
    }


}

void write_file()
{
    std::ofstream write("route.txt");
    for (int i = 0; i < X.size(); i++)
        write << X[i] << std::endl;
    write << std::endl;
    for (int i = 0; i < Y.size(); i++)
        write << Y[i] << std::endl;

write.close();
}



int main(int argc, char* argv[]) {
    if (argc < 2)
        std::cout << "Enter file name";
    else
    write_file();
    read_file(argv[1]);



     auto *sedan = new Sedan;
    sedan->refuel();

    auto *suv = new SUV;
    suv->refuel();

    auto *bus = new Bus();
    bus->refuel();

    auto *bicycle = new Bicycle;
    bicycle->refuel();

    auto *route1 = new Route;
    for(size_t i = 0; i < X.size(); i++)
    route1->add_point(X[i], Y[i], "Point" + i);



    route1->run_to_route(sedan);
    route1->run_to_route(suv);
    route1->run_to_route(bus);
    route1->run_to_route(bicycle);



    sedan->status();
    suv->status();
    bus->status();
    bicycle->status();

    return 0;
}
