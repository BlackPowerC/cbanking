//
// Created by jordy on 17/05/18.
//

#ifndef FCMNOTIFICATION_HPP
#define FCMNOTIFICATION_HPP

#include <curl/curl.h>
#include "../Exception.hpp"
#include "../Util/RegularFile.hpp"
#include "../Util/JSONValidator.hpp"

namespace Fcm
{
    /**
     * @class FCMNotification
     * @brief Cette classe sert à faciliter l'envoie de notification
     * via Firebase Cloud Messaging. Implemente le pattern singleton.
     */
    class FCMNotification
    {
    private :
        static FCMNotification *p_singleton ;
        FCMNotification() ;
    public:
        /**
         * Cette fonction envoie une notification vers un terminal bien précis.
         * @param instanceAppId L'id du terminal.
         * @param message Le méssage à envoyer.
         * @throw CurlException Si l'utilisation de curl échoue.
         * @throw IllegalArgument Si instanceAppId est une chaine vide.
         */
        void sendMessageToSpecificDevice(const std::string &instanceAppId, const std::string &message) ;
        ~FCMNotification() ;
        static FCMNotification *getInstance() ;
    };
}


#endif //FCMNOTIFICATION_HPP
