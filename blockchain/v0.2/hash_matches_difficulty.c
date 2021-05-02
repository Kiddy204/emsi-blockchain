#include"blockchain.h"
/**
 * power - power functon
 * @base: base
 *@exponent: exponent 
 * Return: base ^ expoenent
 */
int power(int base, int exponent)
{
	int result = 1;

	for (int i = exponent; i > 0; i--)
	{
		result = result * base;
	}
	return (result);
}
/**
 * get_difficulty - serialze hash and determines difficulty
 * @hash: hash buffer
 * Return: difficulty
 */
uint32_t get_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH])
{
	uint8_t *ptr;

	ptr = (uint8_t *)hash;
	fprintf(stderr, "\nGET DIFFICULTY\n");
	uint32_t difficulty = 0;

	while (ptr < hash + SHA256_DIGEST_LENGTH)
	{
		for (int i = 7; i >= 0; i--)
		{
			if (*ptr <= power(2, i) - 1)
			{
				difficulty++;
			}
			else
			{
				fprintf(stderr, "diff : %d \n", difficulty);
				return (difficulty);
			}
		}
		ptr++;
	}
	return (difficulty);
}
/**
 * hash_matches_difficulty - determines if hash matches difficulty
 * @hash: hash buffer
 * @difficulty: difficulty to match
 * Return: 1 if matches else 0
 */
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
			uint32_t difficulty)
{
	if (!hash)
		return (0);
	return  (get_difficulty(hash) == difficulty);
}
