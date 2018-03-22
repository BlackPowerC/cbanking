//
// Created by jordy on 21/03/18.
//

/**
 * \file Crypto
 */

#ifndef CRYPTO_HPP
#define CRYPTO_HPP

#include <sodium/crypto_pwhash_argon2i.h>
#include <sodium/crypto_hash_sha512.h>
#include <string>

namespace Util
{
    int hashArgon2(std::string &hash, const std::string &passwsd) ;

    int hashSha512(std::string &hash, const std::string &passwsd) ;
}

#endif // CRYPTO_HPP
