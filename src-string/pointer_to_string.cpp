#include "pch.hpp"
#include "pointer_to_string.hpp"

namespace be::util::detail {

///////////////////////////////////////////////////////////////////////////////
S pointer_address(U16 ptr, be::t::SizeTag<U16>) {
   char buffer[sizeof(std::uintmax_t) * 2 + 4];
   int length = sprintf_s(buffer, sizeof(buffer), "0x%.4jX", (std::uintmax_t)ptr);
   return length < 0 ? "0x????" : S(buffer, (std::size_t)length);
}

///////////////////////////////////////////////////////////////////////////////
S pointer_address(U32 ptr, be::t::SizeTag<U32>) {
   char buffer[sizeof(std::uintmax_t) * 2 + 4];
   int length = sprintf_s(buffer, sizeof(buffer), "0x%.8jX", (std::uintmax_t)ptr);
   return length < 0 ? "0x????????" : S(buffer, (std::size_t)length);
}

///////////////////////////////////////////////////////////////////////////////
S pointer_address(U64 ptr, be::t::SizeTag<U64>) {
   char buffer[sizeof(std::uintmax_t) * 2 + 4];
   int length = sprintf_s(buffer, sizeof(buffer), "0x%.16jX", (std::uintmax_t)ptr);
   return length < 0 ? "0x????????????????" : S(buffer, (std::size_t)length);
}

} // be::util::detail
