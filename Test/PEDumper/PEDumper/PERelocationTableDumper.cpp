#include "stdafx.h"
#include "PERelocationTableDumper.h"

void PERelocationTableDumper::DoDump()
{
    DumpBasicInformation(_relocationTable);

    UINT32 relocationPageCount = _relocationTable->GetPageCount();
    GetOutputElement()->SetAttribute("relocation-page-count", relocationPageCount);

    for (UINT32 relocationPageIndex = 0; relocationPageIndex < relocationPageCount; ++relocationPageIndex) {
        LibPEPtr<IPERelocationPage> relocationPage;
        if (FAILED(_relocationTable->GetPageByIndex(relocationPageIndex, &relocationPage))) {
            continue;
        }

        PERelocationPageDumper()
            .SetDumpElement(relocationPage)
            .SetPEFile(GetPEFile())
            .SetParentElement(GetOutputElement())
            .Run();
    }
}

void PERelocationPageDumper::DoDump()
{
    DumpBasicInformation(_relocationPage);

    BEGIN_DUMP_PE_ELEMENT(_relocationPage)
        DUMP_RAW_FIELD_SIMPLE(VirtualAddress)
        DUMP_RAW_FIELD_SIMPLE(SizeOfBlock)
    END_DUMP_PE_ELEMENT()

    UINT32 relocationItemCount = _relocationPage->GetItemCount();
    GetOutputElement()->SetAttribute("relocation-item-count", relocationItemCount);

    for (UINT32 relocationItemIndex = 0; relocationItemIndex < relocationItemCount; ++relocationItemIndex) {
        LibPEPtr<IPERelocationItem> relocationItem;
        if (FAILED(_relocationPage->GetItemByIndex(relocationItemIndex, &relocationItem))) {
            continue;
        }

        PERelocationItemDumper()
            .SetDumpElement(relocationItem)
            .SetPEFile(GetPEFile())
            .SetParentElement(GetOutputElement())
            .Run();
    }
}

void PERelocationItemDumper::DoDump()
{
    DumpBasicInformation(_relocationItem);

    BEGIN_DUMP_PE_ELEMENT(_relocationItem)
        DUMP_API_RESULT_SIMPLE(GetAddressRVA)
        DUMP_API_RESULT_SIMPLE(GetAddressContent)
    END_DUMP_PE_ELEMENT()
}

