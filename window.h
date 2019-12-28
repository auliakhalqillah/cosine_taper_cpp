#include <vector>
#include <cmath>
#include <fstream>

double costaper(std::vector<double> t, double a, std::vector<double> &c) {
  int j,k,l,m,n;
  double c1,c2,c3,pi;
  std::ofstream winout;
  pi = 3.14;
  n = t.size();

  // Cosine taper
  winout.open("coswinout.txt");
  // Section 1
  j = 0;
  while (t[j] >= 0.0 && t[j] <= a) {
    c1 = (1-cos(pi/a*t[j]))/2;
    c.push_back(c1);
    ++j;
  }
  // Section 2
  k = j;
  while (t[k] >= a && t[k] <= (1-a)) {
    c2 = 1.0;
    c.push_back(c2);
    ++k;
  }
  // Section 3
  l = k;
  while (l < n){
    c3 = (1-cos(pi/a*(1-t[l])))/2;
    c.push_back(c3);
    ++l;
  }
  m = 0;
  while (m < n-1) {
    winout<<m<<"\t"<<t[m]<<"\t"<<c[m]<<"\n";
    ++m;
  }
  winout.close();
  return 0;
}
