import java.util.*;
public class Game
{
	int result; // Stores the result of a game
	Deck d;
	
	Game()  // Get ready to play new game
	{
		d = new Deck();  // Create a new deck
		d.shuffle();  // Shuffle the deck
	}
	
	int sum(ArrayList<Card> hand)
	{
		int total = 0;
		for(int i = 0; i < hand.size(); i++)
			total = total + hand.get(i).value;
		return total;
	}
	
	void showCards(ArrayList<Card> hand)
	{
		for(int i = 0; i < hand.size(); i++)
			System.out.println(hand.get(i));
	}
	void playBlackjack()
	{
		ArrayList<Card> playerHand = new ArrayList<>();
		ArrayList<Card> dealerHand = new ArrayList<>();
		// Conducts the game
		// Both player and dealer get two cards
		playerHand.add(d.drawCard());
		playerHand.add(d.drawCard());
		int playerSum = sum(playerHand);
		showCards(playerHand);
		dealerHand.add(d.drawCard());
		dealerHand.add(d.drawCard());
		int dealerSum = sum(dealerHand);
		showCards(dealerHand);
		
		if(playerSum > dealerSum)
			result = 1;
		else
			result = 0;
	}
	
}
