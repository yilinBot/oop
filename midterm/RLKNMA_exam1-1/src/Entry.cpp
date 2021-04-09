#include <sstream>
#include "Entry.hpp"

; void Entry::Enor::next() {
  ; while (!_file.eof() && _line.empty()) getline(_file, _line)
  ; _end = _file.eof()
  ; if (_end) return
  ; std::istringstream str(_line)
  ; str >> _curr.student
  ; str >> _curr.subject
  ; if (!str) throw PARSE_ERROR
  ; _curr.tasks.clear()
  ; Task task
  ; while (str >> task.task) { // Summation
    ; str >> task.grade
    ; if (!str) throw PARSE_ERROR
    ; _curr.tasks.push_back(task)
    ;}
  ; getline(_file, _line)
  ;}

;
