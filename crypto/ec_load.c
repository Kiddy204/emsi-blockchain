#include "hblk_crypto.h"

/**
 * ec_load - load an EC key pair from the disk
 * @folder: path to pub and pvt keys
 * Return: pointer to created EC key pair, NULL on error
 */
EC_KEY *ec_load(char const *folder)
{
	EC_KEY *key = NULL;
	char buf[BUFSIZ];
	FILE *fp;

	if (!folder)
    {
        fprintf(stderr, "folder param not found");
        return (NULL);
	}

	sprintf(buf, "%s/%s", folder, PUB_FILENAME);
	fp = fopen(buf, "r");
	if (!fp)
        {
        fprintf(stderr, "no File File %s ",buf);
		return (NULL);
        }
	if (!PEM_read_EC_PUBKEY(fp, &key, NULL, NULL))
        {
        fprintf(stderr, "FAIL to load PubKey ");
		goto out;
        }
	sprintf(buf, "%s/%s", folder, PRI_FILENAME);
	fp = fopen(buf, "r");
	if (!fp)
        {
        fprintf(stderr, "no File File %s ",buf);
		return (NULL);
        }
	if (!PEM_read_ECPrivateKey(fp, &key, NULL, NULL))
        {
        fprintf(stderr, "FAIL to load PvtKey ");
		goto out;
        }
out:
    fclose(fp);
	return (key);
}


