//
// Created by jordy on 11/03/18.
//

#ifndef CONVERTERCACHE_HPP
#define CONVERTERCACHE_HPP

#include "Converters.hpp"
#include <memory>

namespace Util
{
    /**
     * Enumération pour Convertisseur.
     * Il s'agit d'énumération pour identifier les classes.
     */
    enum
    class ConverterTypeID
    {
        ACCOUNT_CONVERTER,
        PERSON_CONVERTER,
        CUSTOMER_CONVERTER,
        EMPLOYEE_CONVERTER,
        CURRENT_ACCOUNT_CONVERTER,
        SAVINGS_ACCOUNT_CONVERTER
    };
  /**
    * \class ConverterCache
    * \brief Cette classe implémente le patron de conception
    *        prototype pour les héritiers de Converter.
    */
    class ConverterCache
    {
    private:
        std::unique_ptr<AccountConverter> ac ; /*<! Convertisseur de la classe Account*/
        std::unique_ptr<CurrentAccountConverter> cac ; /*<! Convertisseur de la classe CurrentAccount*/
        std::unique_ptr<SavingsAccountConverter> sac ; /*<! Convertisseur de la classe SavingsAccount*/
        std::unique_ptr<PersonConverter> pc ; /*<! Convertisseur de la classe Person*/
        std::unique_ptr<CustomerConverter> cc ; /*<! Convertisseur de la classe Customer*/
        std::unique_ptr<EmployeeConverter> ec ; /*<! Convertisseur de la classe Employee*/
        // Pattern singleton
        static ConverterCache *p_singleton ;
        ConverterCache() {} ;
    public:
        static ConverterCache *getInstance()
        {
            if(!p_singleton)
            {
                p_singleton = new ConverterCache ;
            }
            return p_singleton ;
        }

        ~ConverterCache()
        {
            if(!p_singleton)
            {
                delete p_singleton ;
            }
        }

        /**
         * \brief Cette fonction renvoie une instance unique
         *        d'un convertisseur.
         * @tparam ConverterType Ce type paramettré doit
         *         Correspondre à un des convertisseurs.
         * \param type_id Identifiant de la classe convertisseur.
         * @return Un std::unique_ptr
         * @warning L'objet retourné ne doit pas être affecté à une variable.
         */
        template <typename ConverterType>
        std::unique_ptr<ConverterType> getConverter(const ConverterTypeID type_id) ;
    };
}

#include "ConverterCache.tpp"

#endif //CONVERTERCACHE_HPP
