//
// Created by jordy on 28/05/18.
//

#include "../../include/Entity/News.hpp"

namespace Entity
{
    News::News()
    {

    }

    News::News(const News &another): m_id(another.m_id), m_date(another.m_date),
                                     m_text(another.m_text), m_title(another.m_title)
    {

    }

    News::News(const News *another): m_id(another->m_id), m_date(another->m_date),
                                     m_text(another->m_text), m_title(another->m_title)
    {

    }

    std::string News::getTitle() const
    {
        return this->m_title ;
    }

    void News::setTitle(const char *title)
    {
        this->m_title = std::string(title) ;
    }
    void News::setTitle(const std::string &title)
    {
        this->m_title = title ;
    }

    long News::getId() const
    {
        return this->m_id ;
    }
    void News::setId(long id)
    {
        this->m_id = id ;
    }

    std::string News::getDate() const
    {
        return this->m_date ;
    }

    void News::setDate(const std::string &date)
    {
        this->m_date =date ;
    }
    void News::setDate(const char *date)
    {
        this->m_date = std::string(date) ;
    }

    std::string News::getText() const
    {
        return this->m_text ;
    }
    void News::setText(const std::string &text)
    {
        this->m_text = text ;
    }

    void News::setText(const char *text)
    {
        this->m_text = std::string(text) ;
    }
}
