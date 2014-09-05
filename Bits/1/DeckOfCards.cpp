#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "DeckOfCards.h"

using namespace std;

DeckOfCards::DeckOfCards()
{
   for ( int i = 0; i <= 51; i++ ) 
   {
      deck[ i ].face = i % 13;
      deck[ i ].suit = i / 13;
      deck[ i ].color = i / 26;
   }
}

void DeckOfCards::shuffle()
{
   for ( int i = 0; i < 52; i++ ) 
   {
      int j = rand() % 52;
      BitCard temp = deck[ i ];
      deck[ i ] = deck[ j ];
      deck[ j ] = temp;     
   }
}

void DeckOfCards::deal()
{
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six",
		                  "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
   const char *color[] = { "Red", "Black" };

   for ( int i = 0; i < 52; i++ ) 
   {
      cout << right << setw( 5 ) << color[ deck[ i ].color ] << ": "
         << setw( 8 ) << face[ deck[ i ].face ] << " of " 
         << left << setw( 8 ) << suit[ deck[ i ].suit ]
         << ( ( i + 1 ) % 2 ? '\t' : '\n' );
   }
}
