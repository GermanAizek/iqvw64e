#include "driver.h"
#include "driver.tmh"
#include <stdint.h>

//#include "iqvw64e.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, iqvw64eEvtDeviceAdd)
//#pragma alloc_text (PAGE, iqvw64eEvtDriverContextCleanup)
#endif

ULONG_PTR data_17100 = -0x2b992ddfa233;
ULONG_PTR data_17108 = 0x2b992ddfa232;

NTSTATUS
DriverEntry(
    _In_ PDRIVER_OBJECT  DriverObject,
    _In_ PUNICODE_STRING RegistryPath
    )
{
    int64_t rax_2 = data_17108;
    if ((rax_2 == 0 || rax_2 == 0x2b992ddfa232))
    {
        rax_2 = ((*(uint64_t*)-0xfffff78000000320 ^ 0x17108) & 0xffffffffffff);
        if (rax_2 == 0)
        {
            rax_2 = 0x2b992ddfa232;
        }
        data_17108 = rax_2;
    }
    data_17100 = !(rax_2);

    return; // sub_5e2010(DriverObject);
}

NTSTATUS
iqvw64eEvtDeviceAdd(
    _In_    WDFDRIVER       Driver,
    _Inout_ PWDFDEVICE_INIT DeviceInit
    )
{
    NTSTATUS status;

    UNREFERENCED_PARAMETER(Driver);

    PAGED_CODE();

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

    status = iqvw64eCreateDevice(DeviceInit);

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");

    return status;
}

//VOID
//iqvw64eEvtDriverContextCleanup(
//    _In_ WDFOBJECT DriverObject
//    )
//{
//    UNREFERENCED_PARAMETER(DriverObject);
//
//    PAGED_CODE();
//
//    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");
//
//    WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)DriverObject));
//}
