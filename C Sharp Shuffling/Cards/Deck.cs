/// File: Deck.cs
/// Programmer: Philip Kempton
/// First Version: March 23rd, 2020
/// Description: This file contains the Deck class

using System.Collections.Generic;
using System.Text;

namespace Cards
{
    /// <summary>
    /// This class represents a deck of playing cards
    /// (Ace through King of each standard suit)
    /// </summary>
    public class Deck
    {
        /// <summary>
        /// Name of the deck of cards
        /// </summary>
        private string Name { get; set; }

        /// <summary>
        /// The list of cards in the deck
        /// </summary>
        private List<Card> Cards { get; set; }

        /// <summary>
        /// Array of all valid suits (used for Population() method)
        /// </summary>
        private static readonly string[] SUITS = {
                "Spades", "Hearts", "Diamonds", "Clubs"
        };

        /// <summary>
        /// Array of all valid card names (used for Population() method)
        /// </summary>
        private static readonly string[] CARD_NAMES = {
                "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                "Eight", "Nine", "Ten", "Jack", "Queen", "King"
        };

        /// <summary>
        /// Constructor
        /// Populates the list of cards and optionally shuffles them
        /// </summary>
        /// <param name="name">bool to decide if deck should start shuffled</param>
        public Deck(string name)
        {
            this.Name = name;
            this.Populate();
        }

        /// <summary>
        /// Populates the card list with Ace through King of all four suits
        /// </summary>
        private void Populate()
        {
            // reset the deck list
            this.Cards = new List<Card>();

            // create all cards from ace -> king of each suit and put into cards list 
            foreach (string suit in SUITS)
            {
                foreach (string cardName in CARD_NAMES)
                {
                    this.Cards.Add(new Card(suit, cardName));
                }
            }
        }

        /// <summary>
        /// Shuffles the cards in the cards list
        /// </summary>
        public void Shuffle(int numOfShuffles)
        {
            // this part is fun, 
            // created a List Extension method that implements a shuffling algorithm
            this.Cards.Shuffle(numOfShuffles);
        }

        /// <summary>
        /// OVERRIDE
        /// Creates and returns string representation of the deck
        /// </summary>
        /// <returns>list of cards in deck</returns>
        public override string ToString()
        {
            // put name of deck on it's own line, follow by an empty line
            // then list each card in the deck on it's own line
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(string.Format("{0}\n", this.Name));
            int lastIndex = this.Cards.Count - 1;
            foreach (Card card in this.Cards)
            {
                if (card != this.Cards[lastIndex])
                {
                    sb.AppendLine(card.ToString());
                }
            }
            sb.Append(this.Cards[lastIndex]);
            return sb.ToString();
        }
    }
}
