/// File: ListExtensions.cs
/// Programmer: Philip Kempton
/// First Version: March 23rd, 2020
/// Description: This file contains the static ListExtensions class.

using System.Collections.Generic;
using System.Security.Cryptography;

namespace Cards
{
    /// <summary>
    /// This class contains extension methods for the System.Collections.Generic.List<T> class.
    /// </summary>
    public static class ListExtensions
    {
        /// <summary>
        /// Random number generator for List.Shuffle() extension method method.
        /// </summary>
        /// <remarks>
        /// This class is better than System.Random where the factorial of the length og the list exceeds 2^64.
        /// This is due to System.Random missing possible permutations of the list when above this length.
        /// </remarks>
        private static readonly RandomNumberGenerator RNG = RandomNumberGenerator.Create();

        /// <summary>
        /// OVERLOADED METHOD
        /// Shuffles a Lift<T> a number of times using a veriable RNG object for randomness.
        /// </summary>
        /// <typeparam name="T">type of object in list</typeparam>
        /// <param name="list">the list</param>
        /// <param name="rng">the RNG object to use</param>
        /// <param name="numOfShuffles">number of times to shuffle</param>
        public static void Shuffle<T>(this IList<T> list, RandomNumberGenerator rng, int numOfShuffles)
        {
            // perform the shuffle [nTimes] number of times
            for (int i = 0; i < numOfShuffles; i++)
            {
                // starting at list.End and moving to list.Beginning:
                //      swap each object with a random one on it's left side
                // CODE REFERENCE: 
                //      Durstenfeld, R (1964). Fisher-Yates Shuffle [algorithm]. Retrieved on 
                //      March 23rd, 2020 from https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
                for (int currIndex = list.Count - 1; currIndex > 0; currIndex--)
                {
                    byte[] randBytes = new byte[1];
                    rng.GetBytes(randBytes);
                    int randIndex = randBytes[0] % (currIndex);
                    list.Swap(currIndex, randIndex);
                }
            } 
        }
        
        /// <summary>
        /// OVERLOADED METHOD
        /// Shuffles a List<T> a number of times using an RNG property object for randomess.
        /// </summary>
        /// <typeparam name="T">type of object in list</typeparam>
        /// <param name="list">the list</param>
        /// <param name="numOfShuffles">number of times to shuffle</param>
        public static void Shuffle<T>(this IList<T> list, int numOfShuffles)
        {
            list.Shuffle(RNG, numOfShuffles);
        }

        /// <summary>
        /// Swaps two objects in a list.
        /// </summary>
        /// <typeparam name="T">the type of object in the list</typeparam>
        /// <param name="list">the list</param>
        /// <param name="iFirst">index of first object to swap</param>
        /// <param name="iSecond">index of second object to swap</param>
        public static void Swap<T>(this IList<T> list, int iFirst, int iSecond)
        {
            // use temp buffer to swap he objects
            T buffer = list[iFirst];
            list[iFirst] = list[iSecond];
            list[iSecond] = buffer;
        }
    }
}
