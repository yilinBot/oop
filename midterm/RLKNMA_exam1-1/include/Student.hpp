#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Subject.hpp"

; struct Student {
  ; std::string name
  ; bool has15
  ; bool hasOne
  ; int fives
  ; class Enor
  ;}

; class Student::Enor {
  ; public:
    ; Enor(const std::string &fname)
      : _enor(fname), _end(false) {}
    ; void first() { _enor.first() ; next() ;}
    ; void next()
    ; Student current() const { return _curr ;}
    ; bool end() const { return _end ;}
  ; private:
    ; Subject::Enor _enor
    ; Student _curr
    ; bool _end
  ;}

#endif // STUDENT_HPP
