#ifndef NEWS_HPP_INCLUDED
#define NEWS_HPP_INCLUDED


#include <memory>
#include <odb/core.hxx>

namespace Entity
{
	#pragma db object pointer(std::shared_ptr) session
	class News
	{
	private:
		friend class odb::access ;

		#pragma db id auto not_null
		long m_id ;
		#pragma db type("VARCHAR(127)")
		std::string m_title ;
		#pragma db type("VARCHAR(127)")
		std::string m_date ;
		#pragma db type("TEXT")
		std::string m_text ;
	public:
        News() ;
        News(const News &another) ;
        News(const News *another) ;

        std::string getTitle() const ;
        void setTitle(const char *title) ;
        void setTitle(const std::string &title) ;

		long getId() const ;
		void setId(long id) ;

		std::string getDate() const ;
		void setDate(const std::string &date) ;
        void setDate(const char *date) ;

		std::string getText() const ;
		void setText(const std::string &text) ;
        void setText(const char *text) ;

        bool operator==(const News &another)
        {
            return this->m_id == another.m_id ;
        }

	};
}

#endif // NEWS_HPP_INCLUDED
