
#ifndef ___UTILITY__DEBUG__CONFIG___
#define ___UTILITY__DEBUG__CONFIG___

#ifdef UTILITY_DEBUG

#define __utility_private public
#define __utility_debug   public
#define __UTILITY_ASSGIN(__TYPE, __TYPENAME, __ASS) \
          __type __TYPENAME = __ASS

#define UTILITY_ALGORITHM_NEED_EXTRA true
#define UTILITY_CONTAINER_NEED_EXTRA true
#define UTILITY_ITERATOR_HAS_EXTRA true
#define UTILITY_MATH_HAS_EXTRA true
#define UTILITY_MEMORY_HAS_EXTRA true
#define UTILITY_TRAIT_HAS_EXTRA true

#define __utility_interspace_start(_name) namespace _name {
#define __utility_interspace_end(_name) }
#define __utility_globalspace_start(_name) namespace _name {
#define __utility_globalspace_end(_name) }

#define __uspace(_name) _name

#ifndef UTILITY_NO_EXTRA_CHECK

#else

#endif // ! UTILITY_NO_EXTRA_CHECK

#else

#define __utility_private private
#define __utility_debug   private
#define __UTILITY_ASSGIN(__TYPE, __TYPENAME, __ASS)

#define __utility_interspace_start(_name) inline namespace _name {
#define __utility_interspace_end(_name) }
#define __utility_globalspace_start(_name) namespace std { \
  inline namespace _name {
#define __utility_globalspace_end(_name) } }

#define __uspace(_name) std::_name

#endif // ! __UTILITY_DEBUG

#ifndef UTILITY_NOEXTRA
# define __utility_extra   public
#else
# define __utility_extra   private
#endif

#endif // ! ___UTILITY__DEBUG__CONFIG___
