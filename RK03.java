import java.text.DecimalFormat;
import java.util.Scanner;
public class RKO3v2 {
	
    public static double gx(double x,double y,double z){
		//0.25y’’ + 64 xy’+ y=0 maka y''=4(-64xy'-y)
		return (4*((-64*x*z)-y));
	}
	
	public static double fx(double x,double y,double z){
		return z;
	}

    public static void main(String[] args) {
		DecimalFormat dec = new DecimalFormat("#.###");
		Scanner in = new Scanner(System.in);
		
		double k1,k2,k3,l1,l2,l3;
		System.out.print("Batas atas : ");
		double b=in.nextDouble();
		System.out.print("Nilai h : ");
		double h=in.nextDouble();
		int n=(int) (b/h);
		System.out.println("Banyak langlah : "+n);
		double[] x = new double[n+1];
		double[] y = new double[n+1];
		double[] z = new double[n+1];
		//y'=z
		//y(0)=1 dan y’(0)=-8
		x[0]=0;
		y[0]=1;
		z[0]=-8;
		//perhitungan k1,k2,k3,k4 & l1,l2,l3,l4
		for(int i=1; i<=n; i++){
			System.out.println();
			k1= Double.parseDouble(dec.format( h * fx(x[i-1],y[i-1],z[i-1] )));
			System.out.println("Nilai K1 adalah = "+k1);
			l1= Double.parseDouble(dec.format( h * gx(x[i-1],y[i-1],z[i-1] )));
			System.out.println("Nilai L1 adalah = "+l1);
			k2= Double.parseDouble(dec.format( h * fx(x[i-1]+h/2, y[i-1]+k1/2, z[i-1]+l1/2 )));
			System.out.println("Nilai K2 adalah = "+k2);
			l2= Double.parseDouble(dec.format( h * gx(x[i-1]+h/2, y[i-1]+k1/2, z[i-1]+l1/2 )));
			System.out.println("Nilai L2 adalah = "+l2);
			k3= Double.parseDouble(dec.format( h * fx(x[i-1]+h, y[i-1]-k1+2*k2, z[i-1]-l1+2*l2 )));
			System.out.println("Nilai K3 adalah = "+k3);
			l3= Double.parseDouble(dec.format( h * gx(x[i-1]+h, y[i-1]-k1+2*k2, z[i-1]-l1+2*l2 )));
			System.out.println("Nilai L3 adalah = "+l3);
			//perhitungan yr dan zr
			y[i]= Double.parseDouble(dec.format( y[i-1] + ((k1 + (4*k2) + k3)/6 )));
			z[i]= Double.parseDouble(dec.format( z[i-1] + ((l1 + (4*l2) + l3)/6 )));
			x[i]=x[i-1]+h;
			System.out.println("Nilai y"+i+" dengan Metode Runge-Kutta Orde 3 adalah = "+y[i]);
			System.out.println("Nilai z"+i+" dengan Metode Runge-Kutta Orde 3 adalah = "+z[i]);
		}
	}
}