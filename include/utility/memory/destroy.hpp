
#ifndef __UTILITY_MEMORY_DESTROY__
#define __UTILITY_MEMORY_DESTROY__

#include<utility/config/utility_config.hpp>
#include<utility/memory/addressof.hpp>
#include<utility/memory/destroy_at.hpp>
#include<utility/trait/type/features/is_trivially_destructible.hpp>
#include<utility/trait/type/type_trait_special.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    namespace __detail
    {
      using trait::type::features::is_trivially_destructible;
      using trait::type::special::declval;

      template<
        typename _ForwardIterator,
        bool = is_trivially_destructible<
          decltype(*declval<_ForwardIterator>())
        >::value
      >
      struct __destroy
      {
        static inline void __aux(_ForwardIterator __first, _ForwardIterator __last)
        {
          for(; __first != __last; ++__first)
          { memory::destroy_at(memory::addressof(*__first));}
        }
      };
      template<typename _ForwardIterator>
      struct __destroy<_ForwardIterator, true>
      {
        static inline void __aux(_ForwardIterator __first, _ForwardIterator __last)
        { }
      };
    }
    template<typename _ForwardIterator>
    void destroy(_ForwardIterator __first, _ForwardIterator __last)
    { __detail::__destroy<_ForwardIterator>::__aux(__first, __last);}
  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_DESTROY__
