#include "hblk_crypto.h"
/**
 *ec_from_pub - creates an EC_KEY structure given a public key
 *@pub  : public key to convert
 *
 *Return : pointer to an EC_KEY
 */

EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *key; /* EC_Key to be returned */
	EC_POINT *point;  /* pub must be converted to EC_POINT */
	EC_GROUP *group;
	/*oct2point params*/
	if (!pub)
		return (NULL);
	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key)
	{
		EC_KEY_free(key);
		return (NULL);
	}
	group = (EC_GROUP *) EC_KEY_get0_group(key);
	point = EC_POINT_new(group);
	if (!point)
	{
		EC_POINT_free(point);
		EC_KEY_free(key);
		return (NULL);
	}
	if (EC_POINT_oct2point(group, point, pub, EC_PUB_LEN, NULL))
	{
		if (EC_KEY_set_public_key(key, point))
		{
			EC_POINT_free(point);
			return (key);
		}
	}
	EC_KEY_free(key);
	EC_POINT_free(point);
	return (NULL);
}

