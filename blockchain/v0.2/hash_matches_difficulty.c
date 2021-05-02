#include"blockchain.h"

int power(int base, int exponent)
{
	int result=1;
	for (exponent; exponent>0; exponent--)
	{
		result = result * base;
	}
	return result;
}
uint32_t get_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH]){
	uint8_t *ptr;
	ptr= (uint8_t *)hash;
	fprintf(stderr, "\nGET DIFFICULTY\n");
	//fprintf(stderr, "HASH : ");
	uint32_t difficulty = 0;
	while(ptr< hash + SHA256_DIGEST_LENGTH){
	
		//fprintf(stderr, " %d /", *ptr);
		//fprintf(stderr, "%d \n", *ptr);
		for (int i=7; i>=0;i--){

		fprintf(stderr, "ptr : %d/ comapre to %d \n",*ptr,power(2,i) -1);

			if(*ptr <= power(2,i) -1){
                               fprintf(stderr, "diff ++ \n");
				difficulty++;
			}
			else {
				fprintf(stderr, "diff : %d \n", difficulty);
				return(difficulty);
			}
		}
		ptr++;
	}
	fprintf(stderr, "MAX SIZE  diff : %d \n", difficulty);
 
	fprintf(stderr, "\n________________________________________________________________\n");
	return (difficulty);
}
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH], uint32_t difficulty)
{
	/*uint32_t cptr = 0;
	while (hash[cptr] == 0){
		fprintf(stderr,"hash:  %d", hash[cptr]);
		cptr++;
	}
	if (cptr == difficulty){
		//fprintf(stderr,"MATCH CONFIRMED  %d \n", cptr);
		return (1);
	}
	//fprintf(stderr,"MATCH DENIED %d \n", cptr);
	fflush(stderr);
	return (0);
	*/
	if (get_difficulty(hash)==difficulty){
		return (1);
	};
	return (0);
}
