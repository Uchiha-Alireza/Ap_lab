#ifndef GUN_H
#define GUN_H
#include <iostream>
#include <ostream>
class Gun{
    private:
    int ammo;
    std::string name;
    float fireRate;
    bool isAutomatic;
    static int numberOfGuns;
    public:
    Gun(int,std::string,float,bool);
    Gun();
    Gun(const Gun&);
    void SetAmmo(int);
    int GetAmmo()const;
    void SetName(std::string);
    std::string GetName()const;
    void SetIsAutomatic(bool);
    bool GetIsAutomatic()const;
    void SetFireRate(float);
    float GetFireRate()const;
    Gun operator+(const Gun&);
    Gun& operator+=(const Gun&);
    bool operator==(const Gun&);
    bool operator!=(const Gun&);
    Gun& operator=(const Gun&);
    Gun operator--(int);
    Gun operator--();
    Gun operator++(int);
    Gun operator++();
    Gun& operator[](int);
    Gun& operator*(int);
    Gun& operator/(int);
    Gun& operator*=(int);
    Gun& operator/=(int);
    friend std::istream& operator>>(std::istream&,Gun&);
    friend std::ostream& operator<<(std::ostream&,const Gun&);
};
#endif 