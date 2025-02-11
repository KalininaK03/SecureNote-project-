//проект подразумевает заметки с шифрованием, вводом пароля пользователя, приветственным окном
//crypto-отвечает за шифрование текста
#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
 using namespace std;
class Crypto
{
public:


    static string encrypt(const string plainText, const string key);
    static string decrypt(const string clipherText, const string key);
};

#endif
