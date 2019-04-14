/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    PhysicalNumber myPhysic(2, Unit::KM);
    PhysicalNumber myPhysic1(300, Unit::M);
    PhysicalNumber myPhysic2(2, Unit::KG);
    PhysicalNumber myPhysic3(30, Unit::TON);
    PhysicalNumber myPhysic4(30, Unit::G);
    PhysicalNumber myPhysic5(60, Unit::SEC);
    PhysicalNumber myPhysic6(1, Unit::MIN);
    PhysicalNumber myPhysic7(1, Unit::HOUR);
    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
       
      .setname("My Tests")
      .CHECK_OUTPUT(c+d-d, "2[hour]")
      .CHECK_OUTPUT(c++, "2[hour]")
      .CHECK_OUTPUT(c, "3[hour]")
      .CHECK_OUTPUT(++(++c), "5[hour]")
      .CHECK_OUTPUT(c--, "5[hour]")
      .CHECK_OUTPUT(c, "4[hour]")
      .CHECK_OUTPUT(--c, "3[hour]")
      .CHECK_OUTPUT(myPhysic2+myPhysic3, "30002[kg]")
      .CHECK_OUTPUT(myPhysic+myPhysic1, "2.3[km]")
      .CHECK_OUTPUT(myPhysic-myPhysic1, "1.7[km]")
      .CHECK_OUTPUT(myPhysic, "2[km]")
      .CHECK_OK((myPhysic+=myPhysic1))
      .CHECK_OUTPUT(myPhysic, "2.3[km]")
      .CHECK_OK(istringstream("2[km]") >> myPhysic)
      .CHECK_OK((myPhysic-=myPhysic1))
      .CHECK_OUTPUT(myPhysic, "1.7[km]")
      .CHECK_EQUAL(myPhysic>myPhysic1, true)
      .CHECK_OK(istringstream("1700[m]") >> myPhysic1)
      .CHECK_EQUAL(myPhysic==myPhysic1, true)
       .CHECK_EQUAL(myPhysic<=myPhysic1, true)
       .CHECK_THROWS(myPhysic3>=myPhysic1)
       .CHECK_EQUAL(myPhysic!=myPhysic1, false)
       .CHECK_EQUAL(myPhysic3>myPhysic2, true)
       .CHECK_OK(myPhysic3++)
       .CHECK_OUTPUT(myPhysic3, "31[ton]")
       .CHECK_OK(myPhysic3--)
       .CHECK_OUTPUT(myPhysic3, "30[ton]")
       .CHECK_THROWS(myPhysic4+myPhysic6)
       .CHECK_THROWS(myPhysic4!=myPhysic6)
       .CHECK_THROWS(myPhysic4-myPhysic6)
       .CHECK_EQUAL(myPhysic5==myPhysic6, true)
       .CHECK_EQUAL(myPhysic7==myPhysic6, false)
       .CHECK_OUTPUT(myPhysic7+myPhysic5, "1.01667[hour]")
       .CHECK_OUTPUT(myPhysic6+myPhysic7, "61[min]")


      
      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
