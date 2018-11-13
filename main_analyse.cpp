
#include "langtonant.h"

#include <iostream>

#define NUM_ITER 15000
#define PLOT_ITER 100

#ifdef GNUPLOT_USE
#include "gnuplot-iostream.h"
#endif

double dist(pair<int,int> coords) {
  return sqrt(coords.first * coords.first + coords.second * coords.second);
}

using namespace std;


template<typename T,typename U>
ostream& operator<<(ostream& out, pair<T,U> data) {
  out << "{ " << data.first << " | " << data.second << " }";
  return out;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T> data) {
  out << "{ ";
  for(int i = 0 ; i < data.size(); i ++) {
    out << data[i] << " ";
  }
  out << " }";
  return out;
}

int main() {


#ifdef GNUPLOT_USE


  // Demo basic

  Gnuplot gp;
  // For debugging or manual editing of commands:
  //Gnuplot gp(std::fopen("plot.gnu"));
  // or
  //Gnuplot gp("tee plot.gnu | gnuplot -persist");

//  std::vector<std::pair<double, double> > xy_pts_A;
//  for(double x=-2; x<2; x+=0.01) {
//    double y = x*x*x;
//    xy_pts_A.push_back(std::make_pair(x, y));
//  }
//
//  std::vector<std::pair<double, double> > xy_pts_B;
//  for(double alpha=0; alpha<1; alpha+=1.0/24.0) {
//    double theta = alpha*2.0*3.14159;
//    xy_pts_B.push_back(std::make_pair(cos(theta), sin(theta)));
//  }

//  gp << "set xrange [-1:16000]\nset yrange [-1:1000]\n";
//  gp << "plot '-' with lines title 'cubic', '-' with points title 'circle'\n";
//  gp.send1d(xy_pts_A);
//  gp.send1d(xy_pts_B);

//  gp.send1d(vals);



  LangtonAnt la("LRRRRRLLR");

  vector<double> vals;//(NUM_ITER);

  int x,y, color;

  for(int i = 0 ; i < NUM_ITER; i ++) {
    double d = dist(la.GetPosition());
    //vals[i] = d;
    vals.push_back(d);
    la.Iterate(x, y, color);

    if (i % PLOT_ITER == 0) {
      gp << "plot '-' binary" << gp.binFmt1d(vals, "array") << "with lines notitle\n";
      gp.sendBinary1d(vals);
      gp.flush();
    }

    //cout << vals << endl;
  }

  //cout << vals;


#endif


  return 0;
}