//
// Created by jordy on 21/03/18.
//

#include "../../include/Util/JSONValidator.hpp"
#include <plog/Log.h>

namespace Util
{
    bool json_is_valid(const std::string &schema, const std::string &json)
    {
        rapidjson::Document schema_document ; schema_document.Parse(schema.c_str()) ;
        rapidjson::Document json_input ; json_input.Parse(json.c_str()) ;

        if(schema_document.HasParseError() || json_input.HasParseError())
        {
            return false ;
        }

        rapidjson::SchemaDocument schema_d(schema_document) ;
        rapidjson::SchemaValidator validator(schema_d) ;
        if(json_input.Accept(validator))
        {
            return true ;
        }
        else
        {
            rapidjson::StringBuffer sb ;
            validator.GetInvalidSchemaPointer().StringifyUriFragment(sb) ;
            LOG_ERROR <<"Invalid schema: "<< sb.GetString() ;
            LOG_ERROR <<"Invalid keyword: "<< validator.GetInvalidSchemaKeyword() ;
            validator.GetInvalidDocumentPointer().StringifyUriFragment(sb);
            LOG_ERROR <<"Invalid document: "<< sb.GetString();
            return false ;
        }
    }
}
