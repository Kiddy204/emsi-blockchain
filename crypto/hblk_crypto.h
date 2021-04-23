#ifndef HBLK_CRYPTO_H_INCLUDED
#define HBLK_CRYPTO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <openssl/sha.h>
uint8_t *sha256(int8_t const *s, size_t len,
	uint8_t digest[SHA256_DIGEST_LENGTH]);
#endif /* HBLK_CRYPTO_H_INCLUDED*/

