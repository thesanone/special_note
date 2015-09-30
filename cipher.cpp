#include "cipher.h"
#include <QDebug>

void Cipher::setKey(const QString value)
{

    key = value;
}

QString Cipher::getKey() const
{
    return key;
}
int Cipher::findMin(QChar *arr, int n)
{
    int index = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[index]) index = i;
    }
    arr[index] = (QChar)32767;
    return index;
}

QString Cipher::encrypt(QString message)
{
    decrypted_message = message;

    const int n = key.size();
    const int m = decrypted_message.size();
    const int z = m+(n - m%n);

    QChar* message_table = new QChar[z];
    QChar* key_char = new QChar[n];
    int* key_arr = new int[n];

    for(int i = 0; i < z; i++)
    {
        if(i < m) message_table[i] = decrypted_message[i];
        else message_table[i] = ' ';
    }

    for(int i = 0; i < n; i++) key_char[i] = key[i];

    for(int i = 0; i < n; i++)
        key_arr[findMin(key_char, n)] = i;

    for(int i = 0; i < z/n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            encrypted_message[n*i+key_arr[j]] = message_table[n*i+j];
        }
    }

    delete[] message_table;
    delete[] key_char;
    delete[] key_arr;

    return encrypted_message;
}

QString Cipher::decrypt(QString message)
{
    encrypted_message = message;

    const int n = key.size();
    const int z = encrypted_message.size();;

    QChar* key_char = new QChar[n];
    int* key_arr = new int[n];
    int* key_arr2 = new int[n];

    for(int i = 0; i < n; i++) key_char[i] = key[i];

    for(int i = 0; i < n; i++)
        key_arr[findMin(key_char, n)] = i;
    for(int i = 0; i < n; i++)
        key_arr2[key_arr[i]] = i;

    for(int i = 0; i < z/n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            decrypted_message[n*i+key_arr2[j]] = encrypted_message[n*i+j];
        }
    }

    delete[] key_arr2;
    delete[] key_char;
    delete[] key_arr;

    return decrypted_message;
}


Cipher::Cipher(QString m_key):key(m_key)
{

}

