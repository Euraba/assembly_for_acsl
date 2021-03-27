//
// Created by she on 27.03.2021.
//

#ifndef ASSEMBLY_ASSEMBLY_H
#define ASSEMBLY_ASSEMBLY_H

namespace Assembly {
    int atoi(Sir val) {
      int ret(0), sgn(1) ;

      for (auto it : val) {
        if (it == '-') {
          sgn = -1 ;
        } else if (it == '=') {

        } else {
          ret = ret * 10 + (it - '0') ;
        }
      }
      return ret * sgn ;
    }

    void start() {
      VS.push_back((Sir)"MULT") ;
      VS.push_back((Sir)"LOAD") ;
      VS.push_back((Sir)"STORE") ;
      VS.push_back((Sir)"ADD") ;
      VS.push_back((Sir)"SUB") ;
      VS.push_back((Sir)"DIV") ;
      VS.push_back((Sir)"BG") ;
      VS.push_back((Sir)"BE") ;
      VS.push_back((Sir)"BL") ;
      VS.push_back((Sir)"BU") ;
      VS.push_back((Sir)"READ") ;
      VS.push_back((Sir)"PRINT") ;
      VS.push_back((Sir)"DC") ;
      VS.push_back((Sir)"END") ;
    }

    bool egal(Sir a, Sir b) {
      int dif = 'a' - 'A' ;
      for (auto &it : a) {
        if ('a' <= it && it <= 'z') {
          it -= dif ;
        }
      }
      for (auto &it : b) {
        if ('a' <= it && it <= 'z') {
          it -= dif ;
        }
      }
      return a == b ;
    }

    bool comanda(Sir x) {
      for (auto it : VS) {
        if (egal(x, it) == 1) {
          return true ;
        }
      }
      return false ;
    }

    Sir fix(Sir x) {
      int dif = 'a' - 'A' ;
      for (int i = 0 ; i < x.size() ; ++ i) {
        if ('a' <= x[i] && x[i] <= 'z') {
          x[i] -= dif ;
        }
      }
      return x ;
    }

}

#endif //ASSEMBLY_ASSEMBLY_H
