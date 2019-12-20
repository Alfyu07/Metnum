#include<iostream>
#include<cmath>
using namespace std;

double interpolasi (double a){
    int j,i,n=11;
    double x[] = {-1,-0.5,0,0.5,1,1.5,2,2.5,3,3.5,4};
    double f[] = {0,3.375,4,2.625,0,-3.125,-6,-7.875,-8,-5.625,0};
    double mult, sum = 0;
    for(j=0;j<n-1;j++)
        {
            for(i=n-1;i>j;i--)
                f[i]=(f[i]-f[i-1])/(x[i]-x[i-j-1]);
        }
        for(i=n-1;i>=0;i--)
        {
            mult=1;
            for(j=0;j<i;j++)
                mult*=(a-x[j]);

            mult*=f[j];
            sum+=mult;
        }
        return sum;
}
int main()
{
    int i = 0;
    double total,third=0, non_third=0, h = 0.01,a=-1,result;
    double x[] = {-1,-0.5,0,0.5,1,1.5,2,2.5,3,3.5,4}; double f[] = {0,3.375,4,2.625,0,-3.125,-6,-7.875,-8,-5.625,0};
    cout <<"TURUNAN PADA F(X)= 0.75"<<endl;
    cout<<"-----------------------------"<<endl;
	cout<<"f(0.75)"<<endl;
	cout<<"|  x\t|  y\t |"<<endl;
	cout<<"-------------------"<<endl;
	for(int i=0;i<11;i++)
        cout<<"|  "<<x[i]<<"\t|"<<f[i]<<"\t|"<<endl;
    cout << "SELISIH MAJU : ";
    result = ((interpolasi(0.75+h))-interpolasi(0.75))/h;
    cout<<result;
    cout<<endl;
    cout << "SELISIH MUNDUR :";
    result = (interpolasi(0.75)-interpolasi(0.75-h))/h;
    cout<<result;
    cout<<endl;
    cout << "SELISIH PUSAT : ";
    result = (interpolasi(0.75+h)-(interpolasi(0.75-h)))/(h+h);
    cout<<result;
    while(a<2){
        if(i == 0)
            total = interpolasi(a);
        else{
            if(i%2!=0)
                third += interpolasi(a);
            else
                non_third += interpolasi(a);
        }
        i++;
        a+=h;
    }
    cout<<"\nINTEGRAL DARI X = -1 SAMPAI X = 2 ADALAH : ";
    total = total + (4*third) + (2*non_third) + interpolasi(a);
    total = h/3 * total;
    cout<<total;
}
