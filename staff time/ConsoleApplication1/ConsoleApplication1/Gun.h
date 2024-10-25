#pragma once
#include <iostream>
#include <ostream>
class Gun {
private:
    int ammo;
    std::string name;
    float fireRate;
    bool isAutomatic;
    bool isDeactive;
    static int numberOfGuns;
public:
    Gun(int, std::string, float, bool,bool);
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
    bool getisDeactive()const;
    void setisDeactive(bool);
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
    friend std::istream& operator>>(std::istream&, Gun&);
    friend std::ostream& operator<<(std::ostream&, const Gun&);
    bool operator<(const Gun&);
    bool operator<=(const Gun&);
    bool operator>(const Gun&);
    bool operator>=(const Gun&);
    Gun operator<<(int);
    Gun operator>>(int);
};