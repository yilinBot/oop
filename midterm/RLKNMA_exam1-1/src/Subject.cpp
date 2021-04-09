#include "Subject.hpp"

; void Subject::Enor::next() {
  ; _end = _enor.end()
  ; if (_end) return
  ; _curr.student = _enor.current().student
  ; _curr.hasOne = false
  ; _curr.fives = 0
  ; for (Entry::Task task : _enor.current().tasks) { // Summation + Counting
    ; _curr.hasOne = _curr.hasOne || task.grade == 1
    ; if (task.grade == 5) ++_curr.fives
    ;}
  ; _enor.next()
  ;}

;
