public class BlackJackIManz
{
	public static void main(String [] args)
	{
		/*Card c = new Card("spades",1);
		
		c.name = "ace";
		c.suit = "spades";
		c.value = 1;
		c.rank = 1;
		c.color = "black";
		
		
		Card c2 = new Card("hearts",13);
		
		c2.name = "king";
		c2.suit = "hearts";
		c2.value = 10;
		c2.rank = 13;
		c2.color = "red";
		
		
		if(c.compareTo(c2) < 0)
			System.out.println("Card 1 is smaller than card 2");
			
		System.out.println(c);
		System.out.println(c2);
		
		
		Deck d = new Deck();
		//System.out.println(d);
		d.shuffle();
		System.out.println(d);
		System.out.println("First card drawn: " + d.drawCard());
		for(int i = 0; i < 5; i++)
			System.out.println((i+1) + " card drawn: " + d.drawCard());
		*/
		
		Game g = new Game();
		g.playBlackjack();
		if(g.result == 1)
			System.out.println("You won the game");
		else
			System.out.println("You lost the game");
	}
}
