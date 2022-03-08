#ifndef GRADE_H
#define GRADE_H
#include <string>
using namespace std;

class Grade{
  private:
  string name;
  int grade;
  public:
  Grade(string n, int g){
    name = n;
    grade = g;
  }
  void set_name(string n){
    name = n;
  }
  void set_grade(int g){
    grade = g;
  }
  string get_name()const{
    return name;
  }
  int get_grade()const{
    return grade;
  }
};
#endif