//
// Created by she on 27.03.2021.
//

#ifndef ASSEMBLY_PROGRAM_H
#define ASSEMBLY_PROGRAM_H

class Program {
private :

    std::vector<int> readValues ;
    std::vector<Line> lines ;
    std::map<Sir, int> values ;
    int ACC ;

public :
    Program() {
      this ->ACC = 0 ;
    }

    void citeste() {
      Sir val ; int value ;
      for ( ; in >> val && (('0' <= val[0] && val[0] <= '9') or val[0] == '-') ; ) {
        value = Assembly::atoi(val) ;
        readValues.push_back(value) ;
      }
      std::reverse(begin(readValues), end(readValues)) ;
      Line prima ;
      prima.citeste(val) ;
      lines.push_back(prima) ;
      for ever {
          prima = Line() ;
          prima.citeste() ;
          lines.push_back(prima) ;
          if (Assembly::egal(prima.OPCODE, (Sir)"END")) {
            break ;
          }
      }
    }

    void rezolva(int idx) {
      for (int i = 0 ; i < lines.size() ; ++ i) {
        lines[i].eval(ACC, i, values, lines, readValues) ;
      }
      out << idx << ". " << ACC ;
    }

} ;

#endif //ASSEMBLY_PROGRAM_H
