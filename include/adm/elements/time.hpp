/// @file time.hpp
#pragma once

#include <chrono>
#include <string>
#include <boost/variant.hpp>
#include "adm/detail/named_type.hpp"
#include "adm/export.h"

namespace adm {

  /// @brief storage for ADM times of format 'hh:mm:ss.zzzzzSfffff'
  struct FractionalTime {
    int64_t numerator;
    int64_t denominator;

    bool operator==(const FractionalTime& other) const {
      return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const FractionalTime& other) const {
      return !(*this == other);
    }
  };

  using Time = boost::variant<std::chrono::nanoseconds, FractionalTime>;

  /// @brief Tag for NamedType ::Start
  struct StartTag {};
  /// @brief NamedType for the start attribute
  using Start = detail::NamedType<std::chrono::nanoseconds, StartTag>;
  /// @brief Tag for NamedType ::End
  struct EndTag {};
  /// @brief NamedType for the end attribute
  using End = detail::NamedType<std::chrono::nanoseconds, EndTag>;
  /// @brief Tag for NamedType ::Duration
  struct DurationTag {};
  /// @brief NamedType for the duration attribute
  using Duration = detail::NamedType<std::chrono::nanoseconds, DurationTag>;
  /// @brief Tag for NamedType ::Rtime
  struct RtimeTag {};
  /// @brief NamedType for the rtime attribute
  using Rtime = detail::NamedType<std::chrono::nanoseconds, RtimeTag>;

  /// @brief Parse an adm timecode and convert it to a std::chrono::duration
  ADM_EXPORT std::chrono::nanoseconds parseTimecode(
      const std::string& timecode);
  /// @brief Format a std::chrono::duration object as an adm timecode string
  ADM_EXPORT std::string formatTimecode(const std::chrono::nanoseconds& time);

}  // namespace adm
