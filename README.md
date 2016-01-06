# Sieve-of-eratosthenes
Implements the Sieve of Eratosthenes up to 103 with underlying vectors. The numbers all start out white, and turn green if prime, or red if composite. Uses the Stanford Graphics libraries (provided in the repository) to create the graphics. Holds the numbers in a vector and their type (prime, composite, unknown) in a corresponding vector.

The Sieve of Eratosthenes is a classic algorithm of determining prime numbers quickly. Looping through all undetermined numbers, it will calculate all numbers that are composite because of the current number and identify them as composite, while the current is prime.  Eliminating more and more numbers as composite will make primes easier to find.
