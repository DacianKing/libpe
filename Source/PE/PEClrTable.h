#pragma once

#include "PE/PEElement.h"

LIBPE_NAMESPACE_BEGIN

template <class T>
class PEClrTableT :
    public IPEClrTable,
    public PEElementT<T>
{
public:
    PEClrTableT() {}
    virtual ~PEClrTableT() {}

    DECLARE_PE_ELEMENT(LibPERawClrDirectory(T))
};

LIBPE_NAMESPACE_END