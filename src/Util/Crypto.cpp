//
// Created by jordy on 22/03/18.
//

/**
 * \file Crypto.cpp
 * \brief Implémentation des fonctions de Crypto.hpp
 */

#include "../../include/Util/Crypto.hpp"
#include <cstring>
#include <plog/Log.h>

namespace Util
{
    std::string hashArgon2(const std::string &passwd)
    {
        unsigned char *out ;
        try
        {
            out = new u_char[crypto_pwhash_argon2i_STRBYTES] ;
        }
        catch(const std::bad_alloc &ba)
        {
            LOG_ERROR << ba.what() ;
            throw BadMalloc(std::string(ba.what())) ;
        }
        unsigned long long passwd_size = (unsigned long long) passwd.size() ;
        if(crypto_pwhash_argon2i_str(out, passwd.c_str(),
                                     passwd_size,
                                     crypto_pwhash_OPSLIMIT_SENSITIVE,
                                     crypto_pwhash_MEMLIMIT_SENSITIVE) != 0)
        {
            delete out ;
            throw OutOfMemory("Impossible de hasher le mot de passe !") ;
        }
        else
        {
            std::string hash(&out[0], &out[crypto_pwhash_argon2i_STRBYTES-1]) ;
            delete out ;
            return hash ;
        }
    }

    std::string hashSha512(const std::string &passwd)
    {
    }

    std::string hashGeneric(const std::string &passwd)
    {
    }
}