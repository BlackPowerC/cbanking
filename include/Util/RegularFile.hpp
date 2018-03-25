//
// Created by jordy on 25/03/18.
//

#ifndef CBANKING_REST_API_REGULARFILE_HPP
#define CBANKING_REST_API_REGULARFILE_HPP

#include <string>
#include <fstream>
#include "../Exception.hpp"

namespace Util
{
    std::string fromFileToString(const std::string &filePath) ;
}

#endif //CBANKING_REST_API_REGULARFILE_HPP
