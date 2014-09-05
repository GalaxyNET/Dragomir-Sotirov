#include <string>
#include "Hardware.h"
using namespace std;

Hardware::Hardware( int partNumberValue, string HardwareNameValue, int inStockValue, double unitPriceValue )
{
   setPartNumber( partNumberValue );
   setHardwareName( HardwareNameValue );
   setInStock( inStockValue );
   setUnitPrice( unitPriceValue );
}

void Hardware::setPartNumber( int partNumberValue )
{
   partNumber = partNumberValue;
}

int Hardware::getPartNumber() const
{
   return partNumber;
}


void Hardware::setHardwareName( string HardwareNameString )
{
   int length = HardwareNameString.size();
   length = ( length < LENGTH ? length : LENGTH - 1 );
   HardwareNameString.copy( HardwareName, length );

   HardwareName[ length ] = '\0';
}

string Hardware::getHardwareName() const
{
   return HardwareName;
}

void Hardware::setInStock( int inStockValue )
{
   inStock = inStockValue;
}

int Hardware::getInStock() const
{
   return inStock;
}

void Hardware::setUnitPrice( double unitPriceValue )
{
   unitPrice = unitPriceValue;
}

double Hardware::getUnitPrice() const
{
   return unitPrice;
}
