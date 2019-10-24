import java.io.*;
import java.util.*;

public class Solution {
   public static String one_to_hundred(int n){
       String str="";
       String[] unit=new String[] {"Zero","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten "};
       String[] ten=new String[] {"Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
       String[] twenty=new String[] {"","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
       while(n!=0){
           if(n<=10){
               str=str + unit[n];
               n=0;

           }
           else if (n>10 && n<20){
               str = str + ten[n%10-1];
               n=0;

           }
           else if (n>=20 && n<100){
               str = str + twenty[n/10-1];
               n=n%10;

           }
       }
       return str;
   }

   public static String hundred_to_ten_thousand(int n){
       String str="";
       while(n!=0){
           if(n<100){
               str=str+ one_to_hundred(n);
               n=0;
           }
           else if(n>=100 && n<1000){
               str = str + one_to_hundred(n/100);
               str = str +"Hundred ";

               n=n%100;
           }
           else if(n>=1000 && n<100000){

               str = str+ one_to_hundred(n/1000);
               str = str + "Thousand " ;
               n=n%1000;

           }

       }
       return str;
   }

   public static String ten_thousand_to_million(long a){
       String str = "";
       int n =(int)a;
        while(n!=0){
           if(n<100000){
               str=str+ hundred_to_ten_thousand(n);
               n=0;
           }
           else if(n>=100000 && n<1000000){
               str = str + hundred_to_ten_thousand(n/100000);
               str = str +"Hundred ";

               n=n%100000;
           }
           else if(n>=1000000 && n<100000000){

               str = str+ hundred_to_ten_thousand(n/1000000);
               str = str + "Million " ;
               n=n%1000000;

           }

       }
       return str;

   }

   public static String million_to_billion(long n){
       String str = "";
        while(n!=0){
           if(n<100000000){
               str=str+ ten_thousand_to_million(n);
               n=0;
           }
           else if(n>=100000000 && n<1000000000){
               str = str + ten_thousand_to_million(n/100000000l);
               str = str +"Hundred ";

               n=n%100000000l;
           }
           else if(n>=1000000000l && n<100000000000l){

               str = str+ ten_thousand_to_million(n/1000000000l);
               str = str + "Billion " ;
               n=n%1000000000l;
           }
       }
       return str;

   }
   public static String billion_to_hundred_billion(long n){
       String str = "";
        while(n!=0){
           if(n<100000000000l){
               str=str+ million_to_billion(n);
               n=0;
           }
           else if(n>=100000000000l && n<1000000000000l){
               str = str + million_to_billion(n/100000000000l);
               str = str +"Hundred ";

               n=n%100000000000l;
           }
           else if(n>=1000000000000l && n<10000000000000l){
               str = str + million_to_billion(n/1000000000000l);
               str = str +"Trillion ";

               n=n%1000000000000l;
           }

       }
       return str;

   }



   public static void main(String[] args) {
       /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
       Scanner in = new Scanner(System.in);
       System.out.println("Enter the no. of test cases");
       int T = in.nextInt();

       if(T>0 && T<=10){
           long[] a= new long[T];
           System.out.println("Enter numbers");
           for(int i=0;i<T;i++){
               a[i]=in.nextLong();

           }
           for(int j=0;j<T;j++){
               if(a[j]==0){
                   System.out.println("Zero");
               }
               else if(a[j]<=1000000000000l){
                   if(j!=(T-1)){
                   System.out.println(billion_to_hundred_billion(a[j]));
                   }
                   else{
                   System.out.print(billion_to_hundred_billion(a[j]));
                   }
               }
           }

       }

   }
}
