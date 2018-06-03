#ifndef NEWS_API_INCLUDED
#define NEWS_API_INCLUDED

#include "PersistenceAPI.hpp"

namespace API
{
    class NewsAPI: public PersistenceAPI
    {
    private:
        static NewsAPI *p_singleton ;
        NewsAPI() {};
    public:
        static NewsAPI* getInstance()
        {
            if(!p_singleton)
            {
                p_singleton = new NewsAPI ;
            }
            return p_singleton ;
        }

        ~NewsAPI()
        {
            if(p_singleton)
            {
                delete p_singleton ;
            }
        }

        void doNothing() {}
    };

    NewsAPI* NewsAPI::p_singleton = nullptr;
}

#endif // NEWS_API_INCLUDED