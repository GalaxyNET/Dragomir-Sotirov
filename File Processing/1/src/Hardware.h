#ifndef HARDWARE_H
#define HARDWARE_H

#include <string>
using namespace std;

class Hardware
{
public:
   static const int LENGTH = 30;

   Hardware( int = -1, string = "", int = 0, double = 0.0 );

   void setPartNumber( int );
   int getPartNumber() const;

   void setHardwareName( string );
   string getHardwareName() const;

   void setInStock( int );
   int getInStock() const;

   void setUnitPrice( double );
   double getUnitPrice() const;
private:
   int partNumber;
   char HardwareName[ LENGTH ];
   int inStock;
   double unitPrice;
};

#endif
