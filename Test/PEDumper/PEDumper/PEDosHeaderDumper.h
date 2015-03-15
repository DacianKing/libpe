#pragma once

#include "PEElementDumper.h"

class PEDosHeaderDumper :
    public PEElementDumper
{
public:
    PEDosHeaderDumper() : PEElementDumper("DosHeader") {}

    PEDosHeaderDumper & SetDumpElement(IPEDosHeader *dosHeader) {
        _dosHeader = dosHeader;
        return *this;
    }

protected:
    void DoDump() override;

private:
    LibPEPtr<IPEDosHeader> _dosHeader;
};