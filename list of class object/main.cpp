#include <iostream>
#include <vector>
#include "grade.h"

using namespace std;

int main(){
  Grade a("a", 65);
  Grade b("b", 85);
  Grade c("c", 100);

  vector<Grade> grades;


  grades.push_back(a);
  grades.push_back(b);
  grades.push_back(c);

  int n = 0;
  while(n < 3){
    string name;
    int g;
    cout <<"Enter name: ";
    cin>>name;
    cout<<"Enter grader for "<< name<<": ";
    cin>>g;
    Grade new_insert(name, g);
    grades.push_back(new_insert);
    n++;
  }
  for(auto it = grades.begin(); it != grades.end(); it++){
    cout << "Name : " << it->get_name() << "\tGrade: " << it->get_grade() << endl;
  }

return 0;
}
