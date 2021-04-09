#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "Entry.hpp"

; struct Subject {
  ; std::string student
  ; bool hasOne
  ; int fives
  ; class Enor
  ;}

; class Subject::Enor {
  ; public:
    ; Enor(const std::string &fname)
      : _enor(fname), _end(false) {}
    ; void first() { _enor.first() ; next() ;}
    ; void next()
    ; Subject current() const { return _curr ;}
    ; bool end() const { return _end ;}
  ; private:
    ; Entry::Enor _enor
    ; Subject _curr
    ; bool _end
  ;}

#endif // SUBJECT_HPP
