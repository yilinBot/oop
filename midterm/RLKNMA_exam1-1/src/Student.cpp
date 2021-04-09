#include "Student.hpp"

; void Student::Enor::next() {
  ; _end = _enor.end()
  ; if (_end) return
  ; _curr.name = _enor.current().student
  ; _curr.has15 = false
  ; _curr.hasOne = false
  ; _curr.fives = 0
  ; while (!_enor.end() && _enor.current().student == _curr.name) { // Summation + Summation + Summation
    ; _curr.has15 = _curr.has15 || (_enor.current().hasOne && _enor.current().fives > 0)
    ; _curr.hasOne = _curr.hasOne || _enor.current().hasOne
    ; _curr.fives += _enor.current().fives
    ; _enor.next()
    ;}
  ;}

;
