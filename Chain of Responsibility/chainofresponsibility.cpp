#include <iostream>


class Computer
{
public:
    Computer(std::string s) : mTitle(s)
    {
        std::cout << "Processing " << mTitle << " ...\n";
    }

private:
    std::string mTitle;
};

class Bios
{
public:
    Bios() : mNextProcess(0) { }

public:
    void process(Computer& pCmp) {
        processImplementation(pCmp);
        if (mNextProcess != 0)
            mNextProcess->process(pCmp);
    }

    virtual ~Bios() { }

    void setNextProcess(Bios* pBs) {
        mNextProcess = pBs;
    }

protected:
    virtual void processImplementation(Computer&) = 0;

private:
    Bios* mNextProcess;
};

class CPU : public Bios
{
public:
    enum TCPU { C7, C8, C9, C10, C11 };
    CPU(TCPU tcpu) : mTCPU(tcpu) { }

private:
    void processImplementation(Computer&) {
        std::cout << "Scaling photo\n";
    }

    TCPU mTCPU;
};

class Keyboard : public Bios
{
private:
    void processImplementation(Computer& kb) {
        std::cout << "Keyboard\n";
    }
};

class Mouse : public Bios
{
private:
    void processImplementation(Computer& ms) {
        std::cout << "Mouse\n";
    }
};

class Headphone : public Bios
{
private:
    void processImplementation(Computer& hp)
    {
        std::cout << "Headphone\n";
    }
};

void Process(Computer& cmp)
{
    Headphone hp;
    Keyboard kb;
    Mouse ms;
    CPU tcpu(CPU::C8);
    tcpu.setNextProcess(&kb);
    kb.setNextProcess(&hp);
    hp.setNextProcess(&ms);
    tcpu.process(cmp);
}

int main()
{
    Computer* pCmp = new Computer("Turned on");
    Process(*pCmp);
    return 0;
}
