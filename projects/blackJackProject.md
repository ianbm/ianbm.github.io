---
layout: project
type: project
image: images/blackJackProject.jpg
title: Black Jack
permalink: projects/blackJackProject
date: 2016-10-07
labels:
  - Java
summary: I created an application that simulates the card game Black Jack
---
<img class="ui medium right floated rounded image" src="/images/blackJackProject.jpg">


Black Jack is a card game where each player receives two cards. Each card has a value: numbered cards have a value of 2-10; Jacks, Queens, and Kings have a value of 10; Aces have a value of either 1 or 11. The objective is for your cards to add up to 21 without exceeding that number. The player with cards that add up to 21 (or closest to 21 if nobody has 21) without exceeding 21 is the winner.

ICS111 is one of the first programming courses that I've taken. In this course we learned the basics of programming and I learned my first programming language which was Java. We were assigned a final project which was to create an application using what we learned that semester. For my project, I chose to create a simulation of the game Black Jack.

Here is some code from the Deck.java file:

```js
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
```
