//
// Created by jordy on 22/03/18.
//

/**
 * \file Crypto.cpp
 * \brief Implémentation des fonctions de Crypto.hpp
 */

#include <plog/Log.h>
#include "../../include/Util/Crypto.hpp"
#include <algorithm>

namespace Util
{
    std::string hashArgon2(const std::string &passwd)
    {
        char out[crypto_pwhash_argon2i_STRBYTES];
        unsigned long long passwd_size = (unsigned long long) passwd.size() ;
        if(crypto_pwhash_argon2i_str(out, passwd.c_str(),
                                     passwd_size,
                                     crypto_pwhash_OPSLIMIT_SENSITIVE,
                                     crypto_pwhash_MEMLIMIT_MIN) != 0)
        {
            throw OutOfMemory("Impossible de hasher le mot de passe !") ;
        }
        return std::string(&out[0], &out[crypto_pwhash_argon2i_STRBYTES-1]);
    }

    std::string hashSha512(const std::string &passwd)
    {
        const int in_size = passwd.size() ;
        u_char out[crypto_hash_sha512_BYTES] ;
        u_char in[in_size+1] ; in[in_size] = 0 ;

        std::copy(passwd.begin(), passwd.end(), in) ;

        std::string hash; hash.resize(crypto_hash_sha512_BYTES) ;
        if(crypto_hash_sha512(out, in, (unsigned long long) in_size)!=0)
        {
            return std::string() ;
        }
        for(int i=0; i<crypto_hash_sha512_BYTES; i++)
        {
            if(out[i] > 127)
                out[i] -= 128 ;
        }
        std::copy(out, out+crypto_hash_sha512_BYTES, hash.begin()) ;
        return hash ;
    }

    std::string hashGeneric(const std::string &passwd)
    {
    }

    bool verifyArgon2Hash(const std::string &hash, const std::string &passwd)
    {
        return crypto_pwhash_str_verify(&hash[0], &passwd[0], (unsigned long long) passwd.size()) == 0 ;
    }
}