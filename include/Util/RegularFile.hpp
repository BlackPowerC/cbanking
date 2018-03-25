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
    /**
     * Cette fonction lit le contenu d'un fichier texte vers une
     * chaine de caractère.
     * @param filePath Le chemin vers le fichier.
     * @return
     */
    std::string fromFileToString(const std::string &filePath) ;
}

#endif //CBANKING_REST_API_REGULARFILE_HPP
