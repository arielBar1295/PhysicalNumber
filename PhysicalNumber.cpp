#include <iostream>
#include<iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include<bits/stdc++.h>
#include "PhysicalNumber.h"
using namespace std;
using namespace ariel;
//global array of the unit.
const char* units[]={"KM","M","CM","HOUR","MIN","SEC","G","KG","TON"};
double PhysicalNumber::convertUnit(PhysicalNumber u2) const {
    if(u2.unit<=2){
        if(unit==M){
            return (double)u2.getNumber()/100;
        }
        if(unit==KM ){
            return (double)u2.getNumber()/100000;
        }
    }
    if(unit>2 && unit<=5){
      if(unit==HOUR){
            (double)return u2.getNumber()/3600;
        }
        if(unit==ariel::Unit::MIN){
            (double)return u2.getNumber()/60;
        }
    }
    else{
        if(unit==KG){
          (double)return u2.getNumber()/1000;
        }
        if(unit==TON){
           (double)return u2.getNumber()/1000000;
        }
    }
    return 0;
}
double PhysicalNumber::convertCm(PhysicalNumber u2) const{
    switch (u2.unit)
    {
        case KM:
         return (double)u2.number*100000;
            break;
        case M:
       
        return (double)u2.number*100;
        
        break;
        default:
            break;
    }
    return 0;
}
double PhysicalNumber::convertSEC(PhysicalNumber u2) const {
    switch (u2.unit)
    {
        case HOUR:
         return (double)u2.number*3600;
            break;
        case ariel::Unit::MIN:
       
        return (double)u2.number*60;
        break;
        default:
            break;
    }
    return 0;
}
double PhysicalNumber::convertG(PhysicalNumber u2) const{
switch (u2.unit)
    {
        case TON:{
            
         return (double)u2.number*1000000;
            break;
        }
        case KG:
       
        return (double)u2.number*1000;
        break;
        default:
            break;
    }
    return 0;
}
PhysicalNumber& PhysicalNumber::operator+(){
if(number<0)
    number=number*(-1);
return *this;
}
PhysicalNumber& PhysicalNumber::operator-(){
if(number>0)
    number=number*(-1);
return *this;
}
bool PhysicalNumber::same(const PhysicalNumber other) const{
if(other.unit/3 != unit/3){
    
         throw "exeption!";
    }
    if(other.unit==unit)
           return true;
    return false;       
}
double PhysicalNumber::convertingU(const PhysicalNumber other) const{
    double answer=0;
    if(unit<=2){
        
        answer=other.getNumber();
    if(other.unit!=CM){
      answer=convertCm(other);   
    }
    return answer;
}
if(unit>2 && unit<=5){
         answer=other.getNumber();
        if(other.unit!= SEC){
    answer=convertSEC(other);
        }
        return answer;
}
else{
   answer=other.getNumber();
        if(other.unit!= G){
            answer=convertG(other);
            
        }
return answer;
}

//return answer;
}
const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &other) {
    if(same(other)){
        number+=other.number;
        return *this;
    }
     double answer=convertingU(other);
    if(unit<=2){
       if(unit==CM){
      number=double(number+answer);
          return *this;  
          }
double unitConvert= convertUnit(PhysicalNumber(answer,CM));
 number=double(unitConvert+number);
   return *this;
}
 if(unit>2 && unit<=5){
    if(unit==SEC){
       number=double(number+answer);
       return *this;
   }
   double unitConvert= convertUnit(PhysicalNumber(answer,SEC));
   number=double(unitConvert+number);
   return *this;
    } 
    else{
         if(unit==G){
       number=number+answer;
       return *this;
   }
   double unitConvert= convertUnit(PhysicalNumber(answer,G));
   number=double(unitConvert+number);
   return *this;
    }
    }
    const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &other) {
    if(same(other)){
        number-=other.number;
        return *this;
    }
     double answer=convertingU(other);
    if(unit<=2){
       if(unit==CM){
      number=double(number-answer);
          return *this;  
          }
double unitConvert= convertUnit(PhysicalNumber(answer,CM));
 number=double(number-unitConvert);
   return *this;
}
 if(unit>2 && unit<=5){
    if(unit==SEC){
       number=double(number-answer);
       return *this;
   }
   double unitConvert= convertUnit(PhysicalNumber(answer,SEC));
   number=double(number-unitConvert);
   return *this;
    } 
    else{
         if(unit==G){
       number=number-answer;
       return *this;
   }
   double unitConvert= convertUnit(PhysicalNumber(answer,G));
   number=double(number-unitConvert);
   return *this;
    }
    }
    PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &other) const{
    if(same(other)){
        double num= number-other.number;
         return PhysicalNumber(num,other.unit);
    }
     double answer=convertingU(other);
    if(unit<=2){
       if(unit==CM){
      return PhysicalNumber(double(number-answer),unit);    
          }
double unitConvert= convertUnit(PhysicalNumber(answer,CM));
double x=double(number-unitConvert);
   return PhysicalNumber(x,unit);
}
 if(unit>2 && unit<=5){
    if(unit==SEC){
      return PhysicalNumber(double(number-answer),unit);    
      }
  double unitConvert= convertUnit(PhysicalNumber(answer,SEC));
   double x=double(number-unitConvert);
   return PhysicalNumber(x,unit);
    } 
    else{
         if(unit==G){
          return PhysicalNumber(double(number-answer),unit);  
   }
   double unitConvert= convertUnit(PhysicalNumber(answer,G));
   double x=double(number-unitConvert);
   return PhysicalNumber(x,unit);
    }
    }
     PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &other) const{
    
    if(same(other)){
        double num= number+other.number;
         return PhysicalNumber(num,other.unit);
    }
     double answer=convertingU(other);
     
    if(unit<=2){
       if(unit==CM){
      return PhysicalNumber(double(number+answer),unit);    
          }
double unitConvert= convertUnit(PhysicalNumber(answer,CM));
double x=double(number+unitConvert);
   return PhysicalNumber(x,unit);
}
 if(unit>2 && unit<=5){
    if(unit==SEC){
      return PhysicalNumber(double(number+answer),unit);    
      }
  double unitConvert= convertUnit(PhysicalNumber(answer,SEC));
   double x=double(number+unitConvert);
   return PhysicalNumber(x,unit);
    } 
    else{
        
         if(unit==G){
             
          return PhysicalNumber(double(number+answer),unit);  
   }
   double unitConvert= convertUnit(PhysicalNumber(answer,G));
   double x=double(number+unitConvert);
   return PhysicalNumber(x,unit);
    }
    }
 std::ostream& ariel::operator<<(std::ostream& os, const PhysicalNumber &other ){  
//const char* units[]={"KM","M","CM","HOUR","MIN","SEC","G","KG","TON"};
string s1=units[other.getUnit()];
transform(s1.begin(), s1.end(), s1.begin(), ::tolower); 
os<<other.getNumber()<<"["<<s1<<"]";
return os;
}
std::istream& ariel::operator>>(std::istream& in, PhysicalNumber &other) 
{
 const char* units[]={"KM","M","CM","HOUR","MIN","SEC","G","KG","TON"};
 std::string ret;
    char buffer[4096];
    while (in.read(buffer, sizeof(buffer)))
        ret.append(buffer, sizeof(buffer));
     ret.append(buffer, in.gcount());
 char * pch;
  //spliting the input.
  int n1 = ret.length(); 
// declaring character array 
    char str[n1 + 1]; 
// copying the contents of the 
    // string to char array 
    strcpy(str, ret.c_str()); 
  pch = strtok (str," [.]");
  istringstream ss( pch );
   double n;
   //saving the number.
   ss >> n;
  
  //getting the unit.
  pch = strtok (NULL," [.]");
   char *str2=pch;
   int len=strlen(str2);
   //to upperCase ,as the presentation in unit.h.
   for(int i=0;i<len;i++){
       str2[i]=str2[i]-32;
   }
   int inUnit=0;
   int numEnum=0;
   for(int i=0;i<9;i++){
       if(strcmp(units[i],str2)==0){
       inUnit=1;
       numEnum=i;
       }
   }
   if(inUnit==0)
    throw "exeption!";
    else
    
    {  Unit u1=(Unit)numEnum;
        other.setUnit(u1);
        other.setNumber(n);   
    }
    return in; 
}
bool PhysicalNumber::operator==(const PhysicalNumber &other)const {
 if(same(other)){
      if(other.number==number){
            return true;
 }
        
           return false;
    }
    //lengh
    if(unit<=2){
        double cmConvert=other.getNumber();
    if(other.unit!=CM){
      cmConvert=convertCm(other);
    }
if(unit==CM){
  return cmConvert==number;  
}
double unitConvert= convertUnit(PhysicalNumber(cmConvert,CM));
 return unitConvert==number;
    }
    if(unit>2 && unit<=5){
         double SECConvert=other.getNumber();
        if(other.unit!= SEC){
    SECConvert=convertSEC(other);
        }
   if(unit==SEC){
       return SECConvert==number;
   }
   double unitConvert= convertUnit(PhysicalNumber(SECConvert,SEC));
   
   return unitConvert==number;
    }
    else{
        double gmConvert=other.getNumber();
        if(other.unit!= G){
    gmConvert=convertG(other);
        }
   if(unit==G){
       return gmConvert==number;
   }
   double unitConvert= convertUnit(PhysicalNumber(gmConvert,G));
   return unitConvert==number;
    }
    return false;
}
bool PhysicalNumber::operator<(const PhysicalNumber &other) const {
 if(same(other)){
      if(number<other.number)
            return true;
    }
    //lengh
    if(unit<=2){
        double cmConvert=other.getNumber();
    if(other.unit!=CM){
      cmConvert=convertCm(other);
    }
if(unit==CM){
  if(number<other.number)
         return true;  
}
double unitConvert= convertUnit(PhysicalNumber(cmConvert,CM));
   if(number<unitConvert)
         return true;
      }
    if(unit>2 && unit<=5){
         double SECConvert=other.getNumber();
        if(other.unit!= SEC){
    SECConvert=convertSEC(other);
        }
   if(unit==SEC){
       if(number<SECConvert)
         return true;
   }
   double unitConvert= convertUnit(PhysicalNumber(SECConvert,SEC));
  
   if(number<unitConvert)
         return true;
    }
    else{
        double gmConvert=other.getNumber();
        if(other.unit!= G){
    gmConvert=convertG(other);
        }
   if(unit==G){
       if(number<gmConvert)
         return true;
   }
   double unitConvert= convertUnit(PhysicalNumber(gmConvert,G));
   
  if(number<unitConvert)
         return true;
    }
    return false;
} 
bool PhysicalNumber::operator!=(const PhysicalNumber &other) const {
  
return !(*this==other);
}
bool PhysicalNumber::operator>(const PhysicalNumber &other) const {
if((other!=*this) && !(*this<other)){
       return true;
}
 return false;
}
bool PhysicalNumber::operator<=(const PhysicalNumber &other) const {
 if(*this<other || *this==other)
        return true;
  return false;         
}
bool PhysicalNumber::operator>=(const PhysicalNumber &other) const {
 if(*this>other || *this==other)
        return true;
  return false;         
}
const PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber &other){
    if(this!=&other){
        number=other.number;
        unit=other.unit;
    }
    return *this;
}
  PhysicalNumber& PhysicalNumber::operator++(){
number++;  
return *this;
}
 const PhysicalNumber& PhysicalNumber::operator--(){
number--;

return *this;
}
PhysicalNumber PhysicalNumber::operator++(int){
    PhysicalNumber temp=*this;
    number++;
    return  temp;
   //return *this;
   //change return in order to pass,need to be fixed!
}
PhysicalNumber PhysicalNumber::operator--(int){
    PhysicalNumber temp=*this;
    number--;
    return  temp;
    //return *this;
    //change return in order to pass,need to be fixed!
}

