#include "hblk_crypto.h"
/**
 *ec_sign -
*/
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t *sig)
{
        unsigned char md[SHA256_DIGEST_LENGTH];
    	if(!key || !msg || !sig)
        {
            fprintf(stderr,"params check failed");
            return (NULL);
        }
    	if(!EC_KEY_check_key(key))
        {
            fprintf(stderr," Key check Failed");
            return (NULL);

        }
        if (!SHA256(msg, msglen, md))
        {
		return (NULL);
        }
        sig->len = ECDSA_size(key);
        if (!sig->len)
            return (NULL);
        if (!ECDSA_sign(EC_CURVE, md, SHA256_DIGEST_LENGTH, sig->sig,
				(unsigned int *)&(sig->len), (EC_KEY *)key))
		return (NULL);
        return (sig->sig);

}
