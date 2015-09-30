#ifndef CIPHER_H
#define CIPHER_H

#include <QChar>
#include <QString>

class Cipher
{
private:
    QString key;
    QString encrypted_message;
    QString decrypted_message;
    int findMin(QChar *arr, int n);
public:
    Cipher(){}
    Cipher(QString key);

    void setKey(const QString value);

    QString encrypt(QString message);
    QString decrypt(QString message);
    QString getKey() const;
};

#endif // CIPHER_H
