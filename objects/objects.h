#ifndef OBJECTS_H
#define OBJECTS_H
#include <vector>
#include <string>

class IVehicle {
public:
    virtual bool drive (double way) = 0;
    virtual void refuel () = 0;
    virtual void status() = 0;
    virtual double get_fuel() = 0;
    virtual int get_mileage() = 0;
};

class Vehicle : public IVehicle {
protected:
    int  mileage;
    double real_tank, full_tank, consumption;
public:


     bool drive (double way);
     void refuel ();
     void status();
     double get_fuel();
     int get_mileage();



};

class SUV : public Vehicle{
public:
     SUV();


};

class Sedan : public Vehicle{

public:
Sedan();


};

class Route {
private:
    std::vector <int> X;
    std::vector <int> Y;
    std::vector <std::string> Name;
public:
    void add_point(int x, int y, std::string name);
    void run_to_route(IVehicle* vehicle);
};

class Bicycle : public IVehicle {
private:
    int mileage = 0;
    double fuel = 0;
public:


    bool drive (double way);
    void refuel ();
    void status();
    double get_fuel();
    int get_mileage();



};

class Bus : public Vehicle{

public:
    Bus();


};




#endif // OBJECTS_H
