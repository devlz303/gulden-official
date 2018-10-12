// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#pragma once

#include "transaction_type.hpp"
#include <cstdint>
#include <string>
#include <utility>

struct TransactionRecord final {
    TransactionType type;
    int64_t amount;
    std::string address;
    std::string label;
    int64_t timestamp;

    TransactionRecord(TransactionType type_,
                      int64_t amount_,
                      std::string address_,
                      std::string label_,
                      int64_t timestamp_)
    : type(std::move(type_))
    , amount(std::move(amount_))
    , address(std::move(address_))
    , label(std::move(label_))
    , timestamp(std::move(timestamp_))
    {}
};