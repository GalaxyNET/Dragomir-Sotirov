#include <iostream>
using namespace std;

enum Direction { DOWN, RIGHT, UP, LEFT };

void mazeTraversal( char [][ 12 ], const int, const int, int, int, int );
void printMaze( const char[][ 12 ] );
bool validMove( const char [][ 12 ], int, int );
bool coordsAreEdge( int, int );

int main()
{
   char maze[ 12 ][ 12 ] =
     {{'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
      {'x', '0', '0', '0', 'x', '0', '0', '0', '0', '0', '0', 'x'},
      {'0', '0', 'x', '0', 'x', '0', 'x', 'x', 'x', 'x', '0', 'x'},
      {'x', 'x', 'x', '0', 'x', '0', '0', '0', '0', 'x', '0', 'x'},
      {'x', 'u', 'x', '0', '0', 'x', 'x', 'x', '0', 'x', '0', '0'},
      {'x', 'x', 'x', 'x', '0', 'x', 'u', 'x', '0', 'x', 'x', 'x'},
      {'x', 'u', 'u', 'x', '0', 'x', 'u', 'x', '0', 'x', 'u', 'x'},
      {'x', 'x', 'u', 'x', '0', 'x', 'x', 'x', '0', 'x', 'u', 'x'},
      {'x', 'u', 'u', 'x', '0', '0', '0', '0', '0', 'x', 'u', 'x'},
      {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'u', 'x'},
      {'x', 'u', 'u', 'u', 'u', 'u', 'u', 'x', 'u', 'u', 'u', 'x'},
      {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}};

   int xStart = 2;
   int yStart = 0;
   int x = xStart;
   int y = yStart;

   mazeTraversal( maze, xStart, yStart, x, y, RIGHT );
}

void mazeTraversal( char maze[][ 12 ], const int xStart, const int yStart,
   int xCoord, int yCoord, int direction )
{
   static bool flag = false;

   maze[ xCoord ][ yCoord ] = '*';
   printMaze( maze );

   if ( coordsAreEdge( xCoord, yCoord ) && xCoord != xStart &&
        yCoord != yStart )
   {
      cout << "\nMaze successfully exited!\n\n";
      return;
   }

   else if ( xCoord == xStart && yCoord == yStart && flag )
   {
      cout << "\nArrived back at the starting location.\n\n";
      return;
   }
   else
   {
      flag = true;

      for ( int move = direction, count = 0; count < 4; count++, move++, move %= 4 )
      {
         switch( move )
         {
            case DOWN:
               if ( validMove( maze, xCoord + 1, yCoord ) )
               {
                  mazeTraversal(
                     maze, xStart, yStart, xCoord + 1, yCoord, LEFT );
                  return;
               }
               break;
            case RIGHT:
               if ( validMove( maze, xCoord, yCoord + 1 ) )
               {
                  mazeTraversal(
                     maze, xStart, yStart, xCoord, yCoord + 1, DOWN );
                  return;
               }
               break;
            case UP:
               if ( validMove( maze, xCoord - 1, yCoord ) )
               {
                  mazeTraversal(
                     maze, xStart, yStart, xCoord - 1, yCoord, RIGHT );
                  return;
               }
               break;
            case LEFT:
               if ( validMove( maze, xCoord, yCoord - 1 ) )
               {
                  mazeTraversal(
                     maze, xStart, yStart, xCoord, yCoord - 1, UP );
                  return;
               }
               break;
         }
      }
   }
}

bool validMove( const char maze[][ 12 ], int r, int c )
{
   return
      ( r >= 0 && r <= 11 && c >= 0 && c <= 11 && maze[ r ][ c ] != 'x' );
}

bool coordsAreEdge( int x, int y )
{
   if ( ( x == 0 || x == 11 ) && ( y >= 0 && y <= 11 ) )
      return true;
   else if ( ( y == 0 || y == 11 ) && ( x >= 0 && x <= 11 ) )
      return true;
   else
      return false;
}

void printMaze( const char maze[][ 12 ] )
{
   for ( int x = 0; x < 12; x++ )
   {
      for ( int y = 0; y < 12; y++ )
         cout << maze[ x ][ y ] << ' ';

      cout << '\n';
   }

   cout << "\nHit ENTER to move...\n";
   cin.get();
}
