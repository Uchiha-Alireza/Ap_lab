#include "Gun.h"
#include <string>
Gun::Gun(int _ammo, std::string _name, float _fireRate, bool _isAutomatic,bool _isdeactive) :ammo(_ammo), name(_name), fireRate(_fireRate), isAutomatic(_isAutomatic), isDeactive(_isdeactive){}
Gun::Gun() {}
int Gun::numberOfGuns = 0;
void Gun::SetAmmo(int _ammo) {
    ammo = _ammo;
}
int Gun::GetAmmo()const {
    return ammo;
}
Gun::Gun(const Gun& object) {
    this->SetAmmo(object.GetAmmo());
    this->SetName(object.GetName());
    this->SetFireRate(object.GetFireRate());
    this->SetIsAutomatic(object.GetIsAutomatic());
}

void Gun::SetName(std::string _name) {
    name = _name;
}
std::string Gun::GetName()const {
    return name;
}
void Gun::SetIsAutomatic(bool _isAutomatic) {
    isAutomatic = _isAutomatic;
}
bool Gun::GetIsAutomatic()const {
    return isAutomatic;
}
void Gun::SetFireRate(float _firerate) {
    fireRate = _firerate;
}
float Gun::GetFireRate()const {
    return fireRate;
}
Gun Gun::operator+(const Gun& object) {
    Gun tmp;
    tmp.SetAmmo(this->GetAmmo() + object.GetAmmo());
    tmp.SetName(this->GetName() + object.GetName());
    tmp.SetFireRate(this->GetFireRate() * object.GetFireRate());
    if (this->GetIsAutomatic() == true || object.GetIsAutomatic() == true) {
        tmp.SetIsAutomatic(true);
    }
    else {
        tmp.SetIsAutomatic(false);
    }
    return tmp;
}
Gun& Gun::operator+=(const Gun& object) {
    this->SetAmmo(this->GetAmmo() + object.GetAmmo());
    this->SetName(this->GetName() + object.GetName());
    this->SetFireRate(this->GetFireRate() * object.GetFireRate());
    if (this->GetIsAutomatic() == true || object.GetIsAutomatic() == true) {
        this->SetIsAutomatic(true);
    }
    else {
        this->SetIsAutomatic(false);
    }
    return *this;
}
bool Gun::operator==(const Gun& object) {
    bool _name, _ammo, _isAutomatic, _firerate;
    if (this->GetAmmo() == object.GetAmmo()) {
        _ammo = true;
    }
    else {
        _ammo = false;
    }
    if (this->GetName() == object.GetName()) {
        _name = true;
    }
    else {
        _name = false;
    }
    if (this->GetFireRate() == object.GetFireRate()) {
        _firerate = true;
    }
    else {
        _firerate = false;
    }
    if (this->GetIsAutomatic() == object.GetIsAutomatic()) {
        _isAutomatic = true;
    }
    else {
        _isAutomatic = false;
    }
    if (_ammo == true && _ammo == _name && _ammo == _firerate && _ammo == _isAutomatic) {
        return true;
    }
    else {
        return false;
    }
}
bool Gun::operator!=(const Gun& object) {
    return !(*this == object);
}
Gun& Gun::operator=(const Gun& object) {
    if (*this == object) {
        return *this;
    }
    else {
        this->SetAmmo(object.GetAmmo());
        this->SetName(object.GetName());
        this->SetFireRate(object.GetFireRate());
        this->SetIsAutomatic(object.GetIsAutomatic());
        return *this;
    }
}
Gun Gun::operator--(int shit) {
    Gun tmp;
    tmp = Gun(*this);
    this->SetAmmo(this->GetAmmo() + 1);
    return tmp;
}
Gun Gun::operator--() {
    this->SetAmmo(this->GetAmmo() + 1);
    return *this;
}
Gun Gun::operator++(int shit) {
    Gun tmp;
    tmp = Gun(*this);
    this->SetAmmo(this->GetAmmo() + 1);
    return tmp;
}
Gun Gun::operator++() {
    this->SetAmmo(this->GetAmmo() + 1);
    return *this;
}
Gun& Gun::operator[](int New) {
    this->SetAmmo(New);
    return *this;
}
Gun& Gun::operator*(int value) {
    return *this;
}
Gun& Gun::operator/(int value) {
    if (value == 0) {
        return *this;
    }
    else {
        return *this;
    }
}
Gun& Gun::operator*=(int value) {
    this->SetAmmo(this->GetAmmo() * value);
    return *this;
}
Gun& Gun::operator/=(int value) {
    if (value == 0) {
        return *this;
    }
    else {
        this->SetAmmo(this->GetAmmo() / value);
        return *this;
    }
}
std::ostream& operator<<(std::ostream& stream, const Gun& NewGun) {
    stream << "Gun Ammo: " << NewGun.ammo << std::endl;
    stream << "Gun Name: " << NewGun.name << std::endl;
    stream << "Gun is Automatic: ";
    if (NewGun.isAutomatic == false) {
        stream << "No" << std::endl;
    }
    else {
        stream << "Yes" << std::endl;
    }
    stream << "Gun FireRate: " << NewGun.fireRate << std::endl;
    return stream;
}
std::istream& operator>>(std::istream& stream, Gun& NewGun) {
    std::cout << "Enter gun ammo: ";
    stream >> NewGun.ammo;
    std::cout << "Enter gun name: ";
    stream >> NewGun.name;
    std::cout << "Is gun automatic (1 for Yes, 2 for No): ";
    int choice;
    stream >> choice;
    if (choice == 1) {
        NewGun.isAutomatic = true;
    }
    else {
        NewGun.isAutomatic = false;
    }
    std::cout << "Enter fire rate: ";
    stream >> NewGun.fireRate;
    return stream;
}
bool Gun::getisDeactive()const {
    return isDeactive;
}
void Gun::setisDeactive(bool s) {
    isDeactive = s;
}
bool Gun::operator<(const Gun& other) {
    return this->GetAmmo() < other.GetAmmo();
}
bool Gun::operator<=(const Gun& other) {
    return this->GetAmmo() <= other.GetAmmo();
}
bool Gun::operator>(const Gun& other) {
    return this->GetAmmo() > other.GetAmmo();
}
bool Gun::operator>=(const Gun& other) {
    return this->GetAmmo() >= other.GetAmmo();
}
Gun Gun::operator<<(int trash) {
    Gun tmp;
    tmp.SetAmmo(this->GetAmmo() * 2);
    return tmp;
}
Gun Gun::operator>>(int trash) {
    Gun tmp;
    tmp.SetAmmo(this->GetAmmo() / 2);
    return tmp;
}