// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef OPERATION_ODB_HXX
#define OPERATION_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "Operation.hpp"

#include "Account-odb.hxx"
#include "Persons-odb.hxx"

#include <memory>
#include <cstddef>
#include <string>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/polymorphic-info.hxx>
#include <odb/result.hxx>
#include <odb/polymorphic-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // BaseOperation
  //
  template <>
  struct class_traits< ::Entity::BaseOperation >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Entity::BaseOperation >
  {
    public:
    typedef ::Entity::BaseOperation object_type;
    typedef ::std::shared_ptr< ::Entity::BaseOperation > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::Entity::BaseOperation root_type;
    typedef ::std::string discriminator_type;
    typedef polymorphic_map<object_type> map_type;
    typedef polymorphic_concrete_info<object_type> info_type;
    typedef polymorphic_abstract_info<object_type> abstract_info_type;

    static const std::size_t depth = 1UL;

    typedef long int id_type;

    static const bool auto_id = true;

    static const bool abstract = true;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };

  // Operation
  //
  template <>
  struct class_traits< ::Entity::Operation >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Entity::Operation >
  {
    public:
    typedef ::Entity::Operation object_type;
    typedef ::std::shared_ptr< ::Entity::Operation > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::Entity::BaseOperation root_type;
    typedef ::Entity::BaseOperation base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 2UL;

    typedef object_traits< ::Entity::BaseOperation >::id_type id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      object_traits<root_type>::pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      root_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };

  // Virement
  //
  template <>
  struct class_traits< ::Entity::Virement >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Entity::Virement >
  {
    public:
    typedef ::Entity::Virement object_type;
    typedef ::std::shared_ptr< ::Entity::Virement > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::Entity::BaseOperation root_type;
    typedef ::Entity::BaseOperation base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 2UL;

    typedef object_traits< ::Entity::BaseOperation >::id_type id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      object_traits<root_type>::pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      root_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>
#include <odb/mysql/query.hxx>

namespace odb
{
  // BaseOperation
  //
  template <typename A>
  struct pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >
  {
    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    id_type_;

    static const id_type_ id;

    // typeid_
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    typeid__type_;

    static const typeid__type_ typeid_;

    // t_source
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    t_source_type_;

    static const t_source_type_ t_source;

    // t_employee
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    t_employee_type_;

    static const t_employee_type_ t_employee;

    // date
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    date_type_;

    static const date_type_ date;

    // montant
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        double,
        mysql::id_double >::query_type,
      mysql::id_double >
    montant_type_;

    static const montant_type_ montant;
  };

  template <typename A>
  const typename pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::id_type_
  pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::typeid__type_
  pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::
  typeid_ (A::table_name, "`typeid`", 0);

  template <typename A>
  const typename pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::t_source_type_
  pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::
  t_source (A::table_name, "`id_account`", 0);

  template <typename A>
  const typename pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::t_employee_type_
  pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::
  t_employee (A::table_name, "`id_employee`", 0);

  template <typename A>
  const typename pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::date_type_
  pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::
  date (A::table_name, "`date`", 0);

  template <typename A>
  const typename pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::montant_type_
  pointer_query_columns< ::Entity::BaseOperation, id_mysql, A >::
  montant (A::table_name, "`montant`", 0);

  template <>
  class access::object_traits_impl< ::Entity::BaseOperation, id_mysql >:
    public access::object_traits< ::Entity::BaseOperation >
  {
    public:
    typedef object_traits_impl<root_type, id_mysql> root_traits;

    struct discriminator_image_type
    {
      details::buffer discriminator_value;
      unsigned long discriminator_size;
      my_bool discriminator_null;

      std::size_t version;
    };

    struct id_image_type
    {
      long long id_value;
      my_bool id_null;

      std::size_t version;
    };

    static map_type* map;
    static const abstract_info_type info;

    struct image_type
    {
      // id
      //
      long long id_value;
      my_bool id_null;

      // typeid_
      //
      details::buffer typeid_value;
      unsigned long typeid_size;
      my_bool typeid_null;

      // t_source
      //
      long long t_source_value;
      my_bool t_source_null;

      // t_employee
      //
      long long t_employee_value;
      my_bool t_employee_null;

      // date
      //
      details::buffer date_value;
      unsigned long date_size;
      my_bool date_null;

      // montant
      //
      double montant_value;
      my_bool montant_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct t_source_tag;
    struct t_employee_tag;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static discriminator_type
    discriminator (const image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef
    mysql::polymorphic_root_object_statements<object_type>
    statements_type;

    typedef statements_type root_statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 6UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 1UL;
    static const std::size_t managed_optimistic_column_count = 0UL;
    static const std::size_t discriminator_column_count = 1UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char find_discriminator_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);

    static void
    discriminator_ (statements_type&,
                    const id_type&,
                    discriminator_type*);
  };

  template <>
  class access::object_traits_impl< ::Entity::BaseOperation, id_common >:
    public access::object_traits_impl< ::Entity::BaseOperation, id_mysql >
  {
  };

  // Operation
  //
  template <typename A>
  struct pointer_query_columns< ::Entity::Operation, id_mysql, A >:
    pointer_query_columns< ::Entity::BaseOperation, id_mysql, typename A::base_traits >
  {
    // BaseOperation
    //
    typedef pointer_query_columns< ::Entity::BaseOperation, id_mysql, typename A::base_traits > BaseOperation;

    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    id_type_;

    static const id_type_ id;

    // typeOperation
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::Entity::TypeOperation,
        mysql::id_long >::query_type,
      mysql::id_long >
    typeOperation_type_;

    static const typeOperation_type_ typeOperation;
  };

  template <typename A>
  const typename pointer_query_columns< ::Entity::Operation, id_mysql, A >::id_type_
  pointer_query_columns< ::Entity::Operation, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::Entity::Operation, id_mysql, A >::typeOperation_type_
  pointer_query_columns< ::Entity::Operation, id_mysql, A >::
  typeOperation (A::table_name, "`typeOperation`", 0);

  template <>
  class access::object_traits_impl< ::Entity::Operation, id_mysql >:
    public access::object_traits< ::Entity::Operation >
  {
    public:
    typedef polymorphic_entry<object_type, id_mysql> entry_type;
    typedef object_traits_impl<root_type, id_mysql> root_traits;
    typedef object_traits_impl<base_type, id_mysql> base_traits;

    typedef root_traits::id_image_type id_image_type;

    static const info_type info;

    struct image_type
    {
      base_traits::image_type* base;

      // id
      //
      long long id_value;
      my_bool id_null;

      // typeOperation
      //
      int typeOperation_value;
      my_bool typeOperation_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static bool
    grow (image_type&,
          my_bool*,
          std::size_t = depth);

    static void
    bind (MYSQL_BIND*,
          const MYSQL_BIND* id,
          std::size_t id_size,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*,
          std::size_t = depth);

    static void
    init (id_image_type&, const id_type&);

    static bool
    check_version (const std::size_t*, const image_type&);

    static void
    update_version (std::size_t*, const image_type&, mysql::binding*);

    typedef
    mysql::polymorphic_derived_object_statements<object_type>
    statements_type;

    typedef
    mysql::polymorphic_root_object_statements<root_type>
    root_statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 2UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char* const find_statements[depth];
    static const std::size_t find_column_counts[depth];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*,
           std::size_t = depth);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload,
           std::size_t = depth);

    static void
    load_ (database&, root_type&, std::size_t);
  };

  template <>
  class access::object_traits_impl< ::Entity::Operation, id_common >:
    public access::object_traits_impl< ::Entity::Operation, id_mysql >
  {
  };

  // Virement
  //
  template <typename A>
  struct pointer_query_columns< ::Entity::Virement, id_mysql, A >:
    pointer_query_columns< ::Entity::BaseOperation, id_mysql, typename A::base_traits >
  {
    // BaseOperation
    //
    typedef pointer_query_columns< ::Entity::BaseOperation, id_mysql, typename A::base_traits > BaseOperation;

    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    id_type_;

    static const id_type_ id;

    // t_destination
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    t_destination_type_;

    static const t_destination_type_ t_destination;
  };

  template <typename A>
  const typename pointer_query_columns< ::Entity::Virement, id_mysql, A >::id_type_
  pointer_query_columns< ::Entity::Virement, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::Entity::Virement, id_mysql, A >::t_destination_type_
  pointer_query_columns< ::Entity::Virement, id_mysql, A >::
  t_destination (A::table_name, "`id_account`", 0);

  template <>
  class access::object_traits_impl< ::Entity::Virement, id_mysql >:
    public access::object_traits< ::Entity::Virement >
  {
    public:
    typedef polymorphic_entry<object_type, id_mysql> entry_type;
    typedef object_traits_impl<root_type, id_mysql> root_traits;
    typedef object_traits_impl<base_type, id_mysql> base_traits;

    typedef root_traits::id_image_type id_image_type;

    static const info_type info;

    struct image_type
    {
      base_traits::image_type* base;

      // id
      //
      long long id_value;
      my_bool id_null;

      // t_destination
      //
      long long t_destination_value;
      my_bool t_destination_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct t_destination_tag;

    using object_traits<object_type>::id;

    static bool
    grow (image_type&,
          my_bool*,
          std::size_t = depth);

    static void
    bind (MYSQL_BIND*,
          const MYSQL_BIND* id,
          std::size_t id_size,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*,
          std::size_t = depth);

    static void
    init (id_image_type&, const id_type&);

    static bool
    check_version (const std::size_t*, const image_type&);

    static void
    update_version (std::size_t*, const image_type&, mysql::binding*);

    typedef
    mysql::polymorphic_derived_object_statements<object_type>
    statements_type;

    typedef
    mysql::polymorphic_root_object_statements<root_type>
    root_statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 2UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char* const find_statements[depth];
    static const std::size_t find_column_counts[depth];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*,
           std::size_t = depth);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload,
           std::size_t = depth);

    static void
    load_ (database&, root_type&, std::size_t);
  };

  template <>
  class access::object_traits_impl< ::Entity::Virement, id_common >:
    public access::object_traits_impl< ::Entity::Virement, id_mysql >
  {
  };

  // BaseOperation
  //
  template <>
  struct alias_traits<
    ::Entity::Account,
    id_mysql,
    access::object_traits_impl< ::Entity::BaseOperation, id_mysql >::t_source_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Entity::Person,
    id_mysql,
    access::object_traits_impl< ::Entity::BaseOperation, id_mysql >::t_employee_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Entity::Employee,
    id_mysql,
    access::object_traits_impl< ::Entity::BaseOperation, id_mysql >::t_employee_tag>
  {
    typedef alias_traits<
      ::Entity::Person,
      id_mysql,
      access::object_traits_impl< ::Entity::BaseOperation, id_mysql >::t_employee_tag>
    base_traits;

    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::Entity::BaseOperation, id_mysql >
  {
    // t_source
    //
    typedef
    odb::alias_traits<
      ::Entity::Account,
      id_mysql,
      access::object_traits_impl< ::Entity::BaseOperation, id_mysql >::t_source_tag>
    t_source_alias_;

    // t_employee
    //
    typedef
    odb::alias_traits<
      ::Entity::Employee,
      id_mysql,
      access::object_traits_impl< ::Entity::BaseOperation, id_mysql >::t_employee_tag>
    t_employee_alias_;
  };

  template <typename A>
  struct query_columns< ::Entity::BaseOperation, id_mysql, A >:
    query_columns_base< ::Entity::BaseOperation, id_mysql >
  {
    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    id_type_;

    static const id_type_ id;

    // typeid_
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    typeid__type_;

    static const typeid__type_ typeid_;

    // t_source
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    t_source_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Entity::Account,
        id_mysql,
        t_source_alias_ > >
    t_source_pointer_type_;

    struct t_source_type_: t_source_pointer_type_, t_source_column_type_
    {
      t_source_type_ (const char* t, const char* c, const char* conv)
        : t_source_column_type_ (t, c, conv)
      {
      }
    };

    static const t_source_type_ t_source;

    // t_employee
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    t_employee_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Entity::Employee,
        id_mysql,
        t_employee_alias_ > >
    t_employee_pointer_type_;

    struct t_employee_type_: t_employee_pointer_type_, t_employee_column_type_
    {
      t_employee_type_ (const char* t, const char* c, const char* conv)
        : t_employee_column_type_ (t, c, conv)
      {
      }
    };

    static const t_employee_type_ t_employee;

    // date
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    date_type_;

    static const date_type_ date;

    // montant
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        double,
        mysql::id_double >::query_type,
      mysql::id_double >
    montant_type_;

    static const montant_type_ montant;
  };

  template <typename A>
  const typename query_columns< ::Entity::BaseOperation, id_mysql, A >::id_type_
  query_columns< ::Entity::BaseOperation, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename query_columns< ::Entity::BaseOperation, id_mysql, A >::typeid__type_
  query_columns< ::Entity::BaseOperation, id_mysql, A >::
  typeid_ (A::table_name, "`typeid`", 0);

  template <typename A>
  const typename query_columns< ::Entity::BaseOperation, id_mysql, A >::t_source_type_
  query_columns< ::Entity::BaseOperation, id_mysql, A >::
  t_source (A::table_name, "`id_account`", 0);

  template <typename A>
  const typename query_columns< ::Entity::BaseOperation, id_mysql, A >::t_employee_type_
  query_columns< ::Entity::BaseOperation, id_mysql, A >::
  t_employee (A::table_name, "`id_employee`", 0);

  template <typename A>
  const typename query_columns< ::Entity::BaseOperation, id_mysql, A >::date_type_
  query_columns< ::Entity::BaseOperation, id_mysql, A >::
  date (A::table_name, "`date`", 0);

  template <typename A>
  const typename query_columns< ::Entity::BaseOperation, id_mysql, A >::montant_type_
  query_columns< ::Entity::BaseOperation, id_mysql, A >::
  montant (A::table_name, "`montant`", 0);

  // Operation
  //
  template <typename A>
  struct query_columns< ::Entity::Operation, id_mysql, A >:
    query_columns< ::Entity::BaseOperation, id_mysql, typename A::base_traits >
  {
    // BaseOperation
    //
    typedef query_columns< ::Entity::BaseOperation, id_mysql, typename A::base_traits > BaseOperation;

    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    id_type_;

    static const id_type_ id;

    // typeOperation
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::Entity::TypeOperation,
        mysql::id_long >::query_type,
      mysql::id_long >
    typeOperation_type_;

    static const typeOperation_type_ typeOperation;
  };

  template <typename A>
  const typename query_columns< ::Entity::Operation, id_mysql, A >::id_type_
  query_columns< ::Entity::Operation, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename query_columns< ::Entity::Operation, id_mysql, A >::typeOperation_type_
  query_columns< ::Entity::Operation, id_mysql, A >::
  typeOperation (A::table_name, "`typeOperation`", 0);

  // Virement
  //
  template <>
  struct alias_traits<
    ::Entity::Account,
    id_mysql,
    access::object_traits_impl< ::Entity::Virement, id_mysql >::t_destination_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::Entity::Virement, id_mysql >
  {
    // t_destination
    //
    typedef
    odb::alias_traits<
      ::Entity::Account,
      id_mysql,
      access::object_traits_impl< ::Entity::Virement, id_mysql >::t_destination_tag>
    t_destination_alias_;
  };

  template <typename A>
  struct query_columns< ::Entity::Virement, id_mysql, A >:
    query_columns_base< ::Entity::Virement, id_mysql >,
    query_columns< ::Entity::BaseOperation, id_mysql, typename A::base_traits >
  {
    // BaseOperation
    //
    typedef query_columns< ::Entity::BaseOperation, id_mysql, typename A::base_traits > BaseOperation;

    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    id_type_;

    static const id_type_ id;

    // t_destination
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    t_destination_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Entity::Account,
        id_mysql,
        t_destination_alias_ > >
    t_destination_pointer_type_;

    struct t_destination_type_: t_destination_pointer_type_, t_destination_column_type_
    {
      t_destination_type_ (const char* t, const char* c, const char* conv)
        : t_destination_column_type_ (t, c, conv)
      {
      }
    };

    static const t_destination_type_ t_destination;
  };

  template <typename A>
  const typename query_columns< ::Entity::Virement, id_mysql, A >::id_type_
  query_columns< ::Entity::Virement, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename query_columns< ::Entity::Virement, id_mysql, A >::t_destination_type_
  query_columns< ::Entity::Virement, id_mysql, A >::
  t_destination (A::table_name, "`id_account`", 0);
}

#include "Operation-odb.ixx"

#include <odb/post.hxx>

#endif // OPERATION_ODB_HXX
