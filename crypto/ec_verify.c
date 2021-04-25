/**
* ec_verify -  Verifies the signature given a public key
* @key : EC_Key structure
* @msg : chars for which to verify the signature
* @msglen : message length
* @sig : signature to be checked
* Return: A boolean
*/
#include "hblk_crypto.h"

int ec_verify(EC_KEY const *key, uint8_t const *msg,
		size_t msglen, sig_t const *sig)
{
	unsigned char digest_msg[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (0);
	if (!EC_KEY_check_key(key))
		return (0);
	unsigned char digest_msg[SHA256_DIGEST_LENGTH];

	if (!SHA256(msg, msglen, digest_msg))
		return (0);
	if (ECDSA_verify(0, digest_msg, SHA256_DIGEST_LENGTH, sig->sig, sig->len,
				(EC_KEY *)key) != 1)
		return (0);
	return (1);
}
