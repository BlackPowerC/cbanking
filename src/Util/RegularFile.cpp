//
// Created by jordy on 23/03/18.
//

#include "../../include/Util/RegularFile.hpp"

namespace Util
{
    std::string fromFileToString(const std::string &filePath)
    {
        std::ifstream file_to_read(filePath, std::ios::binary) ;
        if(file_to_read.fail())
        {
            throw FileStreamError("Impossible de lire "+filePath) ;
        }
        std::string container ;
        file_to_read.seekg(0, std::ios::end) ;
        long file_bytes = file_to_read.tellg()+1L ;
        container.resize(file_bytes) ;
        file_to_read.seekg(0, std::ios::beg) ;
        file_to_read.read(&container[0], file_bytes) ;
        file_to_read.close() ;

        return container ;
    }
}