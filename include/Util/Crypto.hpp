//
// Created by jordy on 21/03/18.
//

/**
 * \file Crypto
 */

#ifndef CRYPTO_HPP
#define CRYPTO_HPP

#include <sodium.h>
#include <string>
#include "../Exception.hpp"

namespace Util
{
    /**
     * Cette fonction hash un mot de passe avec l'algorithme argon2i.
     * @param passwsd Le mot de passe à hasher.
     * @return Le hash du mot de passe.
     * @throw OutOfMemory en cas d'erreur de l'algorithme.
     * @throw BadMalloc en cas d'erreur d'allocation de mémoire.
     */
    std::string hashArgon2(const std::string &passwsd) ;

    /**
    * Cette fonction hash un mot de passe avec l'algorithme argon2i.
    * @param passwsd Le mot de passe à hasher.
    * @return Le hash du mot de passe.
    * @throw OutOfMemory en cas d'erreur de l'algorithme.
    * @throw BadMalloc en cas d'erreur d'allocation de mémoire.
    */
    std::string hashSha512(const std::string &passwsd) ;

    /**
    * Cette fonction hash un mot de passe avec l'algorithme argon2i.
    * @param passwsd Le mot de passe à hasher.
    * @return Le hash du mot de passe.
    * @throw OutOfMemory en cas d'erreur de l'algorithme.
    * @throw BadMalloc en cas d'erreur d'allocation de mémoire.
    */
    std::string hashGeneric(const std::string &passwsd) ;
}

#endif // CRYPTO_HPP
