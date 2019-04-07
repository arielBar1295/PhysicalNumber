
#include <iostream>

#include "Unit.h"
#include <string.h>
#include <sstream>
using namespace ariel;
using namespace std;
namespace ariel{
class PhysicalNumber{
    private:
    Unit unit;
    double number;

public:
PhysicalNumber(double number,Unit unit){
this->unit=unit;
this->number=number;

}
PhysicalNumber operator+(PhysicalNumber &other) const ;
PhysicalNumber operator-(PhysicalNumber &other) const;
const PhysicalNumber& operator+=(const PhysicalNumber &other);
const PhysicalNumber& operator-=(const PhysicalNumber &other);
PhysicalNumber& operator+();
 const PhysicalNumber& operator++() ;
 PhysicalNumber operator++(int);
 PhysicalNumber operator--(int);
 const PhysicalNumber& operator=(const PhysicalNumber &other);
const PhysicalNumber& operator--() ;
PhysicalNumber& operator-();
friend std::ostream& operator<<(ostream& os, const PhysicalNumber &other);
friend std::istream& operator>>(istream& in, PhysicalNumber &other);
bool operator==(const PhysicalNumber &other) const;
bool operator<=(const PhysicalNumber &other) const ;
bool operator>=(const PhysicalNumber &other) const;
bool operator>(const PhysicalNumber &other) const;
bool operator<(const PhysicalNumber &other) const ;
bool operator!=(const PhysicalNumber &other) const;
 
Unit getUnit()  {
    return this->unit;
}
double getNumber() {
    return this->number;
}
Unit getUnit() const {
    return this->unit;
}
double getNumber() const {
    return this->number;
}
void setNumber(double number){
    this->number=number;
}
void setUnit(Unit u){
    this->unit=u;
}
double convertUnit(PhysicalNumber u2) const ;
double convertCm(PhysicalNumber u2) const;
double convertSEC(PhysicalNumber u2) const;
double convertG(PhysicalNumber u2) const;
bool same(const PhysicalNumber other) const;
double convertingU(const PhysicalNumber other) const;
};
}