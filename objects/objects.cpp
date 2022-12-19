#include "objects.h"
#include "iostream"
#include <cmath>

bool Vehicle::drive(double way) {
    bool flag;
    if (real_tank >= ((way/100)*consumption))
    {
        flag = true;
        mileage += way;
        real_tank = real_tank - ((way/100)*consumption);
        std::cout << " You have successfully traveled "  << std::endl;
    }
    else{
        std::cout << "It is imposible. Add fuel in tank" << std::endl;
        flag = false;
    }
    return flag;
}

void Vehicle::refuel() {
    real_tank = full_tank;
    std::cout << "You have successfully filled a full tank" << std::endl;

}

void Vehicle::status() {
    std::cout << "Mileage of your car = " << mileage << std::endl << "Fuell lvl in tank = " << real_tank << std::endl;
}

double Vehicle::get_fuel()
{
    return real_tank;
}

int Vehicle::get_mileage()
{
    return mileage;
}

SUV :: SUV()
{
    mileage = 0;
    real_tank = 0;
    consumption = 14;
    full_tank = 1000;
}

Sedan :: Sedan()
{
    mileage = 0;
    real_tank = 0;
    consumption = 7;
    full_tank = 1000;
}

void Route:: add_point(int x, int y, std::string name)
{
    X.push_back(x);
    Y.push_back(y);
    Name.push_back(name);
}

void Route:: run_to_route(IVehicle* vehicle)
{
    double buff_X, buff_Y, buff;
    for (int i = 0; i < (X.size()-1); i++)
    {
        if(X[i] > X[i+1])
            buff_X = X[i] - X[i+1];
        else buff_X = X[i+1] - X[i];
        if(Y[i] > Y[i+1])
            buff_Y = Y[i] - Y[i+1];
        else buff_Y = Y[i+1] - Y[i];
        buff = (buff_X*buff_X) + (buff_Y*buff_Y);
        buff = sqrt(buff);
        if (vehicle->drive(buff) == true)
        {
            break;
        }
        else
        {
            vehicle->refuel();
            vehicle->drive(buff);
        }

    }
}



bool Bicycle::drive(double way) {
    mileage += way;
    std::cout << " You have successfully traveled "  << std::endl;
    return true;
}

void Bicycle::refuel() {
    std::cout << "No tank" << std::endl;
}

void Bicycle::status() {
    std::cout << "Mileage of your bicycle = " << mileage << std::endl;
}

double Bicycle::get_fuel()
{
    return fuel;

}

int Bicycle::get_mileage()
{
    return mileage;
}



Bus :: Bus()
{
    mileage = 0;
    real_tank = 0;
    consumption = 10;
    full_tank = 1000;
}
