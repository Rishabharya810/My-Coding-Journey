#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Hero
{
    public:
    int health;
    // private:
    // protected:
    char *name;
    char level;

    //Simple Constructor
    Hero()
    {
        cout<<"Contructor called"<<endl;
        name = new char[100];
    }
    
    Hero(int health)
    {
        cout<<"this-> "<<this<<endl;
        this -> health = health;
    }

    // Parameterised Constructor
    Hero(int health, char level)   
    {
        this -> level = level;
        this -> health = health;
    }

    //Copy Constructor
    Hero(Hero& temp)
    {
        char *ch= new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name= ch;
        cout<<"Copy Constructor called"<<endl;
        this->health = temp.health;
        this->level= temp.level;
    }
    void print()
    { 
        cout<<endl;
        cout<<"Name:"<<this->name<<endl;
        cout<<"Hero health: " <<this->health<<endl;
        cout<<"Hero level: "<<this->level<<endl;
    }
      int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
       

    }

    void setLevel(char ch )
    {
        level = ch;
        
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }
    ~Hero()
    {
        cout<<"Destructor called"<<endl; 
    }
};

int main()
{
    //STATIC MEMORY ALLOCATION
    Hero a;

    //DYNAMIC MEMORY ALLOCATION
    Hero *b = new Hero();

    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D'); 
    // char name[7] = "Babbar";
    // hero1.setName(name);
    // hero1.print();

    // //use default copy constructor

    // Hero hero2(hero1);
    // hero2.print();
    // //Hero hero2 = hero1;
    
    // hero1.name[0] = 'G';
    // hero1.print();

    // hero2.print(); 
     
    // hero1 = hero2;
    // hero1.print();
    // hero2.print();

    // Hero s(70,'C');
    // s.print();
    // Hero r(s);
    // r.health = s.health;
    // r.level = s.level;
    // r.print();
    // // Hero tt;
    // Hero ramesh(10);
    
    // cout<<"Address of ramesh "<<&ramesh<<endl;
    // ramesh.getHealth();


    //     //ramesh.Hero( ) is automatically called when Hero ramesh is called 
    // Hero *h = new Hero(11);

    // Hero temp(22,'B');
    // temp.print();

    // Hero a;
    // a.setHealth(80);
    // a.setLevel('B');

    // cout<<"Level is "<<a.level<<endl;
    // cout<<"health is "<<a.getHealth()<<endl;

    // Hero *b = new Hero;
    // b->setLevel('A');
    // b->setHealth(70);
    // cout<<"Level is "<<(*b).level<<endl;
    // cout<<"Health is "<<(*b).getHealth()<<endl;

    // cout<<"Level is "<<b->level<<endl;
    // cout<<"Health is "<<b->getHealth()<<endl;

    // Hero h1;
    // h1.health = 70;
    // h1.level = 'A';

    // cout<<"Size of hero is : "<<sizeof(h1)<<endl;
    // cout<<"Hero health is : "<<h1.health<<endl;
    // cout<<"Hero level is : "<<h1.level;
}