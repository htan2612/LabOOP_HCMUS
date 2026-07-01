#include "BigInteger.h"

int main ()
{
    BigInteger n1 ;
    BigInteger n2(1234567) ;
    BigInteger n3(3, 14) ;
    BigInteger n4(9, 20) ;
    BigInteger n5 = n3.Subtract ( n2 ) ;
    BigInteger n6 = BigInteger::Subtract(45678910, n2) ;
    BigInteger n7 = n4.Subtract(n3) . Add(123456789) ;
    n1.Print();
    n2.Print();
    n3.Print();
    n4.Print();
    n5.Print();
    n6.Print();
    n7.Print();
    cout << endl ;
    cout << "Max BigInteger :" << endl ;
    BigInteger::GetMaxBigInteger().Print () ;    
    return 0;
}