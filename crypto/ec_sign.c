#include "hblk_crypto.h"
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
    fprintf(stderr, "EC_SIGN TROUBLESHOOTING");

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
	if (!sha256(msg, msglen, md))
	{
		fprintf(stderr, " SHA256 Error");
		return (NULL);
	}
	sig->len = ECDSA_size(key);
	if (!sig->len)
	{
	fprintf(stderr, " ECDA_size Error");
	return (NULL);
	}
	if (!ECDSA_sign(EC_CURVE, md, SHA256_DIGEST_LENGTH, sig->sig,
		(unsigned int *)&(sig->len), (EC_KEY *)key))
	{
		fprintf(stderr, " ECDA_size Error");
		return (NULL);
	}
    fprintf(stderr, "msg : %s",msg);
	return (sig->sig);

}

