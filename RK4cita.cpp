#include <iostream>
#include <iomanip>

using namespace std;

double fa(double x, double y, double a){
    return ((-256*x*a)-4*y);
}
int main(){
    double x[5],y[5],a[5];
    x[0] = 0;
    y[0] = 1;
    a[0] = -8;
    double l1,l2,l3;
    double k1,k2,k3;
    
    cout<<"Persamaan differensial : "<<endl;
    cout<<"0.25y'' + 64xy' + y = 0"<<endl;    
    double h;
    cout<<"masukkan nilai h : "; cin>>h;
    int n = 5;

//double fa(double x, double y, double a){
//    return ((-256*x*a)-4*y);
//}
    for(int i = 0; i<n; i++){
         
         
        l1=h*(a[i]);
        l2=h*(a[i]+(l1/2));
        l3=h*(a[i]-l1+2*l2);

        y[i+1]=y[i]+((l1+4*l2+l3)/6);

        cout<<"X"<<i+1<<" = "<<x[i+1]<<endl;
        cout<<"l1 = "<<l1<<endl;
        cout<<"l2 = "<<l2<<endl;
        cout<<"l3 = "<<l3<<endl;
        cout<<"Y"<<i+1<<" = "<<y[i+1]<<endl;
        cout<<endl;

        k1=h*(((-64*x[i]*a[i])-y[i])/0.25);
        k2=h*(((-64*(x[i]+(h/2))*(a[i]+(k1/2)))-(y[i]+(k1/2)))/0.25);
        k3=h*(((-64*(x[i]+h)*(a[i]-k1+2*k2))-(y[i]-k1+2*k2))/0.25);

        a[i+1]=a[i]+((k1+4*k2+k3)/6);
        cout<<"k1 = "<<k1<<endl;
        cout<<"k2 = "<<k2<<endl;
        cout<<"k3 = "<<k3<<endl;
        cout<<"a"<<i+1<<" = "<<a[i+1]<<endl;
        cout<<endl;
        
        x[i+1]=x[i]+h;
    }
    cout<<"Penyelesaian persamaan diferensial dari 0.25y'' + 64xy' + y = 0"<<endl;
    cout<<"dengan y(0)=1 dan y'(0)=-8 adalah : "<<a[4]<<endl;


}