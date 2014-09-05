#include <iostream> 
#include <string> 
#include <iomanip> 
using namespace std;

int main()
{
   string response;
   int w = 0;
   const int WORDS = 4;

   do 
   {
      const char body[] = " o/|\\|/\\";

      string words[ WORDS ] = {  
         "MACAW", "SADDLE", "TOASTER", "XENOCIDE" };
      string xword( words[ w ].length(), '?' );
      
      string::iterator i;
      string::iterator ix = xword.begin();

      char letters[ 26 ] = { '\0' };
      
      int n = 0;
      int xcount = xword.length(); 
      bool found = false;
      bool solved = false;
      int offset = 0;
      int bodyCount = 0;
      bool hung = false;

      cout << "Guess the word: ";

      for ( unsigned loop = 0; loop < words[ w ].length(); loop++ )
         cout << "X";

      do 
      {
         cout << "\n\nGuess a letter (case does not matter): "
            << xword << "\n?";
         
         char temp;
         cin >> temp;
      
         if ( !isalpha( temp ) )
         {
            cout << "\nLETTERS ONLY PLEASE\n";   
            continue;
         }

         letters[ n ] = toupper( temp );

         i = words[ w ].begin();
         found = false;
         offset = 0;

         while ( i != words[ w ].end() ) 
         {
            if ( *i == letters[ n ] ) 
            {
               *( ix + offset ) = *i;
               found = true;
         
               if ( --xcount == 0 )
                  solved = true;
            }

            i++;
            offset++;
         }

         if ( !found )
            bodyCount++;
      
         bool newline = false;

         for ( int q = 1; q <= bodyCount; q++ ) 
         {
            if ( q == 1 || q == 5 || q == 7 ) 
            {
               newline = true;
               cout << body[ 0 ];
            }
            else if ( q == 4 )
               newline = true;
            else
               newline = false;

            cout << body[ q ];

            if ( newline )
               cout << '\n';
         }

         if ( bodyCount == 7 ) 
         {
            cout << "\n\n...GAME OVER...\n";
            hung = true;
            break;
         }

         cout << "\nYour guesses:\n";
   
         for ( int k = 0; k <= n; k++ )
            cout << setw( 2 ) << letters[ k ];

         n++;
      } while ( !solved );

      cout << "\n\nWord: " << words[ w ] << "\n\n";

      if ( !hung )
         cout << "\nCongratulations!!! You guessed "
            << "my word.\n";
   
      if ( w++ >= WORDS )
         break;
         
      cout << "Play again (yes/no)? ";
      cin >> response;
      
   } while ( !response.compare( "yes" ) );

   cout << "\nThank you for playing hangman." << endl;
}
