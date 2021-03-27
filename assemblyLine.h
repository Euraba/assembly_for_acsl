//
// Created by she on 27.03.2021.
//

#ifndef ASSEMBLY_ASSEMBLYLINE_H
#define ASSEMBLY_ASSEMBLYLINE_H

class Line {
private :

public :
    Sir LABEL, OPCODE, LOC ;
    Line() {
      this -> LABEL = this -> OPCODE = this -> LOC = Sir("NU") ;
    }
    Line(Sir _LABEL, Sir _OPCODE, Sir _LOC) {
      this ->LABEL = _LABEL ;
      this ->OPCODE = _OPCODE ;
      this ->LOC = _LOC ;
    }

    void citeste(Sir first = Sir("NU")) {
      if (first == "NU") {
        in >> first ;
      }
      if (Assembly::comanda(first)) {
        if (Assembly::egal(first, (Sir)"END")) {
          this -> OPCODE = first ;
          return ;
        } else {
          Sir second ; in >> second ;
          this -> OPCODE = first ;
          this -> LOC = second ;
        }
      } else {
        Sir second, third ; in >> second >> third ;
        *this = Line(first, second, third) ;
      }
    }

    void eval(int &ACC, int &idx, std::map<Sir, int> &values, std::vector<Line> lines, std::vector<int> &readValues) {
      if (Assembly::egal(this -> OPCODE, (Sir)"END")) {
        return ;
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"DC")) {
        values[this -> LABEL] = Assembly::atoi(this -> LOC) ;
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"LOAD")) {
        if (values.find(this -> LOC) != values.end()) {
          ACC = values[this -> LOC] ;
        } else {
          ACC = Assembly::atoi(this -> LOC) ;
        }
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"STORE")) {
        values[this -> LOC] = ACC ;
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"ADD")) {
        if (values.find(this -> LOC) != values.end()) {
          ACC += values[this -> LOC] ;
        } else {
          ACC += Assembly::atoi(this -> LOC) ;
        }
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"SUB")) {
        if (values.find(this -> LOC) != values.end()) {
          ACC -= values[this -> LOC] ;
        } else {
          ACC -= Assembly::atoi(this -> LOC) ;
        }
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"MULT")) {
        if (values.find(this -> LOC) != values.end()) {
          ACC *= values[this -> LOC] ;
        } else {
          ACC *= Assembly::atoi(this -> LOC) ;
        }
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"DIV")) {
        if (values.find(this -> LOC) != values.end()) {
          ACC /= values[this -> LOC] ;
        } else {
          ACC /= Assembly::atoi(this -> LOC) ;
        }
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"BG")) {
        if (ACC > 0) {
          for ( ; idx < lines.size() && Assembly::egal(lines[idx].LABEL, this -> LOC) == false; ++ idx) ;
          if (idx == lines.size()) {
            for (idx = 0 ; Assembly::egal(lines[idx].LABEL, this -> LOC) == false && idx < lines.size() ; ++ idx) ;
          }
          -- idx ;

        }
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"BE")) {
        if (ACC == 0) {
          for ( ; idx < lines.size() && Assembly::egal(lines[idx].LABEL, this -> LOC) == false ; ++ idx) ;
          if (idx == lines.size()) {
            for (idx = 0 ; Assembly::egal(lines[idx].LABEL, this -> LOC) == false && idx < lines.size() ; ++ idx) ;
          }
          -- idx ;
        }
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"BL")) {
        if (ACC < 0) {
          for ( ; idx < lines.size() && Assembly::egal(lines[idx].LABEL, this -> LOC) == false ; ++ idx) ;
          if (idx == lines.size()) {
            for (idx = 0 ; Assembly::egal(lines[idx].LABEL, this -> LOC) == false && idx < lines.size() ; ++ idx) ;
          }
          -- idx ;
        }
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"BU")) {
        for ( ; idx < lines.size() && Assembly::egal(lines[idx].LABEL, this -> LOC) == false ; ++ idx) ;
        if (idx == lines.size()) {
          for (idx = 0 ; Assembly::egal(lines[idx].LABEL, this -> LOC) == false && idx < lines.size() ; ++ idx) ;
        }
        -- idx ;
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"READ")) {
        values[this -> LOC] = readValues.back() ;
        readValues.pop_back() ;
      }

      else if (Assembly::egal(this -> OPCODE, (Sir)"PRINT")) {
        out << this -> OPCODE << " = " << values[this -> LOC] << '\n' ;
      }

    }

} ;

#endif //ASSEMBLY_ASSEMBLYLINE_H
