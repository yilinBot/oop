#include "Result.hpp"
#include "Student.hpp"

; Result Result::calc(const std::string &fname) {
  ; Result res
  ; res.has15 = false
  ; Student::Enor enor(fname)
  ; enor.first()
  ; while (!enor.end()) { // Linear search + Conditional summation
    ; if (!res.has15) {
      ; res.has15 = enor.current().has15
      ; res.student15 = enor.current().name
      ;}
    ; if (enor.current().hasOne) {
      ; Result::Student1 student
      ; student.name = enor.current().name
      ; student.fives = enor.current().fives
      ; res.student1s.push_back(student)
      ;}
    ; enor.next()
    ;}
  ; return res
  ;}

;
