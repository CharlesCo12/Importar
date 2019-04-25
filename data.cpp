#include <iostream>
#include <fstream>
using namespace std;


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename);

float dzdt(float t, float y, float z, float omega);
float dydt(float t, float y, float z, float omega);

int main(){
  float omega=1.0;
  solve_equation_euler(0.0, 10000.0, omega/2, omega, "euler.dat");
  solve_equation_rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
  solve_equation_leapfrog(0.0, 10000.0, omega/2, omega, "leapfrog.dat");
  return 0;
}

void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float z=0.0;
  float z_1=z;
  ofstream outfile;
  outfile.open(filename);  

  while(t<t_end){    
    outfile << t << " " << y  << " " << z << endl;    
    z = z - delta_t*omega*omega*y;
    y = y + delta_t * z_1;
    z_1=z;
    t = t + delta_t;
  }
  outfile.close();
}

void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float z=0.0;
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){    
    outfile << t << " " << y  << " " << z << endl;
    float z_1=z;
    float y_1=y;
    float m1,m2,m3,m4,k1,k2,k3,k4=0;
      
    m1=dzdt(t,y_1,z_1,omega);
    m2=dzdt(t+(delta_t/2),y_1+(m1*delta_t/2),z_1,omega);
    m3=dzdt(t+(delta_t/2),y_1+(m2*delta_t/2),z_1,omega);
    m4=dzdt(t+(delta_t),y_1+(m3*delta_t),z_1,omega);
      
    k1=dydt(t,y_1,z_1,omega);
    k2=dydt(t+(delta_t/2),y_1,z_1+(k1*delta_t/2),omega);
    k3=dydt(t+(delta_t/2),y_1,z_1+(k2*delta_t/2),omega);
    k4=dydt(t+(delta_t),y_1,z_1+(k3*delta_t),omega);
      
    z = z + (delta_t/6) * (m1+2*m2+2*m3+m4);
    y = y + (delta_t/6) * (k1+2*k2+2*k3+k4);    
    t = t + delta_t;
  }
  outfile.close();
}
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float z=0.0;
  float z_1=0;
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){    
    outfile << t << " " << y  << " " << z << endl;    
    z_1 = z - omega*omega*y*delta_t/2;
    y = y + z_1*delta_t;
    z = z_1 - omega*omega*y*delta_t/2;
    t = t + delta_t;
  }
  outfile.close();
}
float dzdt(float t, float y, float z, float omega){    
    return -1*omega*omega*y;
  }
float dydt(float t, float y, float z, float omega){    
    return z;
  }