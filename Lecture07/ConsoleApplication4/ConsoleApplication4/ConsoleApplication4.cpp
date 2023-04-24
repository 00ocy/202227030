#include <iostream>

using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal : 동물이다잉 (탄생)" << endl;
    }
    virtual ~Animal()
    {
        cout << "Animal : 뒤졌어예 (죽음)" << endl;
    }
    virtual void Talk()
    {
        cout << "Animal : 동물이 뭔 말을 해" << endl;
    }
};

class Hamster : public Animal
{
public:
    Hamster()
    {
        cout << "Hamster : 찍(탄생)" << endl;
    }
    ~Hamster()
    {
        cout << "Hamster : 히이이익(죽음)" << endl;
    }

    void Talk()
    {
        cout << "Hamster : 법규나 처머겅" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        cout << "Cat : 니야아아아옹(탄생)" << endl;
    }
    ~Cat()
    {
        cout << "Cat : 끄앙!(죽음)" << endl;
    }

    void Talk()
    {
        cout << "Cat : 야옹야옹야옹야옹야옹야옹야옹야옹야옹야옹야옹야옹야옹야옹야옹야옹!" << endl;
    }
};

class Tiger : public Animal
{
public:
    Tiger()
    {
        cout << "Tiger : 크아앙(탄생)" << endl;
    }
    ~Tiger()
    {
        cout << "Tiger : 지명준(죽음)" << endl;
    }

    void Talk()
    {
        cout << "Tiger : 영어를 잘해야 외국인을 만남..." << endl;
    }
};

int main()
{
    cout << "냐옹앱 시작" << endl;
    cout << endl;

    int AnimalNum = 3;
    Animal** ani = new Animal * [AnimalNum];

    ani[0] = new Tiger();
    ani[1] = new Cat();
    ani[2] = new Hamster();

    for (size_t i = 0; i < AnimalNum; i++)
    {
        ani[i]->Talk();
        delete(ani[i]);
    }

    
}