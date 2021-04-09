#include <iostream>
#include "Result.hpp"
#include "Entry.hpp"

; int main() {
  ; using namespace std
  ; string fname
  ; cout << "Please input the file name: "
  ; getline(cin, fname)
  ; Result res
  ; try {
    ; res = Result::calc(fname)
    ;}
    catch (const Entry::Enor::Exception &e) {
    ; if (e == Entry::Enor::OPEN_ERROR) {
      ; cerr << "Failed to open the file " << fname << "." << endl
      ; return 1
      ;}
    ; if (e == Entry::Enor::PARSE_ERROR) {
      ; cerr << "Failed to parse the file " << fname << "." << endl
      ; return 2
      ;}
    ;}
  ; cout << endl << "First task:" << endl
  ; if (res.has15)
      cout << res.student15 << " obtained both one and five in the same subject" << endl
  ; else
      cout << "There wasn't any student who obtained both one and five in the same subject" << endl
  ; cout << endl << "Second task:" << endl
  ; for (Result::Student1 student : res.student1s) // Summation
      cout << student.name << " obtained a one and has " << student.fives << " five(s) in total." << endl
  ;}
