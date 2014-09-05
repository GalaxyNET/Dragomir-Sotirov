#include <iostream> 
#include <iomanip> 
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "Hardware.h"
using namespace std;

void initializeFile( fstream & );
void inputData( fstream & );
void listHardwares( fstream & );
void updateRecord( fstream & );
void insertRecord( fstream & );
void deleteRecord( fstream & );
int instructions( void );

int main()
{
   int choice; 
   char response;

   fstream file( "hardware.dat", ios::in | ios::out );
   void ( *f[] )( fstream & ) = { listHardwares, updateRecord, insertRecord, deleteRecord };
   
   if ( !file ) 
   {
      cerr << "File could not be opened.\n";
      exit( 1 );
   }

   cout << "Should the file be initialized (Y or N): ";
   cin >> response;  
   response = toupper( response );

   while ( ( response != 'Y' ) && ( response != 'N' ) ) 
   {
      cout << "Invalid response. Enter Y or N: ";
      cin >> response;
      response = toupper( response );
   }

   if ( response == 'Y' ) 
   {
      initializeFile( file );
      inputData( file );
   }

   while ( ( choice = instructions() ) != 5 ) 
   {
      ( *f[ choice - 1 ] )( file );
      file.clear();
   }
}

void initializeFile( fstream &hw )
{
   Hardware newHw;

   for ( int i = 0; i < 100; i++ )
      hw.write( reinterpret_cast< char * >( &newHw ), sizeof( Hardware ) );
}

void inputData( fstream &hw )
{
   Hardware temp;

   int number;
   string name;
   double price;
   int stock;

   cout << "Enter the part number (0 - 99, -1 to end input): ";
   cin >> number;

   while ( number != -1 ) 
   {
      cout << "Enter the Hardware name: ";
      cin.ignore();
      getline( cin, name );
      temp.setHardwareName( name );
      temp.setPartNumber( number );

      cout << "Enter quantity and price: "; 
      cin >> stock >> price;
      temp.setInStock( stock );
      temp.setUnitPrice( price );
      
      hw.seekp( temp.getPartNumber() * sizeof( Hardware ) );

      hw.write( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );

      cout << "Enter the part number (0 - 99, -1 to end input): ";
      cin >> number;
   }
}

int instructions()
{
   int choice;

   cout << "\nEnter a choice:\n1  List all Hardwares."
      << "\n2  Update record.\n3  Insert record."
      << "\n4  Delete record.\n5  End program.\n";

   do 
   {
      cout << "? ";
      cin >> choice;
   } while ( choice < 1 || choice > 5 );

   return choice;
}

void listHardwares( fstream &hw )
{
   Hardware temp;

   cout << setw( 7 ) << "Record#" << "    " << left 
      << setw( 30 ) << "Hardware name" << left
      << setw( 13 ) << "Quantity" << left << setw( 10 ) << "Cost" << endl;

   for ( int count = 0; count < 100 && !hw.eof(); count++ )
   {
      hw.seekg( count * sizeof( Hardware ) );
      hw.read( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );

      if ( temp.getPartNumber() >= 0 && temp.getPartNumber() < 100 ) 
      {
         cout << fixed << showpoint;
         cout << left << setw( 7 ) << temp.getPartNumber() << "    " 
            << left << setw( 30 ) << temp.getHardwareName() << left
            << setw( 13 ) << temp.getInStock() << setprecision( 2 )
            << left << setw( 10 ) << temp.getUnitPrice() << '\n';
      }
   }
}

void updateRecord( fstream &hw )
{
   Hardware temp;
   int part;
   string name;
   int stock;
   double price;

   cout << "Enter the part number for update: ";
   cin >> part;

   hw.seekg( part * sizeof( Hardware ) );

   hw.read( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );

   if ( temp.getPartNumber() != -1 ) 
   {
      cout << setw( 7 ) << "Record#" << "    " << left 
         << setw( 30 ) << "Hardware name" << left
         << setw( 13 ) << "Quantity" << setw( 10 ) << "Cost" << endl;

      cout << fixed << showpoint;
      cout << setw( 7 ) << temp.getPartNumber() << "    " 
         << left << setw( 30 ) << temp.getHardwareName()
         << left << setw( 13 ) << temp.getInStock() 
         << setprecision( 2 ) << setw( 10 ) << temp.getUnitPrice() << '\n'
         << "Enter the Hardware name: ";

      cin.ignore();
      getline( cin, name );
      temp.setHardwareName( name );

      cout << "Enter quantity and price: ";
      cin >> stock >> price;
      temp.setInStock( stock );
      temp.setUnitPrice( price );

      hw.seekp( temp.getPartNumber() * sizeof( Hardware ) );
      hw.write( reinterpret_cast< char * > ( &temp ), sizeof( Hardware ) );
   }
   else
      cerr << "Cannot update. The record is empty.\n";
}

void insertRecord( fstream &hw )
{
   Hardware temp;
   int part;
   string name;
   int stock;
   double price;

   cout << "Enter the part number for insertion: ";
   cin >> part;

   hw.seekg( part * sizeof( Hardware ) );
   hw.read( reinterpret_cast< char * > ( &temp ), sizeof( Hardware ) );

   if ( temp.getPartNumber() == -1 ) 
   {
      temp.setPartNumber( part );
      cout << "Enter the Hardware name: ";
      cin.ignore();
      getline( cin, name ); 
      temp.setHardwareName( name );

      cout << "Enter quantity and price: "; 
      cin >> stock >> price; 
      temp.setInStock( stock );
      temp.setUnitPrice( price );

      hw.seekp( temp.getPartNumber() * sizeof( Hardware ) );
      hw.write( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );
   }
   else
      cerr << "Cannot insert. The record contains information.\n";
}

void deleteRecord( fstream &hw )
{
   Hardware newHw;
   Hardware temp;
   int part;

   cout << "Enter the part number for deletion: ";
   cin >> part;

   hw.seekg( part * sizeof( Hardware ) );
   hw.read( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );

   if ( temp.getPartNumber() != -1 ) 
   {
      hw.seekp( part * sizeof( Hardware ) );
      hw.write( reinterpret_cast< char * >( &newHw ), sizeof( Hardware ) );
      cout << "Record deleted.\n";
   }
   else
      cerr << "Cannot delete. The record is empty.\n";
}
