#ifndef HBLK_CRYPTO_H_INCLUDED
#define HBLK_CRYPTO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

#define EC_CURVE NID_secp256k1

uint8_t *sha256(int8_t const *s, size_t len,
	uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);
#endif /* HBLK_CRYPTO_H_INCLUDED*/

