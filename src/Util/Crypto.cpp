//
// Created by jordy on 22/03/18.
//

/**
 * \file Crypto.cpp
 * \brief Implémentation des fonctions de Crypto.hpp
 */

#include "../../include/Util/Crypto.hpp"

namespace Util
{
    int hashArgon2(std::string &hash, const std::string &passwsd)
    {
        hash.resize(crypto_pwhash_argon2i_STRBYTES) ;
        return crypto_pwhash_argon2i_str(&hash[0],
                                         &passwsd[0],
                                         passwsd.size(),
                                         crypto_pwhash_OPSLIMIT_SENSITIVE,
                                         crypto_pwhash_MEMLIMIT_SENSITIVE) ;
    }

    int hashSha512(std::string &hash, const std::string &passwsd)
    {
        hash.resize(crypto_hash_sha512_BYTES) ;
        return crypto_hash_sha512(&passwsd[0],
                                  &hash[0],
                                  passwsd.size()) ;
    }
}