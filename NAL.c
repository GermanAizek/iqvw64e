#include "driver.h"
#include <stdint.h>

int64_t sub_5e2010(DRIVER_OBJECT * DriverObject)
{
	sub_11f10("\nNal Windows Driver Loaded -- Compiled %s %s", "Oct 23 2012"); // custom DbgPrintEx

	void* rax = &data_5cfec0;
	data_17120 = 0;
	int64_t i_2 = 0x100;
	int64_t i;

	do
	{
		* (uint8_t*)((char*)rax + 0x108) = 0;
		* (uint64_t*)rax = 0;
		rax = ((char*)rax + 0x110);
		i = i_2;
		i_2 = (i_2 - 1);
	} while (i != 1);

	void* s_1 = &data_3e7a50;
	int64_t i_3 = 0xc350;
	DriverObject->MajorFunction[IRP_MJ_CREATE] = CreateCall; // sub_11070
	DriverObject->MajorFunction[IRP_MJ_CLOSE] = CloseCall; // sub_110d0
	DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = IoControl; // sub_11130
	DriverObject->DriverUnload = UnloadDriver; // sub_11010

	void* s = &data_17148;
	int64_t i_1;
	do
	{
		* (uint32_t*)((char*)s - 8) = 0;
		__builtin_memset(s, 0, 0x48);
		__builtin_memset(s_1, 0, 0x18);
		* (uint64_t*)((char*)s_1 - 0x10) = 0;
		* (uint64_t*)((char*)s_1 - 8) = 0;
		s = ((char*)s + 0x50);
		s_1 = ((char*)s_1 + 0x28);
		i_1 = i_3;
		i_3 = (i_3 - 1);
	} while (i_1 != 1);

	sub_11f10("Nal Windows DriverAddDevice: entered", i_3);

	PDEVICE_OBJECT DeviceObject;
	UNICODE_STRING dev;

	RtlInitUnicodeString(&dev, u"\Device\Nal");
	NTSTATUS status = IoCreateDevice(DriverObject, 0x18, &dev, 0x8086, 0, 0, &DeviceObject);
	NTSTATUS status2;
	int64_t rdx_2;
	if (status >= STATUS_SUCCESS)
	{
		struct _DEVICE_OBJECT* DeviceObject_1 = DeviceObject;
		DriverObject->DeviceObject = DeviceObject_1;
		int64_t * DeviceExtension = DeviceObject_1->DeviceExtension;
		* (uint64_t*)DeviceExtension = DeviceObject_1;
		UNICODE_STRING dos;
		RtlInitUnicodeString(&dos, u"\DosDevices\Nal");
		status2 = IoCreateSymbolicLink(&dos, &dev);
		if (status2 >= STATUS_SUCCESS)
		{
			DEVICE_OBJECT* DeviceObject_2 = DeviceObject;
			DeviceObject_2->Flags |= DO_BUFFERED_IO;
			DEVICE_OBJECT* DeviceObject_3 = DeviceObject;
			DeviceObject_3->Flags &= ~DO_DEVICE_INITIALIZING;
			DeviceExtension[1] = DeviceObject;
		}
	}
	else
	{
		sub_11f10("Nal Windows DriverIoCreateDevice failed.  Status = 0x%0x", ((uint64_t)status));
		status2 = STATUS_UNSUCCESSFUL;
	}

	if ((status < STATUS_SUCCESS || (status >= STATUS_SUCCESS && status2 < STATUS_SUCCESS)))
	{
	    sub_11f10("Nal Windows DriverIoCreateSymbolicLink failed.  Status = 0x%x", ((uint64_t)status2));
	    rdx_2 = IoDeleteDevice(DeviceObject);
	}

	sub_11f10("Nal Windows Driver DriverEntry: Completed", sub_11f10("Nal Windows DriverAddDevice: done", rdx_2));

	return 0;
}
