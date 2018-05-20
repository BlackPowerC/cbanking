//
// Created by jordy on 17/05/18.
//

#include <plog/Log.h>
#include <rapidjson/rapidjson.h>
#include "../../include/Rest/FCMNotification.hpp"

namespace Fcm
{

    FCMNotification *FCMNotification::p_singleton = nullptr ;

    FCMNotification* FCMNotification::getInstance()
    {
        if(!p_singleton)
        {
            p_singleton = new FCMNotification ;
        }
        return p_singleton ;
    }

    FCMNotification::FCMNotification()
    {
        LOG_DEBUG << "FMCNotification class instancied" ;
    }

    FCMNotification::~FCMNotification()
    {
        if(p_singleton)
        {
            delete p_singleton ;
            LOG_DEBUG << "FCMNotification singleton destroyed" ;
        }
    }

    void FCMNotification::sendMessageToSpecificDevice(const std::string &instanceAppId, const std::string &message)
    {
        try
        {
            if(!instanceAppId.length())
            {
                throw IllegalArgument("instanceAppId argument must be a non zero length string") ;
            }
            // lecture de la clé du serveur
            std::string fcm_server_config = Util::fromFileToString("resources/fcm/fcm.config.json") ;
            LOG_DEBUG << "fcm_server_config: " << fcm_server_config ;
            // Validation de la configuration
            rapidjson::Document doc; doc.Parse(fcm_server_config.c_str()) ;
            if(doc.HasParseError())
            {
                LOG_ERROR << "" ;
                throw BaseException("") ;
            }
            // Utilisation de curl
            CURL *curl = curl_easy_init() ;
            if(!curl)
            {
                throw CurlException("Cannot init curl_easy") ;
            }
            // Notification
            std::string notification = "{\"to\":\""+instanceAppId+"\"," ;
                        notification += "\"data\":{";
                        notification += "\"message\":\""+message+"\"}}";
            LOG_DEBUG << "notification: " << notification ;
            CURLcode code ;
            // Creation des headers
            std::vector<std::string> header_str ;
            header_str.push_back("Content-Type: application/json") ;
            header_str.push_back(std::string("Authorization: key=").append(doc["serverKey"].GetString())) ;
            struct curl_slist *header_curl = NULL ;
            header_curl = curl_slist_append(header_curl, header_str[0].c_str()) ;
            header_curl = curl_slist_append(header_curl, header_str[1].c_str()) ;
            // Construction de la requête
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_curl) ;
            curl_easy_setopt(curl, CURLOPT_URL, doc["fcmUrl"].GetString()) ;
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, notification.c_str()) ;
            curl_easy_setopt(curl, CURLOPT_POST, 1) ;
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0) ;
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0) ;
            // Envoie de la requete
            code = curl_easy_perform(curl) ;

            if(code != CURLE_OK)
            {
                throw CurlException(std::string(curl_easy_strerror(code))) ;
            }

            curl_easy_cleanup(curl) ;
            curl_slist_free_all(header_curl) ;

            LOG_DEBUG << "Notification sended to " << instanceAppId ;

        }catch (const FileStreamError &fse)
        {
            LOG_ERROR << fse.what() ;
        }
    }
}