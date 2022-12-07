#include <iostream>
#include <memory>

class ClientCar
{
public:
    virtual ~ClientCar() { std::cout << "Destructor called.\n"; }
    virtual void DriveCar() = 0;
};


class RealCar : public ClientCar
{
public:
    void DriveCar();
};

void RealCar::DriveCar()
{
    std::cout << "Car has been driven!\n";
}

class ProxyCar : public ClientCar
{
public:
    ProxyCar(int driver_age) 
    :   m_driver_age(driver_age) {}

    void DriveCar() override
    {
        if (m_driver_age > 16)
        {
            real_car->DriveCar();
        }
        else
        {
            std::cout << "Sorry, driver is too young!\n";
        }
    }

private:
    std::unique_ptr<ClientCar> real_car = std::make_unique<RealCar>();
    int m_driver_age;

};

int main()
{
    std::unique_ptr<ClientCar> car = std::make_unique<ProxyCar>(25);
    std::unique_ptr<ClientCar> car2{ new ProxyCar(5) };
    car->DriveCar();
}
