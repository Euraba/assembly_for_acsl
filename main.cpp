//
//  main.cpp
//  ACSL
//
//  Created by Eusebiu Rares on 13/05/2020.
//  Copyright © 2020 Eusebiu Rares. All rights reserved.
//

#include <iostream>
#include "cstring"
#include "fstream"
#include "cstdlib"
#include "cstdio"
#include "stdlib.h"
#include "vector"
#include "cstdio"
#include "string"
#include "map"
#include "assembly.h"
#include "assemblyLine.h"
#include "program.h"

std::fstream in ("test.in", std::ios::in) ;
std::fstream out ("test.out", std::ios::out) ;

#define ever (;;)

typedef std::string Sir ;

std::vector<Sir> VS ;

const int MOD = 1e9 + 7 ;

long long fastpow(long long a, long long b) {
  long long ret(1) ;
  for ( ; b ; b >>= 1) {
    if (b & 1) {
      ret = ret * a % MOD ;
    }
    a = a * a ;
  }
  return ret ;
}

void solve(int idx) {
  Program program ;
  program.citeste() ;
  program.rezolva(idx) ;
  return ;
}

int main(int argc, const char * argv[]) {
  Assembly::start() ;
  for (int idx = 1 ; idx <= 1 ; ++ idx) {
    solve(idx) ;
    out << '\n' ;
  }
}
