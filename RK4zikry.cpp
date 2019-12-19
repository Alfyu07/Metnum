#include <iostream>
#include <iomanip>

using namespace std;

double hasil(double x, double y, double z){
    return ((-256*x*z)-4*y);
}

int main(){
    double x,x0,y0,z0, h;
    double k1,k2,k3,k4,l1,l2,l3,l4;
    int n;
    cout<<"Persamaan: 0.25y'' + 64xy' + y = 0"<<endl;
    cout<<"Nilai x: "; cin>>x;
    cout<<"Nilai h: "; cin>>h;
    n = (int) x/h;
    x0=0;
    y0=0;
    z0=-8;
    cout<<"======================================="<<endl;
    cout<<"    y"<<"  \t\t"<<"\t    y'"<<endl;
    cout<<"======================================="<<endl;
    for(int i = 1; i<=n; i++){
        k1 = h*z0;
        l1 = h*hasil(x0,y0,z0);
        k2 = h*(z0+l1/2);
        l2 = h*hasil(x0+h/2,y0+k1/2,z0+l1/2);
        k3 = h*(z0+l2/2);
        l3 = h*hasil(x0+h/2,y0+k2/2,z0+l2/2);
        k4 = h*(z0+l3/2);
        l4 = h*hasil(x0+h/2,y0+k3,z0+l3);
        y0 = y0+((k1+2*k2+2*k3+k4)/6);
        z0 = z0+((l1+2*l2+2*l3+l4)/6);
        cout<<y0<<"  \t\t"<<z0<<endl;
        x0 = x0+h;
    }
}
