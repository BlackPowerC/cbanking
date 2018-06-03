//
// Created by jordy on 01/06/18.
//

#ifndef FUTURABANK_REST_API_NEWSCONVERTER_HPP
#define FUTURABANK_REST_API_NEWSCONVERTER_HPP

#include "Converter.hpp"

namespace Util
{
    class NewsConverter: public Converter<Entity::News>
    {
    public:
        std::string entityToJson(const Entity::News &entity) ;

        std::string entityToJson(const Entity::News *entity) ;

        std::string entityToJson(const std::shared_ptr<Entity::News> &entity) ;
    };
}

#endif //FUTURABANK_REST_API_NEWSCONVERTER_HPP
