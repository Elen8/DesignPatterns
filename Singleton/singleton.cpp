#include <iostream>

class singleton {
public:
    static singleton* instance()
    {
        if (inst != nullptr)
        {
            return inst;
        }
        else
        {
            inst = new singleton;
        }
    }
    
private:
    singleton() = default;
    singleton(singleton& const) = delete;
    singleton(singleton&& const) = delete;
    
private:
    static singleton* inst;
};

singleton* singleton::inst = nullptr;

int main()
{
    singleton* a = singleton::instance();
    singleton* b = singleton::instance();
}
