/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_iqvw64e,
    0x88cb4172,0x0d65,0x4371,0xbc,0x6f,0x1d,0xc3,0x8a,0xd4,0x9d,0x18);
// {88cb4172-0d65-4371-bc6f-1dc38ad49d18}
