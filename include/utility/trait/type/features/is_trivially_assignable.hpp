
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_ASSIGNABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_ASSIGNABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_trivially_assignable

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_trivially_assignable
        template<typename _T, typename _U>
        struct is_trivially_assignable :
          public integral_constant<bool,
            __utility_is_trivially_assignable(_T, _U)>
        { };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#else // __utility_has_is_trivially_assignable

#include<utility/trait/type/categories/is_scalar.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_trivially_assignable
        template<typename _T, typename _U>
        struct is_trivially_assignable: public false_type
        { };
        template<typename _T>
        struct is_trivially_assignable<_T&, _T>: public
          integral_constant<bool,
            trait::type::categories::is_scalar<_T>::value
          >
        { };
        template<typename _T>
        struct is_trivially_assignable<_T&, _T&>: public
          integral_constant<bool,
            trait::type::categories::is_scalar<_T>::value
          >
        { };
        template<typename _T>
        struct is_trivially_assignable<_T&, const _T&>: public
          integral_constant<bool,
            trait::type::categories::is_scalar<_T>::value
          >
        { };
        template<typename _T>
        struct is_trivially_assignable<_T&, _T&&>: public
          integral_constant<bool,
            trait::type::categories::is_scalar<_T>::value
          >
        { };
      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __utility_has_is_trivially_assignable

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_ASSIGNABLE__
