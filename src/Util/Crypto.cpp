//
// Created by jordy on 22/03/18.
//

/**
 * \file Crypto.cpp
 * \brief Implémentation des fonctions de Crypto.hpp
 */

#include <algorithm>
#include "../../include/Util/Crypto.hpp"

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
        return std::string(out);
    }

    std::string hashSha512(const std::string &passwd)
    {
        const int in_size = passwd.size() ;
        u_char out[crypto_hash_sha512_BYTES] ;
        u_char in[in_size+1] ; in[in_size] = 0 ;

        std::copy(passwd.begin(), passwd.end(), in) ;

        std::string hash;
        if(crypto_hash_sha512(out, in, (unsigned long long) in_size)!=0)
        {
            return std::string() ;
        }
        for(int i=0; i<crypto_hash_sha512_BYTES; i++)
        {
            hash += std::to_string((int) out[i]) ;
        }
        return hash ;
    }

    std::string hashGeneric(const std::string &passwd)
    {
    }

    bool verifyArgon2Hash(const std::string &hash, const std::string &passwd)
    {
        return crypto_pwhash_str_verify(hash.c_str(), passwd.c_str(), (unsigned long long) passwd.size()) == 0 ;
    }
}
