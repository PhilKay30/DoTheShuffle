/// File: MainWindow.xaml.cs
/// Programmer: Philip Kempton
/// First Version: March 23rd, 2020
/// Description: Contains Interaction logic for MainWindow.xaml.

using System.Windows;

namespace Cards
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml.
    /// </summary>
    public partial class MainWindow : Window
    {
        /// <summary>
        /// The deck of cards to be shuffled.
        /// </summary>
        private Deck deck { get; set; }

        /// <summary>
        /// CONSTRUCTOR
        /// Initialize window and display a new deck of cards.
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();
            this.DisplayNewDeck();
        }

        /// <summary>
        /// Displays a new, unshuffled deck of cards.
        /// </summary>
        private void DisplayNewDeck()
        {
            this.deck = new Deck(name: "Standard Deck");
            lblDeckDisplay.Content = this.deck.ToString();
        }

        /// <summary>
        /// Shuffles the deck of cards once and displays it again.
        /// </summary>
        private void ShuffleAndDisplay()
        {
            this.deck.Shuffle(numOfShuffles: 1);
            lblDeckDisplay.Content = this.deck.ToString();
        }

        /// <summary>
        /// BUTTON CLICK HANDLER
        /// Shuffles the deck of cards and displays it.
        /// </summary>
        /// <param name="sender">component that recieved trigger event</param>
        /// <param name="e">trigger event</param>
        private void BtnShuffle_Click(object sender, RoutedEventArgs e)
        {
            this.ShuffleAndDisplay();
        }

        /// <summary>
        /// BUTTON CLICK HANDLER
        /// Creates new deck and displays it.
        /// </summary>
        /// <param name="sender">component that recieved the trigger event</param>
        /// <param name="e">trigger event</param>
        private void BtnNewDeck_Click(object sender, RoutedEventArgs e)
        {
            this.DisplayNewDeck();
        }
    }
}
