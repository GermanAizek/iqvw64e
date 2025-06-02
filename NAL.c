#include "driver.h"
#include <stdint.h>

int64_t sub_5e2010(DRIVER_OBJECT * arg1)
{
	sub_11f10("\nNal Windows Driver Loaded -- Compiled %s %s", "Oct 23 2012");
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
	arg1->MajorFunction[0] = sub_11070;
	arg1->MajorFunction[2] = sub_110d0;
	arg1->MajorFunction[0xe] = sub_11130;
	arg1->DriverUnload = sub_11010;
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
	void var_28;
	RtlInitUnicodeString(&var_28, u"\Device\Nal");
	NTSTATUS rax_1 = IoCreateDevice(arg1, 0x18, &var_28, 0x8086, 0, 0, &DeviceObject);
	NTSTATUS rax_2;
	int64_t rdx_2;
	if (rax_1 >= STATUS_SUCCESS)
	{
		struct _DEVICE_OBJECT* DeviceObject_1 = DeviceObject;
		arg1->DeviceObject = DeviceObject_1;
		int64_t * DeviceExtension = DeviceObject_1->DeviceExtension;
		* (uint64_t*)DeviceExtension = DeviceObject_1;
		void var_18;
		RtlInitUnicodeString(&var_18, u"\DosDevices\Nal");
		rax_2 = IoCreateSymbolicLink(&var_18, &var_28);
		if (rax_2 >= STATUS_SUCCESS)
		{
			DEVICE_OBJECT * DeviceObject_2 = DeviceObject;
			DeviceObject_2->Flags = (DeviceObject_2->Flags | DO_BUFFERED_IO);
			DEVICE_OBJECT * DeviceObject_3 = DeviceObject;
			DeviceObject_3->Flags = (DeviceObject_3->Flags & ~DO_DEVICE_INITIALIZING);
			DeviceExtension[1] = DeviceObject;
		}
	}
	else
	{
		sub_11f10("Nal Windows DriverIoCreateDevice failed.  Status = 0x%0x", ((uint64_t)rax_1));
		rax_2 = STATUS_UNSUCCESSFUL;
	}

	if ((rax_1 < STATUS_SUCCESS || (rax_1 >= STATUS_SUCCESS && rax_2 < STATUS_SUCCESS)))
	{
	    sub_11f10("Nal Windows DriverIoCreateSymbolicLink failed.  Status = 0x%x", ((uint64_t)rax_2));
	    rdx_2 = IoDeleteDevice(DeviceObject);
	}
	sub_11f10("Nal Windows Driver DriverEntry: Completed", sub_11f10("Nal Windows DriverAddDevice: done", rdx_2));
	return 0;
}
