/// File: Card.cs
/// Programmer: Philip Kempton
/// First Version: March 23rd, 2020
/// Description: Conatins the Card class.


namespace Cards
{
    /// <summary>
    /// This class represents a playing card.
    /// </summary>
    /// <remarks>
    /// Example: Ace of Spades.
    /// </remarks>
    public class Card
    {
        /// <summary>
        /// The suit of the card (example: "Spades").
        /// </summary>
        public string Suit { get; private set; }

        /// <summary>
        /// The name of the card (example: "Hearts").
        /// </summary>
        public string Name { get; private set; }

        /// <summary>
        /// Constructor
        /// Assigns internal property values.
        /// </summary>
        /// <param name="suit">suit for the card</param>
        /// <param name="name">name for the card</param>
        public Card(string suit, string name)
        {
            this.Suit = suit;
            this.Name = name;
        }

        /// <summary>
        /// OVERRIDE ToString()
        /// </summary>
        /// <remarks>
        /// Example output: "Ace of Spades".
        /// </remarks>
        /// <returns>string representation of the card</returns>
        public override string ToString()
        {
            return string.Format("{0} of {1}", this.Name, this.Suit);
        }
    }
}
