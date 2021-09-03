public class Card
{
	String color, suit, name;
	int value, rank;
	
	// Constructor with empty arguments
	Card()
	{
		color = "red";
		suit = "diamonds";
		name = "ace";
		value = 1;
		rank = 1;
	}
	
	Card(String s, int r) // Suit and rank are provided
	{
		String [] names = {"ace","2","3","4","5","6","7","8","9","10","jack","queen","king"};
		
		suit = s;
		rank = r;
		if(rank > 10)
			value = 10;
		else
			value = rank;
		
		if(suit.equals("spades") || suit.equals("clubs"))
			color = "black";
		else
			color = "red";
			
		name = names[rank-1];
	}
	
	// A method to compare cards
	public int compareTo(Card two)
	{
		if(this.rank < two.rank)
		{
			return -1;
		}
		else if(this.rank > two.rank)
		{
			return 1;
		}
		else
			return 0;
	}
	
	public String toString()
	{
		return name + " " + suit;
	}
}
