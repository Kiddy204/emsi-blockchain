/**
* ec_to_pub - Genereate Public key from private key
* @key : pointer to EC_Key structure
* @pub : extracted public key
* Return: A pointer to pub
*/
#include "hblk_crypto.h"

uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_POINT *point;
	const EC_GROUP *group;

	if (!key)
	{
		return (NULL);
	}
	point = EC_KEY_get0_public_key(key);
	group = EC_KEY_get0_group(key);
	if (!EC_POINT_point2oct(group, point, POINT_CONVERSION_UNCOMPRESSED,
				pub, EC_PUB_LEN, NULL))
	{
		return (NULL);
	}
	return (pub);
}

