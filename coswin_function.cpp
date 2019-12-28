/*******************************************************************************
Name        : coswin_function.cpp
Info        : Cosine Tapering
Written by  : Aulia Khalqillah,S.Si (2019)
Email       : auliakhalqillah.mail@gmail.com
Last Update : December 26, 2019
Source      : Marco Pilz adn Stefano PArolai, GFZ Postdam
              Tapering of windowed time series
              DOI: 10.2312/GFZ.NMSOP-2_IS_14.1
*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "window.h"
using namespace std;
int main() {
  double a, dt, f, t1, t2, pi;
  double x,time,c1,c2,c3,sigcom;
  vector<double> sig,t,c,windowed;
  int ii,i,j,k,kk,l,ll,m,n;
  ofstream signal, winout, combine;
  pi = 3.14;
  a = 0.5;
  dt = 0.0001;
  f = 20;
  t1 = 0.0;
  t2 = 1.0;
  n = (t2-t1)/dt;
  if (a == dt){
    cout<<"Sampling rate have to smaller than taper ratio!"<<"\n";
  }
  // Generate signal
  i = 0;
  time = 0.0;
  signal.open("coswin_signal.txt");
  while (i <= n) {
    x = sin(2*pi*f*time);
    sig.push_back(x);
    t.push_back(time);
    time = time + dt;
    signal<<i<<"\t"<<t[i]<<"\t"<<sig[i]<<"\n";
    ++i;
  }
  signal.close();

  // Cosine taper (take from window.h)
  costaper(t,a,c);

  // Combine
  ii = 0;
  combine.open("coswin_combined.txt");
  while (ii < n) {
    sigcom = sig[ii]*c[ii];
    windowed.push_back(sigcom);
    combine<<ii<<"\t"<<t[ii]<<"\t"<<windowed[ii]<<"\n";
    ++ii;
  }
  combine.close();
  return 0;
}
