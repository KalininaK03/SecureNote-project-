//crypto.cpp
#include "Crypto.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <vector>

std::string Crypto::encrypt(const std::string& plainText, const std::string& key) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    unsigned char iv[16];
    RAND_bytes(iv, sizeof(iv));


    std::vector<unsigned char> encrypted(plainText.size() + 16);
    int len = 0;

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key.c_str(), iv);
    EVP_EncryptUpdate(ctx, encrypted.data(), &len, (unsigned char*)plainText.c_str(), plainText.size());
    int ciphertextLen = len;
    EVP_EncryptFinal_ex(ctx, encrypted.data() + len, &len);
    ciphertextLen += len;

    EVP_CIPHER_CTX_free(ctx);
    return std::string(encrypted.begin(), encrypted.begin() + ciphertextLen);
}
std::string Crypto::decrypt(const std::string& cipherText, const std::string& key) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    unsigned char iv[16] = {0};

    std::vector<unsigned char> decrypted(cipherText.size());
    int len = 0;

    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key.c_str(), iv);
     EVP_DecryptUpdate(ctx, decrypted.data(), &len, (unsigned char*)cipherText.c_str(), cipherText.size());
     int decryptedLen = len;
    EVP_DecryptFinal_ex(ctx, decrypted.data() + len, &len);
    decryptedLen += len;

    EVP_CIPHER_CTX_free(ctx);
    return std::string(decrypted.begin(), decrypted.begin() + decryptedLen);
}

std::string Crypto::encrypt(const std::string plainText, const std::string key)
{
    return std::string();
}

std::string Crypto::decrypt(const std::string clipherText, const std::string key)
{
    return std::string();
}

