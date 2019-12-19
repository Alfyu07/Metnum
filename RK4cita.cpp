#include <iostream>
#include <iomanip>
using namespace std;

int main (){
    double x[5], y[5], a[5], h;
    x[0]=0;
    y[0]=1;
    a[0]=-8;

    cout<<"Menyelesaikan persamaan diferensial:"<<endl;
    cout<<"0.25y'' + 64xy' + y = 0"<<endl;
    cout<<"dengan y(0)=1 dan y'(0)=-8"<<endl;
    cout<<"dengan metode RK orde 4"<<endl;
    cout<<endl;
    cout<<"Masukkan nilai h = ";
    cin>>h;
    cout<<endl;

    for(int i=0; i<4; i++){
        x[i+1]=x[i]+h;
        double k1y=h*(a[i]);
        double k2y=h*(a[i]+(k1y/2));
        double k3y=h*(a[i]+(k2y/2));
        double k4y=h*(a[i]+k3y);

        y[i+1]=y[i]+((k1y+2*k2y+2*k3y+k4y)/6);
        cout<<"X"<<i+1<<" = "<<x[i+1]<<endl;

        cout<<"k1 = "<<setprecision(4)<<k1y<<endl;
        cout<<"k2 = "<<k2y<<endl;
        cout<<"k3 = "<<k3y<<endl;
        cout<<"k4 = "<<k4y<<endl;
        cout<<"Y"<<i+1<<" = "<<y[i+1]<<endl;
        cout<<endl;

        //f(x,y,a)
        //a'=-64xa-y/0.25
        double k1a=h*(((-64*x[i]*a[i])-y[i])/0.25);
        double k2a=h*(((-64*(x[i]+(h/2))*(a[i]+(k1a/2)))-(y[i]+(k1a/2)))/0.25);
        double k3a=h*(((-64*(x[i]+(h/2))*(a[i]+(k2a/2)))-(y[i]+(k2a/2)))/0.25);
        double k4a=h*(((-64*(x[i]+h)*(a[i]+k3a))-(y[i]+k3a))/0.25);

        a[i+1]=a[i]+((k1a+2*k2a+2*k3a+k4a)/6);
        cout<<"k1 = "<<k1a<<endl;
        cout<<"k2 = "<<k2a<<endl;
        cout<<"k3 = "<<k3a<<endl;
        cout<<"k4 = "<<k4a<<endl;
        cout<<"a"<<i+1<<" = "<<a[i+1]<<endl;
        cout<<endl;

    }

    cout<<"Penyelesaian persamaan diferensial dari 0.25y'' + 64xy' + y = 0"<<endl;
    cout<<"dengan y(0)=1 dan y'(0)=-8 adalah : "<<a[4]<<endl;
    return 0;
}
