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
#include <sodium/crypto_pwhash.h>
#include <sodium/crypto_hash.h>
#include <sodium.h>
#include <string>

namespace Util
{
    /**
     * Cette fonction hash un mot de passe avec l'algorithme argon2i.
     * @param hash Le mot de passe hashé.
     * @param passwsd Le mot de passe à hasher.
     * @return
     */
    int hashArgon2(std::string &hash, const std::string &passwsd) ;

    /**
     * Cette fonction hash un mot de passe avec l'algorithme sha512.
     * @param hash Le mot de passe hashé.
     * @param passwsd Le mot de passe à hasher.
     * @return
     */
    int hashSha512(std::string &hash, const std::string &passwsd) ;
}

#endif // CRYPTO_HPP
