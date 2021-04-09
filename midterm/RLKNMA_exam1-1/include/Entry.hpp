#ifndef ENTRY_HPP
#define ENTRY_HPP

#include <fstream>
#include <vector>

; struct Entry {
  ; struct Task {
    ; std::string task
    ; int grade
    ;}
  ; std::string student
  ; std::string subject
  ; std::vector<Task> tasks
  ; class Enor
  ;}

; class Entry::Enor {
  ; public:
    ; enum Exception { OPEN_ERROR, PARSE_ERROR }
    ; Enor(const std::string &fname)
      : _file(fname.c_str()), _end(false) {
      ; if (_file.fail()) throw OPEN_ERROR
      ;}
    ; void first() { getline(_file, _line) ; next() ;}
    ; void next()
    ; Entry current() const { return _curr ;}
    ; bool end() const { return _end ;}
  ; private:
    ; std::ifstream _file
    ; std::string _line
    ; Entry _curr
    ; bool _end
  ;}

;
#endif // ENTRY_HPP
