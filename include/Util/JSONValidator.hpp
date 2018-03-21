//
// Created by jordy on 21/03/18.
//

#ifndef JSONVALIDATOR_HPP
#define JSONVALIDATOR_HPP

#include <rapidjson/document.h>
#include <rapidjson/schema.h>

namespace Util
{
    /**
     * @fn bool json_is_valid(const std::string &schema, const std::string &json)
     * @brief Cette fonction permet de valider du json.
     * @param schema Le schema JSON sous forme de chaine de caractères.
     * @param json La chaîne JSON.
     * @return true si json correspond au schema.
     */
    bool json_is_valid(const std::string &schema, const std::string &json) ;
}

#endif //JSONVALIDATOR_HPP
