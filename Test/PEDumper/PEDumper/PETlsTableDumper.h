#pragma once

#include "PEElementDumper.h"

class PETlsTableDumper :
    public PEElementDumper
{
public:
    PETlsTableDumper() : PEElementDumper("TlsTable") {}

    PETlsTableDumper & SetDumpElement(IPETlsTable *tlsTable) {
        _tlsTable = tlsTable;
        return *this;
    }

protected:
    void DoDump() override;

private:
    LibPEPtr<IPETlsTable> _tlsTable;
};
