/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx_types.h"

namespace php {
template <typename T>
static inline Variant operator+(T a, const Variant &b) {
    return Variant(a) + b;
}

template <typename T>
static inline Variant operator-(T a, const Variant &b) {
    return Variant(a) - b;
}

template <typename T>
static inline Variant operator*(T a, const Variant &b) {
    return Variant(a) * b;
}

template <typename T>
static inline Variant operator/(T a, const Variant &b) {
    return Variant(a) / b;
}

template <typename T>
static inline Variant operator%(T a, const Variant &b) {
    return Variant(a) % b;
}

static inline Variant operator%(Float a, const Variant &b) {
    return Variant(a) % b;
}

template <typename T>
static inline Variant operator<<(T a, const Variant &b) {
    return Variant(a) << b;
}

template <typename T>
static inline Variant operator>>(T a, const Variant &b) {
    return Variant(a) >> b;
}

template <typename T>
static inline Variant operator&(T a, const Variant &b) {
    return Variant(a) & b;
}

template <typename T>
static inline Variant operator|(T a, const Variant &b) {
    return Variant(a) | b;
}

template <typename T>
static inline Variant operator^(T a, const Variant &b) {
    return Variant(a) ^ b;
}

template <typename T>
static inline Variant operator<=(T a, const Variant &b) {
    return Variant(b >= a);
}

template <typename T>
static inline Variant operator<(T a, const Variant &b) {
    return Variant(b > a);
}

template <typename T>
static inline Variant operator>=(T a, const Variant &b) {
    return Variant(b <= a);
}

template <typename T>
static inline Variant operator>(T a, const Variant &b) {
    return Variant(b < a);
}

template <typename T>
static inline bool operator==(T a, const Variant &b) {
    return b == a;
}

template <typename T>
static inline bool operator!=(T a, const Variant &b) {
    return b != a;
}

// A Reference is a Variant; comparing it with a native number must not be
// ambiguous between the Variant member operators and the templates above.
#define PHPX_REFERENCE_CMP(op, ret)                                              \
    static inline ret operator op(const Reference &a, zend_long b) {           \
        return static_cast<const Variant &>(a) op b;                           \
    }                                                                          \
    static inline ret operator op(const Reference &a, double b) {              \
        return static_cast<const Variant &>(a) op b;                           \
    }                                                                          \
    static inline ret operator op(zend_long a, const Reference &b) {           \
        return Variant(a) op static_cast<const Variant &>(b);                  \
    }                                                                          \
    static inline ret operator op(double a, const Reference &b) {              \
        return Variant(a) op static_cast<const Variant &>(b);                  \
    }
PHPX_REFERENCE_CMP(<, bool)
PHPX_REFERENCE_CMP(>, bool)
PHPX_REFERENCE_CMP(<=, bool)
PHPX_REFERENCE_CMP(>=, bool)
PHPX_REFERENCE_CMP(==, bool)
PHPX_REFERENCE_CMP(!=, bool)
#undef PHPX_REFERENCE_CMP
}  // namespace php
