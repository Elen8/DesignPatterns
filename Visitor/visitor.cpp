#include <iostream>

class User;

class Verification
{
public:
    virtual void accept(User*) = 0;
};

class FaceID: public Verification
{
public:
    void accept(User*);
    void allow()
    {
        std::cout << "FaceID-Allow";
    }
    void forbid()
    {
        std::cout << "FaceID-Forbid";
    }
};

class Fingerprint: public Verification
{
public:
    void accept(User*);
    void allow()
    {
        std::cout << "Fingerprint-Allow";
    }
    void forbid()
    {
        std::cout << "Fingerprint-Forbid";
    }
};

class User
{
public:
    virtual void Try(FaceID*) = 0;
    virtual void Try(Fingerprint*) = 0;

    bool m_Match = false;
};

class Allow: public User
{
public:
    void Try(FaceID* FID)
    {
        m_Match = true;
        FID->allow();
        std::cout << "Allowed FaceID";
    }
    void Try(Fingerprint *FP)
    {
        m_Match = true;
        FP->allow();
        std::cout << "Allowed Fingerprint";
    }
};

class Forbid: public User
{
public:
    void Try(FaceID* FID)
    {
        m_Match = false;
        FID->forbid();
        std::cout << "Forbidden FaceID";
    }
    void Try(Fingerprint *FP)
    {
        m_Match = false;
        FP->forbid();
        std::cout << "Forbidden Fingerprint";
    }
};

void FaceID::accept(User *us)
{
    us->Try(this);
}
  
void Fingerprint::accept(User *us)
{
    us->Try(this);
}
  
int main()
{
    Verification* vf = new FaceID;
    Allow al;
    Forbid fb;
    
    vf->accept(&al);
}
