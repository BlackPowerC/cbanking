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
    std::string hashArgon2(const std::string &passwd) ;

    bool verifyArgon2Hash(const std::string &hash, const std::string &passwd) ;

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

    /**
     * Cette fontion convertir un tableau d'octet en une chaine
     * de nombre hexadécimaux.
     * @param bytes Un pointeur sur un tableau d'octets.
     * @param n Le nombre d'octets dans le tableau.
     * @return Une chaine de caractères en hexadécimal
     */
    std::string bytesToHex(const u_char *bytes, int n) ;
}

#endif // CRYPTO_HPP
