import java.util.*;
public class Deck
{
	Card [] myDeck;
	Random bag;
	int top; // To keep track of number of cards currently in deck
	
	Deck()
	{
		myDeck = new Card[52];
		bag = new Random();
		int i = 0;
		String [] suits = {"spades","clubs","diamonds","hearts"};
		
		for(int suit = 0; suit < 4; suit++)  // Run for each suit
		{
			for(int rank = 1; rank <= 13; rank++)  // Runs for every rank
			{
				Card c = new Card(suits[suit],rank);
				myDeck[i] = c;
				i++;
			}
		}
		top = 52;
	}
	
	public void shuffle()
	{
		for(int i = 0; i < myDeck.length; i++)
		{
			// For each card, c, in the deck,
			// generate a random card, c1
			// swap card c with c2
			int j = bag.nextInt(myDeck.length); // j is the position
			Card temp = myDeck[i];
			myDeck[i] = myDeck[j];
			myDeck[j] = temp;
		}
	}
	
	public Card drawCard()
	{
		top--;
		if(top < 0)
			return null;
		else
		{
			return myDeck[top];
		}
	}
	
	public String toString()
	{
		String info = "";
		for(int i = 0; i < myDeck.length; i++)
		{
			info = info + myDeck[i].toString() + "\n";
		}
		return info;
	}
}
