struct BitCard                                 
{                                              
   unsigned face : 4;
   unsigned suit : 2;
   unsigned color : 1;
};

class DeckOfCards
{
public:
   DeckOfCards();
   void shuffle();
   void deal();
private:
   BitCard deck[ 52 ];
};
