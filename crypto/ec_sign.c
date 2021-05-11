#include "hblk_crypto.h"
#include "sha256.c"
/**
 *ec_sign - signs a given set of bytes, using a given EC_KEY private key
 *@key: points to the EC_KEY structure containing
 *the private key to be used to perform the signature
 *@msg: points to the msglen characters to be signed
 *@msglen: len of msg param
 *@sig: holds the address at which to store the signature
 *Return: pointer to signature buffer || NULL upon failure
*/
uint8_t *ec_sign(EC_KEY const *key,
		uint8_t const *msg, size_t msglen, sig_t *sig)
{
	unsigned char md[SHA256_DIGEST_LENGTH];
	int8_t* const new_msg = (int8_t*) msg;

	if (!key || !msg || !sig)
	{
		fprintf(stderr, "params check failed");
		return (NULL);
	}
	if (!EC_KEY_check_key(key))
	{
		fprintf(stderr, " Key check Failed");
		return (NULL);
	}
	if (!sha256(new_msg, msglen, md))
	{
		fprintf(stderr, " sha256 Error");
		return (NULL);
	}
	sig->len = ECDSA_size(key);
	if (!sig->len)
	{
	fprintf(stderr, " ECDA_size Error");
	return (NULL);
	}
	if (!ECDSA_sign(0, md, SHA256_DIGEST_LENGTH, sig->sig,
		(unsigned int *)&(sig->len), (EC_KEY *)key))
	{
		fprintf(stderr, " ECDA_size Error");
		return (NULL);
	}
	fprintf(stderr, "EC_SIGN EXIT STATUS \nmsg:  ");
	fprintf("%s ___", *msg);
	_print_string_buffer(msg, msglen);
	fprintf(stderr, "\n");
	fprintf(stderr, "digested msg: ");
	printf("%u",md);
	fprintf(stderr, "\n");
	fprintf(stderr, "The signature : ");
	printf("0x%02x", (sig->sig));
	fprintf(stderr, "\n");
	fprintf(stderr, "The signature buffer: ");
	_print_hex_buffer(sig->sig, SIG_MAX_LEN);
	fprintf(stderr, "\n");
	fprintf(stderr, "The length of the signature after: ");
	printf("%d",sig->len);
	fprintf(stderr, "\n");
   	return (sig->sig);


}
