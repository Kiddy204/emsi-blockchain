
#include "hblk_crypto.h"
/**
 * EC_create - creates returns a public private EC key
 *
 *  Return:  a pointer to EC_KEY structure
 */

EC_KEY *ec_create()
{
	EC_KEY *key;
	/*Create a new EC SECP256 Structure */
	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key)
	{
		fprintf(stderr, "EC Curve was not successfully generated");
		return (NULL);
	}
	/*Generate Public and private Keys*/
	EC_KEY_generate_key(key);
	if (!key)
	{
		fprintf(stderr, " Key's were not successfully generate");
		return (NULL);
	}
	return (key);
}

