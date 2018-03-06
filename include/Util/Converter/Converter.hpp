/**
 * \file Converter.hpp
 * \author jordy fatigba fatigba72@gmail.com
 * \date 2018-03-06
 * \brief Ce fichier contient la définition de la classe
 *        Converter.
 */

#ifndef CONVERTER_HPP_INCLUDED
#define CONVERTER_HPP_INCLUDED

#include <memory>
#include <string>
#include "../../Entity/Entity.hpp"

/**
 * \namespace Util
 * \brief Le namespace Util contient des classes utilitaires.
 */

namespace Util
{
    /**
     * \class Converter
     * @tparam Entity
     * \brief La classe converter est la classe de base des convertisseurs.
     *        Ces convertisseurs, convertissent des entités en format json.
     */
    template<class Entity>
    class Converter
    {
    public:
        /**
         * \brief Cette fonction convertit une entité en format JSON
         * @param entity
         * @return Une chaine de caractère formaté en JSON.
         */
        virtual std::string entityToJson(const Entity &entity) = 0;

        virtual std::string entityToJson(const Entity *entity) = 0;

        virtual std::string entityToJson(const std::shared_ptr <Entity> &entity) = 0;
    };

}
#endif // CONVERTER_HPP_INCLUDED