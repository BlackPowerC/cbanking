//
// Created by jordy on 21/03/18.
//

#include "../../include/Util/JSONValidator.hpp"
#include <plog/Log.h>

namespace Util
{
    bool json_is_valid(const std::string &schema, const std::string &json)
    {
        rapidjson::Document controlDocument ;
        if(controlDocument.Parse(schema.c_str()).HasParseError()
           || controlDocument.Parse(json.c_str()).HasParseError())
        {
            return false ;
        }

        rapidjson::Document document ; document.Parse(schema.c_str()) ;
        rapidjson::SchemaDocument schemaDocument(document) ;
        rapidjson::SchemaValidator schemaValidator(schemaDocument) ;
        if(controlDocument.Accept(schemaValidator))
        {
//
            return true ;
        }
        else
        {
//            rapidjson::StringBuffer buffer ;
//            schemaValidator.GetInvalidSchemaPointer().StringifyUriFragment(buffer) ;
//            LOG_ERROR << buffer.GetString() ;
//            LOG_ERROR << schemaValidator.GetInvalidSchemaKeyword() ;
            return false ;
        }
    }
}
